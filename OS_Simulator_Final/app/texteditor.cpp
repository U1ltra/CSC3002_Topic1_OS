/*
 * File: texteditor.cpp
 * --------------------
 * This file implements the texteditor.h interface.
 */

#include "app/texteditor.h"
#include "ui_texteditor.h"
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QFileDialog>
#include <QPushButton>
#include <QLayout>
#include <QMouseEvent>
#include <QCloseEvent>
#include <unistd.h>

TextEditor::TextEditor(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    this->setWindowTitle("No Title - Text Editor");
    this->setStyleSheet("background-color: white");
    const QTextCursor cursor = ui->textEdit->textCursor();

    /* Set initial status for current file. */
    isSaved = false;
    hasPath = false;
    currFile = "No Title.txt";
    this->setShortcut();

    /* Update usage by detecting different oparetions.*/
    setMouseTracking(true);
    this->centralWidget()->setMouseTracking(true);  
    system_timer = new QTimer();
    system_timer->setSingleShot(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));  // To return to the fluctuation mode.
    connect(ui->textEdit,SIGNAL(textChanged()), this, SLOT(texting())); //This program is activitied.
}

TextEditor::~TextEditor()
{
    delete ui;
}

/* Setters */

void TextEditor::setPID(int pid){
    PID=pid;
}

void TextEditor::set_CPU(cpuMon * cpu){
    CPU=cpu;
    CPU->createP(PID,"Text Editor",user);
}

void TextEditor::set_memory(Buddy *Memory){
    memory = Memory;
    if (!memory->mem_allocation(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else{
        created = true;
        showNormal();
    }
}

/* Private Slots */

/*
 * Implementation notes: on_action_NewFile_triggered
 * -------------------------------------------------
 * After processing the current file, set instance variables back to initial status
 * and clear the text edit.
 */

void TextEditor::on_action_NewFile_triggered() {
    to_effect_Click();
    sleeping();
    if (checkIfSaved()) {
        isSaved = false;
        hasPath = false;
        this->setWindowTitle("No Title - Text Editor");
        ui->textEdit->clear();
    }
}

/*
 * Implementation notes: on_action_OpenFile_triggered
 * --------------------------------------------------
 * After processing the current file, pop a slef-designed dialog to receive the
 * absolute path of the file that users intend to open. Read from corresponding file
 * and write the text into our text edit.
 */

void TextEditor::on_action_OpenFile_triggered() {
    to_effect_Click();
    sleeping();
    if (checkIfSaved() == true) {    // Process current file and continue.
        QString file_name;
        QString filePath;
        newOpenFile.Root();
        int rec = newOpenFile.exec();
        file_name = newOpenFile.fileName;
        filePath = newOpenFile.dir.absolutePath();
        QString fileName = filePath + "/" + file_name;  //Receive absolute path.
        if (rec == QDialog::Accepted) {
            if (!fileName.isEmpty()) {
                QFile file(fileName);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QMessageBox::warning(this, "Warning", "File not found");
                    return;
                } else {
                    /* Read from the file and write the text into text edit.*/
                    QByteArray t = file.readAll();
                    ui->textEdit->setText(QString(t));
                    file.close();
                    this->setWindowTitle(QFileInfo(fileName).baseName() + "- Text Editor");
                    hasPath = true;
                    currFile = fileName;
                }
            }
        }
        else {
            return;
        }
    }

}

/*
 * Implementation notes: on_action_Save_triggered,
 *                       on_action_SaveAs_triggered
 * -------------------------------------------------
 * Check if current file have been save to the local. If have, then simply
 * write the text of text edit to local file. If not, pop a dialog to receive
 * the absolute path of the file that users intend to save and save the file.
 */

void TextEditor::on_action_Save_triggered() {
    to_effect_Click();
    sleeping();
    if (hasPath) {
        saveFile(currFile);
    } else {
        saveAsFile();
    }
}

void TextEditor::on_action_SaveAs_triggered() {
    to_effect_Click();
    sleeping();
    saveAsFile();
}

/*
 * Implementation notes: on_action_Exit_triggered,
 *                       closeEvent
 * -------------------------------------------------
 * Process current file and quit the program. At the same time,
 * terminate the process in CPU and deallocate free heap.
 */

void TextEditor::on_action_Exit_triggered() {
    if (created){
        if (checkIfSaved()) {
            memory->deallocate(PID,memory_size);
            while(!CPU->isFreeToClose(PID)){
                sleep(1);
            }
            close();
        }
    }else {
        CPU->terminateP(PID);
        close();
    }
}

void TextEditor::closeEvent(QCloseEvent *e) {
    TextEditor::on_action_Exit_triggered();
}

/* Undo, Cut, Copy, Paste*/

void TextEditor::on_action_Undo_triggered() {
    to_effect_Click();
    sleeping();
    ui->textEdit->undo();
}

void TextEditor::on_action_Cut_triggered() {
    to_effect_Click();
    sleeping();
    ui->textEdit->cut();
}

void TextEditor::on_action_Copy_triggered() {
    to_effect_Click();
    sleeping();
    ui->textEdit->copy();
}

void TextEditor::on_action_Paste_triggered() {
    to_effect_Click();
    sleeping();
    ui->textEdit->paste();
}

/*
 * Implementation notes: on_action_Find_triggered
 * ----------------------------------------------
 * Pop a dialog to receive the text that users intend to find. And use
 * QVBoxLayout to design the dialog. Connect slot function: findText() and
 * the signal: clicked().
 */

void TextEditor::on_action_Find_triggered() {
    to_effect_Click();
    sleeping();
    /* Design the layout of dialog. */
    findDlog = new QDialog(this);
    findLine = new QLineEdit(findDlog);
    forwardBtn = new QRadioButton(tr("Forward"));
    backwardBtn = new QRadioButton(tr("Backward"));
    findDirGroup = new QButtonGroup(findDlog);
    findDirGroup->addButton(forwardBtn);
    findDirGroup->addButton(backwardBtn);
    backwardBtn->setChecked(true);
    QPushButton *findBtn = new QPushButton("Find next", findDlog);
    QVBoxLayout *findLayout = new QVBoxLayout(findDlog);
    findLayout->addWidget(findLine);
    findLayout->addWidget(forwardBtn);
    findLayout->addWidget(backwardBtn);
    findDlog->setWindowTitle("Find");
    findDlog->show();
    connect(findBtn,SIGNAL(clicked()),this,SLOT(findText()));
}

/*
 * Implementation notes: findText
 * ------------------------------
 * Highlight the targeting text. If the backwarBtn is checked, then the direction
 * is backward. Otherwise, it is forward.
 */

void TextEditor::findText() {
    QString text = findLine->text();
    if (text.isEmpty()) {
        QMessageBox::information(this,"Text Editor","Empty search field",QMessageBox::Ok);
    } else {
        if (backwardBtn->isChecked()) {
            if (ui->textEdit->find(text, QTextDocument::FindBackward)) {
                QPalette palette = ui->textEdit->palette();
                palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
                ui->textEdit->setPalette(palette);
            } else {
                QMessageBox::information(this,"Text Editor","Cannot find "+text,QMessageBox::Ok);
            }
        } else {
            if (ui->textEdit->find(text)) {
                QPalette palette = ui->textEdit->palette();
                palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
                ui->textEdit->setPalette(palette);
            } else {
                QMessageBox::information(this,"Text Editor","Cannot find "+text,QMessageBox::Ok);
            }
        }

        }
}

/*
 * Implementation notes: to_simple_Click, to_effect_Click, texting,
 *                       to_moving_around, back_to_fluctuation
 * ----------------------------------------------------------------
 * Update usage of CPU by calling function: operationDet. And start the timer,
 * after 100 milliseconds, notify the CPU to switch to initial status.
 */

void TextEditor::to_simple_Click(){
    CPU->operationDet(PID,simpleClick);
    system_timer->start(100);
}

void TextEditor::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(100);
}

void TextEditor::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(100);
}

void TextEditor::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}

void TextEditor::texting(){
    CPU->operationDet(PID,textIn);
    system_timer->start(100);
}

/* Private functions */

/* Helper functions for Save and SaveAs. */

void TextEditor:: saveFile(QString filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Warning"), tr("File not found"));
        return;
    } else {
        QString text = ui->textEdit->toPlainText();
        file.write(text.toUtf8());
        file.close();
        isSaved = true;
        this->setWindowTitle(QFileInfo(filePath).baseName() + "- Text Editor");
    }
}

void TextEditor:: saveAsFile() {
    QString file_name;
    QString filePath;
    newSaveAs.Root();
    int rec = newSaveAs.exec();
    file_name = newSaveAs.fileName;
    filePath = newSaveAs.dir.absolutePath();
    QString fileName = filePath + "/" + file_name + ".txt";
    if (rec == QDialog::Accepted) {
        if (!fileName.isEmpty()) {
            saveFile(fileName);
            isSaved = true;
            hasPath = true;
            this->setWindowTitle(QFileInfo(fileName).baseName() + "- Text Editor");
        }
    }
    else {
        return;
    }
}

/*
 * Implementation notes: checkIfSaved
 * ---------------------------------
 * If the content have been modified and the file have not been saved to
 * the local, then a QMessageBox will pop to ask for user's intention to
 * save. If user clicks Yes, file will be saved accordingly. If user clicks
 * No, program will continue without processing the file. Return false if
 * user choose to stay on the page, and vice versa.
 */

bool TextEditor::checkIfSaved() {
    if (ui->textEdit->document()->isModified() && isSaved == false) {
        QMessageBox::StandardButton msg =
                QMessageBox::question(this,"Text Editor", "Do you want to save changes to" + currFile + "?",
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Yes);
        if (msg == QMessageBox::Yes) {
            if (hasPath) {
                saveFile(currFile);
            } else {
                saveAsFile();
            }
        } else if (msg == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}

void TextEditor::setShortcut() {
    ui->action_NewFile->setShortcut(QKeySequence("ALT+N"));
    ui->action_Save->setShortcut(QKeySequence("ALT+S"));
    ui->action_SaveAs->setShortcut(QKeySequence("ALT+A"));
    ui->action_Exit->setShortcut(QKeySequence("ALT+X"));
    ui->action_OpenFile->setShortcut(QKeySequence("ALT+O"));
    ui->action_Find->setShortcut(QKeySequence("ALT+F"));
    ui->action_Cut->setShortcut(QKeySequence("ALT+T"));
    ui->action_Copy->setShortcut(QKeySequence("ALT+C"));
    ui->action_Paste->setShortcut(QKeySequence("ALT+P"));
    ui->action_Undo->setShortcut(QKeySequence("ALT+U"));
}

void TextEditor::sleeping(){
    if (CPU->isBusy()){
        sleep(1);
    }
}

/* Protected */

void TextEditor::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
}

void TextEditor::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
}





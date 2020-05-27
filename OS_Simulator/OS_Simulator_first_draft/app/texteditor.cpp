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
//#include <windows.h>
#include <unistd.h>


TextEditor::TextEditor(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    isSaved = false;
    hasPath = false;
    currFile = "C:\\Users\\lfy20\\Desktop\\test\\No Title.txt";
    this->setWindowTitle("No Title - Text Editor");
    const QTextCursor cursor = ui->textEdit->textCursor();
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/images/back.jpg")));
    this->setPalette(pal);
    setMouseTracking(true);
    this->centralWidget()->setMouseTracking(true);

    system_timer = new QTimer();  // To return to the fluctuation.
    system_timer->setSingleShot(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));
    if (ui->textEdit->document()->isModified()) texting();
}

TextEditor::~TextEditor()
{
    delete ui;
}

void TextEditor::on_action_NewFile_triggered() {
    to_effect_Click();
    sleeping();
    if (checkIfSaved() == true) {
        isSaved = false;
        hasPath = false;
        this->setWindowTitle("No Title - Text Editor");
        ui->textEdit->clear();
    }

}

void TextEditor::on_action_OpenFile_triggered() {
    to_effect_Click();
    sleeping();
    if (checkIfSaved() == true) {
//        QString fileName = QFileDialog::getOpenFileName(NULL, "Open", "C:\\Users\\lfy20\\Desktop\\test", "*.txt");
        QString file_name;
        QString filePath;

        newOpenFile.Root();
        int rec = newOpenFile.exec();
        file_name = newOpenFile.fileName;
        filePath = newOpenFile.dir.absolutePath();

        QString fileName = filePath + "/" + file_name;
        if (rec == QDialog::Accepted) {
            if (!fileName.isEmpty()) {
                QFile file(fileName);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QMessageBox::warning(this, "Warning", "File not found");
                    return;
                } else {
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

void TextEditor::on_action_Exit_triggered() {
    to_effect_Click();
    sleeping();
    checkIfSaved();
    this->close();
}

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

void TextEditor::on_action_Find_triggered() {
    to_effect_Click();
    sleeping();
    QDialog *findDlog = new QDialog(this);
    findLine = new QLineEdit(findDlog);
    QPushButton *findBtn = new QPushButton("Find next", findDlog);
    QVBoxLayout *findLayout = new QVBoxLayout(findDlog);
    findLayout->addWidget(findLine);
    findLayout->addWidget(findBtn);
    findDlog->setWindowTitle("Find");
    findDlog->show();
    connect(findBtn,SIGNAL(clicked()),this,SLOT(findText()));
}

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
//    QString fileName = QFileDialog::getSaveFileName(this, tr("Save as"),
//                                                    tr("*.txt"), tr("文本文档(*.txt)"));
//    saveAs * sa = new saveAs();
//    sa->show();
//    QString fileName = sa->directoryPath;

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

//    if (!fileName.isEmpty()) {
//        saveFile(fileName);
//        isSaved = true;
//        hasPath = true;
//        this->setWindowTitle(QFileInfo(fileName).baseName() + "- Text Editor");
//    }

}

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

void TextEditor::findText() {
    QString text = findLine->text();
    if (text.isEmpty()) {
        QMessageBox::information(this,"Text Editor","Empty search field",QMessageBox::Ok);
    } else {
        if (ui->textEdit->find(text, QTextDocument::FindBackward)) {
            QPalette palette = ui->textEdit->palette();
            palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
            ui->textEdit->setPalette(palette);
        } else {
            QMessageBox::information(this,"Text Editor","Cannot find "+text,QMessageBox::Ok);
        }
    }

}

void TextEditor::closeEvent(QCloseEvent *e) {

    if (created){
    if (checkIfSaved()) {
        CPU->terminateP(PID);
        memory->deallocate(PID,memory_size);
        e->accept();
    } else {
        e->ignore();
    }
    }
    CPU->terminateP(PID);
}

void TextEditor::set_CPU(cpuMon * cpu){
    CPU=cpu;
    CPU->createP(PID,"Calculator",user);
}


void TextEditor::setPID(int pid){
    PID=pid;
}

void TextEditor::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
}

void TextEditor::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
}


void TextEditor::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}


void TextEditor::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(100);
}

void TextEditor::to_simple_Click(){
    CPU->operationDet(PID,simpleClick);
    system_timer->start(100);
}

void TextEditor::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(100);
}

void TextEditor::texting(){
    CPU->operationDet(PID,textIn);
    system_timer->start(100);
}

void TextEditor::sleeping(){
    if (CPU->isBusy()){
        sleep(1);
    }
}

void TextEditor::set_memory(Buddy *Memory){
    memory = Memory;
    if (!memory->allocate(PID,memory_size)){
        QMessageBox::critical(this,"Memory Shortage Warning","This computer does not have enough memory capacity.");
        close();
    }else{
        created = true;
    }
}


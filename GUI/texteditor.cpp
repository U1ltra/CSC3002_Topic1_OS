#include "texteditor.h"
#include "ui_texteditor.h"
#include <QLabel>
#include <QLineEdit>
//#include <QMessageBox>
//#include <QFileDialog>

/*
TextEditor::TextEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    isSaved = false;
    currFile = "C:\\Users\\lfy20\\Desktop\\test\\No Title.txt";
    this->setWindowTitle(QFileInfo(currFile).baseName() + "- Text Editor");
    connect(ui->textEdit,SIGNAL(cursorPositionChanged()),this,SLOT(do_cursorChanged()));
}

TextEditor::~TextEditor()
{
    delete ui;
}

void TextEditor::on_action_NewFile_triggered() {
    checkIfSaved();
    isSaved = false;
    this->setWindowTitle("No Title - Text Editor");
    ui->textEdit->clear();
    //ui->textEdit->setVisible(true);
}

void TextEditor::on_action_OpenFile_triggered() {
    checkIfSaved();
    QString fileName = QFileDialog::getOpenFileName(NULL, "Open", "C:\\Users\\lfy20\\Desktop\\test", "*.txt");
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
        }
    }
}

void TextEditor::on_action_Save_triggered() {
    if (isSaved) {
        saveFile(currFile);
    } else {
        saveAsFile();
    }
}


void TextEditor::on_action_SaveAs_triggered() {
    saveAsFile();
}

void TextEditor::on_action_Exit_triggered() {
    checkIfSaved();
    ui->textEdit->close();
}

void TextEditor::on_action_Undo_triggered() {
    ui->textEdit->undo();
}

void TextEditor::on_action_Cut_triggered() {
    ui->textEdit->cut();
}

void TextEditor::on_action_Copy_triggered() {
    ui->textEdit->copy();
}

void TextEditor::on_action_Paste_triggered() {
    ui->textEdit->paste();
}

void TextEditor::on_action_Find_triggered() {
    QDialog *find = new QDialog(this);

}

void TextEditor::do_cursorChanged() {
    int rowNum = ui->textEdit->document()->blockCount();
    //获取光标所在行的行号
    const QTextCursor cursor = ui->textEdit->textCursor();
    int colNum = cursor.columnNumber();
    //获取光标所在列的列号
    //first_statusLabel->setText(tr("%1行 %2列").arg(rowNum).arg(colNum));
    //在状态栏显示光标位置
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
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save as"),
                                                    tr("*.txt"), tr("文本文档(*.txt)"));
    if (!fileName.isEmpty()) {
        saveFile(fileName);
        isSaved = true;
        this->setWindowTitle(QFileInfo(fileName).baseName() + "- Text Editor");
    }

}

void TextEditor::checkIfSaved() {
    if (ui->textEdit->document()->isModified()) {
        QMessageBox::StandardButton msg =
                QMessageBox::question(this,"Text Editor", "Do you want to save changes to" + currFile + "?",
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Yes);
        if (msg == QMessageBox::Yes) {
            if (isSaved) {
                saveFile(currFile);
            } else {
                saveAsFile();
            }
        }
    }
}

void TextEditor::setID(int id){
    pid = id;
}

QString TextEditor::getID(){
    return "TextEditor"+QString::number(pid);
}
*/

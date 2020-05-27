#include "app/openfile.h"
#include "ui_openfile.h"

#include <QProcess>

openFile::openFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::openFile)
{
    ui->setupUi(this);
    connect(this, SIGNAL(init()), this, SLOT(Root()));
    connect(ui->fileList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(doubleClicked(QListWidgetItem*)));
    connect(ui->openButton, SIGNAL(clicked()), this, SLOT(setFileName()));
    connect(ui->openButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    emit init();
}

openFile::~openFile()
{
    delete ui;
}

// This function is represent the new directory that the users choose
void openFile::pathChange(QString path) {
    dir.setPath(path); // Set the path to the current directory path
    directoryPath = dir.absolutePath();
    ui->pathEdit->setText(directoryPath);
}

void openFile::showFileInfoList(QDir dir) {
    ui->fileList->clear(); // clear all the item in the QListWidget
    QFileInfoList list = dir.entryInfoList();

    // extract all the items in this directory and add it to the widget
    for (int i = 0; i < list.count(); i++) {
        QFileInfo tempFile = list.at(i);

        if (tempFile.isDir()) {
            QIcon icon;
            QListWidgetItem *tempListWidgetItem = new QListWidgetItem (tempFile.fileName());
            icon.addFile(QString::fromUtf8(":/image/Menu"), QSize(), QIcon::Normal, QIcon::Off);
            tempListWidgetItem->setIcon(icon);
            ui->fileList->addItem(tempListWidgetItem);
        }
        else {
            QIcon icon;
            QListWidgetItem *tempListWidgetItem = new QListWidgetItem (tempFile.fileName());
            icon.addFile(QString::fromUtf8(":/image/File"), QSize(), QIcon::Normal, QIcon::Off);
            tempListWidgetItem->setIcon(icon);
            ui->fileList->addItem(tempListWidgetItem);
        }
    }

}

void openFile::execute() {
    QFileInfo file;
    if (ui->pathEdit->text() == directoryPath){
        if (ui->fileList->selectedItems().count() > 0)
            file.setFile(dir,ui->fileList->selectedItems().first()->text());
        else file.setFile(dir.dirName());
    }
    else {
        file.setFile(ui->pathEdit->text());
        if (!file.isDir()) {
            if (ui->fileList->selectedItems().count() > 0){
                file.setFile(dir,ui->fileList->selectedItems().first()->text());
            }else file.setFile(dir.dirName());
        }
    }
    if (file.isDir())
    {
        pathChange(file.filePath());
        showFileInfoList(dir);
    }
    else {
        pathChange(file.path());
        showFileInfoList(dir);
        QProcess *pro=new QProcess();
        pro->start(file.filePath());
    }
}

void openFile::Root() {
    pathChange("/");
    showFileInfoList(dir);
}

void openFile::setFileName() {
    fileName = ui->fileList->selectedItems().first()->text();
}

void openFile::doubleClicked(QListWidgetItem*) {
    execute();
}

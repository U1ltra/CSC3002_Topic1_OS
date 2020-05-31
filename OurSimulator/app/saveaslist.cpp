
/*
 * File: saveaslist.cpp
 * --------------------
 * This file implements the saving function.
 */

#include <QProcess>
#include "ui_saveaslist.h"
#include "app/saveaslist.h"

saveAsList::saveAsList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saveAsList)
{
    ui->setupUi(this);
    connect(this, SIGNAL(init()), this, SLOT(Root()));
    connect(ui->fileList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(doubleClicked(QListWidgetItem*)));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(setFileName()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    fileName = "";
    emit init();

}

saveAsList::~saveAsList()
{
    delete ui;
}

// This function is represent the new directory that the users choose
void saveAsList::pathChange(QString path) {
    dir.setPath(path);                          // Set the path to the current directory path
    directoryPath = dir.absolutePath();
    ui->pathEdit->setText(directoryPath);
}

void saveAsList::showFileInfoList(QDir dir) {
    ui->fileList->clear();                      // clear all the item in the QListWidget
    QFileInfoList list = dir.entryInfoList();

    // extract all the items in this directory and add it to the widget
    for (int i = 0; i < list.count(); i++) {
        QFileInfo tempFile = list.at(i);

        if (tempFile.isDir()) {
            QIcon icon;
            QListWidgetItem *tempListWidgetItem = new QListWidgetItem (tempFile.fileName());
            icon.addFile(QString::fromUtf8(":/images/Menu"), QSize(), QIcon::Normal, QIcon::Off);
            tempListWidgetItem->setIcon(icon);
            ui->fileList->addItem(tempListWidgetItem);
        }
        else {
            QIcon icon;
            QListWidgetItem *tempListWidgetItem = new QListWidgetItem (tempFile.fileName());
            icon.addFile(QString::fromUtf8(":/images/File"), QSize(), QIcon::Normal, QIcon::Off);
            tempListWidgetItem->setIcon(icon);
            ui->fileList->addItem(tempListWidgetItem);
        }
    }

}

void saveAsList::execute() {
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

void saveAsList::Root() {
    pathChange("/");
    showFileInfoList(dir);
}

void saveAsList::setFileName() {
    fileName = ui->saveAs->text();
}

void saveAsList::doubleClicked(QListWidgetItem*) {
    execute();
}

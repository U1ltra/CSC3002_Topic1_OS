#include "filesys/visualfilemanager.h"
#include "ui_visualfilemanager.h"
#include <QDebug>
#include <QTimer>
//#include <windows.h>
#include <unistd.h>
VisualFileManager::VisualFileManager(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::VisualFileManager)
{
    ui->setupUi(this);
    connect(this, SIGNAL(initialize()), this, SLOT(Root()));
    connect(ui->lwt_File, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(doubleClicked(QListWidgetItem*)));
    connect(ui->btn_Root,SIGNAL(clicked()),this,SLOT(Root()));
    connect(ui->btn_Copy, SIGNAL(clicked()), this, SLOT (Copy()));
    connect(ui->btn_Paste, SIGNAL(clicked()), this, SLOT(Paste()));
    connect(ui->btn_Create, SIGNAL(clicked()), this, SLOT(Create()));
    connect(ui->btn_Delete, SIGNAL(clicked()), this, SLOT(Delete()));
    connect(ui->btn_Up, SIGNAL(clicked()), this, SLOT(Up()));
    connect(ui->btn_Cd, SIGNAL(clicked()), this, SLOT(Cd()));
    connect(ui->btn_Exit, SIGNAL(clicked()), this, SLOT(Exit()));
    connect(this, SIGNAL(fileNotExist()), this, SLOT(showError()));


    emit initialize();
    setMouseTracking(true);

    system_timer = new QTimer();  // To return to the fluctuation.
    system_timer->setSingleShot(true);
    connect(system_timer,SIGNAL(timeout()),this,SLOT(back_to_fluctuation()));
}

VisualFileManager::~VisualFileManager()
{   CPU->terminateP(PID);
    delete ui;
}

// This function is represent the new directory that the users choose
void VisualFileManager::pathChange(QString path) {
    dir.setPath(path); // Set the path to the current directory path
    directoryPath = dir.absolutePath();
    ui->let_Menu->setText(directoryPath);
}

// This function is goiong to show all the file in  the widget
void VisualFileManager::showFileInfoList(QDir dir) {
    ui->lwt_File->clear(); // clear all the item in the QListWidget
    QFileInfoList list = dir.entryInfoList();

    // extract all the items in this directory and add it to the widget
    for (int i = 0; i < list.count(); i++) {
        QFileInfo tempFile = list.at(i);

        if (tempFile.isDir()) {
            QIcon icon;
            QListWidgetItem *tempListWidgetItem = new QListWidgetItem (tempFile.fileName());
            icon.addFile(QString::fromUtf8(":/image/Menu"), QSize(), QIcon::Normal, QIcon::Off);
            tempListWidgetItem->setIcon(icon);
            ui->lwt_File->addItem(tempListWidgetItem);
        }
        else {
            QIcon icon;
            QListWidgetItem *tempListWidgetItem = new QListWidgetItem (tempFile.fileName());
            icon.addFile(QString::fromUtf8(":/image/File"), QSize(), QIcon::Normal, QIcon::Off);
            tempListWidgetItem->setIcon(icon);
            ui->lwt_File->addItem(tempListWidgetItem);
        }
    }

}

void VisualFileManager::getFileCopy() {
    // if no file is selected, then return
    if (ui->lwt_File->selectedItems().count() <= 0) return;
    copiedfile = new copiedFile(ui->lwt_File->selectedItems().first()->text(), directoryPath);
}

void VisualFileManager::filePaste(QString oldFile, QString newFile) {
    QFileInfo tempFile(oldFile);

    if (!tempFile.isDir()) { // case that it is a file
        QFile::copy(oldFile, newFile);
    }
    else { // case that it is a folder
        QDir oldDir, newDir;
        oldDir.setPath(oldFile);
        newDir.mkdir(newFile); // a new folder
        // copy all the files in the old folder into the new one
        QFileInfoList list = oldDir.entryInfoList();
        for (int i = 2; i < list.count(); i++){
            QString tempfileName = list.at(i).fileName();
            filePaste(oldFile + "/" + tempfileName, newFile + "/" + tempfileName);
        }
    }
}

void VisualFileManager::fileDelete(QString file_path) {
    QFileInfo deleteFile(file_path);
    // case that it is only a file
    if (!deleteFile.isDir()) {
        QFile::remove(file_path);
    }
    // case that it is a folder
    else {
        QDir deleteFileDir(file_path);
        QFileInfoList list = deleteFileDir.entryInfoList();
        for (int i = 2; i < list.count(); i++){
            QString file = list.at(i).fileName();
            fileDelete(file_path + "/" + file);
        }
        deleteFileDir.rmdir(file_path);
    }

}

void VisualFileManager::execute() {
    QFileInfo file;
    if (ui->let_Menu->text() == directoryPath){
        if (ui->lwt_File->selectedItems().count() > 0)
            file.setFile(dir,ui->lwt_File->selectedItems().first()->text());
        else file.setFile(dir.dirName());
    }
    else {
        file.setFile(ui->let_Menu->text());
        if (!file.isDir()) {
            if (ui->lwt_File->selectedItems().count() > 0){
                file.setFile(dir,ui->lwt_File->selectedItems().first()->text());
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

void VisualFileManager::Root() {
    to_effect_Click();
     sleeping();
    pathChange("/");
    showFileInfoList(dir);
}

void VisualFileManager::Copy() {
    to_effect_Click();
     sleeping();
    getFileCopy();
}

void VisualFileManager::Paste() {
    to_effect_Click();
     sleeping();
    if (copiedfile->Path == "/")
        copiedfile->Path = "";
    if (directoryPath == "/")
        directoryPath = "";

    QString oldFilePath, newFilePath;
    oldFilePath = copiedfile->Path +"/" + copiedfile->Name;
    newFilePath = directoryPath + "/" + copiedfile->Name;
    filePaste(oldFilePath, newFilePath);

    if (copiedfile->Path == "/")
        copiedfile->Path = "";
    if (directoryPath == "/")
        directoryPath = "";

    dir.setPath(directoryPath);
    showFileInfoList(dir);
}

void VisualFileManager::Create() {
    to_effect_Click();
     sleeping();
    // using the director that user inputs in the menu
    // as the directory path including file name to create file
    QString fullPath = ui->let_Menu->text();
    if (fullPath == directoryPath)
        return;
    else {
        QDir createdFile(fullPath);
        // case that the file exists
        if (createdFile.exists()){
            return;
        }
        else {
            createdFile.mkpath(fullPath);
            QFileInfo newFile(fullPath);
            pathChange(newFile.path());
            showFileInfoList(dir);
        }
    }
}

void VisualFileManager::Delete() {
    to_effect_Click();
     sleeping();
    if (ui->lwt_File->selectedItems().count() == 0) {
        return;
    }

    // in case that it is in the root directory
    if (directoryPath == "/")
        directoryPath = "";

    QString deleteFileName = ui->lwt_File->selectedItems().first()->text();

    fileDelete(directoryPath + "/" + deleteFileName);

    if (directoryPath == "")
        directoryPath = "/";

    dir.setPath(directoryPath);
    showFileInfoList(dir);
}

void VisualFileManager::Up() {
    to_effect_Click();
     sleeping();
    dir.cd("..");
    pathChange(dir.path());
    showFileInfoList(dir);
}

void VisualFileManager::Cd() {
    to_effect_Click();
     sleeping();
    // if using the file selected in the file list
    if (ui->let_Menu->text() == directoryPath) {
        if (ui->lwt_File->selectedItems().count() <= 0)
            return;
        else {
            QString fileName = ui->lwt_File->selectedItems().first()->text();
            QFileInfo file;
            file.setFile(dir, fileName);
            if (file.isDir()) {
                pathChange(file.filePath());
                showFileInfoList(dir);
            }
            else {
                pathChange(file.path());
                showFileInfoList(dir);
                QProcess *process = new QProcess;
                process->start(file.filePath());
            }
        }
    }
    // if the user type a directory in the edit label
    else {
        QString fullPath = ui->let_Menu->text();
        QFileInfo tempFile;
        QDir tempdir(fullPath);
        if (tempdir.exists()){
            pathChange(fullPath);
            showFileInfoList(tempdir);
        }
        else {
            emit fileNotExist();
        }
    }

}

void VisualFileManager::Exit() {
    to_effect_Click();
     sleeping();
    exit(0);
}

void VisualFileManager::doubleClicked(QListWidgetItem*) {
    to_effect_Click();
     sleeping();
    execute();
}

//void VisualFileManager::singleClicked(QListWidgetItem*) {

//}

void VisualFileManager::showError() {
    Error * w_ = new Error();
    w_->show();
}


void VisualFileManager::set_CPU(cpuMon * cpu){
    CPU=cpu;
    CPU->createP(PID,"Calculator",user);
}


void VisualFileManager::setPID(int pid){
    PID=pid;
}

void VisualFileManager::mousePressEvent(QMouseEvent *e){
    to_simple_Click();
    system_timer->start(100);
}

void VisualFileManager::mouseMoveEvent(QMouseEvent *e)
{
    to_moving_around();
    system_timer->start(100);
}


void VisualFileManager::back_to_fluctuation(){
    CPU->operationDet(PID,fluctuation);
}


void VisualFileManager::to_effect_Click(){
    CPU->operationDet(PID,effectClick);
    system_timer->start(100);
}

void VisualFileManager::to_simple_Click(){
    CPU->operationDet(PID,simpleClick);
    system_timer->start(100);
}

void VisualFileManager::to_moving_around(){
    CPU->operationDet(PID,movingAround);
    system_timer->start(100);
}

void VisualFileManager::FileManaging(){
    CPU->operationDet(PID,fileMan);
    system_timer->start(100);
}

void VisualFileManager::sleeping(){
    if (CPU->isBusy()){
        sleep(1);
    }
}

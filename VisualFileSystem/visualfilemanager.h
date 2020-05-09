#ifndef VISUALFILEMANAGER_H
#define VISUALFILEMANAGER_H

#include <QMainWindow>
#include <QProcess>
#include <QDir>
#include <QListWidget>
#include "error.h"

QT_BEGIN_NAMESPACE
namespace Ui { class VisualFileManager; }
QT_END_NAMESPACE

class VisualFileManager : public QMainWindow
{
    Q_OBJECT

public:
    QString directoryPath;
    QDir dir;

    struct copiedFile{
        QString Name;
        QString Path;

        copiedFile(QString Name, QString Path){
            this->Name = Name;
            this->Path = Path;
        }
    } *copiedfile;

    explicit VisualFileManager(QWidget *parent = 0);
    ~VisualFileManager();

    void pathChange(QString path);

    void showFileInfoList(QDir dir);

    void getFileCopy();

    void filePaste(QString oldFile, QString newFile);

    void fileDelete(QString file_path);

    void execute();

signals:
    void initialize();
    void fileNotExist();

private:
    Ui::VisualFileManager *ui;

protected slots:
    void Root();
    void Copy();
    void Paste();
    void Create();
    void Delete();
    void Up();
    void Cd();
    void Exit();
    void doubleClicked(QListWidgetItem*);
//    void singleClicked(QListWidgetItem*);
    void showError();
};
#endif // VISUALFILEMANAGER_H

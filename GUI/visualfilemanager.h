#ifndef VISUALFILEMANAGER_H
#define VISUALFILEMANAGER_H

#include <QMainWindow>
#include <QProcess>
#include <QDir>
#include <QListWidget>
#include "error.h"
#include <QMouseEvent>
#include "cpuMon.h"
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

    void setPID(int pid);

    void set_CPU(cpuMon*);

signals:
    void initialize();
    void fileNotExist();

private:
    Ui::VisualFileManager *ui;
    int PID;
    QTimer *system_timer;
    cpuMon* CPU;
    void sleeping();
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
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

    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

    void FileManaging();
};
#endif // VISUALFILEMANAGER_H

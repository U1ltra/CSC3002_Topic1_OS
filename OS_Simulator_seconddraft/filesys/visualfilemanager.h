#ifndef VISUALFILEMANAGER_H
#define VISUALFILEMANAGER_H

#include <QMainWindow>
#include <QProcess>
#include <QDir>
#include <QListWidget>
#include <QMouseEvent>
#include "monitor/cpuMon.h"
#include "memory/Buddy.h"
QT_BEGIN_NAMESPACE
namespace Ui { class VisualFileManager; }
QT_END_NAMESPACE

/*
 * Class: VisualFileManager
 * -----------------
 * This class simulates some spercific operations of file
 * of the operating system, including copy, paste, create,
 * delete, return to the previous directory, enter specific
 * directory and return to the root directory.
 */
class VisualFileManager : public QMainWindow
{
    Q_OBJECT

public:
    QString directoryPath;
    QDir dir;

    /*
     * Type: copiedFile
     * ----------
     * Structure of a type that store the information
     * of the copied file.
     */
    struct copiedFile{
        QString Name;
        QString Path;

        copiedFile(QString Name, QString Path){
            this->Name = Name;
            this->Path = Path;
        }
    } *copiedfile;
    bool copyFileExist;

    /*
     * Function: VisualFileManager
     * Usage: VisualFileManager(QMainWindow *parent = nullptr);
     * --------------------------------------------------------
     * Initial the mainwindow.
     */
    explicit VisualFileManager(QMainWindow *parent = nullptr);

    /*
     * Function: ~VisualFileManager
     * Usage: ~VisualFileManager();
     * ----------------------------
     * Close the mainwindow.
     */
    ~VisualFileManager();

    /*
     * Function:pathChange
     * Usage: panthChange(QString path);
     * ---------------------------------
     * Use the input string as the directory
     * we need and assign it to the QDir object.
     */
    void pathChange(QString path);

    /*
     * Function: showFileInfoList
     * Usage: showFileInfoList(QDir dir);
     * ----------------------------------
     * Shoe all the file in the input directory.
     */
    void showFileInfoList(QDir dir);

    /*
     * Function: getFileCopy
     * Usage: getFileCopy();
     * ---------------------
     * To get the information of the file
     * that the user would love to copy.
     */
    void getFileCopy();

    /*
     * Function: filePaste
     * Usage: filePaste(QString oldFile, QString newFile);
     * ---------------------------------------------------
     * Use this function to paste the copied file in current
     * directory by given the path of old file and new file.
     * They have the same name but may be in different directory.
     */
    void filePaste(QString oldFile, QString newFile);

    /*
     * Function: fileDelete
     * Usage: fileDelete(QString file_path);
     * -------------------------------------
     * Use the input file path to confirm the
     * exact file and use the remove function
     * in QFile class to delete the file.
     */
    void fileDelete(QString file_path);

    /*
     * Function: execute
     * Usage: execute();
     * -----------------
     * Execute the doubleclicked signal to
     * enter the ceratin directory.
     */
    void execute();

    void setPID(int pid);

    void set_CPU(cpuMon*);

    void set_memory(Buddy* memory);

signals:
    /*
     * Function: initialize
     * Usage: initialize();
     * -----------------
     * A signal to initialize the initial directory.
     */
    void initialize();
    void fileNotExist();

private:

    //////////////////////////
    /// private data field ///
    //////////////////////////

    Ui::VisualFileManager *ui;
    int PID;
    QTimer *system_timer;
    cpuMon* CPU;
    Buddy* memory;
    bool created = false;
    int memory_size=1;
    void sleeping();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void closeEvent(QCloseEvent* event);

protected slots:
    /*
     * Function: Init
     * Usage: Init();
     * -----------------
     * To initialize the initial directory.
     */
    void Init();

    /*
     * Function: Root
     * Usage: Root();
     * -----------------
     * change the path to the root directory.
     */
    void Root();

    /*
     * Function: Copy
     * Usage: Copy();
     * -----------------
     * To copy the selected file.
     */
    void Copy();

    /*
     * Function: Paste
     * Usage: Paste();
     * -----------------
     * To paste the copied file.
     */
    void Paste();

    /*
     * Function: Create
     * Usage: Create();
     * -----------------
     * To create the certain directory that the
     * user input in the ui.
     */
    void Create();

    /*
     * Function: Delete
     * Usage: Delete();
     * -----------------
     * To delete the selected file in the ui.
     */
    void Delete();

    /*
     * Function: Up
     * Usage: Up();
     * -----------------
     * Return to the previous directory.
     */
    void Up();

    /*
     * Function: Cd
     * Usage: Cd();
     * -----------------
     * To enter the selected file or enter the
     * directory that the user type in the ui.
     */
    void Cd();

    /*
     * Function: doubleClicked
     * Usage: doubleClicked(QListWidgetItem*);
     * -----------------
     * To simulate the double clicked operation in
     * the operating system.
     */
    void doubleClicked(QListWidgetItem*);
//    void singleClicked(QListWidgetItem*);

    /*
     * Function: showError
     * Usage: showError();
     * -----------------
     * Use QMessageBox to show the error message
     * when the user do not run the program in proper
     * way.
     */
    void showError();

    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

    void FileManaging();
private slots:
    void on_let_Menu_returnPressed();
};
#endif // VISUALFILEMANAGER_H

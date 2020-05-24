#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QString>
#include <QLineEdit>
#include "monitor/cpuMon.h"
#include <QTimer>
#include <QCloseEvent>
#include "memory/Buddy.h"
namespace Ui {
class TextEditor;
}

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget *parent = nullptr);
    void setPID(int pid);
    void set_CPU(cpuMon*);
    void set_memory(Buddy* memory);
    ~TextEditor();

private slots:
    void on_action_NewFile_triggered();

    void on_action_OpenFile_triggered();

    void on_action_Save_triggered();

    void on_action_SaveAs_triggered();

    void on_action_Exit_triggered();

    void on_action_Undo_triggered();

    void on_action_Cut_triggered();

    void on_action_Copy_triggered();

    void on_action_Paste_triggered();

    void on_action_Find_triggered();

    void findText();

    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

    void texting();


private:
    Ui::TextEditor *ui;
    bool isSaved;
    bool hasPath;
    QString currFile;
    QLineEdit *findLine;
    void saveFile(QString filePath);
    void saveAsFile();
    bool checkIfSaved();

    int PID;
    QTimer *system_timer;
    cpuMon* CPU;
    Buddy* memory;
    bool created = false;
    int memory_size=400;
    void sleeping();
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void closeEvent(QCloseEvent *event);
};

#endif // TEXTEDITOR_H

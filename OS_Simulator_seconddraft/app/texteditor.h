/*
 * File: texteditor.h
 * ------------------
 * This file defines a program for text editing.
 */

#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QString>
#include <QLineEdit>
#include <QTimer>
#include <QButtonGroup>
#include <QRadioButton>
#include "app/saveaslist.h"
#include "app/openfile.h"
#include "memory/Buddy.h"
#include "monitor/cpuMon.h"

namespace Ui {
class TextEditor;
}

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextEditor(QMainWindow *parent = nullptr);

    ~TextEditor();

/*
 * Function: setPID, set_CPU, set_memory
 * Usage: setPID(pid); set_CPU(couMon*); set_memory(Buddy* memory);
 * ----------------------------------------------------------------
 * Set pid for the corressponding created program process and assign pointers
 * which are linkd to CPU and memory.
 */
    void setPID(int pid);
    void set_CPU(cpuMon*);
    void set_memory(Buddy* memory);

private slots:

/*
 * Slot Function: on_action_NewFile_triggered
 * ------------------------------------------
 * Create a new file without path after processing the current file following
 * uesrs' instructions.
 */
    void on_action_NewFile_triggered();

/*
 * Slot Function: on_action_OpenFile_triggered
 * -------------------------------------------
 * Open a file of the path the users select after processing the current file following
 * uesrs' instructions.
 */
    void on_action_OpenFile_triggered();

/*
 * Slot Function: on_action_Save_triggered
 * ---------------------------------------
 * If current file exists and have a path, save the text to the file.
 * If current file does not have a path, create it in the local first and
 * then save the text to it.
 */
    void on_action_Save_triggered();

/*
 * Slot Function: on_action_SaveAs_triggered
 * -----------------------------------------
 * Create the file in local first and then save the text to it.
 */
    void on_action_SaveAs_triggered();

/*
 * Slot Function: on_action_Exit_triggered
 * ---------------------------------------
 * Quit the program after processing the current file following
 * uesrs' instructions.
 */
    void on_action_Exit_triggered();

/*
 * Slot Function: on_action_Undo_triggered, on_action_Cut_triggered,
 *                on_action_Copy_triggered, on_action_Paste_triggered
 * ------------------------------------------------------------------
 * Undo users' last operation.
 * Cut, copy or paster selected text.
 */
    void on_action_Undo_triggered();

    void on_action_Cut_triggered();

    void on_action_Copy_triggered();

    void on_action_Paste_triggered();

/*
 * Slot Function: on_action_Find_triggered
 * ---------------------------------------
 * Pop a dialog to interact with users to find targeting text.
 */
    void on_action_Find_triggered();

/*
 * Slot Function: closeEvent
 * -------------------------
 * Override close event. Quit the program after processing the current file
 * following uesrs' instructions. Terminate the process and deallocate corresponding
 * heap when receiving the signal.
 */
    void closeEvent(QCloseEvent *e);

/*
 * Slot Function: findText
 * -----------------------
 * Highlight the targeting text that users wish to find. Users can choose direction,
 * which is either forward or backward.
 */
    void findText();

/*
 * Slot Function: to_simple_Click, to effect_click,
 *                to_moving_around, back_to_fluctuation
 * ----------------------------------------------------
 * Update usage when corressponding operations are performed.
 */
    void to_simple_Click();

    void to_effect_Click();

    void to_moving_around();

    void back_to_fluctuation();

    void texting();

private:

/* Instance Vatiables */

    Ui::TextEditor *ui;
    bool isSaved;                    /* if current file have been saved after modification. */
    bool hasPath;                    /* if current file have been saved to local.           */
    QString currFile;                /* The absolute path of current file.                  */
    saveAsList newSaveAs;            /* A dialog to help users save files to local.         */
    openFile newOpenFile;            /* A dialog to help users open local files.            */
    QLineEdit *findLine;             /* A line edit that uesrs input texts to find in.      */
    QDialog *findDlog;               /* A dialog to help users find targeting text.         */
    QButtonGroup *findDirGroup;      /* A button group of radio buttons to indicate directions.*/
    QRadioButton *forwardBtn;        /* A radio button that represents forward if checked.  */
    QRadioButton *backwardBtn;       /* A radio button that represents backward if checked. */

    int PID;                         /* The pid for created text editor process.            */
    QTimer *system_timer;            /* A timer to send signals to CPU to return to initial status.*/
    cpuMon* CPU;                     /* Assigned CPU for text editor.                       */
    Buddy* memory;                   /* Assigned memory for text editor.                    */
    bool created = false;            /* Turn true when memory are allocated to text editor. */
    int memory_size=220;             /* The memory size for text editor.                    */

/* Private Functions */

    void saveFile(QString filePath);     /* Helper function for saving file.               */
    void saveAsFile();                   /* Helper function for saving file to local.      */
    bool checkIfSaved();                 /* Check if the file content is modified and needs saved.*/
    void setShortcut();                  /* Set short cut for the above 10 operations.     */
    void sleeping();                     /* When the usage of CPU reachs 75%, the program shuts down.*/

protected:
    void mousePressEvent(QMouseEvent *e);     /* Dectect the oparation of simple(invalid) click.*/
    void mouseMoveEvent(QMouseEvent *e);      /* Dectect the oparation of moving around.        */
};

#endif // TEXTEDITOR_H

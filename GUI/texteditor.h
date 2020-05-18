#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class TextEditor;
}

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget *parent = nullptr);
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

    void do_cursorChanged();

private:
    Ui::TextEditor *ui;
    bool isSaved;
    QString currFile;

    void saveFile(QString filePath);
    void saveAsFile();
    void checkIfSaved();
};

#endif // TEXTEDITOR_H

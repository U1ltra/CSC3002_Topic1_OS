
/*
 * File: saveaslist.h
 * ------------------
 * This file supports the text editor saving function.
 */

#ifndef SAVEASLIST_H
#define SAVEASLIST_H

#include <QDir>
#include <QDialog>
#include <QListWidget>

namespace Ui {
class saveAsList;
}

class TextEditor;
class saveAsList : public QDialog
{
    Q_OBJECT

public:
    friend class TextEditor;
    QString directoryPath;
    QDir dir;
    QString fileName;

    explicit saveAsList(QWidget *parent = nullptr);
    ~saveAsList();

    void pathChange(QString path);

    void showFileInfoList(QDir dir);

    void execute();

signals:
    void init();

private:
    Ui::saveAsList *ui;

protected slots:
    void Root();

    void setFileName();

    void doubleClicked(QListWidgetItem*);
};

#endif // SAVEASLIST_H

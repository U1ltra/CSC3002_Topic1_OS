
/*
 * File: openfile.h
 * ----------------
 * This file is used to open a fold path.
 */

#ifndef OPENFILE_H
#define OPENFILE_H

#include <QDir>
#include <QDialog>
#include <QListWidget>

namespace Ui {
class openFile;
}

class TextEditor;
class openFile : public QDialog
{
    Q_OBJECT

public:
    friend class TextEditor;
    QString directoryPath;
    QString fileName;
    QDir dir;

    explicit openFile(QWidget *parent = nullptr);
    ~openFile();

    void pathChange(QString path);

    void showFileInfoList(QDir dir);

    void execute();

signals:
    void init();

private:
    Ui::openFile *ui;

protected slots:
    void Root();

    void setFileName();

    void doubleClicked(QListWidgetItem*);

};

#endif // OPENFILE_H

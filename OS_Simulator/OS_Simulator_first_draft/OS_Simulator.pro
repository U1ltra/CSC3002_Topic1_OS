QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    app/calculator.cpp \
    app/calendar.cpp \
    app/digitalclock.cpp \
    app/openfile.cpp \
    app/saveaslist.cpp \
    app/texteditor.cpp \
    \
    filesys/visualfilemanager.cpp \
    \
    home/login_interface.cpp \
    home/mainwindow.cpp \
    home/main.cpp \
    \
    memory/Buddy.cpp \
    memory/Memwidget.cpp \
    memory/Pair.cpp \
    memory/m_task.cpp \
    monitor/cpuMon.cpp \
    monitor/monitor.cpp \
    monitor/table_constr.cpp \
    schedule/mythread.cpp \
    schedule/scheduling_algo.cpp \
    schedule/scheduling_uti.cpp \
    schedule/widget.cpp

HEADERS += \
    app/calculator.h \
    app/calendar.h \
    app/digitalclock.h \
    app/openfile.h \
    app/saveaslist.h \
    app/texteditor.h \
#    app/ui_calculator.h \
    \
    filesys/visualfilemanager.h \
    \
    home/login_interface.h \
#    home/ui_login_interface.h \
    home/mainwindow.h \
#    home/ui_widget.h \
    \
    memory/Buddy.h \
    memory/m_task.h \
    memory/pair.h \
    monitor/cpuMon.h \
    monitor/monitor.h \
    monitor/table_constr.h \
    schedule/mythread.h \
    schedule/scheduling.h \
    schedule/widget.h


FORMS += \
    app/calculator.ui \
    app/openfile.ui \
    app/saveaslist.ui \
    app/texteditor.ui \
    \
    filesys/visualfilemanager.ui \
    \
    home/login_interface.ui \
    home/mainwindow.ui \
    \
    memory/Memwidget.ui \
    memory/Schwidget.ui \
    \
    uti/error.ui

INCLUDEPATH += \
    app \
    filesys \
    home \
    monitor \
    memory \
    uti

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .DS_Store \
    images/File.jpg \
    images/Menu.jpg \
    images/Calculator.jpg \
    images/Calendar.jpg \
    images/FileSystem.jpg \
    images/Game.jpg \
    images/TaskManager/jpg \
    images/TextEditor.jpg

RESOURCES += \
    image.qrc

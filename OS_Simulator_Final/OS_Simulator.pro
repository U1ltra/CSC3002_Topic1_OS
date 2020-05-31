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
    filesys/visualfilemanager.cpp \
    home/login_interface.cpp \
    home/main.cpp \
    home/mainwindow.cpp \
    memoryGame/Buddy.cpp \
    memoryGame/Memwidget.cpp \
    memoryGame/Pair.cpp \
    memoryGame/m_task.cpp \
    memoryGame/paintground.cpp \
    memoryGame/table_constr.cpp \
    monitor/CPUmonitor.cpp \
    monitor/cpuMon.cpp \
    monitor/memMonitor.cpp \
    monitor/monitor.cpp \
#    monitor/table_constr.cpp \
    schedule/Schwidget.cpp \
    schedule/scheduling_algo.cpp \
    schedule/scheduling_uti.cpp


HEADERS += \
    app/calculator.h \
    app/calendar.h \
    app/digitalclock.h \
    app/openfile.h \
    app/saveaslist.h \
    app/texteditor.h \
    filesys/visualfilemanager.h \
    home/login_interface.h \
    home/mainwindow.h \
    memoryGame/Buddy.h \
    memoryGame/Memwidget.h \
    memoryGame/m_task.h \
    memoryGame/paintground.h \
    memoryGame/pair.h \
    memoryGame/table_constr.h \
    monitor/CPUmonitor.h \
    monitor/cpuMon.h \
    monitor/memMonitor.h \
    monitor/monitor.h \
#    monitor/table_constr.h \
    schedule/Schwidget.h \
    schedule/scheduling.h


FORMS += \
    app/calculator.ui \
    app/openfile.ui \
    app/saveaslist.ui \
    app/texteditor.ui \
    filesys/visualfilemanager.ui \
    home/login_interface.ui \
    home/mainwindow.ui \
    schedule/Schwidget.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += \
    app \
    filesys \
    home \
    monitor \
    memoryGame \
    schedule

DISTFILES += \
    images/Calculator.png \
    images/Calendar.png \
    images/FileSystem.png \
    images/TaskManager.png \
    images/TextEditor.png \
    images/back.jpg \
    images/background.jpg \
    images/memory.png \
    images/schedule.png

RESOURCES += \
    image.qrc

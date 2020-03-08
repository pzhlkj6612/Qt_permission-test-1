#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit_Input->setPlainText(QCoreApplication::applicationDirPath());
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
QFileDevice::ReadOwner	0x4000	The file is readable by the owner of the file.
QFileDevice::WriteOwner	0x2000	The file is writable by the owner of the file.
QFileDevice::ExeOwner	0x1000	The file is executable by the owner of the file.
QFileDevice::ReadUser	0x0400	The file is readable by the user.
QFileDevice::WriteUser	0x0200	The file is writable by the user.
QFileDevice::ExeUser	0x0100	The file is executable by the user.
QFileDevice::ReadGroup	0x0040	The file is readable by the group.
QFileDevice::WriteGroup	0x0020	The file is writable by the group.
QFileDevice::ExeGroup	0x0010	The file is executable by the group.
QFileDevice::ReadOther	0x0004	The file is readable by anyone.
QFileDevice::WriteOther	0x0002	The file is writable by anyone.
QFileDevice::ExeOther	0x0001	The file is executable by anyone.

from: https://doc.qt.io/qt-5/qfiledevice.html#Permission-enum
*/

void MainWindow::on_pushButton_Process_clicked()
{
    qDebug()<<"MainWindow::on_pushButton_clicked()";

    QString result;

    for(auto path : paths){
        qDebug()<<path;

        if(path.isEmpty()) continue;
        QDir dir(path);

//        QFileInfoList resultList = dir.entryInfoList();
        QFileInfoList resultList = dir.entryInfoList({"."}); // pwd only.

        if(resultList.empty()){
            result += path + " is unreadable, does not exist, or if nothing matches the specification." + '\n';
        }else{
//            for(QFileInfo i : resultList){
//                auto p = i.permissions();
//                result += QString::number(p, 16) + ":" + i.absoluteFilePath() + '\n';
//            }
            auto i = resultList.first();
            auto p = i.permissions();
            result += QString::number(p, 16) + ":" + i.absoluteFilePath() + '\n';
        }
    }

    ui->plainTextEdit_Output->setPlainText(result);
}

void MainWindow::on_plainTextEdit_Input_textChanged()
{
    paths = ui->plainTextEdit_Input->toPlainText().split('\n');
    qDebug()<<"MainWindow::on_plainTextEdit_textChanged() path ="<<paths;
}

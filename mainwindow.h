#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Process_clicked();

    void on_plainTextEdit_Input_textChanged();

private:
    Ui::MainWindow *ui;

    // data
    QStringList paths;
};

#endif // MAINWINDOW_H

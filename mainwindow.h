#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Buttons_OK_clicked();

    void on_Buttons_NOK_clicked();

    void on_NFC_OK_clicked();

    void on_NFC_NOK_clicked();

    void on_HAL_OK_clicked();

    void on_HAL_NOK_clicked();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

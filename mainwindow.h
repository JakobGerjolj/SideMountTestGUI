#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QDebug>
#include <QCoreApplication>
#include <QTimer>
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

signals:
    void appOpenSignal();

private slots:
    void writeData(const QByteArray &data1);
    void readData();
    void openSerialPort();
    void closeSerialPort();
    void on_Buttons_OK_clicked();
    void on_Buttons_NOK_clicked();
    void on_NFC_OK_clicked();
    void on_NFC_NOK_clicked();
    void on_HAL_OK_clicked();
    void on_HAL_NOK_clicked();
    void on_ZERO_OK_clicked();
    void on_ZERO_NOK_clicked();
    void on_LED_OK_clicked();
    void on_LED_NOK_clicked();
    void on_dateTimeEdit_timeChanged(const QTime &time);
    void on_pushButton_3_clicked();

    void on_LED_OK_2_clicked();

    void on_LED_NOK_2_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *m_serial = nullptr;
    QString buffer;
    bool isFullBuffer;
    int stateOfCan;
};
#endif // MAINWINDOW_H

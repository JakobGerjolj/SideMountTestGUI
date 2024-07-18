#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QDebug>
#include <QCoreApplication>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QFileInfo>
#include <QMessageBox>
#include <QtWidgets>
#include <QGraphicsEffect>
#include <QTimer>
#include <QDir>
#include "report.h"
#include "settingsdialog.h"
#include "storage.h"
#include "dialog.h"
#include "dialogled.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void writeData(const QByteArray &data1);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void appOpenSignal();
    void constantSignal();

public slots:
    void onTriggerLED();
    void handleConstantSignal();
    void emitConstantSignal();

private slots:

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
    void on_pushButton_3_clicked();
    void on_LED_OK_2_clicked();
    void on_LED_NOK_2_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_settings_button_clicked();
    void on_actionSettings_triggered();

    void on_actionSettings_changed();

    void on_ZERO_OK_2_clicked();

    void on_ZERO_NOK_2_clicked();



    void on_Serial_line_editingFinished();

private:
    int findClosestTemp(double target);
    QMap<int, double> lookupTable;
    Ui::MainWindow *ui;
    QSerialPort *m_serial = nullptr;
    QString buffer;
    bool isFullBuffer;
    int stateOfCan;
    bool m_NFC_status;
    bool m_HAL_status;
    bool m_ZERO_status;
    bool m_TEMP_status;
    QProcess *m_processSideMount{nullptr};
    QProcess *m_processBootLoader{nullptr};
#if defined(Q_OS_LINUX)
    QString m_ArduinoPort{"/dev/ttyACM0"};
#endif
#if defined(Q_OS_WIN)
    QString m_ArduinoPort{"COM8"};
#endif
    QString m_BootloaderPath{"/home/jakob/Documents/BOOTLOADER/BootloaderCAN/Debug/BootloaderCAN.bin"};
    QString m_processOutput;
    Report *m_report;
    QTimer *m_timer;


};
#endif // MAINWINDOW_H

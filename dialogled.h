#ifndef DIALOGLED_H
#define DIALOGLED_H

#include <QDialog>
#include "storage.h"
namespace Ui {
class DialogLED;
}

class DialogLED : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLED(QWidget *parent = nullptr);
    ~DialogLED();

signals:
    void triggerLEDs();

private slots:
    void on_led1_OK_clicked();

    void on_led1_NOK_clicked();

    void on_led2_OK_clicked();

    void on_led2_NOK_clicked();

    void on_led3_OK_clicked();

    void on_led3_NOK_clicked();

    void on_led4_OK_clicked();

    void on_led4_NOK_clicked();

    void on_led5_OK_clicked();

    void on_led5_NOK_clicked();

    void on_led7_OK_clicked();

    void on_led6_OK_clicked();

    void on_led6_NOK_clicked();

    void on_led7_NOK_clicked();

    void on_led8_OK_clicked();

    void on_led8_NOK_clicked();

    void on_led9_OK_clicked();

    void on_led9_NOK_clicked();

    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    bool leds[10];
    void triggerLED();
    Ui::DialogLED *ui;
};

#endif // DIALOGLED_H

#ifndef DIALOGLED_H
#define DIALOGLED_H

#include <QDialog>

namespace Ui {
class DialogLED;
}

class DialogLED : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLED(QWidget *parent = nullptr);
    ~DialogLED();

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

private:
    Ui::DialogLED *ui;
};

#endif // DIALOGLED_H

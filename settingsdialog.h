#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QProcess>
#include <QFileDialog>

namespace Ui {
class settingsDialog;
}

class settingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit settingsDialog(QWidget *parent = nullptr);
    ~settingsDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    static QString bootFirmwarePath;
    static QString finishedFirmwarePath;
    static QString arduinoPort;
    Ui::settingsDialog *ui;
};

#endif // SETTINGSDIALOG_H

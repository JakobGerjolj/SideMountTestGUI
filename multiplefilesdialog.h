#ifndef MULTIPLEFILESDIALOG_H
#define MULTIPLEFILESDIALOG_H

#include <QDialog>
#include "storage.h"

namespace Ui {
class multipleFilesDialog;
}

class multipleFilesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit multipleFilesDialog(QWidget *parent = nullptr, QString title="Duplicate detected!");
    ~multipleFilesDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::multipleFilesDialog *ui;
};

#endif // MULTIPLEFILESDIALOG_H

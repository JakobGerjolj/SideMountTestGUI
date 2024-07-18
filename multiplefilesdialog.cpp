#include "multiplefilesdialog.h"
#include "ui_multiplefilesdialog.h"

multipleFilesDialog::multipleFilesDialog(QWidget *parent, QString title)
    : QDialog(parent)
    , ui(new Ui::multipleFilesDialog)
{
    ui->setupUi(this);
}

multipleFilesDialog::~multipleFilesDialog()
{
    delete ui;
}

void multipleFilesDialog::on_pushButton_clicked() //Go back and change SN
{
    storage::setMultipleFilesDialogStatus(1);
    this->close();
}


void multipleFilesDialog::on_pushButton_2_clicked() //Overwrite report
{
    storage::setMultipleFilesDialogStatus(2);
    this->close();
}


void multipleFilesDialog::on_pushButton_3_clicked() //Add another with the same SN plus (x)
{
    storage::setMultipleFilesDialogStatus(3);
    this->close();
}


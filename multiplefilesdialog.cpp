#include "multiplefilesdialog.h"
#include "ui_multiplefilesdialog.h"

multipleFilesDialog::multipleFilesDialog(QWidget *parent, QString title)
    : QDialog(parent)
    , ui(new Ui::multipleFilesDialog)
{
    ui->setupUi(this);

    QString ToDisplay= QString::fromStdString("Side_Mount_test."+storage::getSERIAL() + ".txt already exists.\nDo you want to replace it?");
    ui -> label -> setText(ToDisplay);
    ui -> pushButton_3 -> setVisible(false);
}

multipleFilesDialog::~multipleFilesDialog()
{
    if(storage::getMultipleFileDialogStatus() == 0){
        storage::setMultipleFilesDialogStatus(1);
    }
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


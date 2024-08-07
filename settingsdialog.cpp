#include "settingsdialog.h"
#include "ui_settingsdialog.h"

settingsDialog::settingsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::settingsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Settings");

#if defined(Q_OS_LINUX)
    QProcess process;
    QString programmerPath="ls";
        // QString command = "/mnt/98BC1F34BC1F0BFE/STMprogrammer/Installation/bin/STM32_Programmer.sh";
    QStringList arguments;


    //arguments << "/dev/ttyACM*";

    process.start("/bin/bash", QStringList() << "-c" << "ls /dev/ttyACM*");
    // process.setProgram(programmerPath);
    // process.setArguments(arguments);
    // process.start();

    if(!process.waitForStarted()){
        qDebug()<<"Error";
        qDebug()<<process.errorString();
    }

    if(!process.waitForFinished()){
        qDebug()<<"Error";
    }

    QByteArray result = process.readAllStandardOutput();

    // Split the output into lines
    QStringList lines = QString(result).split('\n');

   // ui->portBox
    foreach (const QString &line, lines){
        if (!line.isEmpty()) {
            ui->portBox->addItem(line);
        }
    }
    //ui->portBox->addItem("NO");
    process.waitForFinished();
    qDebug()<<result;
#endif
#if defined(Q_OS_WIN)
    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        ui -> portBox -> addItem(port.portName());
    }

#endif
}

settingsDialog::~settingsDialog()
{
    delete ui;
}

void settingsDialog::on_pushButton_clicked()
{
    QString selectedFile = QFileDialog::getOpenFileName(nullptr, "Select a .bin file", QDir::homePath(), "Binary Files (*.bin)");

    if (!selectedFile.isEmpty()) {
        qDebug() << "Selected file:" << selectedFile;
        ui->file_selected->setText(selectedFile);
        bootFirmwarePath=selectedFile;

    } else {
        qDebug() << "No file selected.";
        ui->file_selected->setText("No file selected.");
    }
}


void settingsDialog::on_pushButton_2_clicked()
{
    QString selectedFile = QFileDialog::getOpenFileName(nullptr, "Select a .bin file", QDir::homePath(), "Binary Files (*.bin)");

    if (!selectedFile.isEmpty()) {
        qDebug() << "Selected file:" << selectedFile;
        ui->file_selected_2->setText(selectedFile);
        finishedFirmwarePath=selectedFile;

    } else {
        qDebug() << "No file selected.";
        ui->file_selected_2->setText("No file selected.");

    }

}

QString settingsDialog::getBotPath()
{
    return bootFirmwarePath;

}

QString settingsDialog::getFinishedFWPath()
{

    return finishedFirmwarePath;
}

QString settingsDialog::getArduinoPort()
{
    return arduinoPort;
}


void settingsDialog::on_buttonBox_accepted()
{
    arduinoPort=ui->portBox->currentText();

}


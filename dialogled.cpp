#include "dialogled.h"
#include "ui_dialogled.h"

DialogLED::DialogLED(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogLED)
{

    ui->setupUi(this);
    this->setWindowTitle("What is wrong with LEDs");
    ui->led1_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led1_NOK_frame->setVisible(false);
    ui->led2_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led2_NOK_frame->setVisible(false);
    ui->led3_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led3_NOK_frame->setVisible(false);
    ui->led4_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led4_NOK_frame->setVisible(false);
    ui->led5_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led5_NOK_frame->setVisible(false);
    ui->led6_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led6_NOK_frame->setVisible(false);
    ui->led7_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led7_NOK_frame->setVisible(false);
    ui->led8_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led8_NOK_frame->setVisible(false);
    ui->led9_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led9_NOK_frame->setVisible(false);
}

DialogLED::~DialogLED()
{
    delete ui;
}

void DialogLED::on_led1_OK_clicked()
{
    ui->led1_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led1_NOK->setStyleSheet("");
    ui->led1_OK_label->setVisible(true);
    ui->led1_NOK_label->setVisible(false);
    ui->led1_NOK_frame->setVisible(false);

}


void DialogLED::on_led1_NOK_clicked()
{
    ui->led1_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led1_OK->setStyleSheet("");
    ui->led1_NOK_label->setVisible(true);
    ui->led1_OK_label->setVisible(false);
    ui->led1_NOK_frame->setVisible(true);


}


void DialogLED::on_led2_OK_clicked()
{
    ui->led2_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led2_NOK->setStyleSheet("");
    ui->led2_OK_label->setVisible(true);
    ui->led2_NOK_label->setVisible(false);
    ui->led2_NOK_frame->setVisible(false);
}


void DialogLED::on_led2_NOK_clicked()
{
    ui->led2_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led2_OK->setStyleSheet("");
    ui->led2_OK_label->setVisible(false);
    ui->led2_NOK_label->setVisible(true);
    ui->led2_NOK_frame->setVisible(true);

}


void DialogLED::on_led3_OK_clicked()
{
    ui->led3_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led3_NOK->setStyleSheet("");
    ui->led3_OK_label->setVisible(true);
    ui->led3_NOK_label->setVisible(false);
    ui->led3_NOK_frame->setVisible(false);


}


void DialogLED::on_led3_NOK_clicked()
{
    ui->led3_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led3_OK->setStyleSheet("");
    ui->led3_OK_label->setVisible(false);
    ui->led3_NOK_label->setVisible(true);
    ui->led3_NOK_frame->setVisible(true);
}


void DialogLED::on_led4_OK_clicked()
{
    ui->led4_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led4_NOK->setStyleSheet("");
    ui->led4_OK_label->setVisible(true);
    ui->led4_NOK_label->setVisible(false);
    ui->led4_NOK_frame->setVisible(false);
}


void DialogLED::on_led4_NOK_clicked()
{
    ui->led4_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led4_OK->setStyleSheet("");
    ui->led4_OK_label->setVisible(false);
    ui->led4_NOK_label->setVisible(true);
    ui->led4_NOK_frame->setVisible(true);
}


void DialogLED::on_led5_OK_clicked()
{
    ui->led5_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led5_NOK->setStyleSheet("");
    ui->led5_NOK_label->setVisible(false);
    ui->led5_OK_label->setVisible(true);
    ui->led5_NOK_frame->setVisible(false);
}


void DialogLED::on_led5_NOK_clicked()
{
    ui->led5_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led5_OK->setStyleSheet("");
    ui->led5_NOK_label->setVisible(true);
    ui->led5_OK_label->setVisible(false);
    ui->led5_NOK_frame->setVisible(true);
}


void DialogLED::on_led6_OK_clicked()
{
    ui->led6_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led6_NOK->setStyleSheet("");
    ui->led6_NOK_label->setVisible(false);
    ui->led6_OK_label->setVisible(true);
    ui->led6_NOK_frame->setVisible(false);
}


void DialogLED::on_led6_NOK_clicked()
{
    ui->led6_OK->setStyleSheet("");
    ui->led6_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led6_NOK_label->setVisible(true);
    ui->led6_OK_label->setVisible(false);
    ui->led6_NOK_frame->setVisible(true);
}


void DialogLED::on_led7_OK_clicked()
{
    ui->led7_NOK->setStyleSheet("");
    ui->led7_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led7_NOK_label->setVisible(false);
    ui->led7_OK_label->setVisible(true);
    ui->led7_NOK_frame->setVisible(false);

}


void DialogLED::on_led7_NOK_clicked()
{
    ui->led7_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led7_OK->setStyleSheet("");
    ui->led7_NOK_label->setVisible(true);
    ui->led7_OK_label->setVisible(false);
    ui->led7_NOK_frame->setVisible(true);

}


void DialogLED::on_led8_OK_clicked()
{
    ui->led8_NOK->setStyleSheet("");
    ui->led8_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led8_NOK_label->setVisible(false);
    ui->led8_OK_label->setVisible(true);
    ui->led8_NOK_label->setVisible(false);

}


void DialogLED::on_led8_NOK_clicked()
{
    ui->led8_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led8_OK->setStyleSheet("");
    ui->led8_NOK_label->setVisible(true);
    ui->led8_OK_label->setVisible(false);
    ui->led8_NOK_frame->setVisible(true);
}


void DialogLED::on_led9_OK_clicked()
{
    ui->led9_NOK->setStyleSheet("");
    ui->led9_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led9_NOK_label->setVisible(false);
    ui->led9_OK_label->setVisible(true);
    ui->led9_NOK_frame->setVisible(false);
}


void DialogLED::on_led9_NOK_clicked()
{
    ui->led9_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led9_OK->setStyleSheet("");
    ui->led9_NOK_label->setVisible(true);
    ui->led9_OK_label->setVisible(false);
    ui->led9_NOK_frame->setVisible(true);
}


void DialogLED::on_pushButton_clicked()
{

    //send data to serial to test
}


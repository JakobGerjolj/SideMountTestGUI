#include "dialogled.h"
#include "ui_dialogled.h"

DialogLED::DialogLED(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogLED)
{

    ui->setupUi(this);
    this->setWindowTitle("What is wrong with LEDs");
    ui->led1_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led1_NOK_frame->setStyleSheet("background-color: rgb(219,114,114)");
    ui->led1_NOK_frame->setVisible(false);
    ui->led2_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led2_NOK_frame->setStyleSheet("background-color: rgb(219,114,114)");
    ui->led2_NOK_frame->setVisible(false);
    ui->led3_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led3_NOK_frame->setStyleSheet("background-color: rgb(219,114,114)");
    ui->led3_NOK_frame->setVisible(false);
    ui->led4_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led4_NOK_frame->setVisible(false);
    ui->led4_NOK_frame->setStyleSheet("background-color: rgb(219,114,114)");
    ui->led5_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led5_NOK_frame->setVisible(false);
    ui->led5_NOK_frame->setStyleSheet("background-color: rgb(219,114,114)");
    ui->led6_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led6_NOK_frame->setVisible(false);
    ui->led6_NOK_frame->setStyleSheet("background-color: rgb(219,114,114)");
    ui->led7_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led7_NOK_frame->setVisible(false);
    ui->led7_NOK_frame->setStyleSheet("background-color: rgb(219,114,114)");
    ui->led8_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led8_NOK_frame->setVisible(false);
    ui->led8_NOK_frame->setStyleSheet("background-color: rgb(219,114,114)");
    ui->led9_NOK_text->setPlaceholderText("Describe the problem...");
    ui->led9_NOK_frame->setVisible(false);
    ui->led9_NOK_frame->setStyleSheet("background-color: rgb(219,114,114)");

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
    leds[0]=true;

}


void DialogLED::on_led1_NOK_clicked()
{
    ui->led1_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led1_OK->setStyleSheet("");
    ui->led1_NOK_label->setVisible(true);
    ui->led1_OK_label->setVisible(false);
    ui->led1_NOK_frame->setVisible(true);
    leds[0]=false;


}


void DialogLED::on_led2_OK_clicked()
{
    ui->led2_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led2_NOK->setStyleSheet("");
    ui->led2_OK_label->setVisible(true);
    ui->led2_NOK_label->setVisible(false);
    ui->led2_NOK_frame->setVisible(false);
    leds[1]=true;
}


void DialogLED::on_led2_NOK_clicked()
{
    ui->led2_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led2_OK->setStyleSheet("");
    ui->led2_OK_label->setVisible(false);
    ui->led2_NOK_label->setVisible(true);
    ui->led2_NOK_frame->setVisible(true);
    leds[1]=false;

}


void DialogLED::on_led3_OK_clicked()
{
    ui->led3_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led3_NOK->setStyleSheet("");
    ui->led3_OK_label->setVisible(true);
    ui->led3_NOK_label->setVisible(false);
    ui->led3_NOK_frame->setVisible(false);
    leds[2]=true;


}


void DialogLED::on_led3_NOK_clicked()
{
    ui->led3_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led3_OK->setStyleSheet("");
    ui->led3_OK_label->setVisible(false);
    ui->led3_NOK_label->setVisible(true);
    ui->led3_NOK_frame->setVisible(true);
    leds[2]=false;
}


void DialogLED::on_led4_OK_clicked()
{
    ui->led4_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led4_NOK->setStyleSheet("");
    ui->led4_OK_label->setVisible(true);
    ui->led4_NOK_label->setVisible(false);
    ui->led4_NOK_frame->setVisible(false);
    leds[3]=true;
}


void DialogLED::on_led4_NOK_clicked()
{
    ui->led4_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led4_OK->setStyleSheet("");
    ui->led4_OK_label->setVisible(false);
    ui->led4_NOK_label->setVisible(true);
    ui->led4_NOK_frame->setVisible(true);
    leds[3]=false;
}


void DialogLED::on_led5_OK_clicked()
{
    ui->led5_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led5_NOK->setStyleSheet("");
    ui->led5_NOK_label->setVisible(false);
    ui->led5_OK_label->setVisible(true);
    ui->led5_NOK_frame->setVisible(false);
    leds[4]=true;
}


void DialogLED::on_led5_NOK_clicked()
{
    ui->led5_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led5_OK->setStyleSheet("");
    ui->led5_NOK_label->setVisible(true);
    ui->led5_OK_label->setVisible(false);
    ui->led5_NOK_frame->setVisible(true);
    leds[4]=false;
}


void DialogLED::on_led6_OK_clicked()
{
    ui->led6_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led6_NOK->setStyleSheet("");
    ui->led6_NOK_label->setVisible(false);
    ui->led6_OK_label->setVisible(true);
    ui->led6_NOK_frame->setVisible(false);
    leds[5]=true;
}


void DialogLED::on_led6_NOK_clicked()
{
    ui->led6_OK->setStyleSheet("");
    ui->led6_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led6_NOK_label->setVisible(true);
    ui->led6_OK_label->setVisible(false);
    ui->led6_NOK_frame->setVisible(true);
    leds[5]=false;
}


void DialogLED::on_led7_OK_clicked()
{
    ui->led7_NOK->setStyleSheet("");
    ui->led7_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led7_NOK_label->setVisible(false);
    ui->led7_OK_label->setVisible(true);
    ui->led7_NOK_frame->setVisible(false);
    leds[6]=true;

}


void DialogLED::on_led7_NOK_clicked()
{
    ui->led7_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led7_OK->setStyleSheet("");
    ui->led7_NOK_label->setVisible(true);
    ui->led7_OK_label->setVisible(false);
    ui->led7_NOK_frame->setVisible(true);
    leds[6]=false;

}


void DialogLED::on_led8_OK_clicked()
{
    ui->led8_NOK->setStyleSheet("");
    ui->led8_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led8_NOK_label->setVisible(false);
    ui->led8_OK_label->setVisible(true);
    ui->led8_NOK_label->setVisible(false);
    leds[7]=true;

}


void DialogLED::on_led8_NOK_clicked()
{
    ui->led8_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led8_OK->setStyleSheet("");
    ui->led8_NOK_label->setVisible(true);
    ui->led8_OK_label->setVisible(false);
    ui->led8_NOK_frame->setVisible(true);
    leds[7]=false;
}


void DialogLED::on_led9_OK_clicked()
{
    ui->led9_NOK->setStyleSheet("");
    ui->led9_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led9_NOK_label->setVisible(false);
    ui->led9_OK_label->setVisible(true);
    ui->led9_NOK_frame->setVisible(false);
    leds[8]=true;
}


void DialogLED::on_led9_NOK_clicked()
{
    ui->led9_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led9_OK->setStyleSheet("");
    ui->led9_NOK_label->setVisible(true);
    ui->led9_OK_label->setVisible(false);
    ui->led9_NOK_frame->setVisible(true);
    leds[8]=false;
}


void DialogLED::on_pushButton_clicked()
{

    triggerLED();
    //send data to serial to test
}

void DialogLED::triggerLED()
{
    emit triggerLEDs();

}


void DialogLED::on_buttonBox_accepted()
{
    //need to add R, G and B to string

    QString temp;
    temp=ui->led1_NOK_text->toPlainText();
    if(ui->led1_check_B->isChecked()){
        temp.prepend("B ");

    }

    if(ui->led1_check_G->isChecked()){
        temp.prepend("G ");

    }
    if(ui->led1_check_R->isChecked()){
        temp.prepend("R ");

    }

    storage::setLedData("LED1", leds[0], temp.toStdString());
    temp=ui->led2_NOK_text->toPlainText();
    if(ui->led2_check_B->isChecked()){
        temp.prepend("B ");

    }

    if(ui->led2_check_G->isChecked()){
        temp.prepend("G ");

    }
    if(ui->led2_check_R->isChecked()){
        temp.prepend("R ");

    }
    storage::setLedData("LED2", leds[1], temp.toStdString());
    temp=ui->led3_NOK_text->toPlainText();
    if(ui->led3_check_B->isChecked()){
        temp.prepend("B ");

    }

    if(ui->led3_check_G->isChecked()){
        temp.prepend("G ");

    }
    if(ui->led3_check_R->isChecked()){
        temp.prepend("R ");

    }
    storage::setLedData("LED3", leds[2], temp.toStdString());
    temp=ui->led4_NOK_text->toPlainText();
    if(ui->led4_check_B->isChecked()){
        temp.prepend("B ");

    }

    if(ui->led4_check_G->isChecked()){
        temp.prepend("G ");

    }
    if(ui->led4_check_R->isChecked()){
        temp.prepend("R ");

    }
    storage::setLedData("LED4", leds[3], temp.toStdString());
    temp=ui->led5_NOK_text->toPlainText();
    if(ui->led5_check_B->isChecked()){
        temp.prepend("B ");

    }

    if(ui->led5_check_G->isChecked()){
        temp.prepend("G ");

    }
    if(ui->led5_check_R->isChecked()){
        temp.prepend("R ");

    }
    storage::setLedData("LED5", leds[4], temp.toStdString());
    temp=ui->led6_NOK_text->toPlainText();
    if(ui->led6_check_B->isChecked()){
        temp.prepend("B ");

    }

    if(ui->led6_check_G->isChecked()){
        temp.prepend("G ");

    }
    if(ui->led6_check_R->isChecked()){
        temp.prepend("R ");

    }
    storage::setLedData("LED6", leds[5], temp.toStdString());
    temp=ui->led7_NOK_text->toPlainText();
    if(ui->led7_check_B->isChecked()){
        temp.prepend("B ");

    }

    if(ui->led7_check_G->isChecked()){
        temp.prepend("G ");

    }
    if(ui->led7_check_R->isChecked()){
        temp.prepend("R ");

    }
    storage::setLedData("LED7", leds[6], temp.toStdString());
    temp=ui->led8_NOK_text->toPlainText();
    if(ui->led8_check_B->isChecked()){
        temp.prepend("B ");

    }

    if(ui->led8_check_G->isChecked()){
        temp.prepend("G ");

    }
    if(ui->led8_check_R->isChecked()){
        temp.prepend("R ");

    }
    storage::setLedData("LED8", leds[7], temp.toStdString());
    temp=ui->led9_NOK_text->toPlainText();
    if(ui->led9_check_B->isChecked()){
        temp.prepend("B ");

    }

    if(ui->led9_check_G->isChecked()){
        temp.prepend("G ");

    }
    if(ui->led9_check_R->isChecked()){
        temp.prepend("R ");

    }
    storage::setLedData("LED9", leds[8], ui->led9_NOK_text->toPlainText().toStdString());

}


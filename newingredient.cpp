#include "newingredient.h"
#include "ui_newingredient.h"

NewIngredient::NewIngredient(QWidget *parent) : QMainWindow(parent), ui(new Ui::NewIngredient)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/pictures/icon.png"));
    connect(this, SIGNAL(sendData(QString)), parent, SLOT(dataReception(QString)));
}

NewIngredient::~NewIngredient()
{
    delete ui;
}

void NewIngredient::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button->text() == "OK") {
        if(ui->lineEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Внимание", "Поле не должно быть пустым!");
        } else {
            QString str = ui->lineEdit->text();
            emit sendData(str);
            ui->lineEdit->clear();
            this->hide();
        }
    } else if(button->text() == "Cancel") {
        ui->lineEdit->clear();
        this->hide();
    }
}

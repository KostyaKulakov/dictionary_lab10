#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_pushButton_clicked()
{
    this->close();
}

void AddDialog::on_pushButton_Add_clicked()
{
    eng = this->ui->engLine->text();
    rus = this->ui->rusLine->text();

    this->close();
}

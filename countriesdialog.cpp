#include "countriesdialog.h"
#include "ui_countriesdialog.h"

CountriesDialog::CountriesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CountriesDialog)
{
    ui->setupUi(this);




}




CountriesDialog::~CountriesDialog()
{
    delete ui;
}

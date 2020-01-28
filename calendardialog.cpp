#include "calendardialog.h"
#include "ui_calendardialog.h"

CalendarDialog::CalendarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalendarDialog)
{
    ui->setupUi(this);
}

CalendarDialog::~CalendarDialog()
{
    delete ui;
}

void CalendarDialog::on_pushButton_2_clicked()
{
    close();
}

void CalendarDialog::on_pushButton_clicked()
{
    emit dateChanged(ui->calendarWidget->selectedDate());

    close();
}

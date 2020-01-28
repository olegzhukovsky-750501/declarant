#include "receiverdialog.h"
#include "ui_receiverdialog.h"

ReceiverDialog::ReceiverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceiverDialog),
    maxLength_textEdit(150),
    maxLength_textEdit_2(150)
{
    ui->setupUi(this);

    ui->lineEdit_2->setValidator(new QIntValidator);
}

ReceiverDialog::~ReceiverDialog()
{
    delete ui;
}

void ReceiverDialog::on_textEdit_textChanged()
{
    if (ui->textEdit->toPlainText().length() > maxLength_textEdit)
    {
        QString text = ui->textEdit->toPlainText();
        text.chop(text.length() - maxLength_textEdit);
        ui->textEdit->setPlainText(text);

        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.setPosition(ui->textEdit->document()->characterCount() - 1);
        ui->textEdit->setTextCursor(cursor);
   }

    emit textEdit_textChanged(ui->textEdit->toPlainText());
}

void ReceiverDialog::on_lineEdit_5_returnPressed()
{
    countryDial = new CountryDialog;
    connect (countryDial, SIGNAL(itemViewClicked(const QModelIndex&)), this, SLOT(itemDoubleClicked(const QModelIndex&)));
    countryDial->exec();

    delete countryDial;
}

void ReceiverDialog::on_lineEdit_5_textChanged(const QString &text)
{
    emit lineEdit_5_textChanged(text);
}

void ReceiverDialog::on_lineEdit_textChanged(const QString &text)
{
    emit lineEdit_textChanged(text);
}

void ReceiverDialog::on_lineEdit_2_textChanged(const QString &text)
{
    emit lineEdit_2_textChanged(text);
}

void ReceiverDialog::on_lineEdit_6_textChanged(const QString &text)
{
    emit lineEdit_6_textChanged(text);
}

void ReceiverDialog::on_lineEdit_3_textChanged(const QString &text)
{
    emit lineEdit_3_textChanged(text);
}

void ReceiverDialog::on_lineEdit_4_textChanged(const QString &text)
{
    emit lineEdit_4_textChanged(text);
}

void ReceiverDialog::on_lineEdit_8_textChanged(const QString &text)
{
    emit lineEdit_8_textChanged(text);
}

void ReceiverDialog::on_lineEdit_7_textChanged(const QString &text)
{
    emit lineEdit_7_textChanged(text);
}

void ReceiverDialog::on_lineEdit_9_textChanged(const QString &text)
{
    emit lineEdit_9_textChanged(text);
}

void ReceiverDialog::on_lineEdit_10_textChanged(const QString &text)
{
    emit lineEdit_10_textChanged(text);
}

void ReceiverDialog::on_lineEdit_11_textChanged(const QString &text)
{
    emit lineEdit_11_textChanged(text);
}

void ReceiverDialog::on_textEdit_2_textChanged()
{
    if (ui->textEdit_2->toPlainText().length()> maxLength_textEdit_2)
    {
        QString text = ui->textEdit_2->toPlainText();
        text.chop(text.length() - maxLength_textEdit_2);
        ui->textEdit_2->setPlainText(text);

        QTextCursor cursor = ui->textEdit_2->textCursor();
        cursor.setPosition(ui->textEdit_2->document()->characterCount() - 1);
        ui->textEdit_2->setTextCursor(cursor);
    }
}

void ReceiverDialog::on_pushButton_clicked()
{
    bool isEmpty_1 = ui->lineEdit_6->text().isEmpty();
    bool isEmpty_2 = ui->lineEdit_3->text().isEmpty();
    bool isEmpty_3 = ui->lineEdit_4->text().isEmpty();

    int countEmpty = isEmpty_1 + isEmpty_2 + isEmpty_3;

    QString str;
    if(countEmpty == 0)
    {
        QString insertStr = "%1, "
                            "%2, "
                            "%3";
        str = insertStr.arg(ui->lineEdit_6->text())
                       .arg(ui->lineEdit_3->text())
                       .arg(ui->lineEdit_4->text());
    }
    else if(countEmpty == 1)
    {
        if(isEmpty_1)
        {
            QString insertStr = "%1, "
                                "%2";
            str = insertStr.arg(ui->lineEdit_3->text())
                           .arg(ui->lineEdit_4->text());
        }
        else if(isEmpty_2)
        {
            QString insertStr = "%1, "
                                "%2";
            str = insertStr.arg(ui->lineEdit_6->text())
                           .arg(ui->lineEdit_4->text());
        }
        else if(isEmpty_3)
        {
            QString insertStr = "%1, "
                                "%2";
            str = insertStr.arg(ui->lineEdit_6->text())
                           .arg(ui->lineEdit_3->text());
        }
    }
    else if(countEmpty == 2)
    {
        if(!isEmpty_1)
        {
            QString insertStr = "%1";
            str = insertStr.arg(ui->lineEdit_6->text());
        }
        else if(!isEmpty_2)
        {
            QString insertStr = "%1";
            str = insertStr.arg(ui->lineEdit_3->text());
        }
        else if(!isEmpty_3)
        {
            QString insertStr = "%1";
            str = insertStr.arg(ui->lineEdit_4->text());
        }
    }

    ui->textEdit_2->setText(str);

    emit buttonNextClicked();
}

void ReceiverDialog::on_lineEdit_returnPressed()
{
    countryDial = new CountryDialog;
    connect (countryDial, SIGNAL(itemViewClicked(const QModelIndex&)), this, SLOT(itemDoubleClicked(const QModelIndex&)));
    countryDial->exec();

    delete countryDial;
}

void ReceiverDialog::itemDoubleClicked(const QModelIndex &index)
{
    int row = index.row();

    QModelIndex inputIndex_1 = countryDial->model->index(row, 0);
    ui->lineEdit_5->setText(inputIndex_1.data().toString());

    QModelIndex inputIndex_2 = countryDial->model->index(row, 2);
    ui->lineEdit->setText(inputIndex_2.data().toString());

    countryDial->close();
}

void ReceiverDialog::on_lineEdit_11_returnPressed()
{
    calendar = new CalendarDialog;

    connect(calendar, SIGNAL(dateChanged(const QDate&)), this, SLOT(slotToChangeLineEdit_11(const QDate&)));

    calendar->exec();

    delete calendar;
}

void ReceiverDialog::slotToChangeLineEdit_11(const QDate &date)
{
    ui->lineEdit_11->setText(date.toString("dd.MM.yy"));
}

void ReceiverDialog::slotToUpdateReceiverDialog()
{

}

#include <QTableView>
#include "senderdialog.h"
#include "ui_senderdialog.h"

SenderDialog::SenderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SenderDialog),
    maxLength_TextEdit(150),
    maxLength_TextEdit_2(150)
{
    ui->setupUi(this);

    ui->lineEdit_2->setValidator(new QIntValidator);
}

SenderDialog::~SenderDialog()
{
    delete ui;
}

void SenderDialog::itemDoubleClicked(const QModelIndex &index)
{
    int row = index.row();

    QModelIndex inputIndex_1 = countryDial->model->index(row, 0);
    ui->lineEdit_5->setText(inputIndex_1.data().toString());

    QModelIndex inputIndex_2 = countryDial->model->index(row, 2);
    ui->lineEdit->setText(inputIndex_2.data().toString());

    countryDial->close();
}

void SenderDialog::on_lineEdit_5_returnPressed()
{
    countryDial = new CountryDialog;
    connect (countryDial, SIGNAL(itemViewClicked(const QModelIndex&)), this, SLOT(itemDoubleClicked(const QModelIndex&)));
    countryDial->exec();

    delete countryDial;
}

void SenderDialog::on_checkBox_stateChanged(int state)
{
    emit checkBox_stateChanged(state);
}

void SenderDialog::on_textEdit_textChanged()
{
    if (ui->textEdit->toPlainText().length() > maxLength_TextEdit)
    {
        QString text = ui->textEdit->toPlainText();
        text.chop(text.length() - maxLength_TextEdit);
        ui->textEdit->setPlainText(text);

        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.setPosition(ui->textEdit->document()->characterCount() - 1);
        ui->textEdit->setTextCursor(cursor);
   }

    emit textEdit_textChanged(ui->textEdit->toPlainText());
}

void SenderDialog::on_lineEdit_5_textChanged(const QString &text)
{
    emit lineEdit_5_textChanged(text);
}

void SenderDialog::on_lineEdit_textChanged(const QString &text)
{
    emit lineEdit_textChanged(text);
}

void SenderDialog::on_lineEdit_2_textChanged(const QString &text)
{
    emit lineEdit_2_textChanged(text);
}

void SenderDialog::on_lineEdit_6_textChanged(const QString &text)
{
    emit lineEdit_6_textChanged(text);
}

void SenderDialog::on_lineEdit_3_textChanged(const QString &text)
{
    emit lineEdit_3_textChanged(text);
}

void SenderDialog::on_lineEdit_4_textChanged(const QString &text)
{
    emit lineEdit_4_textChanged(text);
}

void SenderDialog::on_textEdit_2_textChanged()
{
    if (ui->textEdit_2->toPlainText().length()> maxLength_TextEdit_2)
    {
        QString text = ui->textEdit_2->toPlainText();
        text.chop(text.length() - maxLength_TextEdit_2);
        ui->textEdit_2->setPlainText(text);

        QTextCursor cursor = ui->textEdit_2->textCursor();
        cursor.setPosition(ui->textEdit_2->document()->characterCount() - 1);
        ui->textEdit_2->setTextCursor(cursor);
   }
}

void SenderDialog::on_pushButton_clicked()
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

void SenderDialog::on_lineEdit_returnPressed()
{
    countryDial = new CountryDialog;
    connect (countryDial, SIGNAL(itemViewClicked(const QModelIndex&)), this, SLOT(itemDoubleClicked(const QModelIndex&)));
    countryDial->exec();

    delete countryDial;
}

void SenderDialog::slotToUpdateSenderDialog()
{
    emit toAskForUpdateDataSender();
}

void SenderDialog::slotToUpdateText(QSqlRecord rec)
{
    ui->textEdit->setText((rec.value("SD1")).toString());
    ui->lineEdit_5->setText((rec.value("SD2")).toString());
    ui->lineEdit->setText((rec.value("SD3")).toString());
    ui->lineEdit_2->setText((rec.value("SD4")).toString());
    ui->lineEdit_6->setText((rec.value("SD5")).toString());
    ui->lineEdit_3->setText((rec.value("SD6")).toString());
    ui->lineEdit_4->setText((rec.value("SD7")).toString());
    if(rec.value("SD8").toString() == "контрагент")
    {
        ui->checkBox->setChecked(true);
    }
}

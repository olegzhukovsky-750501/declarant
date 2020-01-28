#pragma once

#include <QDialog>
#include <QCalendarWidget>
#include "countrydialog.h"
#include "calendardialog.h"

namespace Ui {
class ReceiverDialog;
}

class ReceiverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceiverDialog(QWidget *parent = nullptr);
    ~ReceiverDialog();
signals:
    void textEdit_textChanged(const QString &text);

    void lineEdit_5_textChanged(const QString &text);

    void lineEdit_textChanged(const QString &text);

    void lineEdit_2_textChanged(const QString &text);

    void lineEdit_6_textChanged(const QString &text);

    void lineEdit_3_textChanged(const QString &text);

    void lineEdit_4_textChanged(const QString &text);

    void lineEdit_8_textChanged(const QString &text);

    void lineEdit_7_textChanged(const QString &text);

    void lineEdit_9_textChanged(const QString &text);

    void lineEdit_10_textChanged(const QString &text);

    void lineEdit_11_textChanged(const QString &text);

    void buttonNextClicked();

private slots:

    void on_textEdit_textChanged();

    void on_lineEdit_5_returnPressed();

    void on_lineEdit_5_textChanged(const QString &text);

    void on_lineEdit_textChanged(const QString &text);

    void on_lineEdit_2_textChanged(const QString &text);

    void on_lineEdit_6_textChanged(const QString &text);

    void on_lineEdit_3_textChanged(const QString &text);

    void on_lineEdit_4_textChanged(const QString &text);

    void on_lineEdit_8_textChanged(const QString &text);

    void on_lineEdit_7_textChanged(const QString &text);

    void on_lineEdit_9_textChanged(const QString &text);

    void on_lineEdit_10_textChanged(const QString &text);

    void on_lineEdit_11_textChanged(const QString &text);

    void on_textEdit_2_textChanged();

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void itemDoubleClicked(const QModelIndex &index);

    void on_lineEdit_11_returnPressed();

    void slotToChangeLineEdit_11(const QDate &date);

    void slotToUpdateReceiverDialog();

private:
    Ui::ReceiverDialog *ui;
    CountryDialog *countryDial;
    CalendarDialog *calendar;
    int maxLength_textEdit;
    int maxLength_textEdit_2;
};

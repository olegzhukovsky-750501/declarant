#pragma once

#include <QDialog>
#include <QValidator>
#include <QtSql>
#include <QVBoxLayout>
#include <QTableView>
#include "countrydialog.h"

namespace Ui {
class SenderDialog;
}

class SenderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SenderDialog(QWidget *parent = nullptr);
    ~SenderDialog();
signals:
    void textEdit_textChanged(const QString &text);

    void lineEdit_5_textChanged(const QString &text);

    void lineEdit_textChanged(const QString &text);

    void lineEdit_2_textChanged(const QString &text);

    void lineEdit_6_textChanged(const QString &text);

    void lineEdit_3_textChanged(const QString &text);

    void lineEdit_4_textChanged(const QString &text);

    void checkBox_stateChanged(int state);

    void buttonNextClicked();


    void toAskForUpdateDataSender();

private slots:

    void itemDoubleClicked(const QModelIndex &index);

    void on_textEdit_textChanged();

    void on_lineEdit_5_returnPressed();
    
    void on_checkBox_stateChanged(int state);

    void on_lineEdit_5_textChanged(const QString &text);

    void on_lineEdit_textChanged(const QString &text);

    void on_lineEdit_2_textChanged(const QString &text);

    void on_lineEdit_6_textChanged(const QString &text);

    void on_lineEdit_3_textChanged(const QString &text);

    void on_lineEdit_4_textChanged(const QString &text);

    void on_textEdit_2_textChanged();

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();


    void slotToUpdateSenderDialog();

    void slotToUpdateText(QSqlRecord rec);

private:
    Ui::SenderDialog *ui;
    CountryDialog* countryDial;
    int maxLength_TextEdit;
    int maxLength_TextEdit_2;

};

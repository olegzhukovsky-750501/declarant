#pragma once

#include <QtSql>
#include <QFrame>
#include <QTextEdit>
#include <QLineEdit>
#include "calendardialog.h"
#include "senderdialog.h"
#include "receiverdialog.h"
#include "declarantdialog.h"
#include "decltypedialog.h"
#include "countrydialog.h"
#include "goodsdialog.h"
#include "excratedialog.h"
#include "transdialog.h"
#include "proddialog.h"

namespace Ui {
class Frame;
}

class Frame : public QFrame
{
    Q_OBJECT

public:
    explicit Frame(QWidget *parent = nullptr);
    ~Frame();

    QTextEdit* getTextEdit_1();
    QTextEdit* getTextEdit_2();
    QTextEdit* getTextEdit_3();

    QLineEdit *getLineEdit_4();
    QLineEdit* getLineEdit_5();
    QLineEdit* getLineEdit_6();
    QLineEdit* getLineEdit();
    QLineEdit* getLineEdit_7();
    QLineEdit* getLineEdit_8();
    QLineEdit* getLineEdit_9();
    QLineEdit* getLineEdit_10();
    QLineEdit* getLineEdit_11();
    QLineEdit* getLineEdit_12();
    QLineEdit* getLineEdit_2();
    QLineEdit* getLineEdit_3();
    QLineEdit* getLineEdit_13();
    QLineEdit* getLineEdit_1();
    QLineEdit* getLineEdit_16();
    QLineEdit* getLineEdit_15();
signals:
    void sender_textEdit_textChanged(const QString &text);

    void sender_lineEdit_5_textChanged(const QString &text);

    void sender_lineEdit_textChanged(const QString &text);

    void sender_lineEdit_2_textChanged(const QString &text);

    void sender_lineEdit_6_textChanged(const QString &text);

    void sender_lineEdit_3_textChanged(const QString &text);

    void sender_lineEdit_4_textChanged(const QString &text);

    void sender_ButtonFillClicked();

    void sender_checkBox_stateChanged(int state);


    void receiver_textEdit_textChanged(const QString &text);

    void receiver_lineEdit_5_textChanged(const QString &text);

    void receiver_lineEdit_textChanged(const QString &text);

    void receiver_lineEdit_2_textChanged(const QString &text);

    void receiver_lineEdit_6_textChanged(const QString &text);

    void receiver_lineEdit_3_textChanged(const QString &text);

    void receiver_lineEdit_4_textChanged(const QString &text);

    void receiver_lineEdit_8_textChanged(const QString &text);

    void receiver_lineEdit_7_textChanged(const QString &text);

    void receiver_lineEdit_9_textChanged(const QString &text);

    void receiver_lineEdit_10_textChanged(const QString &text);

    void receiver_lineEdit_11_textChanged(const QString &text);

    void receiver_ButtonFillClicked();



    void declarant_textEdit_textChanged(const QString &text);

    void declarant_lineEdit_5_textChanged(const QString &text);

    void declarant_lineEdit_textChanged(const QString &text);

    void declarant_lineEdit_2_textChanged(const QString &text);

    void declarant_lineEdit_6_textChanged(const QString &text);

    void declarant_lineEdit_3_textChanged(const QString &text);

    void declarant_lineEdit_4_textChanged(const QString &text);

    void declarant_lineEdit_8_textChanged(const QString &text);

    void declarant_lineEdit_7_textChanged(const QString &text);

    void declarant_lineEdit_9_textChanged(const QString &text);

    void declarant_lineEdit_10_textChanged(const QString &text);

    void declarant_lineEdit_11_textChanged(const QString &text);

    void declarant_ButtonFillClicked();

    void declarant_comboBox_activated(const QString &text);

    void field_1_1_textChanged (const QString &text);

    void field_5_textChanged(const QString &text);

    void field_6_textChanged(const QString &text);

    void field_7_textChanged(const QString &text);

    void field_8_textChanged(const QString &text);

    void field_9_textChanged(const QString &text);

    void field_10_textChanged(const QString &text);

    void field_11_textChanged(const QString &text);

    void field_12_textChanged(const QString &text);

    void field_13_textChanged(const QString &text);

    void field_14_textChanged(const QString &text);

    void field_15_textChanged(const QString &text);

    void field_16_textChanged(const QString &text);

    void field_18_textChanged(const QString &text);
    void goods_textEdit_textChanged(const QString &text, int row);

    void goods_tableWidget_itemChanged(QTableWidgetItem *item);

    void goodsButtonAddClicked();

    void deleteEntryFromDbGoods(int id);

    void toUpdateSenderDialog();
    void toUpdateReceiverDialog();
    void toUpdateDeclarantDialog();
    void toUpdateGoodsDial();
    void toUpdateUidGoods(QSqlRecord rec);

    void toUpdateGoodsTable(QSqlRecord rec);


    void toAskForUpdateDataSender();

    void toUpdateTextSender(QSqlRecord rec);

private slots:

    void slotToBlockAllFields();

    void slotToUnblockAllFields();

    void sender_slotButtonFillClicked();

    void sender_on_checkBox_stateChanged(int state);

    void sender_on_textEdit_textChanged(const QString &text);

    void sender_on_lineEdit_5_textChanged(const QString &text);

    void sender_on_lineEdit_textChanged(const QString &text);

    void sender_on_lineEdit_2_textChanged(const QString &text);

    void sender_on_lineEdit_6_textChanged(const QString &text);

    void sender_on_lineEdit_3_textChanged(const QString &text);

    void sender_on_lineEdit_4_textChanged(const QString &text);


    void receiver_slotButtonFillClicked();

    void receiver_on_textEdit_textChanged(const QString &text);

    void receiver_on_lineEdit_5_textChanged(const QString &text);

    void receiver_on_lineEdit_textChanged(const QString &text);

    void receiver_on_lineEdit_2_textChanged(const QString &text);

    void receiver_on_lineEdit_6_textChanged(const QString &text);

    void receiver_on_lineEdit_3_textChanged(const QString &text);

    void receiver_on_lineEdit_4_textChanged(const QString &text);

    void receiver_on_lineEdit_8_textChanged(const QString &text);

    void receiver_on_lineEdit_7_textChanged(const QString &text);

    void receiver_on_lineEdit_9_textChanged(const QString &text);

    void receiver_on_lineEdit_10_textChanged(const QString &text);

    void receiver_on_lineEdit_11_textChanged(const QString &text);



    void declarant_slotButtonFillClicked();

    void declarant_on_textEdit_textChanged(const QString &text);

    void declarant_on_lineEdit_5_textChanged(const QString &text);

    void declarant_on_lineEdit_textChanged(const QString &text);

    void declarant_on_lineEdit_2_textChanged(const QString &text);

    void declarant_on_lineEdit_6_textChanged(const QString &text);

    void declarant_on_lineEdit_3_textChanged(const QString &text);

    void declarant_on_lineEdit_4_textChanged(const QString &text);

    void declarant_on_lineEdit_8_textChanged(const QString &text);

    void declarant_on_lineEdit_7_textChanged(const QString &text);

    void declarant_on_lineEdit_9_textChanged(const QString &text);

    void declarant_on_lineEdit_10_textChanged(const QString &text);

    void declarant_on_lineEdit_11_textChanged(const QString &text);

    void declarant_on_comboBox_activated(const QString &text);

    void goods_on_textEdit_textChanged(const QString &text, int row);

    void goods_on_tableWidget_itemChanged(QTableWidgetItem *item);

    void slotDeleteEntryFromDbGoods(int id);

    void slotGoodsButtonAddClicked();


    void slotToUpdateField_1_1(QSqlRecord rec);
    void slotToUpdateField_1_2(QSqlRecord rec);
    void slotToUpdateField_1_3(QSqlRecord rec);
    void slotToUpdateField_5(QSqlRecord rec);
    void slotToUpdateField_6(QSqlRecord rec);
    void slotToUpdateField_7(QSqlRecord rec);
    void slotToUpdateField_8(QSqlRecord rec);
    void slotToUpdateField_9(QSqlRecord rec);
    void slotToUpdateField_10(QSqlRecord rec);
    void slotToUpdateField_11(QSqlRecord rec);
    void slotToUpdateField_12(QSqlRecord rec);
    void slotToUpdateField_13(QSqlRecord rec);
    void slotToUpdateField_14(QSqlRecord rec);
    void slotToUpdateField_15(QSqlRecord rec);
    void slotToUpdateField_16(QSqlRecord rec);
    void slotToUpdateField_18(QSqlRecord rec);


    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_6_returnPressed();

    void declTypeItemDoubleClicked(const QModelIndex &index);

    void slotToAskForUpdateDataSender();

    void slotToUpdateTextSender(QSqlRecord rec);

    void slotToUpdateGoodsTable(QSqlRecord rec);

    void slotToUpdateUidGoods(QSqlRecord rec);

    void slotToChangeLineEdit_15(const QDate &date);

    void on_pushButton_13_clicked();

    void on_lineEdit_15_returnPressed();

    void on_lineEdit_7_returnPressed();

    void field_7_tableItemDoubleClicked(const QModelIndex &index);

    void field_8_tableItemDoubleClicked(const QModelIndex &index);

    void field_9_tableItemDoubleClicked(const QModelIndex &index);

    void field_10_tableItemDoubleClicked(const QModelIndex &index);

    void field_11_tableItemDoubleClicked(const QModelIndex &index);

    void field_12_tableItemDoubleClicked(const QModelIndex &index);

    void field_13_tableItemDoubleClicked(const QModelIndex &index);

    void field_16_tableItemDoubleClicked(const QModelIndex &index);

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_lineEdit_10_returnPressed();

    void on_lineEdit_11_returnPressed();

    void on_lineEdit_12_returnPressed();

    void on_lineEdit_13_returnPressed();

    void on_lineEdit_16_returnPressed();

    void on_lineEdit_textChanged(const QString &text);

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_lineEdit_9_textChanged(const QString &arg1);

    void on_lineEdit_10_textChanged(const QString &arg1);

    void on_lineEdit_11_textChanged(const QString &arg1);

    void on_lineEdit_12_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_13_textChanged(const QString &arg1);

    void on_lineEdit_1_textChanged(const QString &arg1);

    void on_lineEdit_16_textChanged(const QString &arg1);

    void on_lineEdit_15_textChanged(const QString &arg1);

    void on_lineEdit_6_textChanged(const QString &arg1);

private:
    Ui::Frame *ui;
    SenderDialog *sendDial;
    ReceiverDialog *receivDial;
    DeclarantDialog *declDial;
    DeclTypeDialog *dtDial;
    CalendarDialog *calDial;
    GoodsDialog *goodsDial;
    CountryDialog *countryDial;
    ExcRateDialog *excDial;
    TransDialog *transDial;
    ProdDialog *prodDial;
};

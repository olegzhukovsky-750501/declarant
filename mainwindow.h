#pragma once

#include <QMainWindow>
#include <QtSql>
#include <QVector>
#include <QMessageBox>
#include "decltypewindow.h"
#include "decllist.h"

class Frame;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool createConnection();

    void dbSynchronization();

    void setDataIntoDb(const QString &text, int col);

    void setDataIntoDbGoods(const QString &text, int row, int col);

    void frameConnections();

    void toUpdateField_1_1(QSqlRecord rec);
    void toUpdateField_1_2(QSqlRecord rec);
    void toUpdateField_1_3(QSqlRecord rec);
    void toUpdateField_5(QSqlRecord rec);
    void toUpdateField_6(QSqlRecord rec);
    void toUpdateField_7(QSqlRecord rec);
    void toUpdateField_8(QSqlRecord rec);
    void toUpdateField_9(QSqlRecord rec);
    void toUpdateField_10(QSqlRecord rec);
    void toUpdateField_11(QSqlRecord rec);
    void toUpdateField_12(QSqlRecord rec);
    void toUpdateField_13(QSqlRecord rec);
    void toUpdateField_14(QSqlRecord rec);
    void toUpdateField_15(QSqlRecord rec);
    void toUpdateField_16(QSqlRecord rec);
    void toUpdateField_18(QSqlRecord rec);
signals:

    void toRemoveSelectedRow();

    void toChangeTextEdit1(QSqlRecord rec);

    void toChangeTextEdit2(QSqlRecord rec);

    void toChangeTextEdit3(QSqlRecord rec);

    void toUpdateTable(QSqlRecord rec);

    void toUpdateGoodsTable(QSqlRecord rec);

    void toUpdateUidGoods(QSqlRecord rec);

    void toUpdateList();

    void toBlockAllFields();

    void toUnblockAllFields();

    void toRemoveTable();

    void toUpdateTextEdit_1();

    void toUpdateTextEdit_2();

    void toUpdateTextEdit_3();

    void toGiveUpdateDataSender(QSqlRecord rec);

private slots:
    void on_action_6_triggered();

    void on_action_7_triggered();

    void tableItemDoubleClicked(QTableWidgetItem* item);

    void treeItemDoubleClicked(QTreeWidgetItem* treeItem, int column);

    void sender_on_checkBox_stateChanged(int state);

    void sender_on_textEdit_textChanged(const QString &text);

    void sender_on_lineEdit_5_textChanged(const QString &text);

    void sender_on_lineEdit_textChanged(const QString &text);

    void sender_on_lineEdit_2_textChanged(const QString &text);

    void sender_on_lineEdit_6_textChanged(const QString &text);

    void sender_on_lineEdit_3_textChanged(const QString &text);

    void sender_on_lineEdit_4_textChanged(const QString &text);

    void sender_slotButtonFillClicked();


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

    void receiver_slotButtonFillClicked();


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

    void declarant_slotButtonFillClicked();

    void declarant_comboBox_activated(const QString &text);


    void goods_on_textEdit_textChanged(const QString &text, int row);

    void goods_on_tableWidget_itemChanged(QTableWidgetItem *item);

    void slotDeleteEntryFromDbGoods(int id);

    void slotGoodsButtonAddClicked();


    void slotField_1_1_textChanged(const QString &text);
    void slotField_5_textChanged(const QString& text);
    void slotField_6_textChanged(const QString& text);
    void slotField_7_textChanged(const QString& text);
    void slotField_8_textChanged(const QString& text);
    void slotField_9_textChanged(const QString& text);
    void slotField_10_textChanged(const QString& text);
    void slotField_11_textChanged(const QString& text);
    void slotField_12_textChanged(const QString& text);
    void slotField_13_textChanged(const QString& text);
    void slotField_14_textChanged(const QString& text);
    void slotField_15_textChanged(const QString& text);
    void slotField_16_textChanged(const QString& text);
    void slotField_18_textChanged(const QString& text);


    void slotToUpdateTextEdit_1();
    void slotToUpdateTextEdit_2();
    void slotToUpdateTextEdit_3();


    void on_action_declList_triggered();

    void on_action_delete_triggered();

    void on_action_add_triggered();

    void on_action_update_triggered();

    void slotToChangeNumRecords();

    void slotToDeleteEntryFromDb(int id);

    void slotToDeleteEntryFromStack(int id);

    void slotToGiveUpdateDataSender();

    void slotToUpdateGoodsDial();

private:
    Frame *declContents;
    DeclList *declList;
    Ui::MainWindow *ui;
    DeclTypeWindow *declWindow;
    QSqlDatabase dbDecl;
    QSqlQuery *query;
    QMenu *declMenu;
    int nRecords;
    QSqlTableModel *model;

    QVector<Frame*> frameVec;

    QAction* fieldAction;
};


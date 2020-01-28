#include <QtWidgets>
#include <QtSql>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "decltypewindow.h"
#include "frame.h"
#include "decllist.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    declMenu(nullptr),
    nRecords(0)
{
    ui->setupUi(this);

    //MAIN WINDOW CONNECTIONS
    connect(this,
            SIGNAL(toUpdateTextEdit_1()),
            SLOT(slotToUpdateTextEdit_1()));

    connect(this,
            SIGNAL(toUpdateTextEdit_2()),
            SLOT(slotToUpdateTextEdit_2()));

    connect(this,
            SIGNAL(toUpdateTextEdit_3()),
            SLOT(slotToUpdateTextEdit_3()));

    connect(this,
            SIGNAL(toUpdateList()),
            SLOT(on_action_update_triggered()));

    // DECLARATION LIST ELEMENT ON TOOL BAR
    QPixmap declListMap("C:\\Users\\User\\Documents\\untitled3\\images\\declListMap.png");
    QIcon declListIcon(declListMap);

    ui->mainToolBar->addAction(declListIcon,
                              "Список деклараций",
                               this,
                               SLOT(on_action_declList_triggered()));

    // UPDATE ELEMENT ON TOOL BAR
    QPixmap updateMap("C:\\Users\\User\\Documents\\untitled3\\images\\updateMap.png");
    QIcon updateIcon(updateMap);

    ui->mainToolBar->addAction(updateIcon,
                               "Обновить",
                               this,
                               SLOT(on_action_update_triggered()));

    // ADD ELEMENT ON TOOL BAR
    QPixmap addMap("C:\\Users\\User\\Documents\\untitled3\\images\\addMap.png");
    QIcon addIcon(addMap);

    ui->mainToolBar->addAction(addIcon,
                              "Добавить документ",
                               this,
                               SLOT(on_action_add_triggered()));

    // DELETE ELEMENT ON TOOL BAR
    QPixmap deleteMap("C:\\Users\\User\\Documents\\untitled3\\images\\deleteMap.png");
    QIcon deleteIcon(deleteMap);

    ui->mainToolBar->addAction(deleteIcon,
                               "Удалить декларацию",
                               this,
                               SLOT(on_action_delete_triggered()));

    createConnection();

    declList = new DeclList;

    // LIST CONNECTIONS

    connect(this,
            SIGNAL(toUpdateTable(QSqlRecord)),
            declList,
            SLOT(slotToUpdateTable(QSqlRecord)));
    connect(this,
            SIGNAL(toRemoveSelectedRow()),
            declList,
            SLOT(slotToRemoveRow()));
    connect(this,
            SIGNAL(toRemoveTable()),
            declList,
            SLOT(slotToRemoveTable()));
    connect(declList,
            SIGNAL(toChangeNumRecords()),
            this,
            SLOT(slotToChangeNumRecords()));
    connect(declList,
            SIGNAL(toDeleteEntryFromDb(int)),
            this,
            SLOT(slotToDeleteEntryFromDb(int)));
    connect(declList,
            SIGNAL(toDeleteEntryFromStack(int)),
            this,
            SLOT(slotToDeleteEntryFromStack(int)));
    connect(declList,
            SIGNAL(tableItemDoubleClicked(QTableWidgetItem*)),
            this,
            SLOT(tableItemDoubleClicked(QTableWidgetItem*)));

    ui->stackedWidget->addWidget(declList->getScrollArea());
    ui->stackedWidget->setCurrentIndex(0);

    dbSynchronization();

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::createConnection()
{
    dbDecl = QSqlDatabase::addDatabase("QSQLITE", "DeclarationConnection");
    dbDecl.setDatabaseName("C:\\Users\\User\\Documents\\untitled3\\decl.db3");
    dbDecl.setPort(5432);
    dbDecl.setHostName("localhost");
    dbDecl.setUserName("postgres");
    dbDecl.setPassword("root");

    if(!dbDecl.open())
    {
        qDebug() << "Cannot open database:" << dbDecl.lastError();
        return false;
    }
    else
    {
        return true;
    }
}

void MainWindow::dbSynchronization()
{
    query = new QSqlQuery(dbDecl);

    QString str = "SELECT * "
                  "FROM decl";

    query->exec(str);

    while(query->next())
    {
        ++nRecords;

        declContents = new Frame;
        QScrollArea* declScroll = new QScrollArea;
        declContents->setFixedSize(700, 1000);
        declScroll->setWidget(declContents);
        ui->stackedWidget->addWidget(declScroll);

        frameVec.push_back(declContents);

        frameConnections();

        emit toUpdateTable(query->record());

        toUpdateField_1_1(query->record());
        toUpdateField_1_2(query->record());
        toUpdateField_1_3(query->record());
        toUpdateField_5(query->record());
        toUpdateField_6(query->record());
        toUpdateField_7(query->record());
        toUpdateField_8(query->record());
        toUpdateField_9(query->record());
        toUpdateField_10(query->record());
        toUpdateField_11(query->record());
        toUpdateField_12(query->record());
        toUpdateField_13(query->record());
        toUpdateField_14(query->record());
        toUpdateField_15(query->record());
        toUpdateField_16(query->record());
        toUpdateField_18(query->record());

        emit toUpdateTextEdit_1();
        emit toUpdateTextEdit_2();
        emit toUpdateTextEdit_3();
    }
}

void MainWindow::setDataIntoDb(const QString &text, int col)
{
    model = new QSqlTableModel(nullptr, dbDecl);

    model->setTable("decl");

    model->select();

    model->setData(model->index(ui->stackedWidget->currentIndex()-1, col), text);

    model->submitAll();
}

void MainWindow::setDataIntoDbGoods(const QString &text, int row, int col)
{
    model = new QSqlTableModel(nullptr, dbDecl);

    model->setTable("goods");

    model->select();

    model->setData(model->index(row, col), text);

    model->submitAll();
}

void MainWindow::frameConnections()
{
    connect(declContents,
            SIGNAL(toUpdateGoodsDial()),
            this,
            SLOT(slotToUpdateGoodsDial()),
            Qt::UniqueConnection);
    connect(this,
            SIGNAL(toUpdateGoodsTable(QSqlRecord)),
            declContents,
            SLOT(slotToUpdateGoodsTable(QSqlRecord)),
            Qt::UniqueConnection);
    connect(this,
            SIGNAL(toUpdateUidGoods(QSqlRecord)),
            declContents,
            SLOT(slotToUpdateUidGoods(QSqlRecord)),
            Qt::UniqueConnection);
    connect(declContents,
            SIGNAL(deleteEntryFromDbGoods(int)),
            this,
            SLOT(slotDeleteEntryFromDbGoods(int)));


    connect(declContents,
            SIGNAL(toAskForUpdateDataSender()),
            this,
            SLOT(slotToGiveUpdateDataSender()),
            Qt::UniqueConnection);

    connect(this,
            SIGNAL(toGiveUpdateDataSender(QSqlRecord)),
            declContents,
            SLOT(slotToUpdateTextSender(QSqlRecord)));

    connect(declContents,
            SIGNAL(sender_checkBox_stateChanged(int)),
            this,
            SLOT(sender_on_checkBox_stateChanged(int)));
    connect(declContents,
            SIGNAL(sender_textEdit_textChanged(const QString&)),
            this,
            SLOT(sender_on_textEdit_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(sender_lineEdit_textChanged(const QString&)),
            this,
            SLOT(sender_on_lineEdit_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(sender_lineEdit_5_textChanged(const QString&)),
            this,
            SLOT(sender_on_lineEdit_5_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(sender_lineEdit_textChanged(const QString&)),
            this,
            SLOT(sender_on_lineEdit_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(sender_lineEdit_2_textChanged(const QString&)),
            this,
            SLOT(sender_on_lineEdit_2_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(sender_lineEdit_6_textChanged(const QString&)),
            this,
            SLOT(sender_on_lineEdit_6_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(sender_lineEdit_3_textChanged(const QString&)),
            this,
            SLOT(sender_on_lineEdit_3_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(sender_lineEdit_4_textChanged(const QString&)),
            this,
            SLOT(sender_on_lineEdit_4_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(sender_ButtonFillClicked()),
            this,
            SLOT(sender_slotButtonFillClicked()), Qt::UniqueConnection);

    connect(declContents,
            SIGNAL(receiver_textEdit_textChanged(const QString&)),
            this,
            SLOT(receiver_on_textEdit_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(receiver_lineEdit_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(receiver_lineEdit_5_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_5_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(receiver_lineEdit_2_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_2_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(receiver_lineEdit_6_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_6_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(receiver_lineEdit_3_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_3_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(receiver_lineEdit_4_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_4_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(receiver_lineEdit_8_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_8_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(receiver_lineEdit_7_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_7_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(receiver_lineEdit_9_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_9_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(receiver_lineEdit_10_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_10_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(receiver_lineEdit_11_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_11_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(receiver_ButtonFillClicked()),
            this,
            SLOT(receiver_slotButtonFillClicked()),
            Qt::UniqueConnection);



    connect(declContents,
            SIGNAL(declarant_textEdit_textChanged(const QString&)),
            this,
            SLOT(declarant_on_textEdit_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(declarant_lineEdit_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(declarant_lineEdit_5_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_5_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(declarant_lineEdit_2_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_2_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(declarant_lineEdit_6_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_6_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(declarant_lineEdit_3_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_3_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(declarant_lineEdit_4_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_4_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(declarant_lineEdit_7_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_7_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(declarant_lineEdit_9_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_9_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(declarant_lineEdit_10_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_10_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(declarant_lineEdit_11_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_11_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(declarant_ButtonFillClicked()),
            this,
            SLOT(declarant_slotButtonFillClicked()),
            Qt::UniqueConnection);

    connect(declContents,
            SIGNAL(declarant_comboBox_activated(const QString&)),
            this,
            SLOT(declarant_comboBox_activated(const QString&)),
            Qt::UniqueConnection);

    connect(declContents,
            SIGNAL(goods_textEdit_textChanged(const QString&, int)),
            this,
            SLOT(goods_on_textEdit_textChanged(const QString&, int)));

    connect(declContents,
            SIGNAL(goods_tableWidget_itemChanged(QTableWidgetItem*)),
            this,
            SLOT(goods_on_tableWidget_itemChanged(QTableWidgetItem*)));
    connect(declContents,
            SIGNAL(goodsButtonAddClicked()),
            this,
            SLOT(slotGoodsButtonAddClicked()));


    connect(declContents,
            SIGNAL(field_1_1_textChanged(const QString&)),
            this,
            SLOT(slotField_1_1_textChanged(const QString&)));
    connect(declContents,
            SIGNAL(field_5_textChanged(const QString&)),
            this,
            SLOT(slotField_5_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(field_6_textChanged(const QString&)),
            this,
            SLOT(slotField_6_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(field_7_textChanged(const QString&)),
            this,
            SLOT(slotField_7_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(field_8_textChanged(const QString&)),
            this,
            SLOT(slotField_8_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(field_9_textChanged(const QString&)),
            this,
            SLOT(slotField_9_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(field_10_textChanged(const QString&)),
            this,
            SLOT(slotField_10_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(field_11_textChanged(const QString&)),
            this,
            SLOT(slotField_11_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(field_12_textChanged(const QString&)),
            this,
            SLOT(slotField_12_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(field_13_textChanged(const QString&)),
            this,
            SLOT(slotField_13_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(field_14_textChanged(const QString&)),
            this,
            SLOT(slotField_14_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(field_15_textChanged(const QString&)),
            this,
            SLOT(slotField_15_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(field_16_textChanged(const QString&)),
            this,
            SLOT(slotField_16_textChanged(const QString&)));

    connect(declContents,
            SIGNAL(field_18_textChanged(const QString&)),
            this,
            SLOT(slotField_18_textChanged(const QString&)));


}

void MainWindow::on_action_6_triggered()
{
    close();
}

void MainWindow::on_action_7_triggered()
{
    declWindow = new DeclTypeWindow;
    connect(declWindow,
            SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)),
            this,
            SLOT(treeItemDoubleClicked(QTreeWidgetItem*, int)));
    declWindow->exec();

    delete declWindow;
}

void MainWindow::tableItemDoubleClicked(QTableWidgetItem *item)
{
    model = new QSqlTableModel(nullptr, dbDecl);

    model->setTable("decl");

    model->select();

    int itemRow = item->row();
    QTableWidget *tempTable = item->tableWidget();

    int nRow = 0;

    for (; nRow < model->rowCount(); ++nRow)
    {
        QSqlRecord rec = model->record(nRow);
        int id = rec.value("id").toInt();
        if(id == (tempTable->item(itemRow, 1)->text()).toInt())
        {
            break;
        }
    }

    ui->stackedWidget->setCurrentIndex(nRow + 1);
}

void MainWindow::treeItemDoubleClicked(QTreeWidgetItem *treeItem, int column)
{
    if(treeItem != (declWindow->getTree()->topLevelItem(0)))
    {
        declContents = new Frame;
        QScrollArea* declScroll = new QScrollArea;
        declContents->setFixedSize(700, 1000);
        declScroll->setWidget(declContents);
        ui->stackedWidget->addWidget(declScroll);

        frameVec.push_back(declContents);

        ++nRecords;

        frameConnections();

        query = new QSqlQuery(dbDecl);

        QString strF = "INSERT INTO decl (DT1, DT2) "
                       "VALUES('%1', '%2')";
        QString str;

        if(treeItem->text(column) == "Импорт")
        {
            str = strF.arg("ИМ")
                      .arg("40");
        }
        else
        {
            str = strF.arg("ЭК")
                      .arg("10");

        }
        query->exec(str);

        declWindow->close();

        ui->stackedWidget->setCurrentIndex(nRecords);


        model = new QSqlTableModel(nullptr, dbDecl);

        model->setTable("decl");

        model->select();

        int nRec = ui->stackedWidget->currentIndex() - 1;

        QSqlRecord rec = model->record(nRec);

        toUpdateField_1_1(rec);
        toUpdateField_1_2(rec);

        emit toUpdateList();
    }
}

void MainWindow::sender_on_checkBox_stateChanged(int state)
{
    model = new QSqlTableModel(nullptr, dbDecl);

    model->setTable("decl");

    model->select();

    if(state)
    {
        model->setData(model->index(ui->stackedWidget->currentIndex()-1, 8), "контрагент");
    }
    else
    {
        model->setData(model->index(ui->stackedWidget->currentIndex()-1, 8), "");
    }

    model->submitAll();
}

void MainWindow::sender_on_textEdit_textChanged(const QString &text)
{
    setDataIntoDb(text, 1);
}

void MainWindow::sender_on_lineEdit_5_textChanged(const QString &text)
{
    setDataIntoDb(text, 2);
}

void MainWindow::sender_on_lineEdit_textChanged(const QString &text)
{
    setDataIntoDb(text, 3);
}

void MainWindow::sender_on_lineEdit_2_textChanged(const QString &text)
{
    setDataIntoDb(text, 4);
}

void MainWindow::sender_on_lineEdit_6_textChanged(const QString &text)
{
    setDataIntoDb(text, 5);
}

void MainWindow::sender_on_lineEdit_3_textChanged(const QString &text)
{
    setDataIntoDb(text, 6);
}

void MainWindow::sender_on_lineEdit_4_textChanged(const QString &text)
{
    setDataIntoDb(text, 7);
}

void MainWindow::sender_slotButtonFillClicked()
{

    model = new QSqlTableModel(nullptr, dbDecl);

    model->setTable("decl");

    model->select();

    int nRec = ui->stackedWidget->currentIndex() - 1;

    QSqlRecord rec = model->record(nRec);

    frameVec[nRec]->getTextEdit_1()->setText((rec.value("SD1")).toString() + '\n'
                                            +(rec.value("SD3")).toString() + ", "
                                            +(rec.value("SD5")).toString() + ", "
                                            +(rec.value("SD6")).toString() + ", "
                                            +(rec.value("SD7")).toString() + '\n'
                                            +(rec.value("SD8")).toString() + '\n');

}



void MainWindow::receiver_on_textEdit_textChanged(const QString &text)
{
    setDataIntoDb(text, 9);
}

void MainWindow::receiver_on_lineEdit_5_textChanged(const QString &text)
{
    setDataIntoDb(text, 10);
}

void MainWindow::receiver_on_lineEdit_textChanged(const QString &text)
{
    setDataIntoDb(text, 11);
}

void MainWindow::receiver_on_lineEdit_2_textChanged(const QString &text)
{
    setDataIntoDb(text, 12);
}

void MainWindow::receiver_on_lineEdit_6_textChanged(const QString &text)
{
    setDataIntoDb(text, 13);
}

void MainWindow::receiver_on_lineEdit_3_textChanged(const QString &text)
{
    setDataIntoDb(text, 14);
}

void MainWindow::receiver_on_lineEdit_4_textChanged(const QString &text)
{
    setDataIntoDb(text, 15);
}

void MainWindow::receiver_on_lineEdit_8_textChanged(const QString &text)
{
    setDataIntoDb(text, 16);
}

void MainWindow::receiver_on_lineEdit_7_textChanged(const QString &text)
{
    setDataIntoDb(text, 17);
}

void MainWindow::receiver_on_lineEdit_9_textChanged(const QString &text)
{
    setDataIntoDb(text, 18);
}

void MainWindow::receiver_on_lineEdit_10_textChanged(const QString &text)
{
    setDataIntoDb(text, 19);
}

void MainWindow::receiver_on_lineEdit_11_textChanged(const QString &text)
{
    setDataIntoDb(text, 20);
}

void MainWindow::receiver_slotButtonFillClicked()
{
    model = new QSqlTableModel(nullptr, dbDecl);

    model->setTable("decl");

    model->select();

    int nRec = ui->stackedWidget->currentIndex() - 1;

    QSqlRecord rec = model->record(nRec);

    frameVec[nRec]->getTextEdit_2()->setText((rec.value("RV1")).toString() + '\n'
                                            +(rec.value("RV3")).toString() + ", "
                                            +(rec.value("RV5")).toString() + ", "
                                            +(rec.value("RV6")).toString() + ", "
                                             +(rec.value("RV7")).toString() + '\n');
}


void MainWindow::declarant_on_textEdit_textChanged(const QString &text)
{
    setDataIntoDb(text, 24);
}

void MainWindow::declarant_on_lineEdit_5_textChanged(const QString &text)
{
    setDataIntoDb(text, 25);
}

void MainWindow::declarant_on_lineEdit_textChanged(const QString &text)
{
    setDataIntoDb(text, 26);
}

void MainWindow::declarant_on_lineEdit_2_textChanged(const QString &text)
{
    setDataIntoDb(text, 27);
}

void MainWindow::declarant_on_lineEdit_6_textChanged(const QString &text)
{
    setDataIntoDb(text, 28);
}

void MainWindow::declarant_on_lineEdit_3_textChanged(const QString &text)
{
    setDataIntoDb(text, 29);
}

void MainWindow::declarant_on_lineEdit_4_textChanged(const QString &text)
{
    setDataIntoDb(text, 30);
}

void MainWindow::declarant_on_lineEdit_8_textChanged(const QString &text)
{
    setDataIntoDb(text, 31);
}

void MainWindow::declarant_on_lineEdit_7_textChanged(const QString &text)
{
    setDataIntoDb(text, 32);
}

void MainWindow::declarant_on_lineEdit_9_textChanged(const QString &text)
{
    setDataIntoDb(text, 33);
}

void MainWindow::declarant_on_lineEdit_10_textChanged(const QString &text)
{
    setDataIntoDb(text, 34);
}

void MainWindow::declarant_on_lineEdit_11_textChanged(const QString &text)
{
    setDataIntoDb(text, 35);
}

void MainWindow::declarant_slotButtonFillClicked()
{
    model = new QSqlTableModel(nullptr, dbDecl);

    model->setTable("decl");

    model->select();

    int nRec = ui->stackedWidget->currentIndex() - 1;

    QSqlRecord rec = model->record(nRec);

    frameVec[nRec]->getTextEdit_3()->setText((rec.value("DR1")).toString() + '\n'
                                            +(rec.value("DR3")).toString() + ", "
                                            +(rec.value("DR5")).toString() + ", "
                                            +(rec.value("DR6")).toString() + ", "
                                                     +(rec.value("DR7")).toString() + '\n');
}

void MainWindow::declarant_comboBox_activated(const QString &text)
{
    setDataIntoDb(text, 36);
}

void MainWindow::goods_on_textEdit_textChanged(const QString &text, int row)
{
    setDataIntoDbGoods(text, row, 2);
}

void MainWindow::goods_on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    setDataIntoDbGoods(item->text(), item->row(), item->column() + 3);
}

void MainWindow::slotDeleteEntryFromDbGoods(int id)
{
    query = new QSqlQuery(dbDecl);

    QString argStr = "DELETE FROM goods "
                     "WHERE id = %1;";
    QString str = argStr.arg(id);

    query->exec(str);
}

void MainWindow::slotGoodsButtonAddClicked()
{
    model = new QSqlTableModel(nullptr, dbDecl);

    model->setTable("decl");

    model->select();

    QSqlRecord rec = model->record(ui->stackedWidget->currentIndex() - 1);
    int id = rec.value("id").toInt();

    query = new QSqlQuery(dbDecl);
    QString strF = "INSERT INTO goods (uid) "
                   "VALUES(%1);";

    QString str = strF.arg(id);

    query->exec(str);


    model->setTable("goods");

    model->select();

    rec = model->record(model->rowCount() - 1);

    emit toUpdateUidGoods(rec);
}

void MainWindow::slotField_1_1_textChanged(const QString &text)
{
    setDataIntoDb(text, 23);
}

void MainWindow::slotField_5_textChanged(const QString &text)
{
    setDataIntoDb(text, 37);
}

void MainWindow::slotField_6_textChanged(const QString &text)
{
    setDataIntoDb(text, 38);
}

void MainWindow::slotField_7_textChanged(const QString &text)
{
    setDataIntoDb(text, 39);
}

void MainWindow::slotField_8_textChanged(const QString &text)
{
    setDataIntoDb(text, 40);
}

void MainWindow::slotField_9_textChanged(const QString &text)
{
    setDataIntoDb(text, 41);
}

void MainWindow::slotField_10_textChanged(const QString &text)
{
    setDataIntoDb(text, 42);
}

void MainWindow::slotField_11_textChanged(const QString &text)
{
    setDataIntoDb(text, 43);
}

void MainWindow::slotField_12_textChanged(const QString &text)
{
    setDataIntoDb(text, 44);
}

void MainWindow::slotField_13_textChanged(const QString &text)
{
    setDataIntoDb(text, 45);
}

void MainWindow::slotField_14_textChanged(const QString &text)
{
    setDataIntoDb(text, 46);
}

void MainWindow::slotField_15_textChanged(const QString &text)
{
    setDataIntoDb(text, 47);
}

void MainWindow::slotField_16_textChanged(const QString &text)
{
    setDataIntoDb(text, 48);
}

void MainWindow::slotField_18_textChanged(const QString &text)
{
    setDataIntoDb(text, 49);
}

void MainWindow::slotToUpdateTextEdit_1()
{
    model = new QSqlTableModel(nullptr, dbDecl);

    model->setTable("decl");

    model->select();

    QSqlRecord rec = model->record(nRecords - 1);

    declContents->getTextEdit_1()->setText((rec.value("SD1")).toString() + '\n'
                                            +(rec.value("SD3")).toString() + ", "
                                            +(rec.value("SD5")).toString() + ", "
                                            +(rec.value("SD6")).toString() + ", "
                                            +(rec.value("SD7")).toString() + '\n'
                                            +(rec.value("SD8")).toString() + '\n');
}

void MainWindow::slotToUpdateTextEdit_2()
{
    model = new QSqlTableModel(nullptr, dbDecl);

    model->setTable("decl");

    model->select();

    QSqlRecord rec = model->record(nRecords - 1);

    declContents->getTextEdit_2()->setText((rec.value("RV1")).toString() + '\n'
                                            +(rec.value("RV3")).toString() + ", "
                                            +(rec.value("RV5")).toString() + ", "
                                            +(rec.value("RV6")).toString() + ", "
                                                     +(rec.value("RV7")).toString() + '\n');
}

void MainWindow::slotToUpdateTextEdit_3()
{
    model = new QSqlTableModel(nullptr, dbDecl);

    model->setTable("decl");

    model->select();

    QSqlRecord rec = model->record(nRecords - 1);

    declContents->getTextEdit_3()->setText((rec.value("DR1")).toString() + '\n'
                                            +(rec.value("DR3")).toString() + ", "
                                            +(rec.value("DR5")).toString() + ", "
                                            +(rec.value("DR6")).toString() + ", "
                                                     +(rec.value("DR7")).toString() + '\n');
}


void MainWindow::on_action_declList_triggered()
{
    if(declMenu)
    {
       delete declMenu;

       declMenu = nullptr;
    }
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_action_delete_triggered()
{
    if(nRecords)
    {
        emit toRemoveSelectedRow();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Сообщение БД");
        msgBox.setText("Записи отсутствуют в БД");
        msgBox.exec();
    }
}

void MainWindow::on_action_add_triggered()
{
    declWindow = new DeclTypeWindow;
    connect(declWindow,
            SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)),
            this,
            SLOT(treeItemDoubleClicked(QTreeWidgetItem*, int)));
    declWindow->exec();

    delete declWindow;
}

void MainWindow::on_action_update_triggered()
{
    query = new QSqlQuery(dbDecl);

    QString str = "SELECT * "
                  "FROM decl";

    query->exec(str);

    int count = 0;

    emit toRemoveTable();

    while(query->next())
    {
        ++count;

        emit toUpdateTable(query->record());
    }
}

void MainWindow::slotToChangeNumRecords()
{
    --nRecords;
}

void MainWindow::slotToDeleteEntryFromDb(int id)
{
    query = new QSqlQuery(dbDecl);

    QString argStr = "DELETE FROM decl "
                     "WHERE id = %1;";
    QString str = argStr.arg(id);

    query->exec(str);
}

void MainWindow::slotToDeleteEntryFromStack(int id)
{
    model = new QSqlTableModel(nullptr, dbDecl);

    model->setTable("decl");

    model->select();

    int nRow = 0;

    for (; nRow < model->rowCount(); ++nRow)
    {
        QSqlRecord rec = model->record(nRow);
        int db_id = rec.value("id").toInt();
        qDebug() << db_id;
        if(db_id == id)
        {
            break;
        }
    }

    ui->stackedWidget->removeWidget(ui->stackedWidget->widget(nRow + 1));
    frameVec.remove(nRow);
}

void MainWindow::slotToGiveUpdateDataSender()
{
    model = new QSqlTableModel(nullptr, dbDecl);

    model->setTable("decl");

    model->select();

    QSqlRecord rec = model->record(nRecords - 1);

    emit toGiveUpdateDataSender(rec);
}

void MainWindow::slotToUpdateGoodsDial()
{
    query = new QSqlQuery(dbDecl);

    QString str = "SELECT * "
                  "FROM goods";

    query->exec(str);

    while(query->next())
    {
        emit toUpdateGoodsTable(query->record());
    }
}

void MainWindow:: toUpdateField_1_1(QSqlRecord rec)
{
    declContents->getLineEdit_4()->setText((rec.value("DT1")).toString());
}

void MainWindow:: toUpdateField_1_2(QSqlRecord rec)
{
    declContents->getLineEdit_5()->setText((rec.value("DT2")).toString());
}

void MainWindow:: toUpdateField_1_3(QSqlRecord rec)
{
    declContents->getLineEdit_6()->setText((rec.value("DT3")).toString());
}

void MainWindow:: toUpdateField_5(QSqlRecord rec)
{
    declContents->getLineEdit_7()->setText((rec.value("FL5")).toString());
}

void MainWindow:: toUpdateField_6(QSqlRecord rec)
{
    declContents->getLineEdit()->setText((rec.value("FL6")).toString());
}

void MainWindow:: toUpdateField_7(QSqlRecord rec)
{
    declContents->getLineEdit_8()->setText((rec.value("FL7")).toString());
}


void MainWindow:: toUpdateField_8(QSqlRecord rec)
{
    declContents->getLineEdit_9()->setText((rec.value("FL8")).toString());
}

void MainWindow:: toUpdateField_9(QSqlRecord rec)
{
    declContents->getLineEdit_10()->setText((rec.value("FL9")).toString());
}


void MainWindow:: toUpdateField_10(QSqlRecord rec)
{
    declContents->getLineEdit_11()->setText((rec.value("FL10")).toString());
}

void MainWindow:: toUpdateField_11(QSqlRecord rec)
{
    declContents->getLineEdit_12()->setText((rec.value("FL11")).toString());
}

void MainWindow:: toUpdateField_12(QSqlRecord rec)
{
    declContents->getLineEdit_2()->setText((rec.value("FL12")).toString());
}

void MainWindow:: toUpdateField_13(QSqlRecord rec)
{
    declContents->getLineEdit_3()->setText((rec.value("FL13")).toString());
}

void MainWindow:: toUpdateField_14(QSqlRecord rec)
{
    declContents->getLineEdit_13()->setText((rec.value("FL14")).toString());
}

void MainWindow:: toUpdateField_15(QSqlRecord rec)
{
    declContents->getLineEdit_1()->setText((rec.value("FL15")).toString());
}

void MainWindow:: toUpdateField_16(QSqlRecord rec)
{
    declContents->getLineEdit_16()->setText((rec.value("FL16")).toString());
}

void MainWindow:: toUpdateField_18(QSqlRecord rec)
{
    declContents->getLineEdit_15()->setText((rec.value("FL18")).toString());
}

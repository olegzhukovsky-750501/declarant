#include "goodsdialog.h"
#include "ui_goodsdialog.h"

GoodsDialog::GoodsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoodsDialog),
    maxLength_TextEdit(1000)
{
    ui->setupUi(this);

    QLabel *label_0 = new QLabel("Выберите товар");

    ui->stackedWidget->addWidget(label_0);
    ui->stackedWidget->setCurrentIndex(0);
}

GoodsDialog::~GoodsDialog()
{
    delete ui;
}

void GoodsDialog::on_textEdit_textChanged()
{
    int curIndVec = ui->stackedWidget->currentIndex() - 1;
    if ((vecText[curIndVec]->toPlainText()).length() > maxLength_TextEdit)
    {
        QString text = vecText[curIndVec]->toPlainText();
        text.chop(text.length() - maxLength_TextEdit);
        vecText[curIndVec]->setPlainText(text);

        QTextCursor cursor = vecText[curIndVec]->textCursor();
        cursor.setPosition(vecText[curIndVec]->document()->characterCount() - 1);
       vecText[curIndVec]->setTextCursor(cursor);
   }

    emit textEdit_textChanged(vecText[curIndVec]->toPlainText(),
                              curIndVec);
}

void GoodsDialog::on_pushButton_clicked()
{
    nameText = new QTextEdit;

    connect(nameText,
            SIGNAL(textChanged()),
            this,
            SLOT(on_textEdit_textChanged()));

    vecText.push_back(nameText);

    ui->stackedWidget->addWidget(nameText);

    ui->stackedWidget->setCurrentWidget(nameText);

    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

    emit buttonAddClicked();
}

void GoodsDialog::on_tableWidget_cellClicked(int row, int column)
{
    ui->stackedWidget->setCurrentIndex(row + 1);
}

void GoodsDialog::on_pushButton_2_clicked()
{
    QItemSelectionModel *select = ui->tableWidget->selectionModel();

    if(select->hasSelection())
    {
        vecText.remove(ui->stackedWidget->currentIndex() - 1);

        ui->stackedWidget->removeWidget(ui->stackedWidget->currentWidget());

        QModelIndexList selection = select->selectedIndexes();

        QModelIndex index = selection.at(0);

        int id = (ui->tableWidget->item(index.row(), 0)->text()).toInt();

        ui->tableWidget->removeRow(index.row());

        emit deleteEntryFromDbGoods(id);
    }



}

void GoodsDialog::slotToUpdateTable(QSqlRecord rec)
{
    nameText = new QTextEdit;

    vecText.push_back(nameText);

    ui->stackedWidget->addWidget(nameText);

    nameText->setText((rec.value("GD1")).toString());

    connect(nameText,
            SIGNAL(textChanged()),
            this,
            SLOT(on_textEdit_textChanged()));

    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,
                             0, new QTableWidgetItem((rec.value("id")).toString()));

    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,
                             1, new QTableWidgetItem((rec.value("GD2")).toString()));

    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,
                             2, new QTableWidgetItem((rec.value("GD3")).toString()));

    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,
                             3, new QTableWidgetItem((rec.value("GD4")).toString()));

    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,
                             4, new QTableWidgetItem((rec.value("GD5")).toString()));

    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,
                             5, new QTableWidgetItem((rec.value("GD6")).toString()));
}

void GoodsDialog::slotToUpdateUidGoods(QSqlRecord rec)
{
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,
                             0, new QTableWidgetItem((rec.value("id")).toString()));
}

void GoodsDialog::on_tableWidget_itemEntered(QTableWidgetItem *item)
{
    emit tableWidget_itemChanged(item);
}

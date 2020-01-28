#include "frame.h"
#include "ui_frame.h"

Frame::Frame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);

    ui->lineEdit_2->setValidator(new QIntValidator);

}

Frame::~Frame()
{
    delete ui;
}

QTextEdit *Frame::getTextEdit_1()
{
    return ui->textEdit_1;
}

QTextEdit *Frame::getTextEdit_2()
{
    return ui->textEdit_2;
}

QTextEdit *Frame::getTextEdit_3()
{
    return ui->textEdit_3;
}

QLineEdit *Frame::getLineEdit_4()
{
    return ui->lineEdit_4;
}

QLineEdit *Frame::getLineEdit_5()
{
    return ui->lineEdit_5;
}

QLineEdit *Frame::getLineEdit_6()
{
    return ui->lineEdit_6;
}

QLineEdit *Frame::getLineEdit()
{
    return ui->lineEdit;
}

QLineEdit *Frame::getLineEdit_7()
{
    return ui->lineEdit_7;
}


QLineEdit *Frame::getLineEdit_8()
{
    return ui->lineEdit_8;
}

QLineEdit *Frame::getLineEdit_9()
{
    return ui->lineEdit_9;
}

QLineEdit *Frame::getLineEdit_10()
{
    return ui->lineEdit_10;
}

QLineEdit *Frame::getLineEdit_11()
{
    return ui->lineEdit_11;
}

QLineEdit *Frame::getLineEdit_12()
{
    return ui->lineEdit_12;
}

QLineEdit *Frame::getLineEdit_2()
{
    return ui->lineEdit_2;
}

QLineEdit *Frame::getLineEdit_3()
{
    return ui->lineEdit_3;
}

QLineEdit *Frame::getLineEdit_13()
{
    return ui->lineEdit_13;
}

QLineEdit *Frame::getLineEdit_1()
{
    return ui->lineEdit_1;
}

QLineEdit *Frame::getLineEdit_16()
{
    return ui->lineEdit_16;
}

QLineEdit *Frame::getLineEdit_15()
{
    return ui->lineEdit_15;
}

void Frame::slotToBlockAllFields()
{
    ui->textEdit_1->setEnabled(true);
    ui->textEdit_2->setReadOnly(true);
    ui->textEdit_3->setReadOnly(true);
    ui->textEdit_4->setReadOnly(true);

    ui->lineEdit_1->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    ui->lineEdit_6->setReadOnly(true);
    ui->lineEdit_7->setReadOnly(true);
    ui->lineEdit_8->setReadOnly(true);
    ui->lineEdit_9->setReadOnly(true);
    ui->lineEdit_10->setReadOnly(true);
    ui->lineEdit_11->setReadOnly(true);
    ui->lineEdit_12->setReadOnly(true);
    ui->lineEdit_13->setReadOnly(true);
    ui->lineEdit_15->setReadOnly(true);
}

void Frame::slotToUnblockAllFields()
{
    ui->textEdit_1->setEnabled(true);
    ui->textEdit_2->setEnabled(true);
    ui->textEdit_3->setEnabled(true);
    ui->textEdit_4->setEnabled(true);

    ui->lineEdit_1->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_3->setEnabled(true);
    ui->lineEdit_4->setEnabled(true);
    ui->lineEdit_5->setEnabled(true);
    ui->lineEdit_6->setEnabled(true);
    ui->lineEdit_7->setEnabled(true);
    ui->lineEdit_8->setEnabled(true);
    ui->lineEdit_9->setEnabled(true);
    ui->lineEdit_10->setEnabled(true);
    ui->lineEdit_11->setEnabled(true);
    ui->lineEdit_12->setEnabled(true);
    ui->lineEdit_13->setEnabled(true);
    ui->lineEdit_15->setEnabled(true);
}

void Frame::sender_slotButtonFillClicked()
{
    emit sender_ButtonFillClicked();
}

void Frame::sender_on_checkBox_stateChanged(int state)
{
    emit sender_checkBox_stateChanged(state);
}

void Frame::sender_on_textEdit_textChanged(const QString &text)
{
    emit sender_textEdit_textChanged(text);
}

void Frame::sender_on_lineEdit_5_textChanged(const QString &text)
{
    emit sender_lineEdit_5_textChanged(text);
}

void Frame::sender_on_lineEdit_textChanged(const QString &text)
{
    emit sender_lineEdit_textChanged(text);
}

void Frame::sender_on_lineEdit_2_textChanged(const QString &text)
{
    emit sender_lineEdit_2_textChanged(text);
}

void Frame::sender_on_lineEdit_6_textChanged(const QString &text)
{
    emit sender_lineEdit_6_textChanged(text);
}

void Frame::sender_on_lineEdit_3_textChanged(const QString &text)
{
    emit sender_lineEdit_3_textChanged(text);
}

void Frame::sender_on_lineEdit_4_textChanged(const QString &text)
{
    emit sender_lineEdit_4_textChanged(text);
}



void Frame::receiver_slotButtonFillClicked()
{
    emit receiver_ButtonFillClicked();
}

void Frame::receiver_on_textEdit_textChanged(const QString &text)
{
    emit receiver_textEdit_textChanged(text);
}

void Frame::receiver_on_lineEdit_5_textChanged(const QString &text)
{
    emit receiver_lineEdit_5_textChanged(text);
}

void Frame::receiver_on_lineEdit_textChanged(const QString &text)
{
    emit receiver_lineEdit_textChanged(text);
}

void Frame::receiver_on_lineEdit_2_textChanged(const QString &text)
{
    emit receiver_lineEdit_2_textChanged(text);
}

void Frame::receiver_on_lineEdit_6_textChanged(const QString &text)
{
    emit receiver_lineEdit_6_textChanged(text);
}

void Frame::receiver_on_lineEdit_3_textChanged(const QString &text)
{
    emit receiver_lineEdit_3_textChanged(text);
}

void Frame::receiver_on_lineEdit_4_textChanged(const QString &text)
{
    emit receiver_lineEdit_4_textChanged(text);
}

void Frame::receiver_on_lineEdit_8_textChanged(const QString &text)
{
    emit receiver_lineEdit_8_textChanged(text);
}

void Frame::receiver_on_lineEdit_7_textChanged(const QString &text)
{
    emit receiver_lineEdit_7_textChanged(text);
}

void Frame::receiver_on_lineEdit_9_textChanged(const QString &text)
{
    emit receiver_lineEdit_9_textChanged(text);
}

void Frame::receiver_on_lineEdit_10_textChanged(const QString &text)
{
    emit receiver_lineEdit_10_textChanged(text);
}

void Frame::receiver_on_lineEdit_11_textChanged(const QString &text)
{
    emit receiver_lineEdit_11_textChanged(text);
}


void Frame::declarant_slotButtonFillClicked()
{
    emit declarant_ButtonFillClicked();
}

void Frame::declarant_on_textEdit_textChanged(const QString &text)
{
    emit declarant_textEdit_textChanged(text);
}

void Frame::declarant_on_lineEdit_5_textChanged(const QString &text)
{
    emit declarant_lineEdit_5_textChanged(text);
}

void Frame::declarant_on_lineEdit_textChanged(const QString &text)
{
    emit declarant_lineEdit_textChanged(text);
}

void Frame::declarant_on_lineEdit_2_textChanged(const QString &text)
{
    emit declarant_lineEdit_2_textChanged(text);
}

void Frame::declarant_on_lineEdit_6_textChanged(const QString &text)
{
    emit declarant_lineEdit_6_textChanged(text);
}

void Frame::declarant_on_lineEdit_3_textChanged(const QString &text)
{
    emit declarant_lineEdit_3_textChanged(text);
}

void Frame::declarant_on_lineEdit_4_textChanged(const QString &text)
{
    emit declarant_lineEdit_4_textChanged(text);
}

void Frame::declarant_on_lineEdit_8_textChanged(const QString &text)
{
    emit declarant_lineEdit_8_textChanged(text);
}

void Frame::declarant_on_lineEdit_7_textChanged(const QString &text)
{
    emit declarant_lineEdit_7_textChanged(text);
}

void Frame::declarant_on_lineEdit_9_textChanged(const QString &text)
{
    emit declarant_lineEdit_9_textChanged(text);
}

void Frame::declarant_on_lineEdit_10_textChanged(const QString &text)
{
    emit declarant_lineEdit_10_textChanged(text);
}

void Frame::declarant_on_lineEdit_11_textChanged(const QString &text)
{
    emit declarant_lineEdit_11_textChanged(text);
}

void Frame::declarant_on_comboBox_activated(const QString &text)
{
    emit declarant_comboBox_activated(text);
}


void Frame::goods_on_textEdit_textChanged(const QString &text, int row)
{
    emit goods_textEdit_textChanged(text, row);
}

void Frame::goods_on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    emit goods_tableWidget_itemChanged(item);
}

void Frame::slotDeleteEntryFromDbGoods(int id)
{
    emit deleteEntryFromDbGoods(id);
}

void Frame::slotGoodsButtonAddClicked()
{
    emit goodsButtonAddClicked();
}

void Frame::slotToUpdateField_1_1(QSqlRecord rec)
{
    ui->lineEdit_4->setText((rec.value("DT1")).toString());
}

void Frame::slotToUpdateField_1_2(QSqlRecord rec)
{
    ui->lineEdit_5->setText((rec.value("DT2")).toString());
}

void Frame::slotToUpdateField_1_3(QSqlRecord rec)
{
    ui->lineEdit_6->setText((rec.value("DT3")).toString());
}

void Frame::slotToUpdateField_5(QSqlRecord rec)
{
    ui->lineEdit_7->setText((rec.value("FL5")).toString());
}

void Frame::slotToUpdateField_6(QSqlRecord rec)
{
    ui->lineEdit->setText((rec.value("FL6")).toString());
}

void Frame::slotToUpdateField_7(QSqlRecord rec)
{
    ui->lineEdit_8->setText((rec.value("FL7")).toString());
}

void Frame::slotToUpdateField_8(QSqlRecord rec)
{
    ui->lineEdit_9->setText((rec.value("FL8")).toString());
}

void Frame::slotToUpdateField_9(QSqlRecord rec)
{
    ui->lineEdit_10->setText((rec.value("FL9")).toString());
}

void Frame::slotToUpdateField_10(QSqlRecord rec)
{
    ui->lineEdit_11->setText((rec.value("FL10")).toString());
}

void Frame::slotToUpdateField_11(QSqlRecord rec)
{
    ui->lineEdit_12->setText((rec.value("FL11")).toString());
}

void Frame::slotToUpdateField_12(QSqlRecord rec)
{
    ui->lineEdit_2->setText((rec.value("FL12")).toString());
}

void Frame::slotToUpdateField_13(QSqlRecord rec)
{
    ui->lineEdit_3->setText((rec.value("FL13")).toString());
}

void Frame::slotToUpdateField_14(QSqlRecord rec)
{
    ui->lineEdit_13->setText((rec.value("FL14")).toString());
}

void Frame::slotToUpdateField_15(QSqlRecord rec)
{
    ui->lineEdit_1->setText((rec.value("FL15")).toString());
}

void Frame::slotToUpdateField_16(QSqlRecord rec)
{
    ui->lineEdit_16->setText((rec.value("FL16")).toString());
}

void Frame::slotToUpdateField_18(QSqlRecord rec)
{
    ui->lineEdit_15->setText((rec.value("FL18")).toString());
}


void Frame::on_pushButton_1_clicked()
{
    sendDial = new SenderDialog;

    connect(sendDial,
            SIGNAL(checkBox_stateChanged(int)), this, SLOT(sender_on_checkBox_stateChanged(int)));
    connect(sendDial,
            SIGNAL(textEdit_textChanged(const QString&)),
            this,
            SLOT(sender_on_textEdit_textChanged(const QString&)));
    connect(sendDial,
            SIGNAL(lineEdit_textChanged(const QString&)),
            this,
            SLOT(sender_on_lineEdit_textChanged(const QString&)));
    connect(sendDial,
            SIGNAL(lineEdit_5_textChanged(const QString&)),
            this,
            SLOT(sender_on_lineEdit_5_textChanged(const QString&)));
    connect(sendDial,
            SIGNAL(lineEdit_2_textChanged(const QString&)),
            this,
            SLOT(sender_on_lineEdit_2_textChanged(const QString&)));
    connect(sendDial,
            SIGNAL(lineEdit_6_textChanged(const QString&)),
            this,
            SLOT(sender_on_lineEdit_6_textChanged(const QString&)));
    connect(sendDial,
            SIGNAL(lineEdit_3_textChanged(const QString&)),
            this,
            SLOT(sender_on_lineEdit_3_textChanged(const QString&)));
    connect(sendDial,
            SIGNAL(lineEdit_4_textChanged(const QString&)),
            this,
            SLOT(sender_on_lineEdit_4_textChanged(const QString&)));
    connect(sendDial,
            SIGNAL(buttonNextClicked()),
            this,
            SLOT(sender_slotButtonFillClicked()),
            Qt::UniqueConnection);

    connect(this,
            SIGNAL(toUpdateSenderDialog()),
            sendDial,
            SLOT(slotToUpdateSenderDialog()));

    connect(sendDial,
            SIGNAL(toAskForUpdateDataSender()),
            this,
            SLOT(slotToAskForUpdateDataSender()));

    connect(this,
            SIGNAL(toUpdateTextSender(QSqlRecord)),
            sendDial,
            SLOT(slotToUpdateText(QSqlRecord)));


    emit toUpdateSenderDialog();
    emit toUpdateReceiverDialog();
    emit toUpdateDeclarantDialog();

    sendDial->exec();

    delete sendDial;
}

void Frame::on_pushButton_2_clicked()
{
    receivDial = new ReceiverDialog;

    connect(receivDial,
            SIGNAL(textEdit_textChanged(const QString&)),
            this,
            SLOT(receiver_on_textEdit_textChanged(const QString&)));
    connect(receivDial,
            SIGNAL(lineEdit_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_textChanged(const QString&)));
    connect(receivDial,
            SIGNAL(lineEdit_5_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_5_textChanged(const QString&)));
    connect(receivDial,
            SIGNAL(lineEdit_2_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_2_textChanged(const QString&)));
    connect(receivDial,
            SIGNAL(lineEdit_6_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_6_textChanged(const QString&)));
    connect(receivDial,
            SIGNAL(lineEdit_3_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_3_textChanged(const QString&)));
    connect(receivDial,
            SIGNAL(lineEdit_4_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_4_textChanged(const QString&)));

    connect(receivDial,
            SIGNAL(lineEdit_8_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_8_textChanged(const QString&)));
    connect(receivDial,
            SIGNAL(lineEdit_7_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_7_textChanged(const QString&)));
    connect(receivDial,
            SIGNAL(lineEdit_9_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_9_textChanged(const QString&)));
    connect(receivDial,
            SIGNAL(lineEdit_10_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_10_textChanged(const QString&)));
    connect(receivDial,
            SIGNAL(lineEdit_11_textChanged(const QString&)),
            this,
            SLOT(receiver_on_lineEdit_11_textChanged(const QString&)));

    connect(receivDial,
            SIGNAL(buttonNextClicked()),
            this,
            SLOT(receiver_slotButtonFillClicked()),
            Qt::UniqueConnection);

    receivDial->exec();

    delete receivDial;
}

void Frame::on_pushButton_3_clicked()
{
    declDial = new DeclarantDialog;

    connect(declDial,
            SIGNAL(textEdit_textChanged(const QString&)),
            this,
            SLOT(declarant_on_textEdit_textChanged(const QString&)));
    connect(declDial,
            SIGNAL(lineEdit_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_textChanged(const QString&)));
    connect(declDial,
            SIGNAL(lineEdit_5_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_5_textChanged(const QString&)));
    connect(declDial,
            SIGNAL(lineEdit_2_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_2_textChanged(const QString&)));
    connect(declDial,
            SIGNAL(lineEdit_6_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_6_textChanged(const QString&)));
    connect(declDial,
            SIGNAL(lineEdit_3_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_3_textChanged(const QString&)));
    connect(declDial,
            SIGNAL(lineEdit_4_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_4_textChanged(const QString&)));

    connect(declDial,
            SIGNAL(lineEdit_8_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_8_textChanged(const QString&)));
    connect(declDial,
            SIGNAL(lineEdit_7_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_7_textChanged(const QString&)));
    connect(declDial,
            SIGNAL(lineEdit_9_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_9_textChanged(const QString&)));
    connect(declDial,
            SIGNAL(lineEdit_10_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_10_textChanged(const QString&)));
    connect(declDial,
            SIGNAL(lineEdit_11_textChanged(const QString&)),
            this,
            SLOT(declarant_on_lineEdit_11_textChanged(const QString&)));

    connect(declDial,
            SIGNAL(buttonNextClicked()),
            this,
            SLOT(declarant_slotButtonFillClicked()),
            Qt::UniqueConnection);

    connect(declDial,
            SIGNAL(comboBox_activated(const QString&)),
            this,
            SLOT(declarant_on_comboBox_activated(const QString&)),
            Qt::UniqueConnection);

    declDial->exec();

    delete declDial;
}

void Frame::on_lineEdit_6_returnPressed()
{
    dtDial = new DeclTypeDialog;

    connect(dtDial,
            SIGNAL(itemViewClicked(const QModelIndex&)),
            this,
            SLOT(declTypeItemDoubleClicked(const QModelIndex&)));
    dtDial->exec();

    delete dtDial;
}

void Frame::declTypeItemDoubleClicked(const QModelIndex &index)
{
    int row = index.row();

    QModelIndex inputIndex_1 = dtDial->model->index(row, 0);
    ui->lineEdit_6->setText(inputIndex_1.data().toString());

    dtDial->close();
}

void Frame::slotToAskForUpdateDataSender()
{
    emit toAskForUpdateDataSender();
}

void Frame::slotToUpdateTextSender(QSqlRecord rec)
{
    emit toUpdateTextSender(rec);
}

void Frame::slotToUpdateGoodsTable(QSqlRecord rec)
{
    emit toUpdateGoodsTable(rec);
}

void Frame::slotToUpdateUidGoods(QSqlRecord rec)
{
    emit toUpdateUidGoods(rec);
}

void Frame::slotToChangeLineEdit_15(const QDate &date)
{
    ui->lineEdit_15->setText(date.toString("dd.MM.yy"));
}

void Frame::on_pushButton_13_clicked()
{
    goodsDial = new GoodsDialog;

    connect(goodsDial,
            SIGNAL(buttonAddClicked()),
            this,
            SLOT(slotGoodsButtonAddClicked()));
    connect(goodsDial,
            SIGNAL(textEdit_textChanged(const QString&, int)),
            this,
            SLOT(goods_on_textEdit_textChanged(const QString&, int)));
    connect(goodsDial,
            SIGNAL(tableWidget_itemChanged(QTableWidgetItem*)),
            this,
            SLOT(goods_on_tableWidget_itemChanged(QTableWidgetItem*)));
    connect(goodsDial,
            SIGNAL(deleteEntryFromDbGoods(int)),
            this,
            SLOT(slotDeleteEntryFromDbGoods(int)));
    connect(this,
            SIGNAL(toUpdateGoodsTable(QSqlRecord)),
            goodsDial,
            SLOT(slotToUpdateTable(QSqlRecord)));
    connect(this,
            SIGNAL(toUpdateUidGoods(QSqlRecord)),
            goodsDial,
            SLOT(slotToUpdateUidGoods(QSqlRecord)),
            Qt::UniqueConnection);

    emit toUpdateGoodsDial();

    goodsDial->exec();

    delete goodsDial;
}

void Frame::on_lineEdit_15_returnPressed()
{
    calDial = new CalendarDialog;

    connect(calDial, SIGNAL(dateChanged(const QDate&)), this, SLOT(slotToChangeLineEdit_15(const QDate&)));

    calDial->exec();

    delete calDial;
}

void Frame::on_lineEdit_7_returnPressed()
{
    countryDial = new CountryDialog;
    connect (countryDial, SIGNAL(itemViewClicked(const QModelIndex&)), this, SLOT(field_7_tableItemDoubleClicked(const QModelIndex&)));
    countryDial->exec();

    delete countryDial;
}

void Frame::field_7_tableItemDoubleClicked(const QModelIndex &index)
{
    int row = index.row();

    QModelIndex inputIndex_1 = countryDial->model->index(row, 2);
    ui->lineEdit_7->setText(inputIndex_1.data().toString());

    countryDial->close();
}

void Frame::field_8_tableItemDoubleClicked(const QModelIndex &index)
{
    int row = index.row();

    QModelIndex inputIndex_1 = countryDial->model->index(row, 2);
    ui->lineEdit->setText(inputIndex_1.data().toString());

    QModelIndex inputIndex_2 = countryDial->model->index(row, 0);
    ui->lineEdit_8->setText(inputIndex_2.data().toString());

    countryDial->close();
}

void Frame::field_9_tableItemDoubleClicked(const QModelIndex &index)
{
    int row = index.row();

    QModelIndex inputIndex_1 = countryDial->model->index(row, 0);
    ui->lineEdit_9->setText(inputIndex_1.data().toString());

    countryDial->close();
}

void Frame::field_10_tableItemDoubleClicked(const QModelIndex &index)
{
    int row = index.row();

    QModelIndex inputIndex_1 = excDial->model->index(row, 1);
    ui->lineEdit_10->setText(inputIndex_1.data().toString());

    excDial->close();
}

void Frame::field_11_tableItemDoubleClicked(const QModelIndex &index)
{
    int row = index.row();

    QModelIndex inputIndex_1 = transDial->model->index(row, 0);
    ui->lineEdit_11->setText(inputIndex_1.data().toString());

    transDial->close();
}

void Frame::field_12_tableItemDoubleClicked(const QModelIndex &index)
{
    int row = index.row();

    QModelIndex inputIndex_1 = transDial->model->index(row, 0);
    ui->lineEdit_12->setText(inputIndex_1.data().toString());

    transDial->close();
}

void Frame::field_13_tableItemDoubleClicked(const QModelIndex &index)
{
    int row = index.row();

    QModelIndex inputIndex_1 = prodDial->model->index(row, 0);
    ui->lineEdit_13->setText(inputIndex_1.data().toString());

    prodDial->close();
}

void Frame::field_16_tableItemDoubleClicked(const QModelIndex &index)
{
    int row = index.row();

    QModelIndex inputIndex_1 = countryDial->model->index(row, 2);
    ui->lineEdit_16->setText(inputIndex_1.data().toString());

    countryDial->close();
}

void Frame::on_pushButton_8_clicked()
{
    countryDial = new CountryDialog;
    connect (countryDial, SIGNAL(itemViewClicked(const QModelIndex&)), this, SLOT(field_8_tableItemDoubleClicked(const QModelIndex&)));
    countryDial->exec();

    delete countryDial;
}

void Frame::on_pushButton_9_clicked()
{
    countryDial = new CountryDialog;
    connect (countryDial, SIGNAL(itemViewClicked(const QModelIndex&)), this, SLOT(field_9_tableItemDoubleClicked(const QModelIndex&)));
    countryDial->exec();

    delete countryDial;
}

void Frame::on_lineEdit_10_returnPressed()
{
    excDial = new ExcRateDialog;
    connect (excDial, SIGNAL(itemViewClicked(const QModelIndex&)), this, SLOT(field_10_tableItemDoubleClicked(const QModelIndex&)));
    excDial->exec();

    delete excDial;
}

void Frame::on_lineEdit_11_returnPressed()
{
    transDial = new TransDialog;
    connect (transDial, SIGNAL(itemViewClicked(const QModelIndex&)), this, SLOT(field_11_tableItemDoubleClicked(const QModelIndex&)));
    transDial->exec();

    delete transDial;
}

void Frame::on_lineEdit_12_returnPressed()
{
    transDial = new TransDialog;
    connect (transDial, SIGNAL(itemViewClicked(const QModelIndex&)), this, SLOT(field_12_tableItemDoubleClicked(const QModelIndex&)));
    transDial->exec();

    delete transDial;
}

void Frame::on_lineEdit_13_returnPressed()
{
    prodDial = new ProdDialog;
    connect (prodDial, SIGNAL(itemViewClicked(const QModelIndex&)), this, SLOT(field_13_tableItemDoubleClicked(const QModelIndex&)));
    prodDial->exec();

    delete prodDial;
}

void Frame::on_lineEdit_16_returnPressed()
{
    countryDial = new CountryDialog;
    connect (countryDial, SIGNAL(itemViewClicked(const QModelIndex&)), this, SLOT(field_16_tableItemDoubleClicked(const QModelIndex&)));
    countryDial->exec();

    delete countryDial;
}

void Frame::on_lineEdit_7_textChanged(const QString &text)
{
    emit field_5_textChanged(text);
}

void Frame::on_lineEdit_textChanged(const QString &text)
{
    emit field_6_textChanged(text);
}

void Frame::on_lineEdit_8_textChanged(const QString &text)
{
   emit field_7_textChanged(text);
}

void Frame::on_lineEdit_9_textChanged(const QString &text)
{
    emit field_8_textChanged(text);
}

void Frame::on_lineEdit_10_textChanged(const QString &text)
{
    emit field_9_textChanged(text);
}

void Frame::on_lineEdit_11_textChanged(const QString &text)
{
    emit field_10_textChanged(text);
}

void Frame::on_lineEdit_12_textChanged(const QString &text)
{
    emit field_11_textChanged(text);
}

void Frame::on_lineEdit_2_textChanged(const QString &text)
{
    emit field_12_textChanged(text);
}

void Frame::on_lineEdit_3_textChanged(const QString &text)
{
    emit field_13_textChanged(text);
}

void Frame::on_lineEdit_13_textChanged(const QString &text)
{
    emit field_14_textChanged(text);
}

void Frame::on_lineEdit_1_textChanged(const QString &text)
{
    emit field_15_textChanged(text);
}

void Frame::on_lineEdit_16_textChanged(const QString &text)
{
    emit field_16_textChanged(text);
}

void Frame::on_lineEdit_15_textChanged(const QString &text)
{
    emit field_18_textChanged(text);
}

void Frame::on_lineEdit_6_textChanged(const QString &text)
{
    emit field_1_1_textChanged(text);
}

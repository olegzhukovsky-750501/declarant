#include "transdialog.h"
#include "ui_transdialog.h"

TransDialog::TransDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransDialog)
{
    ui->setupUi(this);

    createConnection();
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM vidtrans", transDir);

    model->setHeaderData(0, Qt::Horizontal, "Код");
    model->setHeaderData(1, Qt::Horizontal, "Тип");
    model->setHeaderData(2, Qt::Horizontal, "Наименование");

    ui->view = new QTableView;
    ui->view->setModel(model);

    connect(ui->view, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(itemViewDoubleClicked(const QModelIndex&)));

    verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(ui->view);
    setLayout(verticalLayout);
}

TransDialog::~TransDialog()
{
    delete ui;
}

bool TransDialog::createConnection()
{
    transDir = QSqlDatabase::addDatabase("QSQLITE", "TransBase");
    transDir.setDatabaseName("C:\\Users\\User\\Documents\\untitled3\\npi.db3");
    transDir.setPort(5432);
    transDir.setHostName("localhost");
    transDir.setUserName("postgres");
    transDir.setPassword("root");

    if(!(transDir.open()))
    {
        qDebug() << "Cannot open database:" << transDir.lastError();
        return false;
    }
    else
    {
        return true;
    }
}

void TransDialog::itemViewDoubleClicked(const QModelIndex &index)
{
    emit itemViewClicked(index);
}

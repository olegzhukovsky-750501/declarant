#include "decltypedialog.h"
#include "ui_decltypedialog.h"

DeclTypeDialog::DeclTypeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeclTypeDialog)
{
    ui->setupUi(this);

    createConnection();
    model = new QSqlQueryModel;
    model->setQuery("SELECT DT1, DT2"
                    " FROM decltypes", declDir);

    model->setHeaderData(0, Qt::Horizontal, "Код");
    model->setHeaderData(1, Qt::Horizontal, "Наименование");

    ui->view = new QTableView;
    ui->view->setModel(model);

    connect(ui->view, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(itemViewDoubleClicked(const QModelIndex&)));

    verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(ui->view);
    setLayout(verticalLayout);
}

DeclTypeDialog::~DeclTypeDialog()
{
    delete ui;
}

bool DeclTypeDialog::createConnection()
{
    declDir = QSqlDatabase::addDatabase("QSQLITE", "CountryBase");
    declDir.setDatabaseName("C:\\Users\\User\\Documents\\untitled3\\npi.db3");
    declDir.setPort(5432);
    declDir.setHostName("localhost");
    declDir.setUserName("postgres");
    declDir.setPassword("root");

    if(!(declDir.open()))
    {
        qDebug() << "Cannot open database:" << declDir.lastError();
        return false;
    }
    else
    {
        return true;
    }
}

QTableView *DeclTypeDialog::getTableView()
{
    return ui->view;
}

void DeclTypeDialog::itemViewDoubleClicked(const QModelIndex &index)
{
    emit itemViewClicked(index);
}

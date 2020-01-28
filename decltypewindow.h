#pragma once

#include <QDialog>
#include <QTreeWidgetItem>

namespace Ui {
class DeclTypeWindow;
}

class DeclTypeWindow : public QDialog
{
    Q_OBJECT
signals:
    void itemDoubleClicked(QTreeWidgetItem* treeItem, int column);
public slots:
    void treeItemDoubleClicked(QTreeWidgetItem* treeItem, int column);
public:
    explicit DeclTypeWindow(QWidget *parent = nullptr);
    ~DeclTypeWindow();

    QTreeWidget* getTree();

    friend class MainWindow;
private:
    Ui::DeclTypeWindow *ui;
};

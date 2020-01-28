#pragma once

#include <QWidget>
#include "senderdialog.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_1_clicked();

private:
    Ui::Form *ui;
    SenderDialog* sendDial;
};

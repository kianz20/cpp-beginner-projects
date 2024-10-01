#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qttablelearning.h"

class QTTableLearning : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_addButton_clicked();

public:
    QTTableLearning(QWidget *parent = nullptr);
    ~QTTableLearning();

private:
    Ui::QTTableLearningClass ui;
};

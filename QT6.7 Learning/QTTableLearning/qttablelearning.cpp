#include "qttablelearning.h"
#include <addtotable.h>

QTTableLearning::QTTableLearning(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

QTTableLearning::~QTTableLearning()
{}

static void addItemToColumn(QTableWidget* tableWidget, int column, QTableWidgetItem& item) {
    int rowCount = tableWidget->rowCount();
    for (int i = 0; i < rowCount; ++i) {
        if (!tableWidget->item(i, column)) {
            tableWidget->setItem(i, column, new QTableWidgetItem(item));
            return;
        }
    }

    tableWidget->insertRow(rowCount);
    tableWidget->setItem(rowCount, column, new QTableWidgetItem(item));
}

void QTTableLearning::on_addButton_clicked() {
    addToTable dialog(this);

    QTableWidget* table = ui.tableWidget;
    if (dialog.exec()) {
        QString text = dialog.textInput->text();
        int selectedCol = (-dialog.colButtonGroup->checkedId())-2;

        if (!text.isEmpty()) {
            QTableWidgetItem* item = new QTableWidgetItem(QString(text));
            addItemToColumn(table, selectedCol, *item);
        }
    };

   
}

#pragma once

#include <QDialog>
#include "ui_addtotable.h"

class addToTable : public QDialog, public Ui::addToTableClass
{
	Q_OBJECT

public:
	addToTable(QWidget *parent = nullptr);
	~addToTable();

private:
};

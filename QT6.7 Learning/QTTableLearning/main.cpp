#include "qttablelearning.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTTableLearning w;
    w.show();
    return a.exec();
}

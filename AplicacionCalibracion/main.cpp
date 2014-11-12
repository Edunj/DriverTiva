#include <QApplication>
#include "calibracion.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calibracion w;
    w.show();
    
    return a.exec();
}

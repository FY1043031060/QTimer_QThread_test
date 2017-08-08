#include <QCoreApplication>
#include "TimerTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TimerTest sim;
    return a.exec();
}

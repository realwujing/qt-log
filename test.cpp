#include "test.h"

void logTest()
{
    qDebug() << "logTest";
    qDebug() << "当前时间是: " << QTime::currentTime().toString("hh:mm:ss");
    qInfo() << QString("God bless logTest!");
}
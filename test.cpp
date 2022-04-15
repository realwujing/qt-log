#include "test.h"

void logTest()
{
    // while (true)
    // {
    //     qDebug() << "logTest";
    //     qDebug() << "当前时间是: " << QTime::currentTime().toString("hh:mm:ss");
    //     qInfo() << QString("God bless logTest!");
    //     // QThread::msleep(2);
    // }

    qDebug() << "logTest";
    qDebug() << "当前时间是: " << QTime::currentTime().toString("hh:mm:ss");
    qInfo() << QString("God bless logTest!");
}
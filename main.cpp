#include <QCoreApplication>
#include <QDebug>
#include <QDateTime>

#include "log_handler.h"
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // [[1]] 安装消息处理函数
    LogHandler::instance()->installMessageHandler();

    logTest();

    // [[2]] 输出测试，查看是否写入到文件
    qDebug() << "Hello";
    qDebug() << "当前时间是: " << QTime::currentTime().toString("hh:mm:ss");
    qInfo() << QString("God bless you!");

    return a.exec();
}
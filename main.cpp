#include <QCoreApplication>
#include <QDebug>

#include "log_handler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // [[1]] 安装消息处理函数
    LogHandler::Get().installMessageHandler();

    // [[2]] 输出测试，查看是否写入到文件
    qDebug() << "Hello";
    qDebug() << "当前时间是: " << QTime::currentTime().toString("hh:mm:ss");
    qInfo() << QString("God bless you!");

    // [[3]] 取消安装自定义消息处理，然后启用
    LogHandler::Get().uninstallMessageHandler();
    qDebug() << "........"; // 不写入日志
    LogHandler::Get().installMessageHandler();
    
    // [[4]] 程序结束时释放 LogHandler 的资源，例如刷新并关闭日志文件
    LogHandler::Get().uninstallMessageHandler();

    return a.exec();
}
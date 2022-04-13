#pragma once

#include <iostream>
#include <QDebug>
#include <QDateTime>
#include <QMutexLocker>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QTimer>
#include <QTextStream>
#include <QTextCodec>

const int g_logLimitSize = 10; // 日志文件大小限制，单位 MB

class LogHandler;
class LogHandlerPrivate : public QObject {
    Q_OBJECT
public:
    LogHandlerPrivate(LogHandler *parent);
    ~LogHandlerPrivate();

private:
    // 打开日志文件 log.txt，如果日志文件不是当天创建的，则使用创建日期把其重命名为 yyyy-MM-dd.log，并重新创建一个 log.txt
    void openAndBackupLogFile();
    void checkLogFiles(); // 检测当前日志文件大小
    void autoDeleteLog(); // 自动删除30天前的日志

    // 消息处理函数
    static void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

public:
    LogHandler * const q_ptr;
    Q_DECLARE_PUBLIC(LogHandler);

private:
    QDir   logDir;              // 日志文件夹
    QTimer renameLogFileTimer;  // 重命名日志文件使用的定时器
    QTimer flushLogFileTimer;   // 刷新输出到日志文件的定时器
    QDate  logFileCreatedDate;  // 日志文件创建的时间

    static QFile *logFile;      // 日志文件
    static QTextStream *logOut; // 输出日志的 QTextStream，使用静态对象就是为了减少函数调用的开销
    static QMutex logMutex;     // 同步使用的 mutex
};
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

const int g_logLimitSize = 10; ///< 日志文件大小限制，单位 MB */

class LogHandler;
/**
 * @brief the LogHandlerPrivate class
 * 
 */
class LogHandlerPrivate : public QObject {
    Q_OBJECT
public:
    /**
     * @brief Construct a new Log Handler Private object
     * 
     * @param parent D指针
     *
     */
    LogHandlerPrivate(LogHandler *parent);

    /**
     * @brief Destroy the Log Handler Private object
     * 
     */
    ~LogHandlerPrivate();

private:
    /**
     * @brief 打开日志文件 log.txt，如果日志文件不是当天创建的，则使用创建日期把其重命名为 yyyy-MM-dd.log，并重新创建一个 log.txt
     * 
     */
    void openAndBackupLogFile();

    /**
     * @brief 检测当前日志文件大小
     * 
     */
    void checkLogFiles();

    /**
     * @brief 自动删除30天前的日志
     * 
     */
    void autoDeleteLog();

    /**
     * @brief 消息处理函数
     * 
     * @param type 消息类型
     * @param context 消息上下文
     * @param msg 消息内容
     */
    static void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

public:
    LogHandler * const q_ptr;   ///< D指针
    Q_DECLARE_PUBLIC(LogHandler);   ///< 声明LogHandler类

private:
    QDir   logDir;              ///< 日志文件夹
    QTimer renameLogFileTimer;  ///< 重命名日志文件使用的定时器
    QTimer flushLogFileTimer;   ///< 刷新输出到日志文件的定时器
    QDateTime  logFileCreatedDateTime;  ///< 日志文件创建的时间 

    static QFile *logFile;      ///< 日志文件
    static QTextStream *logOut; ///< 输出日志的 QTextStream，使用静态对象就是为了减少函数调用的开销
    static QMutex logMutex;     ///< 同步使用的 mutex
};
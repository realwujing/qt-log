#pragma once

#include <QObject>

#include "singleton.h"

class LogHandlerPrivate;
class LogHandler : public QObject, public Singleton<LogHandler>
{
    Q_OBJECT
    friend class Singleton<LogHandler>;
public:
    explicit LogHandler(QObject *parent = nullptr);
    ~LogHandler();
    void installMessageHandler();   // 给Qt安装消息处理函数
    void uninstallMessageHandler(); // 取消安装消息处理函数并释放资源

private:
   LogHandlerPrivate * const d_ptr;
   Q_DECLARE_PRIVATE(LogHandler);
};
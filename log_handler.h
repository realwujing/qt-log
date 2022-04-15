#pragma once

#include <QObject>

#include "singleton.h"

class LogHandlerPrivate; /**< 声明 LogHandlerPrivate 类 */

/**
 * @brief The LogHandler class
 * 
 */
class LogHandler : public QObject, public Singleton<LogHandler>
{
    Q_OBJECT
    friend class Singleton<LogHandler>; /**< 友元类，可以访问私有成员 */
public:
    /**
     * @brief Construct a new Log Handler object
     * 
     * @param parent D指针
     *
     */
    explicit LogHandler(QObject *parent = nullptr);

    /**
     * @brief Destroy the Log Handler object
     * 
     */
    ~LogHandler();

    /**
     * @brief 给Qt安装消息处理函数
     * 
     */
    void installMessageHandler();

    /**
     * @brief 取消安装消息处理函数并释放资源
     * 
     */
    void uninstallMessageHandler();

private:
   LogHandlerPrivate * const d_ptr; /**< d_ptr指针，指向LogHandlerPrivate对象 */
   Q_DECLARE_PRIVATE(LogHandler); /**< 声明LogHandlerPrivate类 */
};
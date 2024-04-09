#include <unistd.h>
#include <string>
#include "webserver.h"
#include "cmdline.hpp"


int main(int argc, char** argv) {
    
    cmdline::parser cmds;

    cmds.add<std::string>("resource", 'r', "www resource");

    cmds.parse_check(argc, argv);

    std::string resource = cmds.get<std::string>("resource");

    WebServer server(
        resource,
        1316, 3, 60000, false,             /* 端口 ET模式 timeoutMs 优雅关闭  */
        3306, "root", "root", "webserver", /* Mysql配置 */
        12, 6, true, 1, 1024);             /* 连接池数量 线程池的线程数量 日志开关 日志等级 日志异步队列容量 */
    
    
    // 启动服务器
    server.Start();
} 
  
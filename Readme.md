# 基于`spdlog`开源库封装的日志类

## 功能
**提供了3种不同的日志模式**
- 控制台模式(`mode = 1`)，打印结果输出到控制台
- 文件模式(`mode = 2`)，打印结果输出到指定文件中
- 控制台+文件模式(`mode = 3`)，打印结果输出到控制台和指定文件中

**五种打印级别**
```
ZLOG_TRACE(); 
ZLOG_DEBUG();
ZLOG_INFO();
ZLOG_WARN(); 
ZLOG_ERROR
```

## 使用

编译安装[spdlog](https://github.com/gabime/spdlog)后，直接包含该头文件即可 `#include "logging.h"`

在使用的过程中，记得加上`-lspdlog`编译链接参数

**示例代码：**
```
#include "logging.h"

int main() {

    ZLOG::getInstance("./log/", "test.log", 3);

	int param = 1;
 
	ZLOG_TRACE("this is trace log record, param: {}", ++param); // int type param is ok
	ZLOG_DEBUG("this is debug log record, param: {}", ++param);
	ZLOG_INFO("this is info log record, param: {}", ++param);
	ZLOG_WARN("this is warn log record, param: {}", double(++param)); // double type param is ok
	ZLOG_ERROR("this is error log record, param: {}", std::to_string(++param)); // string type param is ok
 
	return 0;

}

```

**编译运行：**
```
g++ -g main.cpp -o main -lspdlog 
./main
```

**运行结果：**
```
root@VM-4-10-ubuntu:~/logging# ./main 
[2022-06-27 00:07:43][thread 24104][trace]this is trace log record, param: 2
[2022-06-27 00:07:43][thread 24104][debug]this is debug log record, param: 3
[2022-06-27 00:07:43][thread 24104][info]this is info log record, param: 4
[2022-06-27 00:07:43][thread 24104][warning]this is warn log record, param: 5
[2022-06-27 00:07:43][thread 24104][error]this is error log record, param: 6

root@VM-4-10-ubuntu:~/logging# cat ./log/test.log 
[2022-06-27 00:07:43][thread 24104][trace]this is trace log record, param: 2
[2022-06-27 00:07:43][thread 24104][debug]this is debug log record, param: 3
[2022-06-27 00:07:43][thread 24104][info]this is info log record, param: 4
[2022-06-27 00:07:43][thread 24104][warning]this is warn log record, param: 5
[2022-06-27 00:07:43][thread 24104][error]this is error log record, param: 6

```

## Todo

- [ ] 完整CMakeList.txt

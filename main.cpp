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
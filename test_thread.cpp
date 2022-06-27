#include"logging.h"
#include <pthread.h>




void *func_1(void *arg)
{
 
	
	for(int i = 0; i < 100; i++)
	{
        ZLOG_INFO("{0:d} x {1:d} = {2:d}", i, i , i * i);
		// my_log.my_logger->info("{0:d} x {1:d} = {2:d}", i, i , i * i);
		// usleep(100000);
	}
	
	return NULL;
}

void *func_2(void *arg)
{
 
	
	for(int i = 0; i < 100; i++)
	{
        ZLOG_INFO("{0:d} x {1:d} = {2:d}", i, i , i * i);
		// my_log.my_logger->info("{0:d} x {1:d} = {2:d}", i, i , i * i);
		// usleep(100000);
	}
	
	return NULL;
}


int main()
{
    ZLOG::getInstance("./log/", "test.log", 3);

	pthread_t thread_1, thread_2;
	
	pthread_create(&thread_1, NULL, func_1, NULL);
	pthread_create(&thread_2, NULL, func_2, NULL);
	
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	
	// my_log.destroy_logger();
	
	return 0;
	
}
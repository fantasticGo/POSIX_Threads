#include "pthread.h"
#include "stdio.h"
#include "errno.h"

int main(int argc, char *argv[])
{
	pthread_t thread;
	int status;
	status = pthread_join(thread, NULL);
	if(status != 0)
		fprintf(stderr, "error %d: %s\n", status, strerror(status));
	return status;
}

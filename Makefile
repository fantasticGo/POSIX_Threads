CFLAGS = -g -Wall 
CC = gcc
RM = /bin/rm -f

#all: alarm 

alarm: alarm.o
	${CC} ${CFLAGS} -o $@ $^

alarm.o: alarm.c errors.h
	${CC} ${CFLAGS} -c $^

alarm_fork: alarm_fork.o
	${CC} ${CFLAGS} -o $@ $^

alarm_fork.o: alarm_fork.c errors.h wait.h types.h
	${CC} ${CFLAGS} -c $^

alarm_thread: alarm_thread.o
	${CC} ${CFLAGS} -o $@ $^ -lpthread

alarm_thread.o: alarm_thread.c errors.h wait.h types.h
	${CC} ${CFLAGS} -c $^

thread_error:  thread_error.o
	${CC} ${CFLAGS} -o $@ $^ -lpthread

thread_error.o: thread_error.c  
	${CC} ${CFLAGS} -c $^
lifecycle:  lifecycle.o
	${CC} ${CFLAGS} -o $@ $^ -lpthread

lifecycle.o: lifecycle.c errors.h  
	${CC} ${CFLAGS} -c $^


clean:
	${RM} *.o 

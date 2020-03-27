CFLAGS = 
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

clean:
	${RM} *.o alarm

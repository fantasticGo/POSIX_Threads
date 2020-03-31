#include "errors.h"
#include "wait.h"
#include "types.h"

int main(int argc, char *argv[])
{
	int statys;
	int seconds;
	char line[128];
	char message[64];
	pid_t pid;

	while(1)
	{
		printf( "Alarm> " );
		if( fgets( line, sizeof( line ), stdin ) == NULL )
			exit( 0 );

		if( sscanf( line, "%d %64[^\n]", &seconds, message ) < 2 )
		{
			fprintf( stderr, "Bad command\n" );
		}
		else
		{
			pid = fork();
			if(pid == (pid_t)-1)
				errno_abort("Fork");
			if(pid == (pid_t)0)
			{
				printf("I am the chaild process, my process ID is %d\n", getpid());
				sleep( seconds );
				printf( "(%d) %s\n", seconds, message );
				exit(0);
			}
			else
			{
				do
				{
					printf("I am the parent process, my process ID is %d\n", getpid());
					pid = waitpid((pid_t)-1, NULL, WNOHANG);
					printf("In waitpid\n");
					if(pid == (pid_t)-1)
						errno_abort("Wait for child");
				}while(pid != (pid_t)0);   //don`t understand this. The first check pid will eq 0, becasue child process is sleep not exit,
				                           //and parent will execute the input part. How the parent process recovery zombie process? 
										   //Answer: 
			}
		}
	}
}

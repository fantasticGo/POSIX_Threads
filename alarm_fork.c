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
				sleep( seconds );
				printf( "(%d) %s\n", seconds, message );
				exit(0);
			}
			else
			{
				do
				{
					pid = waitpid((pid_t)-1, NULL, WNOHANG);
					if(pid == (pid_t)-1)
						errno_abort("Wait for child");
				}while(pid != (pid_t)0);
			}
		}
	}
}

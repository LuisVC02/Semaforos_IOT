#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <semaphore.h>

#define KEY 0xBE83

#define FIFO_NAME "/tmp/myfifo"
#define MAX_LEN 80

int main(int argc, char * argv[])
{
	char * buff;
	int  retval;
	int  shm_id = shmget(KEY, 4096, IPC_CREAT | 0666);
	sem_t * semaphore_1 = sem_open("Sem1", O_CREAT, 0666, 0);	
	if(shm_id == -1)
	{
		exit(-1);
	}

	printf("Shared memory created\n");
	buff = shmat(shm_id, 0, 0);
	for(;;)
	{
		fflush(stdin);
		char * str = fgets(buff, MAX_LEN, stdin);
		sem_post(semaphore_1);
		if(NULL == str)
		{
			break;
		}
	}
	retval = shmdt(buff);
	if(retval == 0)
	{
		printf("Memory dettached\n");
	}
	return 0;
}

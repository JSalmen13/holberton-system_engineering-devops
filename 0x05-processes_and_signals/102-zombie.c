#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * infinite_while - infinite loop
 * Return: 0
 */

int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - zombie process
 * Return: 0
 */

int main(void)
{
	pid_t zombie;
	int z = 0;

	while(z < 5)
	{
		zombie = fork();
		if (zombie <= 0)
			exit(0);
		printf("Zombie process created, PID: %d\n", zombie);
        z++;
	}
	infinite_while();
	return (0);
}

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv, char **env)
{
	int i;

	i = 0;
	char *s;
	while (env[i])
	{
		if (!strncmp(env[i], "USER=", 5))
		{
			s = strdup(env[i]);
			break;
		}
		i++;
	}
	s = strrchr(s, '=');
	s++;
	printf("%s\n", s);
	i = -1;
	while (s[++i])
		s[i] -= 32;
	while (1)
	{
		printf("\e[0;32mLOCK YOUR SCREEN %s\e[0m\n",s);
		usleep(100);
		printf("\e[0;31mLOCK YOUR SCREEN %s \e[0m\n", s);
		usleep(100);
		printf("\e[0;33mLOCK YOUR SCREEN %s \e[0m\n", s);
		usleep(100);
		printf("\e[0;34mLOCK YOUR SCREEN %s \e[0m\n",s);
		usleep(100);
		printf("\e[0;35mLOCK YOUR SCREEN %s\e[0m\n", s);
		usleep(100);
		printf("\e[0;36mLOCK YOUR SCREEN %s\e[0m\n", s);
		usleep(100);
		printf("\e[0;37mLOCK YOUR SCREEN %s \e[0m\n",s);
		usleep(100);
		printf("\e[0;30mLOCK YOUR SCREEN %s\e[0m\n", s);
		usleep(100);
		printf("\e[0;28mLOCK YOUR SCREEN %s\e[0m\n", s);
		usleep(100);
	}
}
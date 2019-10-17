//
// Created by skullscript on 10/17/19.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../os_defs.h"

void module(char * line)
{
	#ifdef OS_WINDOWS
	char buff[128];
	memset(buff, 0, 128);
	if (line[strlen(line) -2] != '\r' && line[strlen(line) - 1] == '\n')
	{
		printf("not window\n");
		if (line[strlen(line)-1] == '\n')
		{
			printf("new line found\n");
			strncat(buff, line, strlen(line) -1);
			strcat(buff, "\r\n");
		}
		else{
			strcat(buff, line);
			strcat(buff, "\r\n");
		}
	}
	strcpy(line, buff);
	if (strstr(line, "\r\n") != NULL)
	{
		printf("Line engind is CRLF\n");
	}
	#endif

	#if defined(OS_LINUX) || defined(OS_DARWIN)
	printf("Linux | UNIX \n");
	if (line[strlen(line) - 2] == '\r')//there is carriage return
	{
		line[strlen(line) - 2] = '\n';
		line[strlen(line) - 1] = '\0';
	}
	#endif
}
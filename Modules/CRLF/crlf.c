//
// Created by skullscript on 10/16/19.
//

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void module(char * line){
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
}

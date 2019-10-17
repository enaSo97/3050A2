//
// Created by skullscript on 10/15/19.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void module(char * line)
{
	char buff[128];
	memset(buff, 0, 128);
	for (int i = 0; i < strlen(line); i++)
	{
		if (i == 0 && line[i] != ':')
		{
			strcat(buff, "\"");
			buff[strlen(buff)] = line[i];
		}
		else if (line[i] == '\"')
		{
			strcat(buff, "\\");
			strcat(buff, "\"");
		}
		else if(i == strlen(line) - 1)
		{
			strcat(buff, "\"");
		}
		else{
			buff[strlen(buff)] = line[i];
		}
	}
	strcat(buff, "\n");
	strcpy(line, buff);
}
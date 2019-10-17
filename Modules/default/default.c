//
// Created by skullscript on 10/15/19.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void module(char * fileName, int line_no){
	char buffer[128];
	memset(buffer, 0, 128);
	//char * buffer = malloc(sizeof(char)*(strlen(fileName)+5));
	if (line_no < 10)
	{
		sprintf(buffer, "%d  :", line_no);
		strcat(buffer, fileName);
		strcpy(fileName, buffer);
	}
	else if (line_no >= 10 && line_no < 100)
	{
		sprintf(buffer, "%d :", line_no);
		strcat(buffer, fileName);
		strcpy(fileName, buffer);
	}
	else if (line_no > 100)
	{
		sprintf(buffer, "%d :", line_no);
		strcat(buffer, fileName);
		strcpy(fileName, buffer);
	}
}
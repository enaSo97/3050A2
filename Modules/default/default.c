//
// Created by skullscript on 10/15/19.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void default_prepend(char * fileName, int line_no){
	//printf("DEBUG: in the default .so function\n\n");
	//printf("line: %s\n", fileName);
	char buffer[128];
	memset(buffer, 0, 10);
	//char * buffer = malloc(sizeof(char)*(strlen(fileName)+5));
	if (line_no < 10)
	{
		sprintf(buffer, "%d  :", line_no);
		strcat(buffer, fileName);
		strcpy(fileName, buffer);
	}
}
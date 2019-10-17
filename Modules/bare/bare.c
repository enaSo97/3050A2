//
// Created by skullscript on 10/16/19.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void module(char * line){
	if (line[strlen(line) - 2] == '\r')//there is carriage return
	{
		line[strlen(line) - 2] = '\n';
		line[strlen(line) - 1] = '\0';
	}
}
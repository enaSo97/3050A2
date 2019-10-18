//
// Created by skullscript on 10/15/19.
//
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include"../../os_defs.h"

void module(char * content)
{
	for (int i = 0; i < strlen(content); i++)
	{
		content[i] = toupper(content[i]);
	}
	//printf("::%s::\n", content);
}

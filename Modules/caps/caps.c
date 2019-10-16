//
// Created by skullscript on 10/15/19.
//
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

void convert_to_upper(char * content)
{
	printf("\nmodule convert to upper\n");
	for (int i = 0; i < strlen(content); i++)
	{
		content[i] = toupper(content[i]);
	}
	//printf("::%s::\n", content);
}

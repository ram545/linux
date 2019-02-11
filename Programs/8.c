/**********************************************************************
* FILENAME:        8.c

* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 02/11/2019
* SUBMISSION DATE: 02/11/2019

**********************************************************************/

#include<stdio.h>
#include<stdlib.h>

int i=0;


int main(){
	int j;
	static int k;
	char *str = (char)malloc(10*sizeof(char));
	free(str);
	return 0;
}



/*
	Observation :
	stack segment - j
	Memory mapped segment - str
	BSS (Block seperated by symbol) segment - k
	data segment - i
*/
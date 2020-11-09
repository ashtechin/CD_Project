#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include <unistd.h>
symbtbl *st=NULL;


symbtbl *putsymb(char *column,char *table, int type) {
	symbtbl *ptr;
	if((ptr=(symbtbl *)(malloc(sizeof(symbtbl))))==NULL) {
		return(NULL); 
	}
	ptr->column = strdup(column);
	ptr->table = strdup(table);
	ptr->type = type;
printf("Row #%d is correct \n columns: %s\n tables: %s\n\n ",type,strdup(column),strdup(table));
FILE *fileptr;
char filename[] = "results.txt";
fileptr = fopen(filename,"a");
fprintf(fileptr,"line: %d \n columns: %s \n tables: %s\n",type,strdup(column),strdup(table));
fclose(fileptr);


	if(ptr->column==NULL) {
		free(ptr);
		return(NULL);
	}
	ptr->type=type;
	ptr->next=st;
	st=ptr;
	return ptr;
}

symbtbl *getsymb(char *column) {
	symbtbl *ptr;
	for(ptr=st;ptr!=NULL;ptr=ptr->next)
		if(!strcmp(ptr->column,column))
		   return ptr;

	return(NULL);
}

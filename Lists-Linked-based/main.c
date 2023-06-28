#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

void display(ListEntry);

int main(){
    List l;
    int i=0;
    printf("Hello World\n");
    CreateList(&l);
    InsertList(0,5,&l);
    InsertList(1,22,&l);
    //InsertList(2,39,&l);
    //InsertList(3,110,&l);
    DeleteList(1,&i,&l);
    ReplaceList(0,88,&l);
    //RetrieveList(1,&i,&l);
    printf("List size is : %d\n",ListSize(&l));
    TraverseList(&l,&display);
    printf("%d\n",ListFull(&l)); 
    //getchar();
    return 0;
}

void display(ListEntry e){
    printf("List entry is: %d\n",e);
}
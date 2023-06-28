#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

void CreateList(List *pl){
    pl -> current = NULL;
    pl -> currentpos = 0;
    pl -> size = 0;    
}

int ListEmpty(List *pl){
    return pl->size==0;
}

int ListFull(List *pl){
    (void) pl;
    return 0;
}

int ListSize(List *pl){
    return pl->size;
}

void InsertList(int pos, ListEntry e, List *pl){
    Listnode *pe;
    pe = (Listnode*)malloc(sizeof(Listnode));
    pe -> entry = e;
    pe -> next = NULL;
    pe -> prev = NULL;
    if(pos==0 && pl->size){                                 //At the beggining             
        for(; pl->currentpos; pl->currentpos--){
            pl->current = pl->current->prev;
        }
        pe->next = pl->current;
        pl->current->prev = pe;
    }
    else if(pos!=0 && pos == pl->size){                     //At the end
        for(;pl->currentpos != pos-1;pl->currentpos++){
            pl->current = pl->current->next;
        }
        pl->current->next = pe;
        pe->prev = pl->current;
        pl->currentpos++;   
    }
    else if(pos!=0 && pos<pl->size){                        //At the middle
        if(pos <= pl->currentpos){
            for(; pl->currentpos > pos; pl->currentpos--){
                pl->current = pl->current->prev;
            }   
        }
        else{
            for(;pl->currentpos < pos;pl->currentpos++){
                pl->current = pl->current->next;
            }
        }
        pe -> prev = pl ->current->prev;
        pe -> next = pl -> current;
        pe -> prev -> next = pe;
        pe -> next -> prev = pe;
    }
    pl->current = pe;                                       //Also works with empty list
    pl -> size++;
}

void DeleteList(int pos, ListEntry *pe, List *pl){
    Listnode *tmp;
    if(pos==0 && pl->size){                                 //At the begining               
        for(; pl->currentpos; pl->currentpos--){
            pl->current = pl->current->prev;
        }
        tmp = pl->current;
        pl->current = pl->current->next;
        pl->current->prev =NULL;
    }
    else if(pos!=0 && pos == pl->size-1){                     //At the end
        for(;pl->currentpos < pos;pl->currentpos++){
            pl->current = pl->current->next;
        }
        tmp = pl->current;
        pl->current = pl->current->prev;
        pl->current->next = NULL;
        pl->currentpos--;
    }
    else if(pos!=0 && pos<pl->size){                        //At the middle
        if(pos <= pl->currentpos){
            for(;pl->currentpos > pos;pl->currentpos--){
                pl->current = pl->current->prev;
            }   
        }
        else{
            for(;pl->currentpos < pos;pl->currentpos++){
                pl->current = pl->current->next;
            }
        }
        tmp = pl->current;
        pl->current->next->prev = pl->current->prev;
        pl->current->prev->next = pl->current->next;
        pl->current = pl->current->next;
    }
    *pe = tmp->entry;
    free(tmp); 
    pl->size--;
}

void DestroyList(List *pl){
    Listnode *tmp;
    for(;pl->currentpos >= 1; pl->currentpos--){
        pl->current = pl->current->prev;
    }
    tmp = pl->current;
    while(pl->current){
        tmp= pl->current->next;
        free(pl->current);
        pl->current= tmp;
    }
    pl->size= 0;
    pl->currentpos= 0;
}

void TraverseList(List *pl, void (*pf)(ListEntry)){
    Listnode *tmp = pl->current;
    int cpostmp = pl->currentpos;
    for(;cpostmp >= 1; cpostmp--){
        tmp = tmp->prev;
    }
    while(tmp){
        (*pf)(tmp->entry);
        tmp = tmp->next;
    }
}

void RetrieveList(int pos, ListEntry *pe, List *pl){
   if(pos <= pl->currentpos){
        for(;pl->currentpos > pos;pl->currentpos--){
            pl->current = pl->current->prev;
        }           
    }
    else{
        for(;pl->currentpos < pos;pl->currentpos++){
            pl->current = pl->current->next;
        }
    }
    *pe = pl->current->entry; 
}

void ReplaceList(int pos, ListEntry e, List *pl){
   if(pos <= pl->currentpos){
        for(;pl->currentpos > pos;pl->currentpos--){
            pl->current = pl->current->prev;
        }           
    }
    else{
        for(;pl->currentpos < pos;pl->currentpos++){
            pl->current = pl->current->next;
        }
    }
    pl->current->entry = e; 
}
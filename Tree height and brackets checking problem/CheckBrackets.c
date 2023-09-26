#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAXSTACK    100001

typedef struct stack{
    char ch[MAXSTACK];
    int idx[MAXSTACK];
    int s_pointer;
}Stack;

int Check_Brackets(char*);
void CreateStack(Stack*);
void Push(char , Stack*, int);
char Pop(Stack*);
int StackTop(Stack*); 
int Empty(Stack*);

 int main() {
    char input[100001];
    int x ;
    scanf("%s", input);
    x = Check_Brackets(input);
    if(x==0){
        printf("Success");
    }else{
        printf("%d",x);
    }
    
    return 0;
}

int Check_Brackets(char* s){
    int i, e;
    Stack stack;
    CreateStack(&stack);
    char popped;

    for(i=0; s[i]!=NULL; i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            Push(s[i], &stack, i+1);
        }else if(s[i]==')' || s[i]=='}' || s[i]==']'){
            e = Empty(&stack);
            if (e) {
                return i+1;
            }
            popped = Pop(&stack);
            if(s[i]==')' && popped!='('){
                return i+1;
            }
            else if(s[i]=='}' && popped!='{'){
                return i+1;
            }
            else if(s[i]==']' && popped!='['){
                return i+1;
            }
        }
    }
    e = Empty(&stack);
    if(e){
        return 0;
    }else{
        return StackTop(&stack);
    }
}

void CreateStack(Stack *s){
    s->s_pointer=0;
}

void Push(char c, Stack* stack, int i){
    stack->ch[stack->s_pointer] = c;
    stack->idx[stack->s_pointer] = i;
    stack->s_pointer++;
}

char Pop(Stack* stack){
    char c;
    stack->s_pointer--;
    c = stack->ch[stack->s_pointer];
    return c;
}

int StackTop(Stack* stack){
    return stack->idx[stack->s_pointer-1];
}

int Empty(Stack* stack){
    if(stack->s_pointer == 0){
        return 1;
    }else{
        return 0;
    }
}
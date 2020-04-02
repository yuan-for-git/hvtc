#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define INITMAXSIZE 20
#define  Elemtype char
typedef struct{
	int *base;
	int *top;
	int stacksize;
}stack_t_int;

typedef struct{
	Elemtype *base;
	Elemtype *top;
	int stacksize;
}stack_t;

void initstack(stack_t *stack){
	stack->base = malloc(sizeof(Elemtype)*INITMAXSIZE);
	if(!stack->base){
		printf("error");
		exit(-1);
	}
	stack->top = stack->base;
	stack->stacksize = INITMAXSIZE;
}
void initstack_int(stack_t_int *stack){
	stack->base = malloc(sizeof(int)*INITMAXSIZE);
	if(!stack->base){
		printf("error");
		exit(-1);
	}
	stack->top = stack->base;
	stack->stacksize = INITMAXSIZE;
}

void pop(stack_t * stack, Elemtype *e){
	if(stack->top == stack->base){
		printf("error");
		exit(-1);
	}
	*e = *(--stack->top);
}

void pop_int(stack_t_int * stack, int *e){
	if(stack->top == stack->base){
		printf("error");
		exit(-1);
	}
	*e = *(--stack->top);
}
void push(stack_t * stack, Elemtype e){
	if(stack->top - stack->base >=stack->stacksize){
		stack->base = (Elemtype *)realloc(stack->base,sizeof(Elemtype)*(stack->stacksize+10));
		if(!stack->base){
			printf("error");
			exit(-1);
		}
		stack->stacksize = stack->stacksize+10;
		
	}
	*stack->top=e;
	stack->top++;
	
}

void push_int(stack_t_int * stack, int e){
	if(stack->top - stack->base >=stack->stacksize){
		stack->base = (Elemtype *)realloc(stack->base,sizeof(int)*(stack->stacksize+10));
		if(!stack->base){
			printf("error");
			exit(-1);
		}
		stack->stacksize = stack->stacksize+10;
		
	}
	*stack->top=e;
	stack->top++;
	
}
int isempty(stack_t * stack){
	if(stack->top == stack->base){
		return 1;
	}
	else{
		return 0;
	}
	
}
Elemtype gettop(stack_t * stack){
	
	if(stack->top == stack->base){
		return -1;
	}
	else{
		Elemtype a= *(--stack->top);
		stack->top++;
		return a;
		
	}
	
}

int gettop_int(stack_t_int *stack){
	
	if(stack->top == stack->base){
		return -1;
	}
	else{
		int a= *(--stack->top);
		stack->top++;
		return a;
		
	}
	
}

int yun(int a,int b,char theta)
{
    int c;
	printf("(%d:%d)",a,b);
    switch(theta)
    {
    case '+':
        c=a+b;
        break;
    case '-':
        c=a-b;
        break;
    case '*':
        c=a*b;
        break;
    case '/':
        c=a/b;
        break;
    }
    return c;
}

int in(char c)//ÅÐ¶ÏcÊÇ·ñÎª²Ù×÷·û
{
    switch(c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
    case '#':
        return 1;
        break;
    default:return 0;
    }
}
char provir(char a,char b){
	switch(a){
	case '+':
	case '-':
		switch(b){
			case '+':
			case '-':
			case ')':
			case '#':
				return '>';
			case '*':
			case '/':
			case '(':
				return '<';
			
		
		}
	case '*':
	case '/':
		switch(b){
			case '+':
			case '-':
			case ')':
			case '#':
				
				return '>';
			case '*':
			case '/':
			case '(':
				return '<';			
		}
	case '(':
		switch(b){
			case '+':
			case '-':
			case '*':
			case '/':
			case '(':
				return '<';
			case ')':
				return '=';
			case '#':
				return '>';
		
		}
	case ')':
		switch(b){
			case '+':
			case '-':
			case '*':
			case '/':
			case ')':
			case '#':
				return '>';
		
		}
	case '#':
		switch(b){
			case '+':
			case '-':
			case '*':
			case '/':
			case ')':
				
				return '<';
		
		}

	}
	return '1';
}

int main(void){
	stack_t optr;
	stack_t_int opnd;

	char e,c;
	char t[100];
	int i=0;
	int a=0,b=0,d=0,sum=0;
	memset(t,'\0',100);
	initstack(&optr);
	initstack_int(&opnd);
	push(&optr,'#');
	fflush(stdin);

	while((c=getchar())!='#'||gettop(&optr) !='#'){
		if(!in(c)){			
			t[i++] = c;
			
		}
		else{
			d=atoi(t);
			printf("(%d)",d);
			push_int(&opnd,d);
				
			i=0;
			memset(t,'\0',100);
			switch(provir(gettop(&optr),c)){
			case '<': push(&optr,c);break;
			case '=': push(&optr,c);break;
			case '>': pop(&optr,&e);pop_int(&opnd,&a);pop_int(&opnd,&b);
			
				sum=yun(a,b,e);
				printf("sum=%d",sum);
				
				push_int(&opnd,sum);
				printf("('%d')",gettop_int(&opnd));
				push(&optr,c);
				
		
				break;
			default:
				return -1;
			}
		}
		
	}
	
	return 0;
}
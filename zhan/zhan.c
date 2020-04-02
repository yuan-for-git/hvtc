#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define INITMAXSIZE 20
typedef struct zuo{
int x,y;
}zuo_t;
#define  Elemtype zuo_t
#define MAX_ROW  12
#define MAX_COL  14

int maze[12][14] = {
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1,
     1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1,
     1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1,
     1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1,
     1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1,
     1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1,
     1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1,
     1, 0, 0, 0, 0, 1 ,0 ,0, 0 ,0 ,1 ,0 ,1 ,1,
     1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1,
     1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
 };

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

void pop(stack_t * stack, Elemtype *e){
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
int isempty(stack_t * stack){
	if(stack->top == stack->base){
		return 1;
	}
	else{
		return 0;
	}
	
}

#if 0
void main(void){
	stack_t s;
	int i;
	char a;
	char buf[100];
	initstack(&s);

	scanf("%s",buf);
	for(i =0;buf[i]!='\0';i++){
		switch(buf[i]){
		case '[':
		case '(':
		case '{':
			push(&s,buf[i]);
			break;
		case ']':
		case ')':
		case '}':
			pop(&s,&a);
			printf("%c\n",a);
			break;
		default:
			break;
		}
	}
	if(s.base == s.top){
		printf("true");
	}
	else{
		printf("false");
	}
}
#endif
#if 0
void main(void){
	stack_t s;
	char c;
	char ch ;
	initstack(&s);

	while((ch = getchar()) != EOF){
	
			switch(ch){
			case '#':
				if(s.base == s.top){
					break;
				}
				pop(&s,&c);
				break;
			case '@':
				while(s.base != s.top){
					pop(&s,&c);
				}
				break;
			default:
				push(&s, ch);
				
				break;
			}
		
		
	}
	while(s.base != s.top){
		pop(&s,&c);
		printf("%c",c);
	}
	system("pause");
}
#endif

#if 0
void visit(stack_t *s,int flag,zuo_t p){
	push(s,p);
	switch(flag){
		case 1: p.y++;push(s,p);maze[p.x][p.y]=2;break;
		case 2: p.x++;push(s,p);maze[p.x][p.y]=2;break;
		case 3: p.y--;push(s,p);maze[p.x][p.y]=2;break;
		case 4: p.x--;push(s,p);maze[p.x][p.y]=2;break;
	}
}
void main(void){
	stack_t s;
	int i,j=0;
	zuo_t prim={1,1};
	zuo_t tmp ={1,1};
	initstack(&s);
	maze[prim.x][prim.y] = 2;
	push(&s,tmp);
	while(!isempty(&s)){
		pop(&s,&tmp);
		if(tmp.x == MAX_ROW-2 && tmp.y == MAX_COL-2){
		
			break;
		}
		if(tmp.y +1 <= MAX_COL-2 && maze[tmp.x][tmp.y +1] == 0){
		
			visit(&s,1,tmp);
		}
		else if(tmp.x +1 <= MAX_ROW-2 && maze[tmp.x+1][tmp.y] == 0){
			
			visit(&s,2,tmp);
		}
		else if(tmp.y -1 >= 1 && maze[tmp.x][tmp.y -1] == 0){
			
			visit(&s,3,tmp);
		}
		else if(tmp.x - 1 >=1 && maze[tmp.x-1][tmp.y] == 0){
			
			visit(&s,4,tmp);
		}
	}
		printf("\n");
	for(i=0;i<MAX_ROW;i++){
		for(j=0;j<MAX_COL;j++){
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}

}
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#if 0
char* string_patten(char *t,char*s){
	char *tm=NULL;
	char *tn=NULL;
	while(*t){
		tm=t;
		tn=s;
		while(*tm++==*tn++){
			if(!*tn){
				return t;
			}
		}
		t++;
	}
	return NULL;
}
#endif
#if 0
char* string_patten(char *t,char*s){
	int tm=strlen(t);
	int tn=strlen(s);
	int i=0,j=0;
	for(i=0;i<tm-tn;i++){
		for(j=0;j<tn;j++){
			
			if(t[i+j] != s[j])
				break;
		}
	
		if(j==tn){
		
			return (t+i);
		}
	}
	return NULL;
}
#endif

#if 0
int main(void){
char t[]="hostname";
char s[]="na";
char *tmp=NULL;
tmp = string_patten(t,s);
printf("%s",tmp);
return 0;
}
#endif
#if 0
void findnext(char *pattern, char *next){
	int len=0;

	next[0]=0;
	len=strlen(pattern);
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			
		}
	}
}

#endif


void get_next(char *T,int *next,int len)
{
	int i,j;
	next[0] = 0;
	j=0;
	for(i=1;i<len;i++){
		while(j>0 && T[i] != T[j]){
			j=next[j-1];
		}
		if(T[i] == T[j]){
			j=j+1;
		}
		next[i] = j;
	}
	

}

void kmp(char *s,char *p){
	int slen=0,plen=0;
	int i,j=0;
	int *next=NULL;
	slen=strlen(s);
	plen=strlen(p);
	next =malloc(sizeof(int)*plen);
	get_next(p,next,plen);
	for(i=0;i<slen;i++){
		while(j>0 && s[i] != p[j]){
			j=next[j-1];
		}
		if(s[i] == p[j]){
			j++;
		}
		if(j ==plen){
			printf("idx=%d",i-plen+1);
			j=0;
		}
	}
	free(next);
}
int main(void){
	char t[]="hostnametnatna";
	char s[]="tna";
	kmp(t,s);
}

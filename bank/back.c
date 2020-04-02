#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct event{
	int ocur_time;
	int ntype;
}event_t;

typedef struct event_list{
	event_t event;
	struct event_list *next;
}event_list_t;

typedef struct client{
	int arrivaltime;
	int duration;
}client_t;

typedef struct client_list{
	client_t client;
	struct client_list *next;
}client_list_t;

typedef struct queue{
	client_list_t *front;
	client_list_t *rare;
}queue_t;

int queue_init(queue_t *queue){
	queue->front = queue->rare = (client_list_t *)malloc(sizeof(client_list_t));
	if(NULL == queue->front){
		printf("malloc failed");
		exit(-1);
	}
	queue->front->next = NULL;
	return 0;
}


int queue_empty(queue_t *queue){
	if(queue->front == queue->rare){
		return 1;
	}
	else{
		return 0;
	}
}
int queue_length(queue_t *queue){
	int i=0;
	client_list_t* qnode =NULL;
	if(queue->front == queue->rare){
		return 0;
	}
	qnode = queue->front;
	while(qnode->next){
		qnode = qnode->next;
		i++;
	}
	return i;

}
int queue_insert_tail(queue_t *queue, client_t client)
{
	client_list_t * qnode = (client_list_t *)malloc(sizeof(client_list_t));
	if(NULL == qnode){
		printf("malloc failed");
		exit(-1);
	}
	qnode->client = client;
	qnode->next = NULL;
	queue->rare->next = qnode;
	queue->rare = qnode;
	return 0;
}

int queue_del_head(queue_t *queue, client_t *client)
{
	client_list_t *q = NULL;
	if(queue_empty(queue)){
		printf("del failed");
		exit(-1);
	}
	q = queue->rare->next;
	client = &(q->client);
	queue->rare->next= q->next;
	free(q);
	return 0;
}

int queue_get_head(queue_t *queue, client_t *client)
{
	
	if(queue_empty(queue)){
		printf("del failed");
		exit(-1);
	}
	client = &(queue->front->next->client);
	return 0;
}

int event_init(event_list_t *head){
	head = (event_list_t *)malloc(sizeof(event_list_t));
	if(NULL == head){
		printf("malloc failed");
		exit(-1);
	}
	head->next = NULL;
	return 0;
}

int event_insert_order(event_list_t *head, event_t e){
	event_list_t *l =NULL;
	event_list_t *q= NULL;
	l = (event_list_t *)malloc(sizeof(event_list_t));
	if(NULL == l){
		printf("malloc failed");
		exit(-1);
	}
	q = head;	
	if(!q->next){
		l->event = e;
		head->next = l;
		l->next = NULL;
	}
	else{
		while(q->next&&e.ocur_time>=q->next->event.ocur_time){
			q = q->next;
		}
		l->event = e;
		l->next = q->next;
		q->next = l;
		
		
	}
	return 0;
}

int event_del_head(event_list_t *head, event_t *e){
	event_list_t *q=NULL;
	q=head->next;
	*e= q->event;
	head->next = q->next;
	free(q);
	return 0;

}

int event_empty(event_list_t *head){
	if(!head->next){
		return 1;
	}
	else{
		return 0;
	}

}

int event_get_head(event_list_t *head, event_t *e)
{
	
	if(event_empty(head)){
		printf("get failed");
		exit(-1);
	}
	e = &(head->next->event);
	return 0;
}

event_list_t ev;
event_t en;
client_t cn;
queue_t q[5];
int closetime=30;
int totaltime;
int customnum;

void openday(){
	int i =0;
	totaltime = 0;
	customnum=0;
	event_init(&ev);
	en.ocur_time=0;
	en.ntype=0;
	event_insert_order(&ev,en);
	for(i=1;i<=4;i++)
		queue_init(&(q[i]));

}


int queue_min(){
	int cur =1;
	int i=2;
	int len = queue_length(&(q[0]));
	for(i=2;i<=4;i++){
		if(len>queue_length(&(q[i]))){
			len=queue_length(&(q[i]));
			cur=i;
		}
	}
	return i;
}

void customarr(){
	int i;
	int  durtime = rand()%31;
	int intertime = rand()%5;
	event_t e;
	
	int t = en.ocur_time+intertime;
	e.ntype = 0;
	e.ocur_time=t;
	++customnum;
	
	if(t<closetime){
		event_insert_order(&ev,e);
	}
	i=queue_min();
	
	cn.arrivaltime= en.ocur_time;
	cn.duration=durtime;
	queue_insert_tail(&(q[i]), cn);
	printf("d");
	if(queue_length(&(q[i])) == 1){
		e.ntype = i;
		e.ocur_time=en.ocur_time+durtime;
		event_insert_order(&ev,e);
	}

}

void customdep(){
	int i;
	event_t e;
	i=en.ntype;
	queue_del_head(&(q[i]),&cn);
	totaltime+=en.ocur_time-cn.arrivaltime;
	if(!queue_empty(&(q[i]))){
		queue_get_head(&(q[i]),&cn);
		e.ntype = i;
		e.ocur_time=en.ocur_time+cn.duration;
		event_insert_order(&ev,e);
	}
}

int main(){
	event_t e;
	openday();
	printf("a");
	while(!event_empty(&ev)){
		
		event_del_head(&ev, &e);
		printf("b");
		if(e.ntype == 0){
			customarr();
			printf("1c");
		}
		else{
			customdep();
			printf("2c");
		}
	}
	printf("average time:%f",(float)totaltime/customnum);
	return 0;
}

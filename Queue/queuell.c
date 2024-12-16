#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  int data;
  struct node* next;
}node;

typedef struct queue{

  node* front;
  node* rear;
  
}queue;

node* create_node(int data);
queue* create_que();
void enque(queue* ptr,int data);
void deque(queue* ptr);
void printque(queue* ptr);
int peek(queue* ptr);

int main(){

  queue* q1=create_que();
  int option;
  
  
  do{
  
    printf("1-Insert value\n2-Delete value\n3-Peek\n4-Print\n0-EXİT\n\n");
    printf("Please enter the number\n");
    scanf("%d",&option);
    
    switch(option){
    
      case 1:
      
        int value;
        printf("Please enter the number you want to add\n");
        scanf("%d",&value);
        puts("");
        
        enque(q1,value);
        break;
        
      case 2:
      
        deque(q1);
        puts("");
        break;
      
      case 3:
        
        printf("The first value is: %d\n",peek(q1));
        puts("");
        break;
        
      case 4:
        
        printque(q1);
        puts("");
        break;
        
      default:
        break;
        
      }
      
    }while(option!=0);
  
  return 0;
}

node* create_node(int data){

  node* n=(node*)malloc(sizeof(node));
  n->data=data;
  n->next=NULL;
  
  return n;
  
}

queue* create_que(){

  queue* q=(queue*)malloc(sizeof(queue));
  
  q->front=NULL;
  q->rear=NULL;
  
  return q;
}
  
void enque(queue* ptr,int data){

  node* newNode=create_node(data);

  if(ptr->front==NULL && ptr->rear==NULL){

    ptr->front=newNode;
    ptr->rear=newNode;
    
  }else{
  
    ptr->rear->next=newNode;
    ptr->rear=ptr->rear->next;
    
  }
}

void deque(queue* ptr){

  if(ptr->front==NULL){
  
    printf("Queue is empty.\n");
    
  }else{
  
    node* temp=ptr->front;
    ptr->front=ptr->front->next;
    printf("%d popped.\n",temp->data);

    if(ptr->front==NULL){
    
      ptr->rear=NULL;
    }
    
    free(temp);
  }
}

void printque(queue* ptr){
  
  if(ptr->front==NULL){
  
    printf("Queue is empty.\n");
    return ;
  
  }  

  node* iter=ptr->front;
  
  while(iter!=NULL){
  
    printf("%d ",iter->data);
    iter=iter->next;
  }
  puts("");
  
}

int peek(queue* ptr){

  if(ptr->front==NULL){
  
    printf("Queue is empty.\n");
    return -1; 
  }
  
  return ptr->front->data;
}

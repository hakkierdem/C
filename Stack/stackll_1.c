#include <stdio.h>
#include <stdlib.h>

typedef struct stnode{

  int data;
  struct stnode* next;

}stnode;

void push(stnode** ptr,int data);
int pop(stnode** ptr);
void display(stnode* ptr);

int main(){

  stnode* iter=NULL;
  
  for(int i=1;i<=8;i++){
  
    push(&iter,i*10);
  
  }
  
  printf("%d is popped.\n",pop(&iter));
  printf("%d is popped.\n",pop(&iter));
  
  display(iter);

  return 0; 
}

void push(stnode** ptr,int data){

  stnode* new;
  
  new=(stnode*)malloc(sizeof(stnode));
  new->data=data;
  new->next=(*ptr);
  *ptr=new;
}

int pop(stnode** ptr){

  stnode* temp=(*ptr);
  int data=temp->data;
  
  if(ptr==NULL){
  
    printf("Stack is empty.\n");
  }

  *ptr=(*ptr)->next;
  free(temp);
  return data;

}


void display(stnode* ptr){

  stnode* temp=ptr;

  while(temp!=NULL){
  
    printf("%d ",temp->data);
    temp=temp->next;
    
  }
  puts("");
  
}



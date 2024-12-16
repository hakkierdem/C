#include <stdio.h>
#include <stdlib.h>

typedef struct stnode{

  int data;
  struct stnode* next;

}stnode;

int pop(stnode* ptr);
void push(stnode** ptr,int data);
void display(stnode* ptr);

int main(){

  stnode* start=NULL;

  for(int i=1;i<=8;i++){
  
    push(&start,i*10);
    
  }
  
  printf("%d is popped.\n",pop(start));
  printf("%d is popped.\n",pop(start));
  
  display(start);
  
  return 0;
  
}

void push(stnode** ptr,int data){

  stnode* new=(stnode*)malloc(sizeof(stnode));
  new->data=data;
  new->next=NULL;

  if((*ptr)==NULL){
  
    *ptr=new;
   
  }else{

    stnode* temp=(*ptr);

    while(temp->next!=NULL){
    
      temp=temp->next;

    }
  
    temp->next=new;
  
  }
  
}

int pop(stnode* ptr){

  int data;
  stnode* temp=ptr;

  if(ptr==NULL){
  
    printf("Stack is empty.\n");
    return -1; 
  
  }else if(ptr->next==NULL){
  
    data=ptr->data;
    ptr=NULL;
    free(temp);
    return data;

  }else{
  
    while(ptr->next->next!=NULL){
    
      ptr=ptr->next;
    }
    
    temp=ptr->next;
    data=temp->data;
    ptr->next=NULL;
    free(temp);
    return data;
  
  }

}

void display(stnode* ptr){

  if(ptr==NULL){
  
    printf("Stack is empty.\n");
    
  }
  
  while(ptr!=NULL){
  
    printf("%d ",ptr->data);
    ptr=ptr->next;
    
  }
  puts("");

}

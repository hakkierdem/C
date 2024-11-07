#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  int data;
  struct node* next;
  
}node;

node* sequantialadd(node* ptr,int x);
void display(node* ptr);

int main(){
  
  node* start=NULL;
  
  start=sequantialadd(start,1);
  start=sequantialadd(start,5);
  start=sequantialadd(start,3);
  start=sequantialadd(start,4);
  
  display(start);

  return 0;
}

node* sequantialadd(node* ptr,int x){

  node* newNode=(node*)malloc(sizeof(node));
  newNode->data=x;
  newNode->next=NULL;
  
  if(ptr==NULL){
  
    return newNode;
  
  }else if(ptr->next==NULL){
  
    if(ptr->data > x){
    
      newNode->next=ptr;
      return newNode;
      
    }else if(ptr->data < x){
    
      ptr->next=newNode;
    }
  
  }else{
  
    node* temp=ptr;
  
    while(temp->next != NULL && temp->next->data < x){
      
      temp=temp->next;
    
    }
    
    newNode->next=temp->next;
    temp->next=newNode;
    
  }
 
  return ptr;
 
}

void display(node* ptr){

  while(ptr!=NULL){
  
    printf("%d ",ptr->data);
    ptr=ptr->next; 
  }
  puts("");
}

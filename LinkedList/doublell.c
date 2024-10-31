#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  struct node* back;
  int data;
  struct node* next;
  
}node;

void add(node* ptr);
void display(node* ptr);

int main(){

  node* start=(node*)malloc(sizeof(node));
  start->back=NULL;
  start->data=1;
  start->next=NULL;
  
  add(start);
  add(start);

  display(start);

  return 0;

}

void add(node* ptr){

  static int num=2;

  while(ptr->next!=NULL){
  
    ptr=ptr->next;
    
  }
  
  node* newNode=(node*)malloc(sizeof(node));
  newNode->back=ptr;
  newNode->data=num++;
  newNode->next=NULL;
  
  ptr->next=newNode;

}

void display(node* ptr){

  while(ptr!=NULL){
  
    printf("%d ",ptr->data);
    ptr=ptr->next;
  
  }
  puts("");
  
}


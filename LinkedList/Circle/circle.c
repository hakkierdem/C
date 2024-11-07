#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  int data;
  struct node* next;
  
}node;

void addLast(node* ptr);
void addFirst(node** ptr);
void display(node* ptr);

int main(){

  node* start=(node*)malloc(sizeof(node));
  start->data=1;
  start->next=start;
  
  addLast(start);
  addLast(start);
  addFirst(&start);
  addFirst(&start);
  
  
  display(start);


  return 0;

}

void addLast(node* ptr){

  static int num=2;
  
  node* newNode=(node*)malloc(sizeof(node));
  newNode->data=num++;
  newNode->next=ptr;

  node* temp=ptr;
  
  while(temp->next!=ptr){
  
    temp=temp->next;
  }
  
  temp->next=newNode;

}

void addFirst(node** ptr){
  
  static int num=-1;

  node* newNode=(node*)malloc(sizeof(node));
  newNode->data=num--;
  newNode->next=NULL;
  
  node* temp=(*ptr);

  while(temp->next!=(*ptr)){
  
    temp=temp->next;
  }
  
  temp->next=newNode;
  newNode->next=(*ptr);
 
  *ptr=newNode;
 
}

void display(node* ptr){

  node* temp=ptr;

  while(temp->next!=ptr){
  
    printf("%d ",temp->data);
    temp=temp->next;
    
  }
  puts("");

}

#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  int data;
  struct node* next;
}node;

void lenght(node* ptr);

int main(){
  
  node* start=(node*)malloc(sizeof(node));
  
  start->data=10;
  start->next=(node*)malloc(sizeof(node));
  
  start->next->data=20;
  start->next->next=(node*)malloc(sizeof(node));
  
  lenght(start);

  return 0;
}

void lenght(node* ptr){

  int count=0;
  node* temp=ptr;

  while(temp->next!=NULL){
    
    temp=temp->next;
    count++;
  }

  printf("%d\n",count);
}

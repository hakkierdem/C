#include <stdio.h>
#include <stdlib.h>


typedef struct node{

  int data;
  struct node* next;
  
}node;

void add(node* ptr);
void display(node* ptr);

int main(){
  
  int lenght;
  scanf("%d",&lenght);
  
  node* start=(node*)malloc(sizeof(node));
  start->data=1;
  start->next=NULL;
  
  for(int i=0;i<lenght;i++){
  
    add(start);
    
  }
  
  display(start);
  
  return 0;
}

void add(node* ptr){

  static int num=2;
  
  while(ptr->next!=NULL){

    ptr=ptr->next;
  }

  node* newNode=(node*)malloc(sizeof(node));
  newNode->data=num++;
  newNode->next=NULL;
  
  ptr->next=newNode;
  
}

void display(node* ptr){

  while(ptr->next!=NULL){
  
    printf("%d ",ptr->data);  
    ptr=ptr->next;
  }

  printf("\n");
  
}




#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  int data;
  struct node* next;
  
}node;

void display(node* ptr);
void deleteLast(node* ptr);
void deleteFirst(node** ptr);

int main(){
  
  node* start=(node*)malloc(sizeof(node));
  start->data=1;
  start->next=start;
  
  int num=2;
  
  for(int i=0;i<10;i++){
  
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=num++;
    newNode->next=NULL;
    
    node* temp=start;
    
    while(temp->next!=start){
    
      temp=temp->next;
      
    }
    
    newNode->next=temp->next;
    temp->next=newNode;

  }
  
  display(start);
  
  deleteLast(start);
  display(start);
  
  deleteFirst(&start);
  display(start);
  
  return 0;
}

void display(node* ptr){

    node* temp=ptr;
  
  while(temp->next!=ptr){
  
    printf("%d ",temp->data);
    temp=temp->next;
    
  }
  puts("");
}

void deleteLast(node* ptr){

  node* temp=ptr;

  if(temp->next!=ptr){
    
    node* pretemp=temp;
    temp=temp->next;
    
    while(temp->next!=ptr){
    
      pretemp=temp;
      temp=temp->next;
    
    }
    
    pretemp->next=temp->next;
    free(temp);

  }
}

void deleteFirst(node** ptr){

  node* temp=(*ptr);

  while(temp->next!=(*ptr)){
  
    temp=temp->next;
  
  }

  node* toDelete=*ptr;

  temp->next=(*ptr)->next;   
  *ptr=(*ptr)->next;
  
  free(toDelete);
  

}

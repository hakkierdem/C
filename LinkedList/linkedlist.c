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
  
  for(int i=0;i<lenght;i++){
  
    add(start);
    
  }
  
  display(start);
  
  return 0;
}

void add(node* ptr){

  static int num=1;
  
  while(ptr->next!=NULL){

    ptr=ptr->next;
  }

  ptr->next=(node*)malloc(sizeof(node));
  ptr->data=num++;
  
}

void display(node* ptr){

  while(ptr->next!=NULL){
  
    printf("%d ",ptr->data);  
    ptr=ptr->next;
  }

  printf("\n");
  
}




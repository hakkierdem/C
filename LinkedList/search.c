#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  int data;
  struct node* next;
}node;

int search(node* ptr,int num);
void add(node* ptr);

int main(){

  int answer;
  
  node* start=(node*)malloc(sizeof(node));
  
  for(int i=0;i<5;i++){
  
    add(start);
    
  }
  
  answer=search(start,7);
  
  printf("%d",answer);


  return 0;
}

int search(node* ptr,int num){
  
  while(ptr->next!=NULL){
  
    if(ptr->data==num){
    
      return 1;
    }
    
    ptr=ptr->next;
  }

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

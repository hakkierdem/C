#include <stdio.h>
#include <stdlib.h>

typedef struct stack{

  int top;
  int size;
  int* arr;
  
}stack;

stack* create(int size);
void push(stack* st,int val);
int pop(stack* st);
void display(stack* st);

int main(){

  stack* st1=create(2);

  display(st1);
  
  for(int i=0;i<6;i++){
  
    push(st1,i+1);
  }
  
  puts("");
  display(st1);
  puts("");
  
  printf("%d is popped.\n",pop(st1));
  printf("%d is popped.\n",pop(st1));
  printf("%d is popped.\n",pop(st1));
  
  return 0;
}

stack* create(int size){

  stack* st=(stack*)malloc(sizeof(stack));
  st->size=size;
  st->top=0;
  st->arr=(int*)malloc(sizeof(int) * st->size);

  return st;
}

void push(stack* st,int val){

  if(st->top >= st->size){
  
    stack* newst=create((st->size)*2);
    
    for(int i=0;i<st->size;i++){
    
      newst->arr[i]=st->arr[i];
      
    }
  
    st->size=newst->size;
    free(st->arr);
    st->arr=newst->arr;
  }
  
  st->arr[(st->top)++]=val;
  

}

int pop(stack* st){

  if(st->top==0){
  
    printf("Stack is empty.\n");
    return -1;
    
  }
  
  if(st->top<=(st->size)/2){
  
    int* arr=(int*)malloc(sizeof(int) * (st->size/2) );
    
    for(int i=0;i<st->top;i++){
    
      arr[i]=st->arr[i];
      
    }
    
    free(st->arr);
    st->arr=arr;
    st->size /= 2;
  }
  
  return st->arr[--(st->top)];
}

void display(stack* st){

  if(st->top==0){
  
    printf("Stack is empty.\n");
  
  }else{
  
    for(int i=0;i<st->top;i++){
    
      printf("%d ",st->arr[i]);
      
    }
    puts(""); 

  }
}

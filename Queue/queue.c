#include <stdio.h>
#include <stdlib.h>

typedef struct queue{

  int size;
  int* arr;
  int front;
  int rear;
  
}queue;

queue* create(int size);
void enque(queue* ptr,int value);
void deque(queue* ptr);
void printque(queue* ptr);
void edit(queue* ptr);
int peek(queue* ptr);

int main(){

  int option;
  
  do{
  
    printf("1-Create queue\n2-Insert value\n3-Delete value\n4-Peek\n5-Edit\n6-Print\n0-EXİT\n\n");
    printf("Please enter the number\n");
    scanf("%d",&option);
    
    switch(option){
    
      case 1:
      
        int size;
        printf("Please enter the size\n");
        scanf("%d",&size);
        puts("");
        
        queue* q1=create(size);
        break;
        
      case 2:
      
        int value;
        printf("Please enter the number you want to add\n");
        scanf("%d",&value);
        puts("");
        
        enque(q1,value);
        break;
        
      case 3:
      
        deque(q1);
        puts("");
        break;
      
      case 4:
        
        printf("The first value is: %d\n",peek(q1));
        puts("");
        break;
        
      case 5:
      
        edit(q1);
        printf("Queue edited\n");
        puts("");
        break;
        
      case 6:
        
        printque(q1);
        puts("");
        break;
        
      default:
        break;
        
      }
      
  }while(option!=0);
  
  return 0; 
}

queue* create(int size){

  queue* q1=(queue*)malloc(sizeof(queue));
  q1->size=size;
  q1->arr=(int*)malloc(sizeof(int) * size);
  q1->front=0;
  q1->rear=0;
  
  return q1;
  
}

void enque(queue* ptr,int value){

  if(ptr->front==0 && ptr->rear==0){
  
    ptr->arr[ptr->rear++]=value;
    
  }else{
    
    if(ptr->rear < ptr->size){
    
      ptr->arr[ptr->rear++]=value;
      
    }else{
    
      int* new=(int*)malloc(sizeof(int) * ptr->size * 2 );
      
      for(int i=0;i < (ptr->rear - ptr->front);i++){
      
        new[i]=ptr->arr[ptr->front+i];
        
      }
      
      ptr->rear=ptr->rear - ptr->front;
      ptr->front=0;
      ptr->size=ptr->size * 2;
      
      free(ptr->arr);
      ptr->arr=new;
      
    }
  }
}

void deque(queue* ptr){

  if(ptr->front==0 && ptr->rear==0){
  
    printf("Queue is empty\n");
    
  }else{
  
    if((ptr->rear - ptr->front) <= (ptr->size / 4)){
    
      int temp=ptr->arr[ptr->front++];
      printf("%d popped.\n",temp);
    
      int* new=(int*)malloc(sizeof(int) * (ptr->size / 2));
      
      for(int i=0;i < (ptr->rear - ptr->front);i++){
      
        new[i]=ptr->arr[(ptr->front)+i];
        
      }
    
      ptr->rear=ptr->rear - ptr->front;
      ptr->front=0;
      ptr->size=ptr->size / 2;
      
      free(ptr->arr);
      ptr->arr=new;
    
    }else{
  
      int temp=ptr->arr[ptr->front++];
      printf("%d popped.\n",temp);
      
    }
  }
}

void printque(queue* ptr){

  for(int i=0;i<(ptr->rear - ptr->front);i++){
  
    printf("%d ",ptr->arr[ptr->front+i]);
    
  }
  puts("");
  
}

void edit(queue* ptr){

  if(ptr->front==0){
  
    return;
    
  }else{
  
    for(int i=0;i<(ptr->rear - ptr->front);i++){
    
      ptr->arr[i]=ptr->arr[(ptr->front)+i];
    }
    
    ptr->rear=ptr->rear - ptr->front;
    ptr->front=0;
  }
}


int peek(queue* ptr){

  if(ptr->front==0 && ptr->rear==0){
  
    printf("Queue is empty.\n");
    return -1;
    
  }else{
  
    return ptr->arr[ptr->front];
    
  }

}

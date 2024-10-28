#include <stdio.h>

void sort(int arr[],int size);
void merge(int arr1[],int arr2[],int size1,int size2);
void print(int arr1[],int arr2[],int size1,int size2);

int main(){

  int A[4]={1,4,6,9};
  int B[5]={2,3,5,7,8};

  merge(A,B,4,5);
  print(A,B,4,5);
  
  return 0;
}

void sort(int arr[],int size){

  int temp;

  for(int l=0;l<size-1;l++){
    
    for(int i=0;i<size-1;i++){
    
      if(arr[i]>arr[i+1]){
      
        temp=arr[i+1];
        arr[i+1]=arr[i];
        arr[i]=temp;
      }
  
    }
  }
}

void merge(int arr1[],int arr2[],int size1,int size2){

  int left=size1-1;
  int right=0;
  int temp;
  
  while(left>=0 && right<size2){
  
    if(arr1[left]>arr2[right]){

      temp=arr2[right];
      arr2[right]=arr1[left];
      arr1[left]=temp;
    
    }else{
    
      break;
    }
    
    left--;
    right++;
    
  }

  sort(arr1,size1);
  sort(arr2,size2);
  
}

void print(int arr1[],int arr2[],int size1,int size2){

  for(int i=0;i<size1;i++){
  
    printf("%d ",arr1[i]);
    
  }
  
  for(int i=0;i<size2;i++){
  
    printf("%d ",arr2[i]);
  
  }

  puts("");
  
}

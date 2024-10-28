#include <stdio.h>

void merge(int a[],int b[],int n,int m);
void sort(int arr[],int size);

int main(){

  int A[3]={1,4,5};
  int B[5]={0,3,6,8,9};
  
  merge(A,B,3,5);
  
}

void merge(int a[],int b[],int n,int m){

  int arr3[n+m];

  int left=0;
  int right=0;
  int index=0;
  
  while(left<n && right<m){
  
    if(a[left]>b[right]){
    
     arr3[index]=b[right];
      
      right++;
      index++;
      
    }else if(a[left]<b[right]){
    
      arr3[index]=a[left];
      
      left++;
      index++;
    }
  } 


  while(left<n){
    
    arr3[index++]=a[left++];
  
  }
    
  while(right<m){
    
    arr3[index++]=b[right++];
    
  }
  
  
    
  for(int i=0;i<n+m;i++){
  
    printf("%d ",arr3[i]);
    
  }
  puts("");
  
}



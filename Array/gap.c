#include <stdio.h>

void gapmerge(int arr1[],int arr2[],int n,int m);
void swap(int arr1[],int arr2[],int ind1,int ind2);

int main(){

  int a1[4]={1,3,4,7};
  int a2[3]={0,2,5};
  
  gapmerge(a1,a2,4,3);
  
  for(int i=0;i<4;i++){
  
    printf("%d ",a1[i]);
  }
  
  for(int i=0;i<3;i++){
  
    printf("%d ",a2[i]);
    
  }

  return 0;
}

void gapmerge(int arr1[],int arr2[],int size1,int size2){

  int len=size1+size2;
  int gap=(len/2)+(len%2);
  
  while(gap>0){
  
    int left=0;
    int right=left+gap;
    
    while(right<len){
    
      //arr1[] and arr2[]
      if(left<size1 && right>=size1){
      
        swap(arr1,arr2,left,(right-size1));
      
      //arr2[] and arr2[]
      }else if(left>=size1 && right>size1){
      
        swap(arr2,arr2,(left-size1),(right-size1));
      
      //arr1[] and arr1[]  
      }else{
      
        swap(arr1,arr1,left,right);
      }
  
    left++,right++;
    }  
    
    if(gap==(gap/2)+(gap%2)){
    
      break;
      
    }
    
    gap=(gap/2)+(gap%2);
  
  }

}

void swap(int arr1[],int arr2[],int ind1,int ind2){
  
  int temp;
  
  if(arr1[ind1]>arr2[ind2]){
  
    temp=arr2[ind2];
    arr2[ind2]=arr1[ind1];
    arr1[ind1]=temp;
    
  }
  
}
    
    

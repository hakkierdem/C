#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  struct node* left;
  int data;
  struct node* right;

}node;

node* add(node* ptr,int data);
void preorder(node* ptr);
void inorder(node* ptr);
void postorder(node* ptr);
int search(node* ptr,int key);
int max(node* ptr);
int min(node* ptr);
node* delete(node* ptr,int key);

int main(){

  node* tree=NULL;
  
  tree=add(tree,10);
  tree=add(tree,7);
  tree=add(tree,15);
  tree=add(tree,4);
  tree=add(tree,9);
  tree=add(tree,13);
  tree=add(tree,17);
  tree=add(tree,11);

  inorder(tree);
  puts("");
  
  tree=delete(tree,15);
  inorder(tree);
  puts("");
  
  return 0;
}

node* add(node* ptr,int val){

  if(ptr==NULL){
  
    node* newNode=(node*)malloc(sizeof(node));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data=val;
    return newNode;
    
  }
  
  if(ptr->data <= val){

    ptr->right=add(ptr->right,val);

  }else{
  
    ptr->left=add(ptr->left,val);
    
  }
  return ptr;
  
}
    
void preorder(node* ptr){

  if(ptr == NULL) return;
  
  printf("%d ",ptr->data);
  preorder(ptr->left);
  preorder(ptr->right);
  
}

void inorder(node* ptr){

  if(ptr == NULL) return;
  
  inorder(ptr->left);
  printf("%d ",ptr->data);
  inorder(ptr->right);

}

void postorder(node* ptr){

  if(ptr == NULL) return;
  
  postorder(ptr->left);
  postorder(ptr->right);
  printf("%d ",ptr->data);
}

int search(node* ptr,int key){
  
  if(ptr==NULL){
  
    return -1;
    
  }
  
  if(ptr->data == key){
  
    return 1;
    
  }
  
  if(ptr->data <= key){
  
    return search(ptr->right,key);
    
  }else{
  
    return search(ptr->left,key);
    
  }
  
}

int max(node* ptr){

  while(ptr->right!=NULL){
  
    ptr=ptr->right;
    
  }
  
  return ptr->data;
  
}

int min(node* ptr){

  while(ptr->left!=NULL){
  
    ptr=ptr->left;
    
  }
  
  return ptr->data;  
  
}

node* delete(node* ptr,int key){

  if(ptr==NULL) return ptr;
  
  if(ptr->data < key){ //deger buyuk
  
    ptr->right=delete(ptr->right,key);
    return ptr;
    
  }else if(ptr->data > key){ //deger kucuk
  
    ptr->left=delete(ptr->left,key);
    return ptr;
    
  }else{ //deger bulundu
  
    if(ptr->left==NULL && ptr->right==NULL){ //cocuk yok
    
      free(ptr);
      return NULL;
      
    }
    
    if(ptr->right!=NULL && ptr->left == NULL){ //tek cocuk sag
    
      node* temp=ptr->right;
      free(ptr);
      return temp;
      
    }else if(ptr->left!=NULL && ptr->right == NULL){ //tek cocuk sol
    
      node* temp=ptr->left;
      free(ptr);
      return temp;
      
    }else{ //iki cocuk
    
      int successor=min(ptr->right);
      ptr->data=successor;
      ptr->right=delete(ptr->right,successor);
      return ptr;
    }
    return ptr;
    
  }
}

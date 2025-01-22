#include <stdio.h>
#include <stdlib.h>

typedef struct node {

  struct node* left;
  struct node* right;
  int data;
}node;

node* createTree(int data);
void add(node** ptr,int data);
void inorder(node* ptr);
int search(node* ptr,int key);
int max(node* ptr);
int min(node* ptr);
void delete(node** ptr,int key);

int totalExternalNode(node* tree);

int main(){

  node* t1=createTree(10);
  add(&t1,7);
  add(&t1,15);
  add(&t1,13);
  add(&t1,9);
  add(&t1,4);
  add(&t1,11);
  add(&t1,17);
  
  inorder(t1);
  puts("");
  printf("%d ",search(t1,1));
  puts("");
  printf("Min: %d Max: %d",min(t1),max(t1));
  puts("");
  delete(&t1,15);
  inorder(t1);
  puts("");
  printf("%d\n",totalExternalNode(t1));
  
  return 0;
  
}

node* createTree(int data){

  node* tree=(node*)malloc(sizeof(node));
  tree->data=data;
  tree->left=NULL;
  tree->right=NULL;
  return tree;
}

void add(node** ptr,int data){

  if((*ptr)==NULL){
  
    *ptr=createTree(data);
    
  }else{
  
    if(data >= (*ptr)->data){
    
      add(&(*ptr)->right,data);
      
    }else if(data < (*ptr)->data){
    
      add(&(*ptr)->left,data);
    
    }
  }
  
}

void inorder(node* ptr){

  if(ptr==NULL) return;
  
  inorder(ptr->left);
  printf("%d ",ptr->data);
  inorder(ptr->right);
  
}

int search(node* ptr,int key){

  if(ptr==NULL) return -1;
  
  if(key > ptr->data){
  
    return search(ptr->right,key);
    
  }else if(key < ptr->data){
  
    return search(ptr->left,key);
    
  }else{
  
    return 1;
  }
  
}

int max(node* ptr){

  while(ptr->right != NULL){
  
    ptr=ptr->right;
  }
  return ptr->data;
}

int min(node* ptr){

  while(ptr->left != NULL){
  
    ptr=ptr->left;
  }
  return ptr->data;
}

void delete(node** ptr,int key){

  if((*ptr) == NULL) printf("The value is not in tree.\n");
  
  if(key > (*ptr)->data){
    
    delete(&(*ptr)->right,key);
    
  }else if(key < (*ptr)->data){
  
    delete(&(*ptr)->left,key);
    
  }else{ 
    
    if((*ptr)->left == NULL && (*ptr)->right == NULL){
    
      free((*ptr));
      
    }else if((*ptr)->left != NULL && (*ptr)->right == NULL){
    
      node* temp=*ptr;
      *ptr=(*ptr)->left;
      free(temp);

    }else if((*ptr)->right != NULL && (*ptr)->left == NULL){
    
      node* temp=*ptr;
      *ptr=(*ptr)->right;
      free(temp);
    
    }else{
    
      int successor=max((*ptr)->left);
      (*ptr)->data=successor;
      delete(&(*ptr)->left,successor);
    
    }
  
  }
}

int totalExternalNode(node* tree){

  int total=0;
  
  if(tree == NULL) return 0;
  
  if(tree->left == NULL && tree->right == NULL){
    
    return ++total;
  }

  total+=totalExternalNode(tree->left);
  total+=totalExternalNode(tree->right);

  return total;
}

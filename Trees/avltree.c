#include <stdio.h>
#include <stdlib.h>

typedef struct node {

  int data;
  struct node* left;
  struct node* right;
  int height;
}node;

node* createAVL(int data);
int height(node* tree);
int max(int a,int b);
int getBalance(node* tree);
node* leftRotate(node* tree);
node* rightRotate(node* tree);
node* insert(node* tree,int data);
void preorder(node* tree);
node* minValueNode(node* tree);
node* delete(node* tree,int data);

int main(){

  node* t1=NULL;
  
  t1=insert(t1,10);
  t1=insert(t1,20);
  t1=insert(t1,30);
  t1=insert(t1,40);
  t1=insert(t1,50);
  t1=insert(t1,25);
 
  preorder(t1);
  puts("");
  delete(t1,20);
  preorder(t1);
  puts("");
  
  return 0;
}

node* createAVL(int data){
  
  node* newNode=(node*)malloc(sizeof(node));
  newNode->data=data;
  newNode->left=NULL;
  newNode->right=NULL;
  newNode->height=1;
  
  return newNode; 
}

int height(node* tree){

  if(tree == NULL)
    return 0;
    
  return tree->height;
}

int max(int a,int b){

  return (a > b) ? a : b;
}

int getBalance(node* tree){

  if(tree == NULL)
    return 0;

  return height(tree->left)-height(tree->right);
}

node* leftRotate(node* tree){
  
  node* B=tree->right;
  node* X=B->left;

  B->left=tree;
  tree->right=X;
  
  tree->height=1 + max(height(tree->left),height(tree->right));
  B->height=1 + max(height(B->left),height(B->right));

  return B;

}

node* rightRotate(node* tree){
  
  node* B=tree->left;
  node* X=B->right;
  
  B->right=tree;
  tree->left=X;
  
  tree->height=1 + max(height(tree->left),height(tree->right));
  B->height=1 + max(height(B->left),height(B->right));
  
  return B;
  
}

node* insert(node* tree,int data){

  if(tree == NULL){
  
    return createAVL(data); 
  }

  if(data < tree->data){
  
    tree->left=insert(tree->left,data);
    
  }else if(data > tree->data){
  
    tree->right=insert(tree->right,data);
  
  }else{
  
    return tree;
  }
  
  tree->height=1 + max(height(tree->left),height(tree->right));
  
  int balance=getBalance(tree);

  if(balance > 1 && data < tree->left->data)
    return rightRotate(tree);
  
  if(balance < -1 && data > tree->right->data)
    return leftRotate(tree);
  
  if(balance > 1 && data > tree->left->data){
    tree->left=leftRotate(tree->left);
    return rightRotate(tree);
  }
  
  if(balance < -1 && data < tree->right->data){
    tree->right=rightRotate(tree->right);
    return leftRotate(tree);
  }
  
  return tree;
}

void preorder(node* tree){

  if(tree == NULL) return;

  printf("%d ",tree->data);
  preorder(tree->left);
  preorder(tree->right);
  
}

node* minValueNode(node* tree){

  node* temp=tree;
  
  while(temp->left != NULL){
  
    temp=temp->left;
  }
  
  return temp;
  
}
  
node* delete(node* tree,int data){

  if(tree == NULL){
  
    return tree;
    
  }
  
  if(data < tree->data){
  
    tree->left=delete(tree->left,data);
    
  }else if(data > tree->data){
  
    tree->right=delete(tree->right,data);
    
  }else{
  
    if(tree->left == NULL || tree->right == NULL){
    
      node* temp=tree->left ? tree->left : tree->right;
    
      if(temp == NULL){
      
        temp=tree;
        tree=NULL;
        
      }else
        *tree=*temp;
        
      free(temp);
    
    }else{
    
      node* successor=minValueNode(tree->right);
      
      tree->data=successor->data;
      
      tree->right=delete(tree->right,successor->data);
      
    }
    
    if(tree == NULL)
      return tree; 
    
    
    tree->height=1 + max(height(tree->right),height(tree->left));
    int balance=getBalance(tree);
    
    if(balance > 1 && getBalance(tree->left) >= 0){
      return rightRotate(tree);
    }
    
    if(balance > 1 && getBalance(tree->left) < 0){
      tree->left=leftRotate(tree->left);
      return rightRotate(tree);
    }
    
    if(balance < -1 && getBalance(tree->right) >= 0){
      tree->right=rightRotate(tree->right);
      return leftRotate(tree);
    }
    
    if(balance < -1 && getBalance(tree->right) < 0){
      return rightRotate(tree);
    }
    
    return tree;

  }  
}

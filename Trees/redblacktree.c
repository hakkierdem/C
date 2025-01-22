#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

#define MAX(a,b) (( (a) > (b) ) ? (a) : (b))

typedef struct node{

  int data;
  int color;
  struct node* left;
  struct node* right;
  struct node* parent;
}node;

struct node T_Nil_Node = {0,BLACK,NULL,NULL,NULL};

node* T_Nil=&T_Nil_Node;

node* createNode(int data);
node* grandparent(node* n);
node* uncle(node* n);
void leftRotate(node** root,node* n);
void rightRotate(node** root,node* n);
void insertFixUp(node** root,node* new);
void insert(node** root,int data);
int height(node* root);
void printTree(node* root);

int main(){

    node* root = T_Nil;
    int list[10] = {1, 3, 2, 5, 4, 7, 6, 9, 8, 10};
    for (int i = 0; i < 10; i++)
    {
        insert(&root, list[i]);
    }
    printTree(root);

  return 0;
}

node* createNode(int data){

  node* newNode=(node*)malloc(sizeof(node));
  newNode->data=data;
  newNode->color=RED;
  newNode->left=T_Nil;
  newNode->right=T_Nil;
  newNode->parent=T_Nil;
  
  return newNode;
}

node* grandparent(node* n){

  if(n != NULL && n->parent != NULL){
    return n->parent->parent;
  
  }else{
    return NULL;
  }
} 


node* uncle(node* n){

  node* g = grandparent(n);
  
  if(g == NULL){
    return NULL;
  }
  
  if(n->parent == g->left){
    return g->right;
  
  }else{
    return g->left;
  }
}

void leftRotate(node** root,node* n){
  
  node* y=n->right;
  n->right=y->left;
  
  if(y->left != T_Nil){
    y->left->parent = n;
  }
  
  y->parent=n->parent;
  
  if(n->parent == T_Nil){
    (*root)=y;
  }else if(n->parent->left == n){
    n->parent->left = y;
  }else{
    n->parent->right = y;
  }
  y->left = n;
  n->parent = y;
}

void rightRotate(node** root,node* n){

  node* y = n->left;
  n->left=y->right;
  
  if(y->right != T_Nil){
    y->right->parent = n;
  }
  
  y->parent = n->parent;
  
  if(n->parent == T_Nil){
    (*root)=y;
  
  }else if(n->parent->left == n){
    n->parent->left = y;
  
  }else{
    n->parent->right=y;
  }
  
  y->right = n;
  n->parent = y;
  
}

void insertFixUp(node** root,node* new){

  while(new->parent->color == RED){ //if red-red was found in the tree
    
    node* g=grandparent(new);
    node* u=uncle(new);
    
    if(g->left == new->parent){
    
      if(u->color == RED){
        
        u->color=BLACK;
        new->parent->color=BLACK;
        g->color=RED;
        new=g;
      
      }else{
      
        if(new == new->parent->right){
        
          new=new->parent;
          leftRotate(root,new);
        }
        
        new->parent->color=BLACK;
        g->color=RED;
        rightRotate(root,g);
      }
    
    }else{
    
      if(u->color == RED){
      
        u->color=BLACK;
        new->parent->color=BLACK;
        g->color=RED;
        new=g;
      
      }else{
        
        if(new == new->parent->left){
          
          new=new->parent;
          rightRotate(root,new);
        }
        
        new->parent->color=BLACK;
        g->color=RED;
        leftRotate(root,g);
      
      }
    } 
  }
  root[0]->color=BLACK;
}
    
void insert(node** root,int data){

  node* z = createNode(data); //new
  node* y = T_Nil;            //parent
  node* x = *root;            //root temp
         

  while(x != T_Nil){
    
    y = x;
    
    if(z->data < x->data){
      x = x->left;
    
    }else{
      x = x->right;
    }
    
  }
  
  z->parent=y;
  
  if(y == T_Nil){
    *root = z;
  
  }else if(z->data < y->data){
    y->left = z;
  
  }else{
    y->right = z;
  }
  
  z->left=T_Nil;
  z->right=T_Nil;
  z->color=RED;

  insertFixUp(root,z);
}


int height(node* root){

  int h=0;
  
  if(root != NULL){
  
    if(root == T_Nil){
      h=1;
    
    }else{
      int leftHeight=height(root->left);
      int rightHeight=height(root->right);
      
      h=MAX(leftHeight,rightHeight) + 1;
    }
  }
  
  return h;
  
}

void printTree(node* root){

  if(root == T_Nil)
    return;
    
  printTree(root->left);
  printf("%d ",root->data);
  printTree(root->right);
}


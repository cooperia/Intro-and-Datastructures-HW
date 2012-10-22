#include "avl.h"
#include <iostream>

avl::avl(){
  _root = NULL;
  _size = 0;
}

avl::~avl(){
  delete_tree(_root);
  _root = NULL;
  _size = 0;
}

void avl::insert(string data){
  avl_node* newnode = new avl_node();
  avl_node* cursor;
  avl_node* previous;
  int balance;
  newnode -> set_word(data);
  if(_root == NULL){
    _root = new avl_node();
    _root -> set_word(data);
    _root -> set_parent(NULL);
    _root -> set_balance(0);
  }
  else{
    avl_node* ins = search(data);
    if((ins -> get_word()) != data){
      if(data > (ins -> get_word())){
	ins -> set_rchild(newnode);
	newnode -> set_parent(ins);
	balance = 1+(ins -> get_balance());
	ins -> set_balance(balance);
      }
      else{
	ins -> set_lchild(newnode);
	newnode -> set_parent(ins);
	balance = (ins -> get_balance())-1;
	ins -> set_balance(balance);
      }
    }
    else{
      return;
    }
    while(1){
      if(ins -> get_balance() == 0){break;}
      cursor = ins;
      previous = cursor;
      if(cursor -> get_parent() == NULL){break;}
      cursor = cursor -> get_parent();
      if(cursor -> get_lchild() == previous){
	balance = (cursor -> get_balance()) -1;
	cursor -> set_balance(balance);
	if(cursor -> get_balance() == 0){break;}
      }
      else{
	balance = (cursor -> get_balance()) +1;
	cursor -> set_balance(balance);
	if(cursor -> get_balance() == 0){break;}
      }
 
      if(cursor -> get_balance() == -2 || cursor -> get_balance() == 2){
	rebalance(cursor);
	break;
      }
      ins = cursor;
    }

  }
}


void avl::print_tree(){
  string value;
   for(int j = 0; j < BST_ARRAY_SIZE; j++){
     a[j] = NULL;
   }
   bst_to_array(_root, 0);

   for(int i = 0; i < 31;i++){
     if(i == 1 || i == 3 || i==7 || i == 15){
       cout<<endl;
     }
     if(a[i] == NULL){
       cout<<"[    ]";
     }
     else{
       cout<<"["<<(a[i] -> get_word())<<", "<<(a[i] -> get_balance())<<"]";
     }
   }
   cout<<endl;
}

bool avl::is_element(string word){
  avl_node* test = _root;
  avl_node* current = _root;
  while(current != NULL){
    if(current -> get_word() == word){
      return true;
    }
    else if(current -> get_word() > word){
      current =  current -> get_lchild();
    }
    else if(current -> get_word() < word){
      current = current -> get_rchild();
    }
  }
  if(test != _root){
  }

  return false;
}


avl_node* avl::search(string data){
  avl_node* current = _root;
  while(1){
    if(current -> get_word() == data){return current;}
    if(current -> get_word() > data){
      if(current -> get_lchild() == NULL){
	return current;
      }
      else{
	current = current -> get_lchild();
      }
    }
    else{
      if(current -> get_rchild() == NULL){
	return current;
      }
      else{
      current = current -> get_rchild();
      }
    }
  }
}

void avl::bst_to_array(avl_node* n, int i){
  if(n == NULL) return;
  a[i] = n;
  int left = 2*(i)+1;
  int right = 2*(i)+2;
  bst_to_array(n -> get_lchild(), left);
  bst_to_array(n -> get_rchild(), right);
}

void avl::check(){
  cout<<"Root is "<<_root -> get_word()<<endl;
}

void avl::rebalance(avl_node* root){
  if(root -> get_balance() == -2){
    if((root -> get_lchild()) -> get_balance() == -1){
      leftleft(root);
    }
    else{
      leftright(root);
    }
  }
  else{
    if(((root -> get_rchild()) -> get_balance()) == 1){
      rightright(root);
    }
    else{
      rightleft(root);
    }
  }
}

void avl::leftleft(avl_node* yellow){
  avl_node* green = yellow -> get_lchild();
  avl_node* red = green -> get_lchild();
  avl_node* parent = yellow -> get_parent();

  if(parent ==NULL){_root = green;}
  else{
    if(parent -> get_lchild() == yellow){
      parent -> set_lchild(green);
    }
    else{
      parent -> set_rchild(green);
    }
  }
  green -> set_parent(parent);
  yellow -> set_lchild(green -> get_rchild());
  if(yellow -> get_lchild() != NULL){
    (yellow -> get_lchild()) -> set_parent(yellow);
  }
  yellow -> set_parent(green);
  green -> set_rchild(yellow);
  green -> set_balance(0);
  yellow -> set_balance(0);
}

void avl::rightright(avl_node* green){
  avl_node* yellow = green -> get_rchild();
  avl_node* blue = yellow -> get_rchild();
  avl_node* parent = green -> get_parent();

  if(parent == NULL){_root = yellow;}
  else{
    if(parent -> get_lchild() == green){
      parent -> set_lchild(yellow);
    }
    else{
      parent -> set_rchild(yellow);
    }
  }
  yellow -> set_parent(parent);
  green -> set_rchild(yellow -> get_lchild());
  if(green -> get_rchild() != NULL){
    (green -> get_rchild()) -> set_parent(green);
  }
  green -> set_parent(yellow);
  yellow -> set_lchild(green);
  green -> set_balance(0);
  yellow -> set_balance(0);
}

void avl::rightleft(avl_node* green){

 avl_node* yellow = green -> get_rchild();
 avl_node* red = yellow -> get_lchild();
 avl_node* parent = green -> get_parent();

 if(red -> get_balance() == 0){
   yellow -> set_balance(0);
   green -> set_balance(0);
 }
 else if(red -> get_balance() == -1){
   yellow -> set_balance(1);
   green -> set_balance(0);
 }
 else if(red -> get_balance() == 1){
   yellow -> set_balance(0);
   green -> set_balance(-1);
 }
   red -> set_balance(0);


 if(parent == NULL){_root = red;}
 else{
   if(parent -> get_lchild() == green){
     parent -> set_lchild(red);
   }
   else{
     parent -> set_rchild(red);
   }
 }

 green -> set_rchild(red -> get_lchild());
 if(green -> get_rchild() != NULL){
   (green -> get_rchild()) -> set_parent(green);
 }
 yellow -> set_lchild(red -> get_rchild());
 if(yellow -> get_lchild() != NULL){
   (yellow -> get_lchild()) -> set_parent(yellow);
 }
 red -> set_parent(parent);
 red -> set_lchild(green);
 green -> set_parent(red);
 red -> set_rchild(yellow);
 yellow -> set_parent(red);
}

void avl::leftright(avl_node* yellow){
  avl_node* green = yellow -> get_lchild();
  avl_node* red = green -> get_rchild();
  avl_node* parent = yellow -> get_parent();

  if(red -> get_balance() == 0){
    green -> set_balance(0);
    yellow -> set_balance(0);
  }
  else  if(red -> get_balance() == 1){
    green -> set_balance(-1);
    yellow -> set_balance(0);
  }
  else if(red -> get_balance() == -1){
    green -> set_balance(0);
    yellow -> set_balance(1);
  }
  red -> set_balance(0);

  if(parent == NULL){_root = red;}
  else{
    if(parent -> get_rchild() == yellow){
      parent -> set_rchild(red);
    }
    else{
      parent -> set_lchild(red);
    }
  }

  green -> set_rchild(red -> get_lchild());
  if(green -> get_rchild() != NULL){
    (green -> get_rchild()) -> set_parent(green);
  }
  yellow -> set_lchild(red -> get_rchild());
  if(yellow -> get_lchild() != NULL){
    (yellow -> get_lchild()) -> set_parent(yellow);
  }
  red -> set_parent(parent);
  red -> set_lchild(green);
  green -> set_parent(red);
  red -> set_rchild(yellow);
  yellow -> set_parent(red);

}

void avl::delete_tree(avl_node* n){
  if(n == NULL){return;}
  if(n -> get_rchild() == NULL && n-> get_lchild() == NULL){return;}
  
  delete_tree(n -> get_rchild());
  delete_tree(n -> get_lchild());
  delete n;

}

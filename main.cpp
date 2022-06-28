#include <iostream>
#include <vector>

using namespace std;

struct Node{
Node* left = 0;
Node* right = 0;
int value = 0;
};

class BinarySearchTree {
public:

Node* root = new Node;
BinarySearchTree(){

}

void insert(int value) {
  if(root->value == NULL) {
    root->value = value;
  }

 else {
   Node* newNode = new Node;
   newNode->value = value;
   Node* currentNode = root;
   while(true){
     if(value > currentNode->value) {
       if(!currentNode->right) {
         currentNode->right = newNode;
         break;
       }
         currentNode = currentNode->right;
     }
     else {
       if(!currentNode->left) {
         currentNode->left = newNode;
         break;
       }
         currentNode = currentNode->left;
     }
   }
   

   }


}

bool lookup(int value) {
  if(!root) {
    cout << "No nodes in list" << endl;
  }
  Node* currentNode = root;

  while(currentNode) {
    if(value > currentNode->value) {
      currentNode = currentNode->right;
    }
    else if(value < currentNode->value) {
      currentNode = currentNode->left;
    }
    else if(value == currentNode->value) {
      cout << "Found!" << endl;
      return true;
    }
  }
  cout << "Not in list" << endl;
  return false;

}

bool remove(int value) {
  if(root->value == NULL) {
    cout << "No items in list" << endl;
    return false;
  }

  Node* curr = root;
  Node* prev = NULL;
  Node* next = NULL;

  while(curr) {
    prev = curr;
    
    if(value > curr->value) {
      curr = curr->right;
    }
    else if(value < curr->value) {
      curr = curr->left;
    }
    else if(value == curr->value) {
      
      //If the node is a leaf (no children)
      if(!curr->right && !curr->left) {
        delete curr;
        //curr = NULL;
        cout << "Node is a leaf called" << endl;
      }
        //If the node has 1 child
      else if(curr->right && !curr->left || curr->left && !curr->right) {
        cout << "Node has one child called" << endl;
        if(curr->right && !curr->left) {
          next = curr->right;
        }
        else {
          next = curr->left;
        }
        
        if(prev->value > next->value) {
          prev->left = next;
        }
        else{
          prev->right = next;
          }

        
      }
        //If the node has 2 children
      else if(curr->right && curr->left) {
        cout << "Node has 2 children called" << endl;
        next = curr->right;
        prev->right = next;
        delete curr;
        //curr = NULL;

      }
    }
  }
 
}

vector<int> breadthFirstSearch() {
  Node* curr = root;
  vector<int> list {};
  vector<Node*> queue {};
  queue.push_back(curr);

  while(queue.size() > 0) {
    curr = queue[0];
    cout << queue[0]->value << " ";
    queue.erase(queue.begin());
    list.push_back(curr->value);

    if(curr->left) {
      queue.push_back(curr->left);
    }
    if(curr->right) {
      queue.push_back(curr->right);
    }
  }

  return list;
  
}

void print() {
Node* temp = root;
  //temp = temp->right;
 cout << "Value of root is: " << temp->value << endl;
  Node* right = temp->right;
  cout << "value of root right is: " << right->value << endl;
  Node* left = temp->left;
    cout << "value of root left is: " << left->value << endl;
}

};


int main() {
  BinarySearchTree obj;
  obj.insert(9);
  obj.insert(4);
  obj.insert(6);
  obj.insert(20);
  obj.insert(100);
  obj.insert(15);
  obj.insert(1);
  obj.insert(7);
  obj.print();
  obj.breadthFirstSearch();
  //obj.lookup(170);
  //obj.remove(20);
}
#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

Node* buildTree(Node* root){
  int data;
  cin >> data;
  root = new Node(data);

  if(data == -1){
    return NULL;
  }
  root->left = buildTree(root);
  root->right = buildTree(root);

  return root;
}

void countLeaves(Node* root, int &count){
  if(root == NULL){
    return;
  }

  countLeaves(root->left, count);
  if(root->left == NULL && root->right == NULL){
    count++;
  }
  countLeaves(root->right, count);
}

int main() {
  Node* root = NULL;
  cout << "Enter data in single line: " << endl;
  root = buildTree(root);
  int count = 0;
  countLeaves(root, count);
  cout << "Number of leaves: " << count;
}
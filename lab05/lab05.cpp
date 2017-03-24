#include "book.h"
#include "BSTNode.h"
#include "lqueue.h"

// Count the number of nodes in a binary tree
template <typename E>
int count(BinNode<E>* root) {
  if (root == NULL) return 0;  // Nothing to count
  return 1 + count(root->left())
           + count(root->right());
}

template <typename E>
int height(BinNode<E>* root) { 
  	if(root== NULL) return 0;
	int lHeight = count(root->left());
	int rHeight = count(root->right());
  	if (lHeight > rHeight) return lHeight;
	
	else return rHeight;
	
	}

template <typename E>
int leaf_count(BinNode<E>* root) 
{
	if(root == NULL) return 0;
	
	if(root -> isLeaf() == true) return 1;
	
	else{	
		return (leaf_count(root -> left())) +
		leaf_count(root -> right());
			
	}
	//if(root -> isLeaf() == true);
	//return count(int(root -> isLeaf()));
}

template <typename E>
int sum_nodes(BinNode<E>* root) {
	if (root == NULL) return 0;
	
	int leafSum = 0;
	leafSum = root -> element() + sum_nodes(root -> left()) 
	+ sum_nodes(root -> right());
	/*
	leafSum += sum_nodes(int(root -> left())) +
	sum_nodes(int(root -> right()));	*/
	return leafSum;
}


template <typename E>
bool search(BinNode<E>* root, const E& val) {	
	if (root == NULL) return 0;	
	else if (root -> element()  == val) return 1;
	else if (search(root -> left(), val)) return 1;
	else if (search(root -> right(), val)) return 1;
	else return 0;	
}

template <typename E>
void print_tree_by_level(BinNode<E>* root) {
	if(root==NULL) return;
	int tLength = count(root);
	LQueue<BinNode<E>*> printQ(tLength);
	cout << "Your tree:" << endl;
	printQ.enqueue(root);
	while(printQ.length()>0){
		//cout << printQ.frontValue() -> element() << endl;
  		//if(printQ.frontValue() -> element()  == NULL) {	
			BinNode<E>* temp = printQ.dequeue();	
			cout << temp -> element() << endl;
			
			//if(temp -> left() -> isLeaf() == false){
				printQ.enqueue(temp -> left());
			
			//if(temp -> right() -> isLeaf() == false){
				printQ.enqueue(temp -> right());
			
		
		
	       	
	}			 			
}

template <typename E>
void print_tree(BinNode<E>* root) {
	if(root==NULL) return;
	print_tree(root -> left());
	print_tree(root -> right());
	
	cout << root -> element() << endl;
}

int main()
{
  BSTNode<int,int>* root = new BSTNode<int,int>(1,1);
  BSTNode<int,int>* left = new BSTNode<int,int>(2,2);
  BSTNode<int,int>* right = new BSTNode<int,int>(3,3);
  BSTNode<int,int>*  l2= new BSTNode<int,int>(4,4);
  BSTNode<int,int>* r2= new BSTNode<int,int>(5,5);
  //BSTNode<int,int>*  l3= new BSTNode<int,int>(6,7);
  //BSTNode<int,int>* r3= new BSTNode<int,int>(7,9);

  //l3->setLeft(l2);
  //r3->setRight(r2);
  left ->setLeft(l2);
  left ->setRight(r2);
  root->setLeft(left);
  root->setRight(right);
  cout << "Your tree out of order:" << endl;
  print_tree(root);
  print_tree_by_level(root);
  cout << " Node count = " << count(root) << endl;
  cout << " Height = " << height(root) << endl;
  cout << " Leaf count = " << leaf_count(root) << endl;
  cout << " Sum of node values = " << sum_nodes(root) << endl;
  for (int i=0; i <= 9; i++) {
    if (search(root, i)) {
      cout << "Found " << i << " in the tree..." << endl;
    }
    else {
      cout << "Did not find " << i << " in the tree..." << endl;
    }
  }
}

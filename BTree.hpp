#ifndef BTREE_HPP
#define BTREE_HPP
#include "BTNode.hpp"




class BTree{

private:
	BTNode *root; 
	int treeDepth; 
	int totalKeys;
	int order; 

public: 

	BTree(int treeOrder); 			//constructor 

	~BTree(); 						//destructor 

	bool search(int value);			//method to determine if value exists in the tree 

	void insertTree(int value);			//method to insert values into the BTree 

	void deleteValue(int value);	//method to delete a given value from the Tree 

	void printTree();				//test method to print tree to console 

	BTNode *getRoot();				//return pointer to root Node 
};




#endif //BTREE_HPP
#ifndef BTREE_HPP
#define BTREE_HPP
#include "BTNode.hpp"




class BTree{

private:
	BTNode *root; 
	int treeDepth; 
	int totalKeys;

public: 

	BTree(int order); 				//constructor 

	~BTree(); 						//destructor 

	bool search(int value);			//method to determine if value exists in the tree 

	void insert(int value);			//method to insert values into the BTree 

	void deleteValue(int value);	//method to delete a given value from the Tree 

	void printTree();				//test method to print tree to console 
};




#endif //BTREE_HPP
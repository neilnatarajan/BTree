#ifndef BTNODE_HPP
#define BTNODE_HPP
#include <vector>
#include <iostream>


//header file for BTNode class aka single node of the B Tree

//each node will keep track of the number of keys it contains, the keys themselves
class BTNode{

private: 
	int numKeys;					//each node will keep track of the number of keys it contains 
	std::vector<int> keys; 			//vector of keys that node contains 
	int order; 						//specifies degree of the tree
	std::vector<BTNode*>children;	//vector of ptr's to child nodes 
	BTNode *parent; 				//mark the parent of this node 
	bool isLeaf; 					//marker to indicate if node is leaf node 
	int maxKeys; 



public: 
	BTNode(int orderTree, bool leafBool);		//constructor 

	~BTNode();									//destructor 

	int getNumKeys();							//simply return the number of keys this node contains

	std::vector<int> getKeys();					//return vector containing node's keys 

	std::vector<BTNode*> getChildren();			//return the vector containing the child nodes of this node 

	BTNode *getParent();						//method to return ptr to the parent of current node

	void setParent(BTNode *p);					//method to assign parent of node 

	bool isLeafNode();
	
};


#endif 
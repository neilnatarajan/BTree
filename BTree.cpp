#include "BTree.hpp"



//constructor 
BTree::BTree(int order){
	root = new BTNode(order,true);		//the root will initially be a leaf 
	treeDepth = 0; 						//labeling root as depth 0
	totalKeys = 0;						//no keys inserted yet 
}

BTree::~BTree(){
	return;
}

//TODO:this method will search the tree for a given value and return 
//a bool as to whether it is found or not 
bool BTree::search(int value){


	BTNode * currPtr = root; 

	bool found = false;			//start assuming value doesn't exist in the tree

	int keysRead = 0; 


	while(1){
		//iterate through the node's keys 
		for(int i=0;i<currPtr->getNumKeys();i++){
			//if key at index i is equal to value 
			if(value == currPtr->getKeyAt(i)){
				found = true; 
				return found; 
			}
			//if key at index i is greater than 
		}
	}

	//iterate through root node's keys

		//if found return true
		//if not found and keysRead == totalKeys 
			//return false 

		//if value is between keys go to appropriate child 
			//go to next iteration of the loop 


}


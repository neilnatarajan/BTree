#include "BTree.hpp"



//constructor 
BTree::BTree(int treeOrder){
	root = new BTNode(order,true);		//the root will initially be a leaf 
	treeDepth = 0; 						//labeling root as depth 0
	totalKeys = 0;						//no keys inserted yet 
	order= treeOrder; 					//make order of the tree accessible 
}

BTree::~BTree(){
	return;
}

//TODO:this method will search the tree for a given value and return 
//a bool as to whether it is found or not 
bool BTree::search(int value){


	BTNode * currPtr = root; 	//ptr node to iterate through the Tree

	bool found = false;			//start assuming value doesn't exist in the tree

	int keysRead = 0; 			//keep track of total keys Read so far 


	//if the node is a leaf and it is still not found then false


	while(1){
		//iterate through the node's keys 
		for(int i=0;i<currPtr->getNumKeys();i++){

			//if key at index i is equal to value 
			if(value == currPtr->getKeyAt(i)){
				found = true; 
				return found; 
			}
			//if key at index i is greater than value
			else if(value < currPtr->getKeyAt(i)){
			 	
				if(currPtr->isLeafNode()){			//reached leaf without finding
					found = false; 
					return found; 
				}
				else{								//child exists 
					currPtr = currPtr->getChildAt(i);
					break;							//restart while loop for new node 
				}

			}
			//if key at index i is less than value 
			else if(value > currPtr->getKeyAt(i)){
				//if at end of keys for node then start searching last child 
				if(i==((currPtr->getNumKeys())-1)){

					//check to see if leaf
					if(currPtr->isLeafNode()){
						//reached end without finding value 
						found = false; 
						return found; 
					}
					//not leaf - child node exists 
					int numChild = currPtr->getNumChildren();
					currPtr  = currPtr->getChildAt(numChild-1); 
					//std::cout << currPtr->getNumKeys() << std::endl;
					//std::cout << currPtr->getKeyAt(0) << std::endl;
					break;							//now restart while loop for new node 
				}
				else{
					continue;						//keep iterating through keys for current node
				}
			}
		}
	}
}

BTNode* BTree::getRoot(){
	return root;
}


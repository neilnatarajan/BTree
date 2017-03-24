#include "BTree.hpp"
#include <queue> 



//constructor 
BTree::BTree(int treeOrder){
	root = new BTNode(treeOrder,true);	//the root will initially be a leaf 
	treeDepth = 0; 						//labeling root as depth 0
	totalKeys = 0;						//no keys inserted yet 
	order= treeOrder; 					//make order of the tree accessible 
}

BTree::~BTree(){
	return;
}

//method to insert a value into the tree
void BTree::insertTree(int value){
	//we will call the BTNode::insertKey() only on the appropriate 
	//leaf node 
	//essentially a modified version of search where instead of returning found
	//call BTNode::insertKey()

	BTNode *currPtr = root; 	//ptr node to iterate through the Tree

	if(currPtr->getNumKeys()==0){
		//empty tree
		std::vector<int> tKeys;
		tKeys.push_back(value); 
		currPtr->setKeys(tKeys);
		return;
	}

	while(1){
		//iterate through the node's keys
		for(int i=0; i < currPtr->getNumKeys();i++){

			//if key at index i is equal to value
			if(value == currPtr->getKeyAt(i)){
				//I'm not Sure what to do with duplicates yet
				//TODO 
			}
			//if key at index i is greater than value 
			else if(value < currPtr->getKeyAt(i)){

				if(currPtr->isLeafNode()){						//found leaf node 
					currPtr->insertKey(value);
					root = getRoot();							//update the root of the tree 
					return; 									//mission accomplished!Break Loop
				}
				else{											//keep traversing
					currPtr = currPtr->getChildAt(i);
					break;	
				}
			}
			//if key at index is less than value 
			else{
				//if at the end of keys for node search last child
				if(i==((currPtr->getNumKeys())-1)){

					//check to see if leaf
					if(currPtr->isLeafNode()){					//found leaf node  
						currPtr->insertKey(value);
						root = getRoot();						//update the root of the tree 
						return; 								//mission accomplished!Break Loop
					}
					//not leaf - child node exists 
					int numChild = currPtr->getNumChildren();
					currPtr  = currPtr->getChildAt(numChild-1); 
					break;											//now restart while loop for new node 
				}
				else{
					continue;										//keep iterating through keys for current node
				}
			}
		}
	}

}


//this method will search the tree for a given value and return 
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
			 	
				if(currPtr->isLeafNode()){							//reached leaf without finding
					found = false; 
					return found; 
				}
				else{												//child exists 
					currPtr = currPtr->getChildAt(i);
					break;											//restart while loop for new node 
				}

			}
			//if key at index i is less than value 
			else if(value > currPtr->getKeyAt(i)){
				//if at end of keys for node then start searching last child 
				if(i==((currPtr->getNumKeys())-1)){

					//check to see if leaf
					if(currPtr->isLeafNode()){						//reached end without finding value 
						found = false; 
						return found; 
					}
					//not leaf - child node exists 
					int numChild = currPtr->getNumChildren();
					currPtr  = currPtr->getChildAt(numChild-1); 
					break;											//now restart while loop for new node 
				}
				else{
					continue;										//keep iterating through keys for current node
				}
			}
		}
	}
}

//method to traverse the tree Breadth first and print it out level by level 
void BTree::printTree(){

	//make sure tree is not empty 
	if(!root || root->getNumKeys()==0){
		std::cout << "the tree is empty nothing to traverse." << std::endl;
	}

	//format for printing out the tree 
	std::cout << "format: level,child: key(s)" << std::endl;

	//create a datastructure to hold nodes for Breadth First Traversal 
	std::queue<BTNode*> printQueue; 

	//create pointer to Iterate through the tree 
	BTNode *currPtr = root; 
	int lv = currPtr->getLevel();
	int c = 0;

	//add the pointer to the queue 
	printQueue.push(currPtr);

	//loop through the queue 
	while(!printQueue.empty()){
		BTNode *curr = printQueue.front();
		printQueue.pop();

		//add the children to the queue
		for (int i = 0; i < curr->getNumChildren(); i++)
		{
			printQueue.push(curr->getChildAt(i));
		}

		if (curr->getLevel() > lv)			//reached new level in the tree 
		{	
			lv = curr->getLevel();	
			std::cout << std::endl;
			c = 0;
		}
		std::cout << curr->getLevel() << ',' << c << ": "; 
		for (int i = 0; i < curr->getNumKeys(); ++i)
		{
			std::cout << curr->getKeyAt(i) << ' ';
		}
		if(curr->getParent()){
			std::cout << " from p containing: " << curr->getParent()->getKeyAt(0);
		}
		if(!printQueue.empty()){
			
			std::cout <<"	";
		}
		c++;
	}
	std::cout << std::endl;
}


BTNode* BTree::getRoot(){
	//iterate to top of the tree
	while(root->getParent()){
		root = root->getParent(); 
	}
	return root;
}


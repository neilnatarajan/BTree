#include "BTNode.hpp"


//constructor will need the order of the node 
BTNode::BTNode(int orderTree, bool leafBool){
	
	numKeys = 0; 			//upon creation the node holds no keys
	order = orderTree; 		//set order of the node 
	isLeaf = leafBool; 		//set whether node is a leaf or not 
	maxKeys = order - 1;	//maximum number of keys node can hold 

	
	parent = NULL;			//set the parent to NULL 
}

//destructor
BTNode::~BTNode(){
	//does nothing for now 

	//delete the node's children before deleting the node itself 
	return; 
}


//method to return the number of keys contained in a node 
int BTNode::getNumKeys(){
	numKeys = keys.size();
	return numKeys; 
}

//method to return vector object of keys in node 
std::vector<int> BTNode::getKeys(){
	return keys;
}

//method to return vector of child pointers in node 
std::vector<BTNode*> BTNode::getChildren(){
	return children;
}

//method to return parent of node 
BTNode *BTNode::getParent(){
	return parent;
}

//method to assign parent to node 
void BTNode::setParent(BTNode *p){
	parent = p; 
}

bool BTNode::isLeafNode(){
	if(children.size()==0){
		return true;
	}
	else{
		return false;
	}
}

int BTNode::getKeyAt(int index){

	if((index > keys.size()-1)){		//check for invalid index 
		return -1; 
	}
	else{								//index is valid 
		return keys[index];
	}
}



/*void BTNode::insertKey(int value){
	if(!isLeaf){
		//find appropriate range to iterate to child node 
		int insertIndex=0;
		for(int i =0; i < keys.size();i++){
			if(value>)

		}

		//recursively try to insert again in appropriate child node 
	}


	//place the value in the keys vector at appropriate index 
	for(int i=0;i<keys.size();i++){	

	}

	//check if the node is full 
	if(getKeys()>maxKeys){
		//then break the node 
	}



	int insertIndex = 0;		//variable to hold the index to insert key 

	//place the value in the appropriate index in the key vector
	for(int i=0; i<keys.size();i++){
		if(value > keys[i]){
			continue;
		}
		//if value is less than key[i] then 
		else if(value < keys[i]){
			insrtIndex = i; 
			break;
		}
	}
*/
//}





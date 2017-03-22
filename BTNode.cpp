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
	p->addChild(this);
}

//method to determine if node is leaf 
bool BTNode::isLeafNode(){
	if(children.size()==0){
		return true;
	}
	else{
		return false;
	}
}


//method to return key at given index in node 
int BTNode::getKeyAt(int index){

	if((index > keys.size()-1)){		//check for invalid index 
		return -1; 
	}
	else{								//index is valid 
		return keys[index];
	}
}

//method to return pointer to child node at given index 
BTNode* BTNode::getChildAt(int index){
	if((index > children.size()-1)){
		return NULL;					//check for invalid index 
	}
	else{
		return children[index];
	}
}

//method to add child to node 
void BTNode::addChild(BTNode* c){
	children.push_back(c);
}

//method to insert child into proper index in children 
void BTNode::insertChild(BTNode* c){
	for(int i=0; i < children.size();i++){
		if(c->getKeyAt(0) < children[i]->getKeyAt(0)){
			//insert here 
			children.insert(children.begin()+i,c);
		}
		else if(c->getKeyAt(0) > children[i]->getKeyAt(0)){
			if(i==children.size()-1){
				children.push_back(c);
			}
			continue;
		}
		else{
			//something wrong happened 
			//not accounting for duplicate keys yet.
		}
	}
}


//method to return the number of child nodes 
int BTNode::getNumChildren(){
	return children.size();
}

//test method to see if search works in BTree
void BTNode::setKeys(std::vector<int> values){
	keys = values;
}

//method to insert key at node 
void BTNode::insertKey(int value){


	//create iterator to go through vector keys
	std::vector<int>::iterator it; 

	for (int i = 0; i < keys.size(); ++i)
	{
		if(value < keys[i]){
			keys.insert(keys.begin()+i,value);
		}
		else if(value > keys[i] && i==keys.size()-1){
			keys.push_back(value);
		}
	}

/*
	//insert the value at the appropriate index in the node 
	for(it = keys.begin(); it < keys.end(); it++){
		//if the value is less than key at index 
		if(value < *it){
			keys.insert(it,value);					//insert the key at index i 
			break;
		}
		else if((value > *it) && (it == keys.end()-1)){
			keys.push_back(value);
		}
	}
*/
	//std::cout << "keys in this node: " << keys.size() << std::endl;
	//std::cout << "order of this node: " << order << std::endl; 
	//int max = order -1; 
	//std::cout << "maxKeys: " << max << std::endl; 

	//check if node is beyond capacity
	if(keys.size()>maxKeys){
		//print out the value
		std::cout << "key: " << value << " but node full" << std::endl;
		//insert midPoint into parent node 
		int midPointIndex = keys.size()/2 - (1 - (keys.size()%2));
		int midPointKey = keys[midPointIndex];
	

		if(parent==NULL){
			//root is full so no parent exists 
			BTNode *newRoot = new BTNode(order,false);
			parent = newRoot;
		}

		parent->insertKey(midPointKey);				//recursive call to insert midpoint key in parent
		
		//create new node to prep break 
		BTNode *right = new BTNode(this->order,this->isLeaf);
		std::vector<int> rightKeys; 
		
		//pop off values to the right of midPointIndex 
		for(int i=midPointIndex+1;i<keys.size();i++){
			rightKeys.push_back(keys[i]);						//copy over keys for right node 
		}
		keys.erase(keys.begin()+midPointIndex-1, keys.end());	//erase keys from current node that go to right
		right->setKeys(rightKeys);								//set keys 
		right->setParent(this->parent);							//set the parent of right 
		(right->parent)->insertChild(right);					//insert right to the children of parent 
		

		//if node isn't a leaf node then partion the children as well
		if(this->isLeafNode()==false){
			for(int i=midPointIndex+1;i < children.size(); i++){
				right->addChild(children[i]);
			}
			children.erase(children.begin()+midPointIndex+1,children.end());
		}

	}

}








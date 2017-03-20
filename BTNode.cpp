#include "BTNode.hpp"


//constructor will need the order of the node 
BTNode::BTNode(int orderTree, int leafBool){
	
	numKeys = 0; 					//initially numKeys will be 0
	order = orderTree; 				//set order of node to passed in value 
	isLeaf = leafBool;

	keys = new int[order-1] 		//max keys per node is order - 1
	children = new BTNode[order]	//max children per node is order 

}


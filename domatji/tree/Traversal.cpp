#include"Traversal.h"
#include<iostream>

void Traversal::vist(TreeNode* node) {
	/*for (int i = 0; i < node->getKeys().size(); i++) {
		std::cout << node->getKeys().at(i);
		if (i < node->getKeys().size() - 1)
			std::cout << ",";
	}*/
	std::cout << node;
}
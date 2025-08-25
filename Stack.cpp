#include "Stack.h"
#include <iostream>
void Stack::pushNode(tree::Node* node) {
	Stack::nodeStack.push(node);
}
void Stack::iterativeInorder(tree::Node* node) {
	tree::Node* currentNode = node;
	while (currentNode != nullptr || !nodeStack.empty()) {
		while (currentNode != nullptr) {
			pushNode(currentNode);
			currentNode = currentNode->left;
		}
		currentNode = nodeStack.top();
		nodeStack.pop();
		std::cout << currentNode->value << " ";
		currentNode = currentNode->right;

	}
}
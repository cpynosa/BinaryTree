#include "Stack.h"
#include <iostream>
void Stack::pushNode(tree::Node* node) {
	Stack::nodeStack.push(node);
}
void Stack::iterativeInorder(tree::Node* node) {
	tree::Node* currentNode = node;
	while (currentNode || !nodeStack.empty()) {
		while (currentNode) {
			pushNode(currentNode);
			currentNode = currentNode->left;
		}
		currentNode = nodeStack.top();
		nodeStack.pop();
		std::cout << currentNode->value << " ";
		currentNode = currentNode->right;

	}
}
void Stack::iterativePreorder(tree::Node* node) {
	tree::Node* currentNode = node;
	pushNode(currentNode);
	while (!nodeStack.empty()) {
		currentNode = nodeStack.top();
		nodeStack.pop();
		std::cout << currentNode->value << " ";
		if (currentNode->right)pushNode(currentNode->right);
		if (currentNode->left)pushNode(currentNode->left);
	}

}
void Stack::iterativePostorder(tree::Node* node) {
	tree::Node* currentNode = node;
	pushNode(currentNode);
	while (currentNode) {
		if (currentNode->right)pushNode(currentNode->right);
		if (currentNode->left)pushNode(currentNode->left);
		currentNode = currentNode->left;
	}
	while (!nodeStack.empty()) {
		currentNode = nodeStack.top();
		nodeStack.pop();
		std::cout << currentNode->value << " ";
	}
}
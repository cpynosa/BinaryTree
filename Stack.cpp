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
	if (!node) return;

	std::stack<tree::Node*> stack1, stack2;
	stack1.push(node);

	while (!stack1.empty()) {
		tree::Node* current = stack1.top();
		stack1.pop();
		stack2.push(current);

		if (current->left) stack1.push(current->left);
		if (current->right) stack1.push(current->right);
	}

	while (!stack2.empty()) {
		std::cout << stack2.top()->value << " ";
		stack2.pop();
	}
}

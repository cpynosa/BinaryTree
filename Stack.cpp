#include "Stack.h"
void Stack::pushNode(tree::Node* node) {
	Stack::nodeStack.push(node);
}
void Stack::iterativeInorder(tree::Node* node) {
	if (node == nullptr)return;
	tree::Node* currentNode = node;
	 do{
		pushNode(currentNode->left);
		currentNode = currentNode->left;
	}while (currentNode->left != nullptr);

}
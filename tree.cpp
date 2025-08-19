#include "tree.h"
tree::Node::Node(int value) {
	this->value = value;
	this->left = nullptr;
	this->right = nullptr;
}
tree::BinaryTree::BinaryTree(){
	this->root = nullptr;
}
tree::Node* tree::BinaryTree::insertNode(Node* node, int value) {
	if (node == nullptr)return new Node(value);
	if (value < node->value) {
		node->left = insertNode(node->left, value);
	}
	else {
		node->right = insertNode(node->right, value);
	}
	return node;
}
tree::BinaryTree::~BinaryTree() {
	deleteTree(root);
}

void tree::BinaryTree::deleteTree(Node* node) {
	if (node == nullptr) return;
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}

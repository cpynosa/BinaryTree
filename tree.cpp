#include "tree.h"
//#include "utils.h"
#include <format>
#include <iostream>
void tree::BinaryTree::inOrder(Node* root) {
	if (root != nullptr) {
		inOrder(root->left);
		std::cout << root->value << "" << std::endl;
		inOrder(root->right);
	}
}
void tree::BinaryTree::postOrder(Node* root) {
	if (root != nullptr) {
		postOrder(root->left);
		postOrder(root->right);
		std::cout << root->value << "" << std::endl;
	}
}
void tree::BinaryTree::preOrder(Node* root) {
	if (root != nullptr) {
		std::cout << root->value << "" << std::endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}
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
void tree::BinaryTree::insert(int value) {
	root = insertNode(root, value);
}
tree::Node* tree::BinaryTree::getRoot() {
	return this->root;
}

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
std::optional<int> tree::BinaryTree::binarySearch(Node* node, int value) {
	while (node) {
		if (value == node->value)return node->value;
		else if (value < node->value)node = node->left;
		else node = node->right;
	}
	return std::nullopt;
}
// árbol AVL
// introduction to algorithms cormen
tree::AVLTree::AVLTree() : BinaryTree(){}

int tree::AVLTree::height(tree::Node* node) {
	if (node == nullptr)return 0;
	return std::max(height(node->left), height(node->right)) + 1;
}

int tree::AVLTree::balanceFactor(tree::Node* node) {
	if (node == nullptr)return 0;
	return height(node->left) - height(node->right);
}

tree::Node* tree::AVLTree::rotateLeft(tree::Node* node) {
	Node* newRoot = node->right;
	Node* temp = newRoot->left;

	newRoot->left = node;
	node->right = temp;

	return newRoot;
}
tree::Node* tree::AVLTree::rotateRight(tree::Node* node) {
	Node* newRoot = node->left;
	Node* temp = newRoot->right;

	newRoot->right = node;
	node->left = temp;
	return newRoot;

}
tree::Node* tree::AVLTree::insertNode(Node* node, int value) {
	if (node == nullptr) return new Node(value);

	if (value < node->value) {
		node->left = insertNode(node->left, value);
	}
	else if (value > node->value) {
		node->right = insertNode(node->right, value);
	}
	else {
		// Valor duplicado, no se inserta
		return node;
	}

	int balance = balanceFactor(node);

	// Rotación simple derecha (LL)
	if (balance > 1 && value < node->left->value) {
		return rotateRight(node);
	}

	// Rotación simple izquierda (RR)
	if (balance < -1 && value > node->right->value) {
		return rotateLeft(node);
	}

	// Rotación doble izquierda-derecha (LR)
	if (balance > 1 && value > node->left->value) {
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}

	// Rotación doble derecha-izquierda (RL)
	if (balance < -1 && value < node->right->value) {
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}

	return node;
}

void tree::AVLTree::insert(int value) {
	root = insertNode(root, value);
}
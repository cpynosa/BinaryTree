#pragma once
namespace tree {
	class Node {
	public:
		int value;
		Node* left;
		Node* right;
		Node(int value);
	};
	class BinaryTree {
	private:
		Node* root;
		Node* insertNode(Node* node, int value);
		void deleteTree(Node* node);
	public:
		BinaryTree();
		~BinaryTree();
		Node* getRoot();
		void insert(int value);
		// Deep First Search (DFS)
		void inOrder(Node* root);
		void postOrder(Node* root);
		void preOrder(Node* root);
	};
}

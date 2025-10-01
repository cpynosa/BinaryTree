#pragma once
#include <optional>
namespace tree {
	class Node {
	public:
		int value;
		Node* left;
		Node* right;
		Node(int value);
	};
	class BinaryTree {
	protected:
		Node* root;
		virtual Node* insertNode(Node* node, int value);
		void deleteTree(Node* node);
	public:
		std::optional<int> binarySearch(Node* node, int value);
		BinaryTree();
		virtual ~BinaryTree();
		Node* getRoot();
		virtual void insert(int value);
		// Deep First Search (DFS)
		void inOrder(Node* root);
		void postOrder(Node* root);
		void preOrder(Node* root);
	};
	class AVLTree : public BinaryTree {
	private:
		int height(Node* node);
		int balanceFactor(Node* node);
		Node* rotateLeft(Node* node);
		Node* rotateRight(Node* node);
		Node* insertNode(Node* node, int value) override;
	public:
		AVLTree();
		void insert(int value) override;
	};
}

#pragma once
#include <stack>
#include "tree.h"
class Stack
{
private:
	std::stack<tree::Node*> nodeStack;
public:
	void pushNode(tree::Node* node);
	void iterativeInorder(tree::Node* node);
	void iterativePostorder(tree::Node* node);
	void iterativePreorder(tree::Node* node);

};


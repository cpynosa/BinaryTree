#pragma once
#include <stack>
#include "tree.h"
class Stack
{
private:
public:
	void pushNode(tree::Node* node);
	void iterativeInorder(tree::Node* node);
	std::stack<tree::Node*> nodeStack;

};


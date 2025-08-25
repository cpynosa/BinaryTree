#include <iostream>
#include "tree.h"
#include <stack>
#include "Stack.h"
// C# WPS
int main()
{
    tree::BinaryTree bt;    
    bt.insert(20);
    bt.insert(14);
    bt.insert(19);
    bt.insert(13);
    bt.insert(12);
    bt.insert(21);
    bt.insert(10);
    bt.insert(7);
    Stack s;
    s.iterativeInorder(bt.getRoot());
    //bt.preOrder(bt.getRoot());
    // Convertir las 3 funciones de recursivas 
    // a iterativas
}


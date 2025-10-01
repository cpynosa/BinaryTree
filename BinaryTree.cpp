#include <iostream>
#include "tree.h"
#include <stack>
#include "Stack.h"
// C# WPS
int main()
{
    tree::BinaryTree bt;    
    bt.insert(4);
    bt.insert(2);
    bt.insert(1);
    bt.insert(3);
    bt.insert(10);
    bt.insert(7);
    bt.insert(15);
    bt.insert(5);
    bt.insert(6);
    bt.insert(8);
    bt.insert(14);
    bt.insert(17);
    std::optional<int> result = bt.binarySearch(bt.getRoot(), 6);
    if (result.has_value())std::cout << "Se encontro";
    else std::cout << "No se encontro";
    //Stack s;
    //bt.inOrder(bt.getRoot());
    //bt.preOrder(bt.getRoot());
   //std::cout << std::endl;
    //bt.postOrder(bt.getRoot());
    //std::cout << std::endl;
    //s.iterativeInorder(bt.getRoot());
    //s.iterativePostorder(bt.getRoot());
    //s.iterativePreorder(bt.getRoot());

    //bt.preOrder(bt.getRoot());
    // Convertir las 3 funciones de recursivas 
    // a iterativas
}


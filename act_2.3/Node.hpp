#include <iostream>

class Node {
public:
    std::string data;
    Node *next;
    
    Node() {}
    Node(std::string info) {
        data = info;
        next = NULL;
    }
};
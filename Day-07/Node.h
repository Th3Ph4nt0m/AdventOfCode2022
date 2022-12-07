//
// Created by Henrik Steffens on 07.12.22.
//

#ifndef DAY_07_NODE_H
#define DAY_07_NODE_H

#include <string>
#include <vector>

struct File {
    std::string name;
    long long size;
};

struct Node {
    std::string name;
    long long size;
    Node *parent;
    std::vector<Node*> children;
    std::vector<File*> files;


};


#endif //DAY_07_NODE_H

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include "Node.h"

int calculateSize(Node *node) {
    int sum = 0;

    for (auto &file : node->files) {
        sum += file->size;
    }

    for (auto &child : node->children) {
        sum += calculateSize(child);
    }

    node->size = sum;
    return sum;
}

void findSmall(Node *node, int &sum) {
    if (node->size < 100000) {
        sum += node->size;
    }

    for (auto &child : node->children) {
        findSmall(child, sum);
    }
}

 void findLarge(Node *node, std::vector<Node*> &nodes, long long diff) {
    if(node->size + diff > 0) {
        nodes.push_back(node);
    }

    for (auto &child : node->children) {
        findLarge(child, nodes, diff);
    }

}

int main() {
    // read a file line by line
    std::ifstream file("../input.txt");
    std::string line;
    Node *root = new Node({"/", 0, nullptr, {}, {}});
    Node *cur = root;
    int sum = 0;
    std::vector<Node*> nodes;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string s;
        std::vector<std::string> parts;
        while (getline(iss, s, ' ')) {
            parts.push_back(s);
        }

        if (parts[0] == "$") {
            if (parts[1] == "cd") {
                if (parts[2] == "..") {
                        cur = cur->parent;
                } else {
                    for (auto &child : cur->children) {
                        if (child->name == parts[2]) {
                            cur = child;
                            break;
                        }
                    }
/*                    Node newCur = Node(parts[2], 0);
                    cur.addChildren(&newCur);
                    newCur.setParent(&cur);
                    cur = newCur;*/
                }
            }
        } else {
            if(parts[0] == "dir") {
                Node *newNode = new Node({parts[1], 0, cur, {}, {}});
                newNode->parent = cur;
                cur->children.push_back(newNode);
            } else {
                File *newFile = new File({parts[1], std::stoll(parts[0])});
                cur->files.push_back(newFile);
            }
        }
    }
    calculateSize(root);
    findSmall(root, sum);
    std::cout << sum << std::endl;
    findLarge(root, nodes, 70000000 - 30000000 - root->size);
    std::sort(nodes.begin(), nodes.end(), [](Node *a, Node *b) {
        return a->size < b->size;
    });
    std::cout << nodes[0]->size << std::endl;
}


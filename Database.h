#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <unordered_map>
#include <string>
#include "Node.h"
using namespace std;

struct Edge {
    Node src, dst;
};

class Database {
private:
    int size;
    unordered_map <string, Node> data;

public:
    Database();
    bool is_empty(ifstream&);
    void insert(string key, Node value);
    void print();
    vector<Edge> get_edges(string key);
    ~Database();
};

#endif
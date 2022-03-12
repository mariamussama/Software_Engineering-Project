#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <unordered_map>
#include <string>
#include "node.hpp"
using namespace std;

struct Edge{
    Node src, dst;
};

class Database{
    private:
    int size;
    unordered_map <string, Node> data;

    public:
    Database();
    bool is_empty();
    void insert(string key, Node value);
    vector<Edge> get_edges(string key);
    ~Database();
};

#endif
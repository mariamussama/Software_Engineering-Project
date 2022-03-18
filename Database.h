#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <unordered_map>
#include <string>
#include "Node.h"
using namespace std;

class Database {
private:
    int size;
    unordered_map <string, Node> data;

public:
    Database();
    bool is_empty(ifstream&);
    int get_size();
    void insert(string key, Node value);
    vector<string> get_titles();
    Node get_node(string key);
    void print();
    vector<Edge> get_edges(string key);
    ~Database();
};


#endif
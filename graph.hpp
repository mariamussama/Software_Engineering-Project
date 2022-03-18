#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
#include <unordered_map>
#include "node.h"

using namespace std;


class Graph{
    private:
    int V; // size of graph
    unordered_map <string, vector<Node>> adjacency_list; // adj list for graph
    public:
    Graph(int N, vector<Edge> edges);
    void print_graph();
    ~Graph();
};


#endif
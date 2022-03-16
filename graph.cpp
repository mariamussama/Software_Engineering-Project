#include <iostream>
#include "graph.hpp"

using namespace std;

Graph::Graph(int N, vector<Edge> edges)
{
    V = N+1;
    for (auto edge: edges){
        adjacency_list[edge.src.get_title()].push_back(edge.dst);
    }
}
void Graph::print_graph()
{
    for (auto node: adjacency_list){
        cout << node.first << " references the following papers: " << "\n";
        int i = 1;
        for (auto ref: node.second){
            cout << i << ". " << ref.get_title() << ". " << "\n";
            i++;
        }
    }
}

Graph::~Graph(){}
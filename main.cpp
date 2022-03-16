#include <iostream>
#include "database.h"
#include "graph.hpp"

using namespace std;

class Main{
    void run(){
        Database db = Database::Database();
        cout << "List of publications: \n";
        vector<string> titles = db.get_titles();
        for(int i = 1; i <= db.get_size(); i++){
            cout << i << ". " << titles[i] << "\n";
        }
        cout << "Choose the publication for which you would like to generate a graph: ";
        int input;
        cin >> input;
        while(input < db.get_size() || input > db.get_size()){
            cout << "Please enter a valid number: ";
            cin >> input;
        }
        vector<Edge> references = db.get_edges(titles[input]);
        Graph paper = Graph(db.get_node(titles[input]).get_num_references(), references);
        paper.print_graph();
    }
};



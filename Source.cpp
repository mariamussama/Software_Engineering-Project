#include <iostream>
#include "database.h"
#include "graph.h"

using namespace std;

int run() 
{
    vector<string> sequence;
    int input2;
    Database db = Database();
    cout << "Welcome to literature explorer, please choose one of the following: " << "\n";
    cout << "1. View list of publications \t\t 2.Exit \n";
    int input3;
    cin >> input3;
    while (input3 <= 0 || input3 > 2) {
        cout << "Please enter a valid choice: ";
        cin >> input3;
    }
    if (input3 == 2)
    {
        cout << "Exiting...";
        return 0;
    }
    bool flag = true;
    while (flag) {
        string current;
        cout << "List of publications: \n";
        vector<string> titles = db.get_titles();
        for (int i = 1; i <= db.get_size(); i++) {
            cout << i << ". " << titles[i - 1] << "\n";
        }
        cout << "Choose the publication for which you would like to generate a graph: ";
        int input;
        bool condition = true;
        while (condition)
        {
            cin >> input;
            condition = false;
            if (input > db.get_size() || input <= 0)
            {
                cout << "Please enter a valid number: ";
                condition = true;
            }
            else if (db.get_edges(titles[input - 1]).size() == 0)
            {
                cout << "NO references are available\nChoose another page\n";
                condition = true;
            }

        }
        current = titles[input - 1];

        do {
            sequence.push_back(current);
            vector<Edge> references = db.get_edges(current);
            Graph paper = Graph(db.get_node(current).get_num_references(), references);
            paper.print_graph();
            cout << "1. Choose another node\t\t2. return\t3. exit back to list of publications\t4. exit program\n";
            condition = true;
            while (condition)
            {
                cin >> input2;
                condition = false;
                if (input2 > 4 || input2 <= 0)
                {
                    cout << "Please enter a valid number: ";
                    condition = true;
                }
                else if (input2 == 2 && sequence.size() == 1)
                {
                    cout << "NO more returns are available\n";
                    condition = true;
                }
                else if (input2 == 1 && references.size() == 0)
                {
                    cout << "NO references are available\n";
                    condition = true;
                }
            }

            if (input2 == 1)
            {
                cout << "Choose the node you would like to view: ";
                int input;
                cin >> input;
                while (input > references.size() || input <= 0) {
                    cout << "Please enter a valid number: ";
                    cin >> input;
                }
                current = references[input - 1].dst.get_title();
            }
            else if (input2 == 2)
            {

                sequence.pop_back();
                current = sequence.back();
            }
            else if (input2 == 4)
            {
                flag = false;
                break;
            }

        } while (input2 != 3);
        if (input2 == 3) {
            cout << "going back to list of publications \n";
        }
    }
    cout << "Exiting...";
}
int main() {
    run();
    return 0;
 
}
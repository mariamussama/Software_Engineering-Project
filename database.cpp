#include "Database.h"
#include "Node.h"
#include <fstream>
using namespace std;

Database::Database() 
{
	ifstream read("Database.txt");
	if (!read.is_open()) { cout << "File not open"; exit(1); }
	if (!is_empty(read))
	{
		vector<string> ref;
		vector<string> auth;
		string node_name,temp, journal, paper_doi;
		int num_auth,num_ref,year;
		while (!read.eof()) 
		{
			read >> node_name;
			read >> num_auth;
			for (int i = 0; i < num_auth; i++)
			{
				read >> temp;
				auth.push_back(temp);
			}
			read >> num_ref;
			for (int i = 0; i < num_ref; i++)
			{
				read >> temp;
				ref.push_back(temp);
			}
			read >> year;
			read >> journal >> paper_doi;
			Node n(node_name, num_auth, auth, num_ref, ref, year, journal, paper_doi);
			data[node_name] = n;
			ref.clear();
			auth.clear();
		}
	}
	else cout << "File is empty";
	read.close();
	print();
}
bool Database::is_empty(ifstream& inFile) 
{ 
	return inFile.peek() == std::ifstream::traits_type::eof(); 
}
void Database::print()
{	
	int i = 1;
	for (auto paper : data)
	{
		// Node n;
		cout << i << ". " << paper.first << " \n";
		i++;
		// n = x.second;
		// n.print(); cout << endl;
	}
}
void Database::insert(string key, Node value) {}
vector<Edge> Database::get_edges(string key) 
{
	vector<Edge> edges;
	for (auto dst: data[key].get_reference_titles()){
		Edge edge = {data[key], data[dst]};
		edges.push_back(edge);
	}
	return edges;
}
int Database::get_size(){
	return data.size();
}
vector<string> Database::get_titles(){
	vector<string> titles;
	for(auto title: data){
		titles.push_back(title.first);
	}
	return titles;
}
Database::~Database() {
}

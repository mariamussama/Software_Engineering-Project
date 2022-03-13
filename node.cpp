#include "Node.h"
using namespace std;

Node::Node()
{
    title = "";
    n_authors = -1;
    n_references = -1;
    year_published = -1;
    journal_name = "";
    doi = "";
}

Node::Node(string paper_title, int num_auth, vector<string> auth_names, int num_references, vector<string> ref_titles, int year, string journal, string paper_doi)
{
    title = paper_title;
    n_authors = num_auth;
    authors = auth_names;
    n_references = num_references;
    references_titles = ref_titles;
    year_published = year;
    journal_name = journal;
    doi = paper_doi;
}

// getters
string Node::get_title()
{
    return title;
}

int Node::get_num_authors()
{
    return n_authors;
}

vector<string> Node::get_author_names()
{
    return authors;
}

int Node::get_num_references()
{
    return n_references;
}

vector<string> Node::get_reference_titles()
{
    return references_titles;
}

int Node::get_publish_year()
{
    return year_published;
}

string Node::get_journal_name()
{
    return journal_name;
}

string Node::get_paper_doi()
{
    return doi;
}

// setters
void Node::set_title(string paper_title)
{
    title = paper_title;
}

void Node::set_num_authors(int num_auth)
{
    n_authors = num_auth;
}

void Node::set_author_names(vector<string> auth_names)
{
    authors = auth_names;
}


void Node::set_num_references(int num_references)
{
    n_references = num_references;
}

void Node::set_reference_titles(vector<string> ref_titles)
{
    references_titles = ref_titles;
}

void Node::set_publish_year(int year)
{
    year_published = year;
}

void Node::set_journal_name(string journal)
{
    journal_name = journal;
}

void Node::set_paper_doi(string paper_doi)
{
    doi = paper_doi;
}

// debugging 
bool Node::is_empty() {
    return n_authors == -1 ? true : false;
}
void Node::print() // prints details of node
{
   if (!is_empty()) 
   {
        cout << "Paper title: " << title << "\n";
        cout << "Authors: ";
        for (int i=0; i < n_authors; i++) {
            if (i < n_authors - 1) cout << authors[i] << ", ";
            else cout << authors[i] ;
        }
        cout << "\n" << "References: " << "\n";
        for (int i=0; i < n_references; i++) {
            cout << i + 1 << ". " << references_titles[i] << "\n";
        }
        cout << "Year Published: " << year_published << "\n";
        cout << "Journal name: " << journal_name << "\n";
        cout << "Doi: " << doi << "\n";
    }
    else 
    {
        cout << "No data in this node" << endl;
    }
}

// destructor
Node::~Node()
{
    // nothing to delete so left empty
}


#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {

private:

    string title; // title of paper
    int n_authors; // number of authors 
    vector<string> authors; // list of author last names
    int n_references; // number of references used in this paper
    vector<string> references_titles; // titles of papers referenced
    int year_published; // year paper was published
    string journal_name; // name of journal paper was published in
    string doi; // doi of research paper 

public:
    //default constructor
    Node();
    // parametarized consructor
    Node(string paper_title, int num_auth, vector<string> auth_names, int num_references, vector<string> ref_titles, int year, string journal, string paper_doi);

    // getters
    string get_title();
    int get_num_authors();
    vector<string> get_author_names();
    int get_num_references();
    vector<string> get_reference_titles();
    int get_publish_year();
    string get_journal_name();
    string get_paper_doi();

    // setters
    void set_title(string paper_title);
    void set_num_authors(int num_auth);
    void set_author_names(vector<string> auth_names);
    void set_num_references(int num_references);
    void set_reference_titles(vector<string> ref_titles);
    void set_publish_year(int year);
    void set_journal_name(string journal);
    void set_paper_doi(string paper_doi);

    // debugging 
    void print(); // prints details of node
    bool is_empty();
    // destructor
    ~Node();
};

struct Edge {
    Node src, dst;
};



#endif


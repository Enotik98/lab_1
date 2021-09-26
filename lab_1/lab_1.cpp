#include <iostream>
#include <vector>
using namespace std;

class Tree {
private:
    
    class Node {
    public:
        int idex;
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
        vector<Node*> Leaves;
        Node(int year, int month, int day, int hour, int minute, int second);
    };
    int count;
    Node *root;
public:
    Tree(int year, int month, int day, int hour, int minute, int secoud);
    ~Tree();
    void deleteTree(Node* current);
    
};

Tree::Node::Node(int year, int month, int day, int hour, int minute, int second){
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

Tree::~Tree(){
    deleteTree(root);
}

void Tree::deleteTree(Tree::Node* current){
    for(auto& leaves: current->Leaves){
        deleteTree(leaves);
    }
    cout << "Node" << current << "is deleted" << endl;
    delete current;
    
}

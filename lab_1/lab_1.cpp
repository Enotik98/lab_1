#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Tree {
private:
    class Node {
    public:
        T idex;
        T year;
        T month;
        T day;
        T hour;
        T minute;
        T second;
        vector<Node*> Leaves;
        Node(T year, T month, T day, T hour, T minute, T second);
    };
    int count;
    Node *root;
public:
    Tree(T year, T month, T day, T hour, T minute, T secoud);
    ~Tree();
    void deleteTree(Node* current);
    Node* getRoot();
    Node* deleteNode();
    void outputTree(Node *current, int temp);
    
};

template <typename T>

Tree<T>::Node::Node(T year, T month, T day, T hour, T minute, T second){
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}
template <typename T>
Tree<T>::~Tree(){
    deleteTree(root);
}
template <typename T>
void Tree<T>::deleteTree(Tree::Node* current){
    for(auto& leaves: current->Leaves){
        deleteTree(leaves);
    }
    cout << "Node" << current << "is deleted" << endl;
    delete current;
    
}
template <typename T>
typename Tree<T>::Node* Tree<T>::getRoot(){
    return root;
}
template <typename T>
typename Tree<T>::Node* Tree<T>::deleteNode(){
    Node* curr = root;
    Node* prev = root;
    int temp = -1 , dop;
    
    if (root->Leaves.empty()){
        cout << "No leaves ." << endl;
        return NULL;
    }
    
    while (true){
        if(curr->Leaves.empty()){
            cout << "This node hasn't leaves " << endl;
            prev->Leaves.erase(prev->Leaves.begin()+temp);
            cout << "Node " << curr << " is deleted " << endl;
            return curr;
        }
        
        cout << "Leavs : " ;
        for (int i = 0; i < curr->Leaves.size(); i++){
            cout << i <<" ";
        }
        cout << "\nChoose leavef or '-1'\n ";
        cin >> dop;
        if ( dop == -1){
            if (temp == -1){
                cout << "Can't delete the root" << endl;
                continue;
            }
            prev->Leaves.erase(prev->Leaves.begin()+temp);
            cout << "Node " << curr << " is deleted " << endl;
            return curr;
        }else{
            temp = dop;
            prev = curr;
            curr = curr->Leaves[temp];
        }
    }
}


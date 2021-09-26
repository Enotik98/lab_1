#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Tree {
private:
    template <typename U>
    class Node {
    public:
        int index;
        U data;
        U time;
        vector<Node*> Leaves;
        Node(U data, U time);
    };
    int count;
    Node<T> *root;
public:
    Tree<T>(T data, T time);
    ~Tree<T>();
    void deleteTree(Node<T>* current);
    Node<T>* getRoot();
    Node<T>* deleteNode();
    void outputTree(Node<T> *current, int temp);
    
};

template <typename T>
template <typename U>
Tree<T>::Node<U>::Node(U data, U time){
    this->data = data;
}
template <typename T>
Tree<T>::~Tree(){
    deleteTree(root);
}
template <typename T>
void Tree<T>::deleteTree(Tree::Node<T>* current){
    for(auto& leaves: current->Leaves){
        deleteTree(leaves);
    }
    cout << "Node" << current << "is deleted" << endl;
    delete current;
    
}
template <typename T>
typename Tree<T>::template Node<T>* Tree<T>::getRoot(){
    return root;
}
template <typename T>
template <typename U>
Tree<T>::Node<U>* Tree<T>::deleteNode(){
    Node<U>* curr = root;
    Node<U>* prev = root;
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
template <typename T>
void Tree<T>::outputTree(Node<T>* current, int temp){
    cout << current->index << ": " << current << " date";
}

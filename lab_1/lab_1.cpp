#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Tree {
public:
    
    class Node {
    public:
        int index;
        T data;
        T time;
        vector<Node*> Leaves;
        Node(T data, T time);
    };
    int count;
    Node *root;

    Tree<T>(T data, T time);
    ~Tree<T>();
    void deleteTree(Node* current);
    Node* getRoot();
    Node* deleteNode();
    void outputTree(Node *current, int temp);
    void insert(T data, T time);
    void setIndex(Node* current);
    void printNode(Node* current);
    void defOutput();
};

template <typename T>
Tree<T>::Node::Node(T data, T time){
    this->data = data;
}
template <typename T>
Tree<T>::~Tree(){
    deleteTree(root);
}
template <typename T>
void Tree<T>::deleteTree(Tree<T>::Node* current){
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
template <typename T>
void Tree<T>::outputTree(Node* current, int temp){
    cout << current->index << ": " << current << " data= " << current->data << "|" << " time= " << current->time << "\n";
    temp++;
    for(int i = 0;i < current->Leaves.size();i++){
        for(int j = 0;j < temp; j++){
            cout << "\t";
        }
        cout << i << ". ";
        outputTree(current->Leaves[i], temp);
    }
}
template <typename T>
void Tree<T>::insert(T data, T time){
    Node* curr = root;
    int temp;
    if(root->Leaves.empty()){
        Node* newNode = new Node(data,time);
        count++;
        Tree<T>::setIndex(newNode);
        root->Leaves.push_back(newNode);
        return ;
    }
    
    while(true){
        Tree<T>::outputTree(curr, 1);
        if(curr->Leaves.empty()){
            Node* newNode = new Node(data, time);
            count++;
            Tree<T>::setIndex(newNode);
            curr->Leaves.push_back(newNode);
            return;
        }
        cout << "Leaves: ";
        for(int i = 0;i < curr->Leaves.size();i++){
            cout << i << " ";
        }
        cout<<"\nChoose the leap or enter '-1'\n";
        cin >> temp;
        if(temp == -1){
            Node* newNode = new Node(data, time);
            count++;
            Tree<T>::setIndex(newNode);
        }else{
            curr = curr->Leaves[temp];
        }
    }
    
}
template <typename T>
void Tree<T>::setIndex(Tree<T>::Node* current){
    current->index = count;
}
template <typename T>
void Tree<T>::printNode(Tree<T>::Node* current){
    cout << current->index << ": " << current->data << " " << current->time;
}
template <typename T>
void Tree<T>::defOutput(){
    outputTree(root, 0);
}

template<typename U>
class BinaryTree{
public:
    class Node{
    public:
    U index;
    U date;
    U time;
    Node* left;
    Node* right;
        Node(U index, U date, U time);
    };
    Node* root;
    int count;
    
    BinaryTree(U date, U time);
    ~BinaryTree();
    void printUtil(Node* current, int space);
    void deleteTree();
    Node* deleteNode();
    Node* getRoot();
    void setIndex(Node* current);
    void insert(U date, U index);
    
};
template<typename U>
BinaryTree<U>::~BinaryTree(){
    printUtil(root, 0);
    deleteTree();
}
template<typename U>
void BinaryTree<U>::printUtil(Node* current, int space){
    if(current == NULL){
        return ;
    }
    space += count;
    printUtil(current->right, space);
    cout<<"\n";
    for(int i = count; i < space; i++){
        cout<<" ";
    }
    cout << current->date << " | "<<current->time<<"\n";
    printUtil(current->left, space);
}
template<typename U>
void BinaryTree<U>::deleteTree(){
    while(root != NULL){
        deleteNode();
    }
}
template<typename U>
typename BinaryTree<U>::Node* BinaryTree<U>::deleteNode(){
    Node* prev = root;
    Node* curr = root;
    //Если нету потомков, то удаляем указатели на корень
    if((root->left == NULL) && (root->right == NULL)){
        cout << "Root hasn't got leaves";
        root = NULL;
        cout << "Tree with root"<<curr<<"is deleted"<<endl;
        return NULL;
    }
    //Проходим повсему дереву и удаляем указатели
    while(true){
        if (curr->left != NULL){
            prev = curr;
            curr = curr->left;
        }else{
            if((curr->left == NULL) && (curr->right != NULL)){
                prev = curr;
                curr = curr->right;
            }else {
                cout << "Node" << curr<<" is deleted "<< endl;
                if(prev->left == curr){
                    prev->left = NULL;
                }else{
                    prev->right = NULL;
                }
                curr = NULL;
                return NULL;
            }
        }
    }
}
template <typename U>
typename BinaryTree<U>::Node* BinaryTree<U>::getRoot(){
    return root();
}
template <typename U>
void BinaryTree<U>::setIndex(Node* current){
    current->index = count;
}
template <typename U>
void BinaryTree<U>::insert(U date, U time){
    Node* curr = root;
    int tmp;
    while(true){
        if( (curr->left != NULL)&&(curr->right != NULL )){
            cout<<"Chode the Node we need to go"<<endl;
            cout<<"Left: "<<curr->left<<"\t"<<"Right: "<<curr->right<<endl;
            cin>>tmp;
            switch (tmp) {
                case 1:
                    curr = curr->left;
                    break;
                case 2:
                    curr = curr->right;
                    break;
                default:
                    cout <<"Not integer expression"<<endl;
                    break;
            }
        }else{
            if( (curr->left ==NULL) && (curr->right != NULL)){
                cout<<"Chooose the Node we need ";
            }
        }
    }
}
int main(){
    Tree<int> tre(23, 45);
    tre.insert(56, 88);
    
    
    return 0;
}

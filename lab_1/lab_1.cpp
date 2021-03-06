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
    //????????????
    void printUtil(Node* current, int space);
    void outputUtil(Node* current, int space);
    void printNode(Node* current);
    
    
    Node* deleteNode();
    Node* getRoot();
    Node* getParent(Node* current, Node* tree);
    
    void setIndex(Node* current);
    void insert(U date, U index);
    void deleteTree();
    void serchNodeByValue(U date, U time);
    void deleteNodeByValue(U date, U time);
    
    bool checkValues(Node* current, U date, U time);
    bool checkEqual(Node* current, Node* newNode);
    bool checkEqual(Node* current, U date, U time);
    bool check2Nodes(Node* current, Node* newNode);
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
void BinaryTree<U>::outputUtil(Node *current, int space){
    if(root == NULL) return;
    space += count;
    outputUtil(root->right, space);
    cout<<"\n";
    for(int i = count; i < space;i++) cout <<" ";
    cout << root->date<<" | "<<root->time<<endl;
    outputUtil(root->left, space);
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
    //???????? ???????? ????????????????, ???? ?????????????? ?????????????????? ???? ????????????
    if((root->left == NULL) && (root->right == NULL)){
        cout << "Root hasn't got leaves";
        root = NULL;
        cout << "Tree with root"<<curr<<"is deleted"<<endl;
        return NULL;
    }
    //???????????????? ?????????????? ???????????? ?? ?????????????? ??????????????????
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
                cout<<"Chooose the Node we need to go\n Left(new): "<<curr->left<<"\t"<<"Right(new): "<<curr->right<<endl;
                cin >> tmp;
                switch (tmp){
                    case 1:
                        curr->left = new Node(date, time);
                        count ++;
                        setIndex(curr->left);
                        return ;
                    case 2:
                        curr->right = new Node(date, time);
                        count ++;
                        setIndex(curr->right);
                        return;
                        default:
                        break;
                }
            }
        }
    }
}
template<typename U>
typename BinaryTree<U>::Node* BinaryTree<U>::getParent(Node* current, Node* tree){
    Node* parent = getParent(current, tree);
    if(!checkEqual(current, tree)){
        if(check2Nodes(current, tree)){ //???????? current ???????????? ?????? tree
            Node *result = getParent(tree->left, tree);//?????????? ???????????????? ?????? tree->left(??????????????????)
            if(result) result;
            return tree;
        }else if(!check2Nodes(current, tree)){
            Node* result = getParent(tree->right, current);
            if(result) return result;
            return tree;
        }
    }else return NULL;
}
template <typename U>
bool BinaryTree<U>::checkEqual(Node *current, Node *newNode){
    if(current->date == newNode->date){
        if(current->time == newNode->time){
            return true;
        }else return false;
    }else return false;
}

template <typename U>
bool BinaryTree<U>::check2Nodes(Node *current, Node *newNode){
    if(current->date <= newNode->date){
        if(current->time <= newNode->time){
            return true;
        }else return false;
    }else return false;
}
template <typename U>
bool BinaryTree<U>::checkEqual(Node* current, U date, U time){
    if(current->date == date){
        if(current->time == time){
            return true;
        }else return false;
    }else return false;
}

template <typename U>
void BinaryTree<U>::serchNodeByValue(U date, U time){
    Node* curr = root;
    while(true){
        if(checkValues(curr, date, time)){
            if(checkEqual(curr, date, time)){
                printNode(curr);
            }else{
                if(curr->left != NULL){
                    curr = curr->left;
                }else{
                    cout<<"Can't search nothing more"<<endl;
                    return;
                }
            }
        }else{
            if(curr->right != NULL){
                curr = curr->right;
            }else{
                cout<<"Can't search nothing more"<<endl;
                return;
            }
        }
    }
}
template <typename U>
bool BinaryTree<U>::checkValues(Node *current, U date, U time){
    if(current->date >= date){
        if(current->time >= time){
            return true;
        }else return false;
    }else return false;
}
template<typename U>
void BinaryTree<U>::printNode(Node *current){
    cout<<current->index<<": "<<current->date<<" | "<<current->time<<"\n";
}
template <typename U>
void BinaryTree<U>::deleteNodeByValue(U date, U time){
    Node* curr = root;
    Node* parent = getParent(root, curr);
    if(curr->left == NULL && curr->right == NULL){
        if(checkEqual(curr, date, time)){
            if(parent->left == curr){
                parent->left = NULL;
            }else{
                parent->right = curr->right;
                curr = parent->right;
            }
        }else{
            if(parent->left == curr){
                parent->left = curr->right;
                curr = parent->right;
            }else{
                parent->right = curr->right;
                curr = parent->right;
            }
        }
    }else{
        
    }
}
//===================================================

template <typename U>
class BinarySearchTree{
public:
    class Node{
    public:
        int index;
        U date;
        U time;
        Node* left;
        Node* right;
        Node(U date, U time);
    };
    Node* root;
    int count;
    
    BinarySearchTree(U date, U time);
    ~BinarySearchTree();
    
    void deleteTree();
    void setIndex(Node* current);
    void insert(U date, U time);
    void searchNodeByValue(U date, U time);
    void deleteNodeByValue(U date, U time);
    
    //??????????
    void printNode(Node* current);
    
    bool checkValues(Node* current, U date, U time);
    bool checkEqual(Node* current, U date, U time);
    bool checkEqual(Node* current, Node* newNode);
    bool check2Nodes(Node* current, Node* newNode);
    
    Node* getParent(Node* current, Node* tree);
    Node* deleteNode();
    
};
template <typename U>
BinarySearchTree<U>::Node::Node(U date, U time){
    this->date = date;
    this->time = time;
    left = right = NULL;
}

template <typename U>
BinarySearchTree<U>::BinarySearchTree(U date, U time){
    count = 1;
    root = new Node(date, time);
}
template <typename U>
BinarySearchTree<U>::~BinarySearchTree(){
    deleteTree();
}
template <typename U>
void BinarySearchTree<U>::deleteTree(){
    while(root != NULL){
        deleteNode();
    }
}
template <typename U>
typename BinarySearchTree<U>::Node* BinarySearchTree<U>:: deleteNode(){
    Node* prev = root;
    Node* curr = root;
    if((root->left == NULL)&&(root->right ==NULL)){
        root == NULL;
        return NULL;
    }
    while(true){
        if(((curr->left != NULL) && (curr->right == NULL)) || ((curr->left != NULL) && (curr->right != NULL))){
            prev = curr;
            curr = curr->left;
        }else if((curr->left == NULL) && (curr->right != NULL)){
            prev = curr;
            curr = curr->right;
        }else{
            if (prev->left == curr){
                prev->left = NULL;
            }else {
                prev->right = NULL;
            }
            curr = NULL;
            return NULL;
        }
    }
}

template <typename U>
void BinarySearchTree<U>::setIndex(Node* current){
    current->index = count;
}

template <typename U>
void BinarySearchTree<U>::insert(U date, U time){
    Node* curr = root;
    while(true){
        if(checkValues(curr, date, time)){
            if(curr->left != NULL){
                curr = curr->left;
            }else{
                count++;
                curr->left = new Node(date, time);
                setIndex(curr->left);
                return;
            }
        }
    }
}

template <typename U>
bool BinarySearchTree<U>::checkValues(Node *current, U date, U time){
    if(current->date == date){
        if(current->time == time){
            return true;
        }else return false;
    }else return false;
}
template <typename U>
bool BinarySearchTree<U>::checkEqual(Node *current, U date, U time){
    if(current->date == date){
        if(current->time == time){
            return true;
        }else return false;
    }else return false;
}
template <typename U>
void BinarySearchTree<U>::searchNodeByValue(U date, U time){
    Node* curr = root;
    while(true){
        if(checkValues(curr, date, time)){
            if(checkEqual(curr, date, time)){
                printNode(curr);
            }else{
                if(curr->left != NULL){
                    curr = curr->left;
                }else{
                    cout<<"Can't search nothing more"<<endl;
                    return;
                }
            }
        }else{
            if(curr->right != NULL){
                curr = curr->right;
            }else{
                cout<<"Can't search nothing more"<<endl;
                return;
            }
        }
    }
}
template <typename U>
bool BinarySearchTree<U>::check2Nodes(Node* current, Node* newNode){
    if(current->date <= newNode){
        if(current->time <= newNode){
            return true;
        }else return false;
    }else return false;
}
template <typename U>
bool BinarySearchTree<U>::checkEqual(Node *current, Node *newNode){
    if(current->date == newNode->date){
        if(current->time == newNode->time){
            return true;
        }else return false;
    }else return false;
}
template <typename U>
void BinarySearchTree<U>::printNode(Node *current){
    cout<<current->index<<": "<<current->date<<" | "<<current->time<<"\n";
}
template <typename U>
typename BinarySearchTree<U>::Node* BinarySearchTree<U>::getParent(Node *current, Node *tree){
    Node* parent = NULL;
    if(!checkEqual(current, tree)){
        if(check2Nodes(current, tree)){
            parent = getParent(tree->left, current);
            if(parent){
                return parent;
            }
            return tree;
        }else{
            if(!check2Nodes(current, tree)){
                parent = getParent(tree->right, current);
                if(parent){
                    return parent;
                }
                return tree;
            }
           }
    }else{
        return NULL;
    }
}
template <typename U>
void BinarySearchTree<U>::deleteNodeByValue(U date, U time){
    Node* curr = root;
    Node* parent = getParent(root, curr);
    //?????????????? ???????? ?????????????? ????????????????????
    if(curr->left == NULL && curr->right == NULL){
        if(!checkEqual(curr, date, time)){
            return;
        }else{
            if(parent->left == curr){
                parent->left = NULL;
                return;
            }else if(parent->right == curr){
                parent->right = NULL;
                return;
            }
        }
    }else{
        //???????? 1 ??????????????
        if (curr->left == NULL || curr->right == NULL){
            if(checkEqual(curr, date, time)){
                if(curr->left == NULL){
                    if(parent->left == NULL){
                        parent->left = curr->right;
                    }else{
                        parent->right = curr->right;
                    }
                }else{
                    if(parent->left == curr){
                        parent->left = curr->left;
                    }else
                        parent->right = curr->left;
                }
            }else{
                if(curr->left == NULL){
                    if(!checkValues(curr, date, time)){
                        curr = curr->right;
                    }else{
                        return;
                    }
                }else{
                    if(curr->right == NULL){
                        if(checkValues(curr, date, time)){
                            curr = curr->left;
                        }else {
                            return;
                        }
                    }
                }
            }
        }else{
            //???????? 2 ??????????????
            while(true){
                parent = getParent(root, curr);
                Node* tmp = curr->left;
                if(parent != NULL){
                    if((curr->left == NULL && curr->right == NULL) && (!checkEqual(curr, date, time))){
                        return;
                    }else{
                        if(checkEqual(curr, date, time)){
                            if(parent->left == curr){
                                parent->left = tmp;
                            }else{
                                parent->right = tmp;
                            }
                            while(tmp->right){
                                tmp = tmp->right;
                            }
                            tmp->right = curr->right;
                            curr = tmp;
                        }else{
                            if(!checkEqual(curr, date, time)){
                                if(curr->left != NULL && curr->right != NULL){
                                    if(checkValues(curr, date, time)){
                                        curr = curr->right;
                                    }else{
                                        curr = curr->left;
                                    }
                                }else{
                                    if(curr->left != NULL){
                                        curr = curr->left;
                                    }else{
                                        curr = curr->right;
                                    }
                                }
                            }else{
                                if(!checkEqual(curr, date, time)){
                                    if(checkValues(curr, date, time)&& curr->left != NULL){
                                        curr = curr->left;
                                    }else{
                                        if(!checkValues(curr, date, time) && curr->right != NULL){
                                            curr = curr->right;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


int main(){
    
    
    return 0;
}

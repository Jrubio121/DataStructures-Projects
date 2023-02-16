//Jared Rubio


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node {
private:
    Node* parent;
    Node* left;
    Node* right;
    int SID;
public:
    Node();
    void SetParent(Node* ptr);
    void SetLeft(Node* ptr);
    void SetRight(Node* ptr);
    void SetSID(int data);
    Node* GetParent();
    Node* GetLeft();
    Node* GetRight();
    int GetSID();
};
Node::Node() {
    parent = NULL;
    left = NULL;
    right = NULL;
    SID = -1;
};
void Node::SetParent(Node* ptr) {
    parent = ptr;
};
void Node::SetLeft(Node* ptr) {
    left = ptr;
};
void Node::SetRight(Node* ptr) {
    right = ptr;
};
void Node::SetSID(int data) {
    SID = data;
};
Node* Node::GetParent() {
    return parent;
};
Node* Node::GetLeft() {
    return left;
};
Node* Node::GetRight() {
    return right;
};
int Node::GetSID() {
    return SID;
};

class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree();
    void SetRoot(Node* ptr);
    Node* GetRoot();
    void PreTraverse(Node* ptr);
    int SizeHelp();
    int Size();
    Node* Search(Node* ptr, int key);
    void Add(Node* ptr);
    Node* FindMax(Node* ptr);
    Node* FindMin(Node* ptr);
    Node* RemoveHelp(Node* node, int key);
    void Remove1(int key);
    void Remove2(int key);
};
BinarySearchTree::BinarySearchTree() {
    root = NULL;
};
void BinarySearchTree::SetRoot(Node* ptr) {
    root = ptr;
};
Node* BinarySearchTree::GetRoot() {
    return root;
};
void BinarySearchTree::PreTraverse(Node* ptr) {
    if (ptr->GetSID() == -1) {
        return;
    }
    else {
        cout << ptr->GetSID() << endl;
        PreTraverse(ptr->GetLeft());
        PreTraverse(ptr->GetRight());
    }
};
int BinarySearchTree::SizeHelp(){
    int count = 0;
    queue<Node*> Q;
    Q.push(root);
    
    while(!Q.empty()){
        if(Q.front()->GetLeft() != NULL){
            Q.push(Q.front()->GetLeft());
            count++;
        }
        if(Q.front()->GetRight() != NULL){
            Q.push(Q.front()->GetRight());
            
        }
        Q.pop();
    }
    return count;
}
int BinarySearchTree::Size(){
    return SizeHelp();
};
Node* BinarySearchTree::Search(Node* ptr, int key){
    if(ptr->GetSID() == -1){
        return ptr;
    }
    else if(ptr->GetSID() == key){
        return ptr;
    }
    else if(ptr->GetSID() >= key){
        return Search(ptr->GetLeft(),key);
    }
    else{
        return Search(ptr->GetRight(),key);
    }
    
};
void BinarySearchTree::Add(Node* ptr){
    
    if(root == NULL){
        SetRoot(ptr);
        ptr->SetLeft(new Node);
        ptr->SetRight(new Node);
        ptr->GetLeft()->SetParent(ptr);
        ptr->GetRight()->SetParent(ptr);
        return;
    }
    else {
        Node* temp = Search(root,ptr->GetSID());
        temp = temp->GetParent();
    
        if(ptr->GetSID() > temp->GetSID()){
            temp->SetRight(ptr);
        }
        else{
            temp->SetLeft(ptr);
        }
        
        ptr->SetParent(temp);
        ptr->SetLeft(new Node);
        ptr->SetRight(new Node);
        ptr->GetLeft()->SetParent(ptr);
        ptr->GetRight()->SetParent(ptr);
    }
};
Node* BinarySearchTree::FindMax(Node* ptr){
    while(ptr->GetRight() != NULL && ptr->GetRight()->GetSID() != -1){
        ptr = ptr->GetRight();
    }
    return(ptr);

};
Node* BinarySearchTree::FindMin(Node* ptr){
    
    while(ptr->GetLeft() != NULL && ptr->GetLeft()->GetSID() != -1){
        ptr = ptr->GetLeft();
    }
    return(ptr);
};
void BinarySearchTree::Remove1(int key){
    Node* temp = FindMin(root->GetRight());
    
    if(temp->GetSID() == -1){
        return;
    }
    
      
};
void BinarySearchTree::Remove2(int key){
    Node* temp = Search(root, key);
    
    if(temp->GetSID() == -1){
        return;
    }
        if(temp->GetParent()->GetRight() == temp){
            temp->GetParent()->SetRight(temp->GetLeft());
        }
        else{
            temp->GetParent()->SetLeft(temp->GetLeft());
        }
        return;
};

int main()
{
    int mode, key;
    cin >> mode >> key;
    BinarySearchTree x;
    int temp_SID;
    Node* temp_node;
    // now we construct the tree using "Add"
    while (cin >> temp_SID) {
        temp_node = new Node;
        temp_node->SetSID(temp_SID);
        x.Add(temp_node);
    }
    switch (mode) {
    case 1: // check the "Size" function
        cout << x.Size();
        break;
    case 2: // check the "Add" function
        x.PreTraverse(x.GetRoot());
        break;
    case 3: // check the "FindMax" function, assuming tree is not empty
        cout << x.FindMax(x.GetRoot())->GetSID();
        break;
    case 4: // check the "FindMin" function, assuming tree is not empty
        cout << x.FindMin(x.GetRoot())->GetSID();
        break;
    case 5: // check the "Remove1" function
        x.Remove1(key);
        x.PreTraverse(x.GetRoot());
        break;
    case 6: // check the "Remove2" function
        x.Remove2(key);
        x.PreTraverse(x.GetRoot());
        break;
    }
    return 0;
}


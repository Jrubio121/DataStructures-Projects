// Jared Rubio

#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* link_next;
public:
    void SetData(int x);
    int GetData();
    void SetLink_Next(Node* ptr);
    Node* GetLink_Next();
    Node();
};
Node::Node() {
    data = 0;
    link_next = NULL;
}
void Node::SetData(int x) {
    data = x;
}
int Node::GetData() {
    return data;
}
void Node::SetLink_Next(Node* ptr) {
    link_next = ptr;
}
Node* Node::GetLink_Next() {
    return link_next;
}

class SList {
private:
    Node* head;
public:
    
    SList();
    void Print();
    void SetHead(Node* ptr);
    Node* GetHead();

    int GetSize();
    int LinearSearch(int key);
    void Add(int val, int idx);
    void Remove(int idx);
    void Reverse();
};

SList::SList() {
    head = NULL;
}
void SList::Print() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->GetData() << endl;
        temp = temp->GetLink_Next();
    }
}
Node* SList::GetHead() {
    return head;
}
void SList::SetHead(Node* ptr) {
    head = ptr;
}

int SList::GetSize(){
    int count = 0;
    
    Node* move = head;
    
    while(move != NULL){
        count++;
        move = move->GetLink_Next();
    }
    
    return count;
}

int SList::LinearSearch(int key){
    
    Node* temp = GetHead();
    int idx = 0;
    
    while(temp != NULL){
        
        if(temp->GetData() == key){
            return idx;
        }
        temp = temp->GetLink_Next();
        idx++;
        
    }
    
    return -1;
}

void SList::Add(int val, int idx){
    
    // initializing the node
    Node* temp = new Node();
    temp->SetData(val);
    
    if(idx == 0){
        temp->SetLink_Next(head);
        head = temp;
    }
    
    // initializing the tail
    else if (GetSize() <= idx){
        Node* temp2 = head;
        while (temp2->GetLink_Next() != NULL) {
            temp2 = temp2->GetLink_Next();
        }
        temp2->SetLink_Next(temp);
        
    }
    // initializing the middle
        else {
            Node* temp2 = head;
            int pos{0};
            while(pos != idx-1){
                temp2 = temp2->GetLink_Next();
                ++pos;
            }
            temp->SetLink_Next(temp2->GetLink_Next());
            temp2->SetLink_Next(temp);
        }
        
    }

void SList::Remove(int idx){
    
    Node* temp = head;
    
    if(idx == 0){
        head = temp->GetLink_Next();
        free(temp);
        return;
    }
    
    for(int i = 0; temp != NULL && i < idx - 1; ++i){
        temp = temp->GetLink_Next();
        
        if(temp == NULL || temp->GetLink_Next() == NULL){
            return;
        }
        
        Node* after = temp->GetLink_Next()->GetLink_Next();
        
        free(temp->GetLink_Next());
        
        temp->SetLink_Next(after);
    }
}

void SList::Reverse(){
    
    Node* current = head;
    Node* previous = NULL;
    Node* after = NULL;
    
    while(current != NULL){
        
        after = current->GetLink_Next();
        current->SetLink_Next(previous);
        
        previous = current;
        current = after;
    }
    head = previous;
}

Node* Merge(Node* one, Node* two){
    
    Node* help = new Node();
    Node* helper = help;
    
    while(one!= NULL && two != NULL){
        if(one->GetData() < two->GetData()){
            helper->SetLink_Next(one);
            one = one->GetLink_Next();
        }
        else{
            helper->SetLink_Next(two);
            two = two->GetLink_Next();
        }
        helper = helper->GetLink_Next();
    }
    
    if(one != NULL)
        helper->SetLink_Next(one);
    
    if(two != NULL)
        helper->SetLink_Next(two);
    
    return help->GetLink_Next();
}

Node* MergeSort(Node* ptr) {
    SList *one = new SList();
    SList *two = new SList();
    
    int size = 0;
    Node *help = ptr;
    
    while(help!=NULL){
        ++size;
        help = help->GetLink_Next();
    }
    
    if(size < 2) return ptr;
    
    int mid = size/2;
    Node* helper = ptr;
    
    for(int i = 0; i < mid; ++i){
        one->Add(helper->GetData(), i);
        helper = helper->GetLink_Next();
    }
    
    for(int i = mid; i < size; ++i){
        int temp = 0;
        two->Add(helper->GetData(), temp);
        ++temp;
        helper = helper->GetLink_Next();
    }
    
    one->SetHead(MergeSort(one->GetHead()));
    two->SetHead(MergeSort(two->GetHead()));
    
    SList *sort = new SList();
    sort->SetHead(Merge(one->GetHead(),two->GetHead()));
    
    return sort->GetHead();
}

int main()
{

    SList x;
    int mode, value, idx, key, temp;

    cin >> mode >> value >> idx >> key;

    for (int i = 0; i < 4; i++) {
        cin >> temp;
        x.Add(temp,0);
    }

    switch (mode) {

    case 1:
        x.Print();
        break;

    case 2:
        cout << x.GetSize();
        break;

    case 3:
        cout << x.LinearSearch(key);
        break;

    case 4:
        x.Add(value, idx);
        x.Print();
        break;

    case 5:
        x.Remove(idx);
        x.Print();
        break;

    case 6:
        x.Reverse();
        x.Print();
        break;

    case 7:
        x.SetHead(MergeSort(x.GetHead()));
        x.Print();
        break;
    }

    return 0;
}

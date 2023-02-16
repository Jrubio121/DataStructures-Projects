// Jared Rubio
// HW4_Hash_template.cpp
// 11/8/2022

#include <iostream>
#include <vector>
using namespace std;
enum major { CS, CE, NA };
class Student {
public:
    int SID;
    enum major MAJ;
    Student* next;
    Student();
};
Student::Student() {
    SID = -1;
    MAJ = NA;
    next = NULL;
};
class HashTable {
private:
    Student** table;
    int size;
public:
    HashTable(int table_size);
    void Add_Head(Student x);
    void Add_Order(Student x);
    void Remove(int key);
    enum major Search(int key);
    void Print();
    int Hash(int key);
};
HashTable::HashTable(int table_size) {
    size = table_size;
    table = new Student * [size];
    for (int i = 0; i < size; i++) {
        table[i] = NULL;
    }
};
int HashTable::Hash(int key) {
    return key % size;
};

void HashTable::Add_Head(Student x){
    
    Student* temp = new Student(x);
    int key = Hash(x.SID);
    Student* current = table[key];
    temp->next = current;
    table[key] = temp;
    
}
    
void HashTable::Add_Order(Student x){
    
    int key = Hash(x.SID);
    
    Student* temp = new Student(x);
    
    if(table[key] == NULL){
        table[key] = temp;
    }
    else{
        Student* head = table[key];
        
        if(head->SID > temp->SID){
           temp->next = head;
            table[key] = temp;
        }
    
       else{
           while(head->next != NULL){
               if(head->next->SID > temp->SID){
                   temp->next = head->next;
                   head->next = temp;
                   break;
               }
               else{
                   head = head->next;
               }
           }
           if(head->next == NULL){
               head->next = temp;
           }
       }
    }
}

void HashTable::Remove(int key){
    
    Student* head = table[Hash(key)];
    
   
    if(table[Hash(key)] == NULL){
        return;
    }
    else{
        
        while(head != NULL){
           
            if(key == head->SID){
                Student* temp;
                int help = head->next->SID;
                temp = head->next;
                head->next = nullptr;
                head->SID = help;
                break;
            }
            else if(key == head->next->SID){
                Student* temp;
                temp = head->next;
                head->next = nullptr;
                break;
            }
         
            head = head->next;
        }
    }
    
}
enum major HashTable::Search(int key){
    
    if(table[Hash(key)] == NULL){
        return NA;
    }
    else{
        Student* temp = table[Hash(key)];
        
        while(temp!=NULL){
            if(temp->SID == key){
                return temp ->MAJ;
            }
            else{
                temp = temp->next;
            }
        }
        return NA;
    }
}

void HashTable::Print() {
    Student* temp;
    
    for(int i = 0; i < size; i++){
        temp = table[i];
        
        while(temp!=NULL){
            cout<< temp->SID << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    int mode, size, key, sid, maj;
    vector<Student> input;
    Student temp;
    
    cin >> mode >> size >> key;
   
    while (cin >> sid >> maj) {
        temp.SID = sid;
        temp.MAJ = static_cast<enum major>(maj);
        input.push_back(temp);
    };
    
    HashTable x(size);
    switch (mode) {
    case 1:
        for (int i = 0; i < input.size(); i++) {
            x.Add_Head(input.at(i));
        }
        x.Print();
        break;
    case 2:
        for (int i = 0; i < input.size(); i++) {
            x.Add_Order(input.at(i));
        }
        x.Print();
        break;
    case 3:
        for (int i = 0; i < input.size(); i++) {
            x.Add_Order(input.at(i));
        }
        switch (x.Search(key)) {
        case 0:
            cout << "CS" << endl;
            break;
        case 1:
            cout << "CE" << endl;
            break;
        case 2:
            cout << "NA" << endl;
            break;
        }
            break;
    case 4:
        for (int i = 0; i < input.size(); i++) {
            x.Add_Order(input.at(i));
        }
        x.Remove(key);
        x.Print();
        break;
    }
    return 0;
}


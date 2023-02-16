//
//  hw1_binarySearch.cpp
//  Assignment 1
//
//  Created by Jared Rubio on 9/11/22.
//

#include <iostream>
using namespace std;
class Student {
public:
    void SetSID(int a);
    int GetSID();
private:
    int SID;
};

void Student::SetSID(int a) {
    SID = a;
};

int Student::GetSID() {
    return SID;
};
int* BinarySearch(Student* ptr, int arr_size, int key) {
    
    int last = arr_size - 1;
    int first = 0;
    int mid = 0;
    bool isFound = false;
    int number = 0;
    static int val[2];

    while(first <= last && !isFound){
        mid = (first + last) / 2;
        
        if(key > ptr[mid].GetSID()){
            first = mid + 1;
            number++;

        }
        else if(key < ptr[mid].GetSID()){
            last = mid - 1;
            number++;

        }
        else{
            number++;
            val[0] = mid;
            val[1] = number;
            isFound = true;
        }
    }
    
    if(!isFound){
        val[0] = -1;
        val[1] = number;
    }

    
    return val;
}
int CheckOrder(Student* ptr, int arr_size) {
    
    for(int i = 1; i < arr_size; i++){
        if(ptr[i-1].GetSID() > ptr[i].GetSID()){
            return 0;
        }
    }
    return 1;
}
int main()
{
    
    Student x[7];
    int temp, key, mode, *value;
    cin >> mode >> key;
    for (int i = 0; i < 7; i++) {
        
        cin >> temp;
        x[i].SetSID(temp);
    }
    switch (mode) {
    
    case 1:
        
        cout << CheckOrder(x, 7) << endl;
        break;
    case 2:
        if (CheckOrder(x, 7)) {
            value = BinarySearch(x, 7, key);
            cout << value[0] << endl;
        }
        else {
            cout << -2 << endl;
        }
        break;
    case 3:
        if (CheckOrder(x, 7)) {
            value = BinarySearch(x, 7, key);
            cout << value[1] << endl;
        }
        else {
            cout << -2 << endl;
        }
        break;
    }
    return 0;
}

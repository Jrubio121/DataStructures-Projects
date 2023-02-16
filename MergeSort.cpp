//
//  MergeSort.cpp
//  Merge Sort
//
//  Created by Jared Rubio on 10/2/22.
//

#include <iostream>
#include <vector>
using namespace std;

class MergeSort {
public:
    void SetList(vector<int> InputList){
        list = InputList;
    }
    vector<int> GetList(){
        return list;
    }
    void SortList();
private:
    vector<int> list;
    vector<int> RecursiveSort(vector<int> x){
        if(x.size() == 1){
            return x;
        }
        
        
        vector<int> list_l(x.begin(), x.begin() + (x.size() / 2));
        vector<int> list_r(x.begin() + (x.size() / 2), x.end());
       
        list_l = RecursiveSort(list_l);
        list_r = RecursiveSort(list_r);
        
        x = merge(list_l, list_r);
        
        return x;
    }
    
    vector<int>merge(vector<int> left, vector<int> right){
        int x = 0;
        int y = 0;
        vector<int> result;
        
        while(x < left.size() && y < right.size()){
            if(left.at(x) <= right.at(y)){
                result.push_back(left.at(x));
                ++x;
            }
            else{
                result.push_back(right.at(y));
                ++y;
            }
        }
        
        while(x < left.size()){
            result.push_back(left.at(x));
            ++x;
        }
        
        while(y < right.size()){
            result.push_back(right.at(y));
            ++y;
        }
        
        return result;
        
    }
};

void MergeSort::SortList() {
    
    vector<int> list_l(list.begin(), list.begin() + (list.size() / 2));
    vector<int> list_r(list.begin() + (list.size() / 2), list.end());
   
    list_l = RecursiveSort(list_l);
    list_r = RecursiveSort(list_r);
        
    list = merge(list_l, list_r);
};

int main()
{
   
    vector<int> InputList;
    vector<int> TestList;
    int temp, mode;
    MergeSort x;
    // takie inputs
    cin >> mode;
    while (cin >> temp) {
        InputList.push_back(temp);
    }
    x.SetList(InputList);

    switch (mode) {
    case 1:
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 2:
        x.SortList();
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    }
    return 0;
}

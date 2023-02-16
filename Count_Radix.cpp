//
//  Count_Radix.cpp
//  Count Radix
//
//  Created by Jared Rubio on 10/2/22.
//

#include <iostream>
#include <vector>
using namespace std;

class CountSort {
public:
    void SetList(vector<int> InputList){
        list = InputList;
    }
    vector<int> GetList(){
        return list;
    }
    int ListMax(){
        int max = 0;
        
        for(int i = 0; i < list.size(); ++i){
            if(list[i] > max){
                max = list[i];
            }
        }
        return max;
    }
    void SortList(){
       int max = ListMax();
        vector<int> count(max + 1);
        vector<int> result;
        
        for(int i = 0; i < max + 1; ++i){
            count[i] = 0;
        }
        
        for(int j = 0; j < list.size(); ++j){
            count[list[j]]++;
        }
        
        for(int h = 0; h < max + 1; ++h){
            while(count[h] > 0){
                result.push_back(h);
                count[h]--;
            }
            list = result;
        }
        
        
    }
private:
    vector<int> list;
};

class RadixSort {
public:
    void SetList(vector<int> InputList){
        list = InputList;
    }
    vector<int> GetList(){
        return list;
    }
    int GetNumBit(){
        int max = 0;
        
        for(int i = 0; i < list.size(); ++i){
            if(list[i] > max){
                max = list[i];
            }
        }
        return to_string(max).length();
    }
    vector<int> GetList_byBit(int IdxBit){
        
        IdxBit = IdxBit - 1;
        int temp = IdxBit;
        
        for(int i =0; i < list.size(); ++i){
            IdxBit = temp;
            while(IdxBit>0){
                list[i]/=10;
                --IdxBit;
            }
            list[i] = list[i] % 10;

        }
        return list;
        
    }
    
    void swap(int* helper, int* method){
        int temp = *helper;
        *helper = *method;
        *method = temp;
    }
    
    void SortList_byBit(int IdxBit){
        
        vector<int> temp = GetList();
        list = GetList_byBit(IdxBit);
        
        for(int i = 0; i < list.size(); ++i){
            for(int j = 0; j < list.size() - 1; ++j){
                if(list[j] > list[j+1]){
                    swap(&list[j], &list[j + 1]);
                    swap(&temp[j], &temp[j+1]);
                }
            }
        }
        
        list = temp;
        
    }
private:
    vector<int> list;
}
;

int main()
{
  
    vector<int> InputList;
    vector<int> TestList;
    int temp, mode, IdxBit;
    CountSort x;
    RadixSort y;

    cin >> mode >> IdxBit;
    while (cin >> temp) {
        InputList.push_back(temp);
    }

    x.SetList(InputList);
    y.SetList(InputList);
    
    switch (mode) {
    case 1:
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 2:
        TestList = y.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 3:
        cout << x.ListMax() << endl;
        break;
    case 4:
        x.SortList();
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    
    case 5:
        cout << y.GetNumBit() << endl;
        break;
    case 6:
        TestList = y.GetList_byBit(IdxBit);
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 7:
        y.SortList_byBit(IdxBit);
        TestList = y.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    }
    return 0;
}



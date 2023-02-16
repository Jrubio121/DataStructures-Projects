//
//  BasicSort.cpp
//  Basic Sort
//
//  Created by Jared Rubio on 10/2/22.
//

#include <iostream>
#include <vector>
using namespace std;

class BasicSort {
public:
    void SetList(vector<int> InputList){
        list = InputList;
    }
    vector<int> GetList(){
        return list;
    }
    void BubbleSort(int NumRound){
        
        if(NumRound == -1){
            
            int x = static_cast<int>(list.size());
            
            while(x>0){
                
                int val = 0;
                for(int i = 1; i < x; ++i){
                    if(list[i - 1] > list[i]){
                        int temp = list[i - 1];
                        list[i-1] = list[i];
                        list[i] = temp;
                        val = i;
                    }
                }
                x = val;
                
            }
        
        }
        
        else{
            
            for(int i = 0; i < NumRound; ++i){
                for(int j = 0; j < list.size() - 1; ++j){
                    if(list[j] > list[j+1]){
                        swap(&list[j],&list[j+1]);
                    }
                }
            }
            
        }
    }
    
    void swap(int* help, int* method){
        int temp = *help;
        *help = *method;
        *method = temp;
    }
    
    void SelectionSort(int NumRound){
        
        if(NumRound == -1){
            
        for(int i = 0; i < list.size() - 1; ++i){
            
            int min = i;
            for(int j = i + 1; j < list.size(); ++j){
                if(list[j] < list[min]){
                    min = j;
                }
            }
                int val = list[i];
                list[i] = list[min];
                list[min] = val;
            }
        
        }
        
        else{
        for(int i = 0; i < NumRound; ++i){
            
            int min = i;
            for(int j = i + 1; j < list.size(); ++j){
                if(list[j] < list[min]){
                    min = j;
                }
            }
                int val = list[i];
                list[i] = list[min];
                list[min] = val;
            }
        
        }
        
    }
    
private:
    vector<int> list;
};

int main()
{
   
    vector<int> InputList;
    vector<int> TestList;
    int temp, mode, NumRound;
    BasicSort x;
    cin >> mode >> NumRound;
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
        x.BubbleSort(NumRound);
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 3:
        x.BubbleSort(NumRound);
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 4:
        x.SelectionSort(NumRound);
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 5: 
        x.SelectionSort(NumRound);
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    }
    return 0;
}



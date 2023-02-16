//Jared Rubio

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Graph {
private:

vector<vector<int>> adj;
int V;

public:
Graph(int V){
    this->V=V;
    adj= vector<vector<int>>(V,vector<int>(V,false));

}
void AddEdge(int x,int y){
    adj[x][y]=true;
    adj[y][x]=true;
}
void DepthFirstSearchHelper(int start, vector<bool>& checked,vector<int> &ans){

    ans.push_back(start);
    checked[start] = true;

    for (int i = 0; i < adj[start].size(); i++) {
        if (adj[start][i] == 1 && (!checked[i])) {
            DepthFirstSearchHelper(i, checked,ans);
        }
    }
}
void BuildGraph(vector<int> link);
vector<int> DepthFirstTraverse(int i);
vector<int> BreadthFirstTraverse(int i);
};

void Graph::BuildGraph(vector<int> link) {
    
   for(int i=0; i<link.size()-1; i=i+2)
   {
           AddEdge(link[i],link[i+1]);
   }
};

vector<int> Graph::DepthFirstTraverse(int i) {
 vector<bool> checked(V, false);
 
    vector<int> ans;
    DepthFirstSearchHelper(i, checked,ans);
    return ans;

};

vector<int> Graph::BreadthFirstTraverse(int i) {
   
   vector<bool> checked(adj.size(), false);
   vector<int> temp;
   vector<int> ans;
    temp.push_back(i);

    checked[i] = true;
  
    int vis;
    while (!temp.empty()) {
        vis = temp[0];
        ans.push_back(vis);
        temp.erase(temp.begin());
  
        for (int i = 0; i < adj[vis].size(); i++) {
            if (adj[vis][i] == 1 && (!checked[i])) {
  
                temp.push_back(i);
  
                checked[i] = true;
            }
        }
    }
    
    return ans;
};
int main()
{
int mode, temp;
vector<int> input;
vector<int> output;
Graph x(5);
cin >> mode;


while (cin>>temp) {
input.push_back(temp);
}

switch(mode) {
case 0:
x.BuildGraph(input);
output = x.DepthFirstTraverse(input.at(0));
for (int i = 0; i < output.size(); i++) {
cout << output.at(i) << endl;
}
break;
case 1:

x.BuildGraph(input);
output = x.BreadthFirstTraverse(input.at(0));
for (int i = 0; i < output.size(); i++) {
cout << output.at(i) << endl;
}
break;
}
return 0;
}

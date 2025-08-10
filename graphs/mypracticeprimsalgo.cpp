#include<bits/stdc++.h>
using namespace std;
int myprimsalgo(vector<vector<int>> &graph){
    int n=graph.size();
    vector<int> parent(n,-1);   
    vector<int> weight(n,INT_MAX);
    vector<bool> visited(n,false);
    weight[0]=0;
    parent[0]=-1;
    for(int i=0;i<n-1;++i){
        int indx=-1;
        for(int j=0;j<n;j++){
            if(!visited[j] && (indx==-1 || weight[j]<weight[indx])) indx=j;
        }
        for(int j=0;j<n;j++){
            if(!visited[j] && graph[indx][j]!=0 && graph[indx][j]<weight[j]){
                weight[j]=graph[indx][j];
                parent[j]=indx;
            }
        }
    }
}
int main(){
    int n,e;
    return 0;
}
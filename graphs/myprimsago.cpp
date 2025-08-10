#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> graph(n,vector<int>(n,0));
    for (int i = 0; i < e; ++i) {
        int u,v,val;
        cin>>u>>v>>val;
        graph[u][v]=val;
        graph[v][u]=val;
    }
    vector<int> parent(n);
    vector<int> weight(n,INT_MAX);
    vector<bool> visited(n,false);
    weight[0]=0;
    parent[0]=-1;
    for(int i=0;i<n-1;++i){
        int indx=-1;
        for(int j=0;j<n;j++){
            if(!visited[j] && (indx==-1 || weight[j] < weight[indx])) indx=j;
        }
        visited[indx]=true;
        // cout<<indx<<' ';
        for(int j=0;j<n;j++){
            if(!visited[j] && graph[indx][j]!=0 && graph[indx][j]<weight[j]){
                weight[j]=graph[indx][j];
                parent[j]=indx;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<parent[i]<<' '<<i<<' '<<weight[i]<<'\n';
    }
    return 0;

}
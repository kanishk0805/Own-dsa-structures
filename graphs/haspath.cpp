#include <bits/stdc++.h>
using namespace std;
bool haspath(bool ** arr,bool *dec,int v,int first,int second){
    queue<int> q;
    q.push(first);
    while(!q.empty()){
        int size=q.size();
        int front=q.front();
        q.pop();
        if(dec[front]) continue;
        dec[front]=true;
        for(int i=0;i<v;++i){
            if(!dec[i] && arr[front][i]){
                q.push(i);
                if(i==second) return true;
            }
        }        
    }
    return false;
}
int main() {
    int v,e;
    cin>>v>>e;
    bool **arr=new bool*[v];
    for(int i=0;i<v;++i){
        arr[i]=new bool[v];
        for(int j=0;j<v;++j) arr[i][j]=false;
    }
    for(int i=0;i<e;++i){
        int p1,p2;
        cin>>p1>>p2;
        arr[p1][p2]=true;
        arr[p2][p1]=true;
    }
    int vertex1,vertex2;
    cin>>vertex2>>vertex1;
    bool * dec=new bool[v];
    for(int i=0;i<v;++i) dec[i]=false;
  if( haspath(arr, dec, v, vertex1,vertex2))   cout<<"true";
  else cout<<"false";
  return 0;
}
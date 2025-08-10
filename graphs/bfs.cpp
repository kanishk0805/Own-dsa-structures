#include <bits/stdc++.h>
using namespace std;
void print(bool ** arr,bool *dec,int v,int first){
    queue<int> q;
    q.push(first);
    while(!q.empty()){
        int size=q.size();
        int front=q.front();
        q.pop();
        if(dec[front]) continue;
        cout<<front<<' ';
        dec[front]=true;
        for(int i=0;i<v;++i){
            if(!dec[i] && arr[front][i]){
                q.push(i);
            }
        }        
    }
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
    bool * dec=new bool[v];
    for(int i=0;i<v;++i) dec[i]=false;
   for(int i=0;i<v;++i){
       if(!dec[i]){
           print(arr,dec,v,i);
       }
   }
   return 0;
}
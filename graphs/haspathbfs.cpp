#include <bits/stdc++.h>
using namespace std;
bool haspath(bool ** arr,int *dec,int *path,int v,int first,int second){
    queue<int> q;
    q.push(first);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        if(dec[front]) continue;
        dec[front]=true;
        for(int i=0;i<v;++i){
            if(!dec[i] && arr[front][i]){
                q.push(i);
                path[i]=front;
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
    cin>>vertex1>>vertex2;
    int * path=new int[v];
    int * dec=new int[v];
    for(int i=0;i<v;++i) path[i]=-1,dec[i]=false;
    if(vertex1>=v || vertex2>=v) return 0;
    if(haspath(arr, dec, path,v,vertex1,vertex2)){  
        int pos=vertex2;
        while(pos!=-1){
            cout<<pos<<' ';
            pos=path[pos];
        }
    }
    delete []path;
    delete []dec;
    return 0;
}
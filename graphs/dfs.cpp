#include <bits/stdc++.h>
using namespace std;
void print(bool ** v,int n,int sv,bool * vertices){
    cout<<sv<<endl;
    vertices[sv]=true;
    for(int i=0;i<n;++i){
        if(!vertices[i] && v[sv][i]){
            print(v,n,i,vertices);
        }
    }
}
int main(){
    int n,e;
    cout<<"vertice & edges"<<endl;
    cin>>n>>e;
    bool ** v=new bool*[n];
    for(int i=0;i<n;i++){
        v[i]=new bool[n];
        for(int j=0;j<n;++j){
            v[i][j]=false;
        }
    }
    cout<<"enter the edges"<<endl;    
    while(e--){
        int i,j;
        cin>>i>>j;
        v[i][j]=true;
        v[j][i]=true;
    }
    bool *vertices=new bool[n];
    for(int i=0;i<n;++i) vertices[i]=false;
    print(v,n,0,vertices);
    

}
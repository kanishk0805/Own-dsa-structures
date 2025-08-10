#include <bits/stdc++.h>
using namespace std;
class edges{
    public:
   int  value;
    int source;
    int dest;
  
};
int checkparent(vector<int> & parent,int child){
    if(parent[child]==child) return child;
    return parent[child]=checkparent(parent,parent[child]);
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<edges> graph(e);
    for(int i=0;i<e;++i){
        int val,s,d;
        cin>>s>>d>>val;
        graph[i].value = val;   
        graph[i].source = s;
        graph[i].dest = d;
    }
    //sorting the array based on weight of edge 
    sort(graph.begin(),graph.end(),[](const edges &a,const edges& b) {return a.value<b.value;});
    vector<edges> output(n-1);
    vector<int> parent(n);
    iota(parent.begin(),parent.end(),0);
    int count=0,i=0;
    while(count< n-1){
        edges curr=graph[i];
        int ps=checkparent(parent,curr.source);
        int pd=checkparent(parent,curr.dest);
        if(pd!=ps){
            output[count++]=curr;
            parent[pd]=ps;
        }
        ++i;
    }
    for(int i=0;i<n-1;++i){
        if(output[i].source<output[i].dest){
            cout<<output[i].source<<' '<<output[i].dest;

        }else{
            cout<<output[i].dest<<' '<<output[i].source;

        }
        cout<<' '<<output[i].value<<endl;
    }
    return 0;

}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    unordered_map<int,int> mp;
    for(auto &i: v) ++mp[i];
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto &i: mp){
        pq.push(i.second);
    }
    int size;
    cin>>size;
    int ans=0;
    while(pq.size()>size){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans<<endl;
}
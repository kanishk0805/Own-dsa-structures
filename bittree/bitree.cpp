#include <bits/stdc++.h>
using namespace std;
class bitTree{
    vector<int> bit;
    vector<int> arr;
    int n;
    public:
    bitTree(int n){
        bit.resize(n+1,0);
        arr.resize(n+1,0);
        this->n=n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            update(arr[i],i);       
        }
    }
    void update(int x,int indx){
        int t=arr[indx];
        arr[indx]=x;
        x-=t;
        while(indx<=n){
            bit[indx]+=x;
            indx+=indx&(-indx);
        }
    }
    int query(int i){
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i-=i&(-i);
        }
        return sum;
    }
};
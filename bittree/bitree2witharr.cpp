#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class bitTree{
    vector<int> bit;
    int n;
    public:
    bitTree(vi &arr){
        n=arr.size();
        bit.resize(n+1,0);
        for(int i=1;i<=n;i++){
            update(i,arr[i-1]);       
        }
    }
    void update(int indx,int x=1){
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
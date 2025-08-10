#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long long int sum=accumulate(v.begin(),v.end(),(long long int)(0));
    int extra;
    cin>>extra;
   long long int maxi=*max_element(v.begin(),v.end());
    int sumi=maxi*n-sum;
    extra-=sumi;
    int ans=maxi;
    if(extra>0){
        ans+=(extra+n-1)/n;
    }
    return ans;

}
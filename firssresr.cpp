#include <bits/stdc++.h>
using namespace std;

long func(vector<int> &starting, vector<int> &end){
    long ans=0;
    int n=starting.size();
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
        vp[i]={starting[i],i};
    }
    sort(vp.begin(),vp.end());
    vector<long long > dp(n);
    for(int i=0;i<n;i++){
        int indx=vp[i].second;
        pair<int,int> p=make_pair(end[vp[i].second],n);
        int count=upper_bound(vp.begin(),vp.end(),p)-vp.begin();
        dp[indx]=n-count;
    }
    // for(int i=0;i<n;i++) cout<<dp[i]<<' ';
    // cout<<endl;
    vector<long long> dp2(n);
    for(int i=0;i<n;i++){
        vp[i]={end[i],i};
    }
    sort(vp.begin(),vp.end());
    for(int i=0;i<n;i++){
        int indx=vp[i].second;
        pair<int,int> p=make_pair(starting[indx],-1);
        int count=lower_bound(vp.begin(),vp.end(),p)-vp.begin();
        dp2[indx]=count;
    }
    // for(int i=0;i<n;i++) cout<<dp2[i]<<' ';
    // cout<<endl;
    for(int i=0;i<n;i++){
        ans+=dp[i]*dp2[i];
    }
    return ans;
}
int main(){
    vector<int> starting={1,2,3,4};
    vector<int> ending={1,2,3,4};
    cout<<func(starting,ending);
    return 0;
}
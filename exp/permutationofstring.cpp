#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> &v,int &n,string ans){
    if(ans.size()==n) {
        cout<<ans<<endl;
        return ;
    }
    for(int i=0;i<26;i++){
        if(v[i]>0){
            ans.push_back('a'+i);
           // cout<<ans<<endl;
           v[i]--;
            helper(v,n,ans);
            v[i]++;
            ans.pop_back();
        }
    }
    
}
int main(){
    string ins;
    cin>>ins;
    int n=ins.size();
    vector<int> v(26);
    for(int i=0;i<n;i++) v[ins[i]-'a']++;
   // for(int i=0;i<26;i++) cout<<v[i]<<' ';
    helper(v,n,"");
    return 0;
}
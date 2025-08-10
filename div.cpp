#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   set<int> st;
   vector<int> v(n);
   for(int i=0;i<n;i++) {
       cin>>v[i];
   }
   int largest=0;
   for(int i=0;i<n;i++){
        if(v[i]>largest){
            while(st.find(largest)!=st.end())++largest;
            v[i]=largest++;

        }
        st.insert(v[i]);
   }
   
   for(int i=0;i<n;i++) {
       cout<<v[i]<<' ';
   }
   return 0;
   
}
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
namespace __gnu_pbds{
          typedef tree<int,
                       null_type,
                       less_equal<int>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;


typedef  long long int lli;
typedef long long ll;
typedef  pair<int,int> pii;
typedef  vector<int> vi;
typedef  vector<lli> vlli;
typedef  vector<int> vi;
typedef vector<string> vs;
#define PI  3.141592653589
typedef   vector<pii> vpii;
typedef   vector<vi>  vvi;



using namespace std;
class SegmentTree{
    vector<vlli>  ST;
    vector<vlli>  merged;
    int n;
    void combine(vlli &a,vlli &b,vlli &c,vlli &d){
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]){
                c.push_back(a[i]);
                i++;
            }
            else{
                c.push_back(b[j]);
                j++;
            }
        }
        while(i<a.size()){
            c.push_back(a[i]);
            i++;
        }
        while(j<b.size()){
            c.push_back(b[j]);
            j++;
        }
        d.push_back(c[0]);
        for(int k=1;k<c.size();k++){
            
            d.push_back(c[k]+d[k-1]);
        }
    }
    void buildSegmentTree(vector<int> &A,int si,int ss,int se) {
        // cout<<"creating"<<endl;
        if (ss == se) {
            // cout<<A[ss]<<' ';
            ST[si].push_back(A[ss]);
            merged[si].push_back(A[ss]);
            return ;
        }
        int mid= (ss + se)/2;
        buildSegmentTree(A,si*2, ss ,mid);
        buildSegmentTree(A,si*2+1,mid+1,se);
        combine(merged[si*2],merged[si*2+1],merged[si],ST[si]);
        return;
    }
    lli givesum(int si,int ss,int se,int l,int r,int val){
        if(se<l || ss>r) return 0;
        
        if(ss>=l && se<=r){
            int indx=upper_bound(merged[si].begin(),merged[si].end(),val)-merged[si].begin();
            lli sumi=val*(indx);
            if(indx-1>=0) sumi-=ST[si][indx-1]*2;
            sumi-=val*(ST[si].size()-indx);
            sumi+=ST[si].back();
            return sumi;
        }
        int mid = (ss + se)/2;
        return givesum(si*2,ss,mid,l,r,val)+givesum(si*2+1,mid+1,se,l,r,val);
    }
    public:
    SegmentTree(vector<int>& arr){
        n = arr.size();
        ST.resize(4*n);
        merged.resize(4*n);
        buildSegmentTree(arr,1,0,n-1);
    }
    lli query(int l,int r,int val){
        return givesum(1,0,n-1,l,r,val);
    }
};



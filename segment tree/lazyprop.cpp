#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
    vector<int>  ST;
    vector<int> isLazy;
    vector<int> unprop;
    int n;
    void buildSegmentTree(vector<int> &A,int si,int ss,int se) {
        // cout<<"creating"<<endl;
        isLazy[si]=false;
        unprop[si]=0;
        if (ss == se) {
            // cout<<A[ss]<<' ';
            ST[si] = A[ss];
            return ;
        }
        int mid= (ss + se)/2;
        buildSegmentTree(A,si*2, ss ,mid);
        buildSegmentTree(A,si*2+1,mid+1,se);
        ST[si]=max(ST[si*2],ST[si*2+1]);
        return;
    }
    void apply(int si,int ss,int se,int val){
        
        if(ss!=se){
            isLazy[si]=true;
            unprop[si]=val;
        }
        ST[si] += (se-ss+1)*val;
    }
    void pushdown(int si, int ss,int se){
        if(!isLazy[si]) return;
        int mid=(ss+se)/2;
        isLazy[si]=false;
        apply(si*2,ss,mid,unprop[si]);
        apply(si*2+1,mid+1,se,unprop[si]);
        unprop[si]=0;
    }
    void update(int si,int ss,int se,int l,int r,int val){
        if(r<ss || l>se) return;
        if(l<=ss && r>=se){
            apply(si,ss,se,val);
            return ;
        }
        int mid=(ss+se)/2;
        pushdown(si,ss,se);
        update(si*2,ss,mid,l,r,val);
        update(si*2+1,mid+1,se,l,r,val);
        ST[si]=ST[si*2]+ST[si*2+1];
        return ;
    }
    int givesum(int si,int ss,int se,int l,int r){
        if(se<l || ss>r) return 0;
        
        if(ss>=l && se<=r) return ST[si];
        int mid = (ss + se)/2;
        return givesum(si*2,ss,mid,l,r)+givesum(si*2+1,mid+1,se,l,r);
    }
    public:
    SegmentTree(vector<int>& arr){
        n = arr.size();
        ST.resize(4*n);
        isLazy.resize(4*n);
        unprop.resize(4*n);
        buildSegmentTree(arr,1,0,n-1);
    }
    
    void updateval(int l,int r,int val){
        update(1,0,n-1,l,r,val);
    }
    int query(int l,int r){
        // cout<<l<<' '<<r<<endl;
        return givesum(1,0,n-1,l,r);
    }
    void printSegmentTree(){
        int t=1;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                t=q.front();
                cout<<ST[t]<<' ';
                q.pop();
                if(t*2<n*2) q.push(t*2);
                if(t*2+1<n*2) q.push(t*2+1);
                t++;
            }
            cout<<endl;
        }

        // cout<<endl;
    }
};


int main(){
    int n=5;
    // cin>>n;
    vector<int> v={1,2,3,4,5};
    // for(auto &i : v) cin>>i;
    SegmentTree st(v);
    for(int i=0;i<n;i++){
        cout<<st.query(i,i)<<' ';
    }
    cout<<endl;
    st.printSegmentTree();
    st.updateval(3,4,8);
    for(int i=0;i<n;i++){
        cout<<st.query(i,i)<<' ';
    }
    cout<<endl;
    st.printSegmentTree();
    
    

}
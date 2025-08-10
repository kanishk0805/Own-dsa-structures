#include<bits/stdc++.h>
using namespace std;

/*

    कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥
    (Bhagavad Gita, Chapter 47, Verse 17)


    मय्येव मन आधत्स्व मयि बुद्धिं निवेशय |
    निवसिष्यसि मय्येव अत ऊर्ध्वं न संशय: || 

*/
/* Author: kanishkgupta071 */


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define INF 	1e18
#define MOD 	1000000007
#define MOD1 	998244353
#define nline 	"\n"
#define pb 		push_back
#define ppb 	pop_back
#define mp 		make_pair
#define ff 		first
#define ss 		second
#define set_bits __builtin_popcountll
typedef long long int lli;
    typedef pair<int,int> pii;
    typedef vector<int> vi;
    typedef vector<lli> vlli;
    typedef vector<int> vi;
    typedef vector<string> vs;
    #define PI  3.141592653589
    typedef   vector<pii> vpii;
    typedef   vector<vi>  vvi;
    void print(auto &v){for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<nline;}
    #define tin(x) for(auto &i:x) cin>>i;
    class SegmentTree{
        vector<int>  ST;
        int n;

        void buildSegmentTree(vector<lli> &A,int si,int ss,int se) {
            // cout<<"creating"<<endl;
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
        void update(int si,int ss,int se,int index,int val){
            if(index<ss || index>se) return;
            if(index==ss && index==se){
                ST[si] = val;
                return ;
            }
            int mid=(ss+se)/2;
            update(si*2,ss,mid,index,val);
            update(si*2+1,mid+1,se,index,val);
            ST[si]=max(ST[si*2],ST[si*2+1]);
            return ;
        }
        int givesum(int si,int ss,int se,int l,int r){
            if(se<l || ss>r) return 0;
            
            if(ss>=l && se<=r) return ST[si];
            int mid = (ss + se)/2;
            return max(givesum(si*2,ss,mid,l,r),givesum(si*2+1,mid+1,se,l,r));
        }
        public:
        SegmentTree(){

        }
        SegmentTree(int n){
            this->n = n+1;
            ST.resize(4*n);
        }
        void updateval(int indx,lli val){
            update(1,0,n-1,indx,val);
        }
        int query(int l,int r){
            return givesum(1,0,n-1,l,r);
        }
    };

 
class HLD{
    public:
    vi depth,heavy,head,size,parent,pos;
    vlli value;
    vector<vector<pair<int,lli>>> graph;
    int n;
    SegmentTree bt;
    HLD(int n,vvi &edges){
        this->n=n;
        parent.resize(n+1,0),depth.resize(n+1,0), heavy.resize(n+1,0), head.resize(n+1,0),size.resize(n+1,0),pos.resize(n+1,0);
        graph.resize(n+1);
        value.resize(n+1,0ll);
        for(auto &i:edges){
            int u=i[0],v=i[1];
            lli w=i[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        dfs(1,0,0);
        int cpos=1;
        dfsLHD(1,1,0,cpos);
        bt=SegmentTree(n);
        for(int i=1;i<=n;i++){
            bt.updateval(pos[i],value[i]);
        }
    }

    void dfs(int u,int p,lli value=0){
        depth[u]=depth[p]+1;
        parent[u]=p;
        int maxc=0;
        this->value[u]=value;
        for(auto &pairv:graph[u]){
            int v=pairv.ff;
            if(v==p) continue;
            dfs(v,u,pairv.ss);
            size[u]+=size[v];
            if(size[v]>size[maxc]) maxc=v;
        }
        size[u]++;
        heavy[u]=maxc;
    }
    void dfsLHD(int u,int h,int p,int &cpos){
        head[u]=h;
        pos[u]=cpos++;
        if(heavy[u])dfsLHD(heavy[u],h,u,cpos);
        for(auto &pairv:graph[u]){
            int v=pairv.ff;
            if(v==p || v==heavy[u]) continue;
            dfsLHD(v,v,u,cpos);
        }  
    }
    int lca(int u,int v){
        while(head[u]!=head[v]){
            if(depth[head[u]]>depth[head[v]]) {
                u=parent[head[u]];
            }
            else v=parent[head[v]];
        }
        return depth[u]>depth[v]?v:u;
    }
    void update(int v,lli val){
        bt.updateval(pos[v],val);
    }
    lli givesum(int u,int v){
        int sum=0;
        while(head[u]!=head[v]){
            if(depth[head[u]]<depth[head[v]]){
                swap(u,v);
            }
            sum=max(bt.query(pos[head[u]],pos[u]),sum);
            u=parent[head[u]];
        }
        if(u==v) return sum;
        if(depth[u]<depth[v])swap(u,v);
        sum=max(bt.query(pos[v]+1,pos[u]),sum);
        return sum;
    }
    
};
    
    
    int main(){
        fastio();
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            vvi edges(n-1,vi(3));
            for(auto &i:edges) tin(i);
            HLD hld(n,edges);
            while(1){
                string s;
                cin>>s;
                if(s=="DONE") break;
                if(s=="CHANGE"){
                    int num;
                    lli val;
                    cin>>num>>val;
                    int u=edges[num-1][0],v=edges[num-1][1];
                    if(hld.depth[u]<hld.depth[v]){
                        swap(u,v);
                    }
                    hld.update(u,val);
                }else{
                    int u,v;
                    cin>>u>>v;
                    cout<<hld.givesum(u,v)<<nline;
                }
            }
        }
        
}
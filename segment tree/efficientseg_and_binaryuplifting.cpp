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
        
        void build( int arr[]) 
        { 
            // insert leaf nodes in tree
            for (int i=0; i<n; i++)    
                ST[n+i] = arr[i];
                
                // build the tree by calculating parents
                for (int i = n - 1; i > 0; --i)     
                ST[i] =max( ST[i<<1] , ST[i<<1 | 1]);    
            }
            // function to update a tree node
            public:
        void updateTreeNode(int p, int value) 
        { 
            // set value at position p
            ST[p+n] = value;
            p = p+n;
            
            // move upward and update parents
            for (int i=p; i > 1; i >>= 1)
                ST[i>>1] = max(ST[i] , ST[i^1]);
        }

        // function to get sum on interval [l, r)
        int query(int l, int r) 
        { 
            int res = 0;
            
            // loop to find the sum in the range
            for (l += n, r += n; l < r; l >>= 1, r >>= 1)
            {
                if (l&1) 
                    res = max(ST[l++],res);
            
                if (r&1) 
                    res = max(ST[--r],res);
            }
            
            return res;
        }

        SegmentTree(){

        }
        SegmentTree(int n){
            this->n = n+1;
            ST.resize(4*n);
        }

    };

 
class HLD{
    public:
    vi depth,heavy,head,size,parent,pos;
    vlli value;
    vvi graph;
    int n;
    SegmentTree bt;
    HLD(int n){
        this->n=n;
        parent.resize(n+1,0),depth.resize(n+1,0), heavy.resize(n+1,0), head.resize(n+1,0),size.resize(n+1,0),pos.resize(n+1,0);
        graph.resize(n+1);
        value.resize(n+1,0ll);
        for(int i=1;i<=n;i++){
            cin>>value[i];
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1,0);
        int cpos=1;
        dfsLHD(1,1,0,cpos);
        bt=SegmentTree(n);
        for(int i=1;i<=n;i++){
            bt.updateTreeNode(pos[i],value[i]);
        }
    }

    void dfs(int u,int p){
        depth[u]=depth[p]+1;
        parent[u]=p;
        int maxc=0;
        for(auto &v:graph[u]){
            // int v=pairv.ff;
            if(v==p) continue;
            dfs(v,u);
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
        for(auto &v:graph[u]){
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
        bt.updateTreeNode(pos[v],val);
    }
    lli givesum(int u,int v){
        int sum=0;
        while(head[u]!=head[v]){
            if(depth[head[u]]<depth[head[v]]){
                swap(u,v);
            }
            sum=max(bt.query(pos[head[u]],pos[u]+1),sum);
            u=parent[head[u]];
        }
        if(depth[u]<depth[v])swap(u,v);
        sum=max(bt.query(pos[v],pos[u]+1),sum);
        return sum;
    }
    
};
    
    
    int main(){
        fastio();
            int n,q;
            cin>>n>>q;
            HLD hld(n);
            while(q--){
                int s;
                cin>>s;
                if(s==1){
                    int num, val;
                    cin>>num>>val;
                    hld.update(num,val);
                }else{
                    int u,v;
                    cin>>u>>v;
                    cout<<hld.givesum(u,v)<<' ';
                }
            }
        
}
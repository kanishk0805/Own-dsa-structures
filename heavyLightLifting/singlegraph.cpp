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
class bitTree{
    vector<lli> bit;
    int n;
    public:
    bitTree(){

    }
    bitTree(int n){bit.resize(n+1,0);this->n=n;}
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
    lli query(int i){
        lli sum=0;
        while(i>0){
            sum+=bit[i];
            i-=i&(-i);
        }
        return sum;
    }
};
 
class HLD{
    public:
    vi depth,heavy,head,size,parent,pos,rpos;
    vi isblack;
    vector<vector<int>> graph;
    int n;
    bitTree bt;
    HLD(int n){
        this->n=n;
        parent.resize(n+1,0),depth.resize(n+1,0), heavy.resize(n+1,0), head.resize(n+1,0),size.resize(n+1,0),pos.resize(n+1,0);
        graph.resize(n+1);
        rpos.resize(n+1);
        isblack.resize(n+1);
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1,0);
        int cpos=1;
        dfsLHD(1,1,0,cpos);
        bt=bitTree(n);
    }

    void dfs(int u,int p){
        depth[u]=depth[p]+1;
        parent[u]=p;
        int maxc=0;
        for(auto &v:graph[u]){
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
        rpos[pos[u]]=u;
        if(heavy[u])dfsLHD(heavy[u],h,u,cpos);
        for(auto &v:graph[u]){
            if(v==p || v==heavy[u]) continue;
            dfsLHD(v,v,u,cpos);
        }  
    }
    void update(int v){
        int val=1;
        if(isblack[v]) val=-1;
        bt.update(pos[v],val);
        isblack[v]=isblack[v]^1;
    }
    int query(int u){
        lli sum=0;
        int ans=-1;
        while(u!=0){
            int posu=pos[u],posv=pos[head[u]];
            int dec=bt.query(posv-1);
            while(posu>=posv){
                int mid=(posu+posv)/2;
                if(bt.query(mid)-dec>0){
                    posu=mid-1;
                    ans=rpos[mid];
                }else{
                    posv=mid+1;
                }
            }
            u=parent[head[u]];
        }
        return ans;
    }
    
};

    

int main(){
    int n,q;
    cin>>n>>q;
    HLD hld(n);
    while(q--){
        // cout<<q<<endl;
        int t,u;
        cin>>t>>u;
        if(t==0){
            hld.update(u);
        }else{
            cout<<hld.query(u)<<nline;
        }

    }
}
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
    vi depth,heavy,head,size,parent,pos;
    vlli value;
    vector<vector<pair<int,lli>>> graph;
    int n;
    bitTree bt;
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
        bt=bitTree(n);
        for(int i=1;i<=n;i++){
            bt.update(pos[i],value[i]);
        }
    }

    void dfs(int u,int p,lli value){
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
        bt.update(pos[v],val-value[v]);
        value[v]=val;
    }
    lli givesum(int u,int v){
        lli sum=0;
        while(head[u]!=head[v]){
            if(depth[head[u]]<depth[head[v]]){
                swap(u,v);
            }
            sum+=bt.query(pos[u])-bt.query(pos[head[u]]-1);
            u=parent[head[u]];
        }
        if(depth[u]<depth[v])swap(u,v);
        sum+=bt.query(pos[u])-bt.query(pos[v]);
        return sum;
    }
    
};
class Solution {
    public:
        vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
            HLD hld(n,edges);
            vi ans;
            for(auto i:queries){
                if(i[0]==1){
                    if(hld.depth[i[1]]<hld.depth[i[2]]){
                        swap(i[1],i[2]);
                    }
                    hld.update(i[1],i[3]);
                }else{
                    ans.push_back((int)hld.givesum(i[1],1));
                }
            }
            return ans;
        }
    };
    

// int main(){
//     Solution s;
//     vvi edges={{1,2,1},{1,3,2}};
//     vvi queries={{1,1,2,1},{2,2,3,2}};
//     s.treeQueries(3,edges,queries);
// }
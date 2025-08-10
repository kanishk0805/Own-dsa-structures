#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
/*

    कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥
    (Bhagavad Gita, Chapter 47, Verse 17)


    मय्येव मन आधत्स्व मयि बुद्धिं निवेशय |
    निवसिष्यसि मय्येव अत ऊर्ध्वं न संशय: || 

*/
/* Author: kanishkgupta071 */
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
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define INF 	1e18
#define MOD 	1000000007
#define MOD1	 998244353
#define INF 	1e18
#define nline 	"\n"
#define pb 		push_back
#define ppb 	pop_back
#define ff 		first
#define ss 		second
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define tin(x) for(auto &i:x) cin>>i;
#define print(x) for(auto &i:x) cout<<i<<' ';
 //for non prime b

/*...............................................................
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void google(int t) {cout << "Case #" << t << ": ";}
.....................................................*/
struct Centroid{
    int n;
    vi parent;
    vector<bool> vis;
    vi sz;
    int givecentroid(int u,vvi &graph,int num,int par=-1){
        for(auto &i:graph[u]){
            if(!vis[i] && par!=i && 2*sz[i]>num){
                return givecentroid(i,graph,num,u);
            }
        }
        int p=0;
        return u;

        
    }
    void dfsnoc(int u,vvi &graph,int par=-1){
        sz[u]=1;
        for(auto &i:graph[u]){
            if(!vis[i] && par!=i){
                dfsnoc(i,graph,u);
                sz[u]+=sz[i];
            }
        }
        return;
    }
    int dfsconstruct(int u,vvi &graph){
        dfsnoc(u,graph,-1);
        int centroid=givecentroid(u,graph,sz[u]);
        vis[centroid]=true;
        for(auto &i:graph[centroid]){
            if(!vis[i]){
                int t=dfsconstruct(i,graph);
                parent[t]=centroid;
            }
        }
        return centroid;
    }
    Centroid(vvi &graph){
        n=graph.size();
        parent.resize(n,-1);
        vis.resize(n);
        sz.resize(n);
        dfsconstruct(0,graph);
    }
};
struct lca{
    vi depth;
    vvi sparsetable;
    int n;
    void dfs(vvi &graph,int u=0,int par=0){;
        sparsetable[u][0]=par;
        for(int j=1;j<20;++j ){
            sparsetable[u][j]=sparsetable[sparsetable[u][j-1]][j-1];
        }
        for(auto &i:graph[u]){
            if( par!=i){
                depth[i]=depth[u]+1;
                dfs(graph,i,u);
            }
        }
    }
    int givelca(int u,int v){
        if(depth[u]<depth[v])swap(u,v);
        for(int i=19;i>=0;--i){
            if(depth[sparsetable[u][i]]>=depth[v]) u=sparsetable[u][i];
        }
        if(u==v) return u;
        for(int i=19;i>=0;--i){
            if(sparsetable[u][i]!=sparsetable[v][i]) u=sparsetable[u][i],v=sparsetable[v][i];
        }
        return sparsetable[u][0];
    }
    int distance(int u,int v){
        int l=givelca(u,v);
        return depth[u]+depth[v]-2*depth[l];
    }
    lca(vvi &graph){
        n=graph.size();
        depth.resize(n);
        sparsetable.resize(n,vi(20));
        dfs(graph);
    }
};

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

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
 
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
const int MX = 2e5;
ll fact[MX+1];
ll ifact[MX+1];
void ICombo() {
	fact[0] = 1;
    for(int i=1;i<=MX;i++) {
        fact[i] = (fact[i-1]*i)%MOD;
    }    
    ifact[MX] = expo(fact[MX],MOD-2,MOD);
    for(int i=MX-1;i>=0;i--) {
        ifact[i] = (ifact[i+1]*(i+1))%MOD;
    }
}
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
class bitTree{
    vector<int> bit;
    int n;
    public:
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
    int query(int i){
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i-=i&(-i);
        }
        return sum;
    }
};
 
class HLD{
    public:
    vi depth,heavy,head,size,parent;
    vi pos;
    vector<vi> child;
    int n;
    HLD(int n){
        this->n=n;
        parent.resize(n+1,0);
        depth.resize(n+1,0);
        heavy.resize(n+1,0);
        head.resize(n+1,0);
        size.resize(n+1,0);
        pos.resize(n+1,0);
        child=vvi(n+1);
        
    }
    void dfs(int u,int p){
        depth[u]=depth[p]+1;
        parent[u]=p;
        int maxc=0;
        for(auto v:child[u]){
            dfs(v,u);
            size[u]+=size[v];
            if(size[v]>size[maxc]) maxc=v;
            
        }
        size[u]++;
        heavy[u]=maxc;
    }
    void dfsLHD(int u,int h,int &cpos){
        head[u]=h;
        pos[u]=cpos++;
        if(heavy[u])dfsLHD(heavy[u],h,cpos);
        for(auto v:child[u]){
            if(v!=heavy[u]) dfsLHD(v,v,cpos);
        }   
    }
    int lca(int u,int v){
        while(head[u]!=head[v]){
            // cout<<u<<" "<<v<<endl;
            if(depth[head[u]]>depth[head[v]]) {
                u=parent[head[u]];
            }
            else v=parent[head[v]];
        }
        return depth[u]>depth[v]?v:u;
    }
    
    void solve(int q){
        dfs(1,0);
        int cpos=1;
        dfsLHD(1,1,cpos);
        while(q--){
            int u,v;
            cin>>u>>v;
            cout<<lca(u,v)<<nline;
        }
    }
};
 
int main(){
    fastio();
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<":"<<nline;
        int n;
        cin>>n;
        HLD hld(n);
        for(int i=1;i<=n;i++){
            int p;
            cin>>p;
            for(int j=0;j<p;j++){
                int x;
                cin>>x;
                hld.child[i].pb(x);
            }
        }
        int q;
        cin>>q;
        // cout<<endl;
        hld.solve(q);
    }
} 

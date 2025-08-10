#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>   
using namespace std;
using namespace __gnu_pbds;
typedef long long ll; 
#define int long long
typedef unsigned long long lu;
typedef vector<ll> v;
typedef vector<vector<ll> > vv;
typedef vector<string>  vs;
typedef vector<pair<ll,ll>> vpr;
typedef vector<bool>vb;
typedef vector<double>vd;
typedef long double ld;
#define f(i,n) for(ll i = 0; i < n; i++)
#define ff(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define amax(x,y) if(y>x) x=y;
#define amin(x,y) if(y<x)x=y;
#define bg(x) x.begin()
#define sz(x) (ll)x.size()
#define in(x,n) for(ll i=0;i<n;i++)cin>>x[i]
#define out(x,n) for(ll i=0;i<n;i++)cout<<x[i]<<" " 
#define mxt(a) *(max_element(a.begin(),a.end()))
#define mnt(a) *(min_element(a.begin(),a.end())
#define tc ll t;cin>>t;while(t--)
typedef pair<ll,ll> pi;
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define yesno(f) if(f) yes else no
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
const ld PI = 2 * acos(0.0);
ll cel(ll x1,ll y1){if((x1%y1)==0)return x1/y1;else return x1/y1+1;}
ll power(ll a,ll b,ll m)
{
    if(b==0)
        return 1;
    ll d=power(a,b/2,m);
    d=(d*d)%m;
    if(b&1)
        d=(d*a)%m;
    return d;
}
const ll mod=1e9+7;
int MOD(int a)
{
    if(a<0)
        a+=mod;
    if(a>=mod)
        a%=mod;
    return a;
}
// set_name.find_by_order(k) It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time
// set_name.order_of_key(k) It returns to the number of items that are strictly smaller than our item k in O(logn) time.
/*string operations :
str.substr (x,y) : returns a substring str[x],str[x+1],...str[x+y-1]
str.substr (x) : returns a substring str[x],... end of string
str.find(qtr) : returns the first occurenece of qtr in str */
struct Centroid{
 vector<int>szz,parent;
 vb vst;
 void dfs(int u,int pa,vv &gr,vb &vst){
     szz[u]=1;
     for(auto it:gr[u])
     {
         if(it!=pa && !vst[it])
         {
             dfs(it,u,gr,vst);
             szz[u]+=szz[it];
         }
     }
 }
 int get_centroid(int root,int pa,vv &gr,vb &vst,int n)
 {
     int centroid=root;
     for(auto it:gr[root])
     {
         if(it!=pa && !vst[it])
         {
             if(szz[it] > (n/2))
             {
                 centroid=get_centroid(it,root,gr,vst,n);
             }
         }
     }
     return centroid;
 }
 int construct(int root,vv &gr,vb &vst){
     dfs(root,-1,gr,vst);
     int n=szz[root];
     int ctr=get_centroid(root,-1,gr,vst,n);
     vst[ctr]=true; 
     for(auto it:gr[ctr])
     {
         if(vst[it])
             continue;
         int ch=construct(it,gr,vst);
         parent[ch]=ctr;
     }
     return ctr;
 }
 Centroid(vv &gr){
     int n=sz(gr);
     szz.resize(n,0);
     parent.resize(n,-1);
     vst.resize(n,false);
     int ctr=construct(0,gr,vst);
 }
};

const int N=1e5+1;
const int Log=20;
int ancestor[N][Log],depth[N];
void dfs1(int root,int pa,vv &gr)
{

    ancestor[root][0]=pa;
    for(int j=1;j<Log;j++)
    {
        ancestor[root][j]=ancestor[ancestor[root][j-1]][j-1];
    }
    for(auto it:gr[root])
    {
        if(it!=pa)
        {
            depth[it]=depth[root]+1;
            dfs1(it,root,gr);
        }
    }
}
int lca(int a,int b)
{
    if(depth[a] < depth[b])
        swap(a,b);
    for(int j=Log-1;j>=0;j--)
    {
        if(depth[ancestor[a][j]] >=depth[b])
        {
            a=ancestor[a][j];
        }
    }
    if(a==b)
        return a;
    // cout<<a+1<<" "<<b+1<<endl;
    // cout.flush();
    for(int j=Log-1;j>=0;j--)
    {
        if(ancestor[a][j] != ancestor[b][j])
        {
            a=ancestor[a][j];
            b=ancestor[b][j];
        }
    }
    return ancestor[a][0];
}
ll dist(int a,int b)
{
    if(a==-1 || b==-1)
        return 0;
    return depth[a]+depth[b]-2*depth[lca(a,b)];
}


int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,q;cin>>n>>q;
    vv gr(n);
    for(int i=0;i<n-1;i++)
    {
    	int a,b;cin>>a>>b;
    	a--;
    	b--;	
    	gr[a].pb(b);
    	gr[b].pb(a);
    }
        

   	dfs1(0,0,gr);
   	Centroid ctr(gr);
   	vector<ll>mn(n,1e18);
   	int curr=0;
   	while(curr!=-1){
        mn[curr]=min(mn[curr],dist(curr,0));
        curr=ctr.parent[curr];
    }
   	// return 0;
   	for(int i=0;i<q;i++)
   	{
   		int ch,ver;cin>>ch>>ver;
   		ver--;
   		if(ch==2)
   		{
            curr=ver;
   			int ans=mn[ver];
   			while(curr!=-1){
                mn[curr]=min(mn[curr],dist(curr,ver));
                curr=ctr.parent[curr];
            }
   			cout<<ans<<endl;
   		}
   		else
   		{
            curr=ver;
            while(curr!=-1){
                mn[curr]=min(mn[curr],dist(curr,0));
                curr=ctr.parent[curr];
            }
   		}
   	}

    return 0;
}
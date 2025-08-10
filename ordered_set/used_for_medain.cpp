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
/*...............................................................
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void google(int t) {cout << "Case #" << t << ": ";}
.....................................................*/

class Solution {
    public:
    int n;
    vector<long long> medians;
    vector<vlli> dp;
vlli data;
        long long answer(int pos,int k,int x) {
            if(k==0) return 0;
            if(pos+x-1>=n){
                return 1e15;
            }
            if(dp[pos][k]!=-1) return dp[pos][k];
            long long ans=answer(pos+1,k,x);
            lli sum=data[pos];
            ans=min(ans,sum+answer(pos+x,k-1,x));
            return dp[pos][k]=ans;
        }
        long long minOperations(vector<int>& nums, lli x, int k) {
            if(x==1) return 0;
            n=nums.size();
            ordered_set s;
            dp.resize(n,vlli(k+1,-1));
            data.resize(n);
            for(int i=n-1;i>=n-x;i--){
                s.insert(nums[i]);
            }
            lli suml=0,sumright=0;
            lli med=*(s.find_by_order((x)/2));
            for(int i=0;i<x;i++){
                if(i<x/2) suml+=*(s.find_by_order(i));
                else sumright+=*(s.find_by_order(i));
            }
            cout<<med<<' '<<suml<<' '<<sumright<<endl;
            data[n-x]=sumright-med*((x+1)/2)+med*((x)/2)-suml;
                for(int i = n-x-1; i>=0; i--) {
                    int val=nums[i+x];
                    auto it = s.upper_bound(val);
                    if(it != s.end() && *it == val)
                        s.erase(it);
                    else {
                        it = s.lower_bound(val);
                        if(it !=s.end() && *it == val)
                            s.erase(it);
                    }
                    s.insert(nums[i]);
                        if(val>=med) {
                            sumright-=val;
                            if(nums[i]>=med) sumright+=nums[i];
                            else{
                                suml+=nums[i];
                                lli t=*(s.find_by_order(x/2));
                                sumright+=t;
                                suml-=t;
                            }
                        }
                        else{
                            suml-=val;
                            if(nums[i]>=med) {
                                sumright+=nums[i];
                                lli t=*(s.find_by_order(x/2-1));
                                sumright-=t;
                                suml+=t;
                            }
                            else{
                                suml+=nums[i];
                            }
                        }
                    lli currmed= *(s.find_by_order((x)/2));
                    med=currmed;
                    data[i]=sumright-currmed*((x+1)/2)+currmed*((x)/2)-suml;
            // cout<<med<<' '<<suml<<' '<<sumright<<endl;
                    
            // cout<<med<<' ';
                } 
             // cout<<nline;
             //    for(auto &i:data) cout<<i<<" ";
            return answer(0,k,x);
        }
    };
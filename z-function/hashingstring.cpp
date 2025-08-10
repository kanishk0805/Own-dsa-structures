#include <bits/stdc++.h>
using namespace std;

typedef  long long int lli;
typedef long long ll;
typedef  pair<int,int> pii;
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
#define sz(x) x.size();
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/*...............................................................
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void google(int t) {cout << "Case #" << t << ": ";}
.....................................................*/
struct Hashing
{
    string s;
    int n;
    int primes;
    vector<long long> hashPrimes = {1000000009, 100000007};
    const long long base = 31;
    vector<vector<long long> > hashValues;
    vector<vector<long long> > powersOfBase;
    vector<vector<long long> > inversePowersOfBase;
    Hashing(string a)
    {
        primes = sz(hashPrimes);
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length();
        for (int i = 0; i < hashPrimes.size(); i++)
        {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++)
            {
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for (int j = n - 1; j >= 0; j--)
            {
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            }
        }
        for (int i = 0; i < hashPrimes.size(); i++)
        {
            hashValues[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<long long> substringHash(int l, int r) // O(1)
    {
        vector<long long> hash(primes);
        for (int i = 0; i < primes; i++)
        {
            long long val1 = hashValues[i][r];
            long long val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};
 
void solve(){
    // int n;
    // cin>>n;
   string s;
   cin>>s;
    struct Hashing h = Hashing(s);
	int n=s.size();
	if(n%2==1){
		cout<<0<<nline;
		return;
	}
		vector<lli> l=h.substringHash(n-1,n-1);
	int ans=0;
    // cout<<l[0]<<nline;
	for(int size=1;size<n/2;++size){
        
		vector<lli> l1=h.substringHash(0,size-1);
    
		vector<lli> l2=h.substringHash(size,2*size-1);
		vector<lli> l3=h.substringHash(2*size,n/2+size-1);
		vector<lli> l4=h.substringHash(n/2+size,n-1);
        // cout<<l1[0]<<' '<<l2[0]<<' '<<l3[0]nline;
		if(l1[0]==l2[0] && l1[1]==l2[1] &&l3[0]==l4[0] && l3[0]==l4[0] ) ++ans;
// && l1[1]==l2[1] &&l3[0]==l4[0]
	}
		vector<lli> l1=h.substringHash(0,n/2-1);
    
		vector<lli> l2=h.substringHash(n/2,n-1);
        if(l1[0]==l2[0]) ans+=2;
    cout<<ans;
    cout<<nline;

}

signed main(){
	fastio();
	int t=1;
	cin>>t;
	for(int i=1;i<=t;i++){
        // cout<<"t = "<<i <<' ';
		solve();
	}
}
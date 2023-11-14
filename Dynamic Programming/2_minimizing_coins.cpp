#include<bits/stdc++.h>
using namespace std;
#define ll                           long long
#define INF                          1e18
#define fo(i, n)                     for (int i = 0; i < n; i++)
#define fo2(i, z, n)                 for (int i = z; i <= n; i++)
#define pb                           push_back
#define ppb                          pop_back
#define all(x)                       x.begin(), x.end()
#define desc                         greater<int>()
#define set_bits                     __builtin_popcountll
#define YES                          cout << "YES\n";
#define NO                           cout << "NO\n";
#define Yes                          cout << "Yes\n";
#define No                           cout << "No\n";
#define sz                           size()
#define F                            first
#define S                            second
#define lb                           lower_bound
#define up                           upper_bound
 
/*----------------------Standard use case---------------------------------*/
#define arin(arr,n)             long long arr[n];for(int i=0; i<n; i++)cin>>arr[i];
#define sinn (str)              string str; cin>>str;
#define vecin(arr,n)            vector<long long>arr(n);for(int i=0;i<n;++i)cin>>arr[i];
#define cy                      printf("YES\n")
#define cn                      printf("NO\n")
#define nline                   "\n";
/*-------------------------------------------------------------------------*/
// Constants
#define PI                      3.1415926535897932384626
#define MOD                     1000000007
#define MOD2                    998244353
/*-------------------------------------------------------------------------*/
typedef pair < ll, ll > pl;
typedef vector < ll > vl;
typedef map < ll, ll > mll;
typedef vector < pl > vpl;
 
/*-------------------------Mathematical Operators--------------------------*/
long long gcd(long long a, long long b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
 
long long gcdX(long long a, long long b, long long &x, long long &y) // gcd extended
{
    x = 1, y = 0;
    long long x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        long long q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
 
long long lcm(long long a, long long b)
{
    return ((long long)a * b) / gcd(a, b);
}
// modular exponentiation
long long modpow(long long x, long long n, long long m = MOD)
{
    if (x == 0 && n == 0)
        return 0; // undefined case
    long long res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = ((res % m) * (x % m)) % m;
        }
        x = ((x % m) * (x % m)) % m;
        n >>= 1;
    }
    return res;
}
 
long long modinv(long long x, long long m = MOD)
{
    return modpow(x, m - 2, m);
}
 
// ncr i.e number of combinations
const long long factN = 100005;
long long fact[factN];
long long inv_fact[factN];
void preNCR()
{
    fact[0] = 1;
    fact[1] = 1;
    inv_fact[0] = inv_fact[1] = modinv(1);
    for (int i = 2; i < factN; i++)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
        inv_fact[i] = modinv(fact[i]);
    }
}
long long ncr(long long n, long long r)
{
    if (n < r)
    {
        return 0;
    }
    long long ans = fact[n];
    ans %= MOD;
    ans *= inv_fact[r];
    ans %= MOD;
    ans *= inv_fact[n - r];
    ans %= MOD;
    return ans;
}
long long npr(long long n, long long r)
{
    if (n < r)
    {
        return 0;
    }
    long long ans = fact[n];
    ans %= MOD;
    ans *= inv_fact[n - r];
    ans %= MOD;
    return ans;
}
 
/*--------------- Seive -----------------------*/
// Get All The Divisors Of That Number
vector<long long> getdiv(long long n)
{
    vector<long long> ans;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.pb(i);
            if (n / i != i)
                ans.pb(n / i);
        }
    }
    return ans;
}
 
// sieve method to find prime numbers in 1 to n
vector<long long> sieve(long long n)
{
    long long *arr = new long long[n + 1]();
    vector<long long> vect;
    for (long long i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (long long  j = i * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
 
//prime factorization
vector<long long> getprimefac(long long n)
{
    vector<long long> ans;
    long long nn = n;
    for (long long i = 2; i * i <= n; i++)
    {
        if (nn % i == 0)
        {
            ans.push_back(i);
            while (nn % i == 0)
            {
                nn /= i;
            }
        }
    }
    if (nn > 1)
    {
        ans.push_back(nn);
    }
    return ans;
}
 
int sum(int n){
	int res=0;
	while(n){
		res+=n%10;
		n/=10;
	}
	return res;
}
 
ll bintodec(string &str){
	ll dec=0;
	ll base=1;
	for(ll i=str.sz-1;i>=0;i--){
		if(str[i]=='1'){
			dec+=base;
		}
		base*=2;
	}
	return dec;
}
/*---------------------WRITE YOUR CODE HERE --------------------------------------*/
void solve(){
    ll n,x;
    cin >> n >> x;
    // vector<ll> arr(n);
    vecin(arr, n);
 
    vector<ll> dp(x + 1, INF);
    dp[0] = 0;
 
    for (ll i = 1; i <= x; i++) {
        for (ll j = 0; j < n; j++) {
            if (i >= arr[j] && dp[i - arr[j]] != INF) {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }
 
    if (dp[x] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }
}
 
 
/*--------------------------------------------------------------------------------*/
 
int main ()
{
  ios_base::sync_with_stdio (0);
  cin.tie (0);
  int t = 1;
  // cin >> t;
  while (t--)
    {
      solve ();
    }
 
  return 0;
}









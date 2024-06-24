#include <iostream>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <iterator>
using namespace std;
 
//defines
#define ll long long
#define usg unsigned
#define kap map
#define print(x, n) for(int for_loop = 0; for_loop < n; for_loop++){cout<<x[for_loop]<<' ';}cout<<endl; 
#define read(x, n) for(int for_loop = 0; for_loop < n; for_loop++){cin>>x[for_loop];} 
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ratdig(x) cout << fixed << setprecision(x);
#define xfixdig(x) cout << setprecision(x);
#define multi int t; cin>>t; presolve(); while(t--) solve()
#define single presolve(); solve(); return 0
#define rev(x) reverse(x.begin(), x.end())
#define all(x) x.begin(), x.end()
 
//functions
void yn(bool b)
{
	if (b)
	{
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}
 
ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return gcd(b % a, a);
}
 
ll lcm(ll a, ll b)
{
	return (a * b) / gcd(a, b);
}
 
string to2(ll a)
{
	string r = "";
	for (ll i = a; i > 0; )
	{
		ll k = i % 2;
		i /= 2;
		char c = k + 48;
		r += c;
	}
	if (a == 0)
	{
		r = "0";
	}
	rev(r);
 
	return r;
}
 
ll binpow(ll a, ll b, ll mod = -1)
{
	ll ans = 1;
	while (b)
	{
		if ((b & 1) == 1)
		{
			ans *= a;
			if (mod != -1)
				ans %= mod;
		}
		b >>= 1;
		a *= a;
		if (mod != -1)
			a %= mod;
	}
	return ans;
}
 
//body
 
void presolve()
{
 
}
 
ll l;
ll par[200005], up[200005][32];
ll rn[200005];
vector<ll>child[200005];
 
void dfs(ll gag, ll k = 0)
{
	up[gag][0] = par[gag];
	rn[gag] = k;
	for (ll i = 1; i <= l; i++)
	{
		up[gag][i] = up[up[gag][i - 1]][i - 1];
	}
	for (ll i = 0; i < child[gag].size(); i++)
	{
		dfs(child[gag][i], k + 1);
	}
}
 
ll binlift(ll a, ll k)
{
	ll i, j, n, m;
	if (rn[a] < k)
	{
		return -2;
	}
	for (i = l; i >= 0; i--)
	{
		if ((1 << i) == k)
			return up[a][i];
		if ((1 << i) < k)
		{
			return binlift(up[a][i], k - (1 << i));
		}
	}
}
 
void solve()
{
	ll x, i, j, n, m, k;
	cin >> n >> m;
	for (i = 1; i < n; i++)
	{
		cin >> j;
		j--;
		par[i] = j;
		child[j].push_back(i);
	}
	while ((1 << l) <= n)  l++;
	dfs(0);
	while (m--)
	{
		cin >> i >> j;
		i--;
		cout << binlift(i, j) + 1 << endl;
	}
}
 
int main()
{
	speed;
	single;
	multi;
 
	return 0;
}

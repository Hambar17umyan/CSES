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
const int N = 200005;
ll arr[N];
void solve()
{
	ll x, i, j, n, m, k;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	k = 0;
	m = 0;
	k = arr[0];
	if (k != 1)
	{
		cout << 1 << endl;
		return;
	}
	for (i = 1; i < n; i++)
	{
		if (arr[i] - k > 1)
		{
			cout << k + 1 << endl;
			return;
		}
		k += arr[i];
	}
	cout << k + 1;
}
 
int main()
{
	speed;
	single;
	multi;
 
	return 0;
}

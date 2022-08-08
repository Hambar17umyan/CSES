#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include <math.h>
#include <ctime>
#include <algorithm>
#include <deque>
#include <string>
#include <queue>
#include <stack>
using namespace std;

#define ll long long
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define commadig(x) cout << fixed << setprecision(x);
#define kap map
#define _2 second
#define _1 first
#define rev(x) reverse(x.begin(), x.end())
#define mpr make_pair
#define multi int t; cin>>t; presolve(); while(t--) solve()
#define single presolve(); solve(); return 0
#define endl '\n'

//////////////////////////////////////////////////////////////////////////////////////
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
void yn(bool b)
{
	if (b)
		cout << "YES\n";
	else cout << "NO\n";
}
/////////////////////////////////////////////////////////////////////////////////////

void presolve()
{

}

ll arr[150004];

void solve()
{
	ll i, j, k, m, n, o, p, l;
	string s;
	cin >> n;
	k = ((n + 1) * n) / 2;
	if (k % 2)
	{
		cout << 0;
		return;
	}
	for (i = 1; i <= n; i++)
	{
		arr[i] = 1;
	}
	for (i = n; i >= 1; i--)
	{
		for (j = k; j > i; j--)
		{
			if (i + j <= k)
			{
				arr[i + j] += arr[i] * arr[j];
				arr[i + j] = (arr[i + j] + 1000000007) % 1000000007;
			}
		}
	}
	cout << arr[k / 2] / 2;
}

int main()
{
	single;
	multi;

	return 0;
}
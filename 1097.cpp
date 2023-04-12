#include <iostream>
using namespace std;
#define ll long long

ll arr[5005];
ll pref[5005];
ll dp[5002][5002];
ll opt2(int s, int e);
ll opt1(int s, int e)
{
	if (s == e)
		return arr[s];
	if (dp[s][e])
		return dp[s][e];
	ll a, b;
	a = opt2(s + 1, e);
	b = opt2(s, e - 1);
	a = pref[e] - pref[s] - a + arr[s];
	if (s > 0)
	{
		b = pref[e - 1] - pref[s - 1] - b + arr[e];
	}
	else b = pref[e - 1] - b + arr[e];
	return dp[s][e] = max(a, b);
}
ll opt2(int s, int e)
{
	if (s == e)
		return arr[s];
	if (dp[s][e])
		return dp[s][e];
	ll a, b;
	a = opt1(s + 1, e);
	b = opt1(s, e - 1);
	a = pref[e] - pref[s] - a + arr[s];
	if (s > 0)
	{
		b = pref[e - 1] - pref[s - 1] - b + arr[e];
	}
	else b = pref[e - 1] - b + arr[e];
	return dp[s][e] = max(a, b);
}
int main()
{
	int i, j, n;
	cin >> n;
	ll k = 0;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		pref[i] = k;
		pref[i] += arr[i];
		k = pref[i];
	}
	cout << opt1(0, n - 1) << endl;

	return 0;
}
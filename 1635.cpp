#include <iostream>
using namespace std;

int arr[1000006];
int coins[105];
int main()
{
	int i, j, k, l, m, n, o, p, x;
	cin >> n >> x;
	for (i = 0; i < n; i++)
	{
		cin >> coins[i];
		arr[coins[i]]++;
	}
	for (i = 1; i <= x; i++)
	{
		if (arr[i] == 0)
			continue;
		for (j = 0; j < n; j++)
		{
			if (coins[j] + i <= x)
			{
				arr[coins[j] + i] += arr[i];
				arr[coins[j] + i] %= 1000000007;
			}
		}
	}
	cout << arr[x];

	return 0;
}
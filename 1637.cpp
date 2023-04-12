#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int arr[6000006];
int main()
{
	int i, j, k, l, m, n, o, p; 
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> n;
	arr[n] = 0;
	for (i = n; i >= 1; i--)
	{
		if (arr[i] > 0 || i == n)
		{
			m = 0;
			int a[8];
			k = i;
			for (j = 6; j >= 0; j--)
			{
				o = k / pow(10, j);
				k %= int(pow(10, j));
				a[m] = o;
				if (a[0] > 0)
				{
					o = a[m];
					if (o == 0)
						continue;
					if (arr[i - o] > arr[i] + 1 || arr[i - o] == 0)
						arr[i - o] = arr[i] + 1;
					m++;
				}
			}
		}
	}
	cout << arr[0];

	return 0;
}
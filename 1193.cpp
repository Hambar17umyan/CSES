#include <iostream>
#include <vector>
#include <map>
using namespace std;

char arr[1002][1002];
map<pair<int, int>, vector<pair<int, int>>>v;
string s = "";
pair<int, int>A, B;


int main()
{
	int i, j, k, l, m, n, o, p;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (arr[i][j] == '.' || arr[i][j] == 'A' || arr[i][j] == 'B')
			{
				if (arr[i][j] == 'A')
				{
					A = make_pair(i, j);
				}
				else if (arr[i][j] == 'B')
				{
					B = make_pair(i, j);
				}
				if (i > 0)
				{
					if (arr[i - 1][j] == '.')
					{
						v[make_pair(i, j)].push_back(make_pair(i - 1, j));
					}
				}
				if (i < n - 1)
				{
					if (arr[i + 1][j] == '.')
					{
						v[make_pair(i, j)].push_back(make_pair(i + 1, j));
					}
				}
				if (j < m - 1)
				{
					if (arr[i][j + 1] == '.')
					{
						v[make_pair(i, j)].push_back(make_pair(i, j + 1));
					}
				}
				if (j > 0)
				{
					if (arr[i][j - 1] == '.')
					{
						v[make_pair(i, j)].push_back(make_pair(i, j - 1));
					}
				}
			}
		}
	}


	return 0;
}
#include <iostream>
using namespace std;

typedef long long ll;

#define midd mid + 1
#define middle int mid = (l + r) / 2
#define poss pos * 2

const int N = 200005;
int arr[N], prr[N];
pair<pair<int, int>, int> t[4 * N];

//segment tree

void build(int l, int r, int pos)
{
	if (l == r)
	{
		t[pos].first = make_pair(arr[r], arr[r]);
		prr[l] = pos;
		t[pos].second = 1;
		return;
	}
	middle;
	build(l, mid, poss);
	build(midd, r, poss + 1);
	t[pos].first = make_pair(min(t[poss].first.first, t[poss + 1].first.first), max(t[poss].first.second, t[poss + 1].first.second));
	t[pos].second = t[poss].second + t[poss + 1].second;
}

void update(int ind)
{
	int pos = prr[ind];
	t[pos].first = make_pair(arr[ind], arr[ind]);
	pos /= 2;
	while (pos)
	{
		t[pos].first = make_pair(min(t[poss].first.first, t[poss + 1].first.first), max(t[poss].first.second, t[poss + 1].first.second));
		pos /= 2;
	}
}

int query(int a, int b, int l, int r, int pos)
{
	middle;
	if (t[pos].first.first >= a && t[pos].first.second <= b)
	{
		return t[pos].second;
	}
	if (t[poss].first.first > b || t[poss].first.second < a)
	{
		if (t[poss + 1].first.first > b || t[poss + 1].first.second < a)
		{
			return 0;
		}
		return query(a, b, midd, r, poss + 1);
	}
	if (t[poss + 1].first.first > b || t[poss + 1].first.second < a)
	{
		return query(a, b, l, mid, poss);
	}
	return query(a, b, l, mid, poss) + query(a, b, midd, r, poss + 1);
}

/////////////////////////////////////////////////

int main()
{
	int i, j, n, q, m;
	cin >> n >> q;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	build(0, n - 1, 1);
	while (q--)
	{
		char op;
		cin >> op;
		int a, b;
		cin >> a >> b;
		if (op == '!')
		{
			arr[a] = arr[b];
			update(a);
		}
		else
		{
			cout << query(a, b, 0, n - 1, 1) << endl;
		}
	}

	return 0;
}
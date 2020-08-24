#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;


int parent[1000001];


int find(int a)
{
	if (parent[a] == a)
		return a;

	return parent[a] = find(parent[a]);
}


int getParent(int x)
{

}


void uni(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
		return;
	else
		parent[a] = b;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;



	for (int i = 1; i <= n; i++)
		parent[i] = i;

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;

		if (a == 0)
			uni(b, c);
		else
		{
			if (find(b) == find(c))
				cout << "YES\n";
			else
				cout << "NO\n";
		}

		 
	}
}


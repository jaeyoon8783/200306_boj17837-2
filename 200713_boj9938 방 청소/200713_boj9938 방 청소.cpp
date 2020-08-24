#include <iostream>
#define pii pair<int, int>
using namespace std;


int parent[300001];
int total[300001];
int bear[300001] = { 0 };
int find(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = find(parent[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
	{
		parent[a] = b; // b 가 상위
		total[b] += total[a];
		bear[b] += bear[a];
	}
	//cout << total[b] << ' ' << bear[b] << '\n';

	if (total[b] == bear[b])
		cout << "SMECE\n";
	else
	{
		cout << "LADICA\n";
		bear[b] += 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, l;
	cin >> n >> l;

	for (int i = 1; i <= l; i++)
	{
		parent[i] = i;
		total[i] = 1;
	}

	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		uni(a, b);
	}
}

/*
5 4
1 4
2 3
1 3
2 4
1 2
*/
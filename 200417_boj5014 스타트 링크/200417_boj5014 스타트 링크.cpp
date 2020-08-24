#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

//1725

int check[1000001];



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int f, s, g, u, d; //  총 f층, 강호는 s위치, 목적지는 g
	cin >> f >> s >> g >> u >> d;


	check[s] = 1;
	queue<int> q;
	q.push(s);


	while (!q.empty())
	{
		int t = q.front();
		q.pop();


		if (t + u <= f && check[t + u] == 0)
		{
			check[t + u] = check[t] + 1;
			q.push(t + u);
		}
		if (t - d >= 1 && check[t - d] == 0)
		{
			check[t - d] = check[t] + 1;
			q.push(t - d);
		}

	}
	if (check[g] == 0)
		cout << "use the stairs";
	else
		cout << check[g] - 1;

}

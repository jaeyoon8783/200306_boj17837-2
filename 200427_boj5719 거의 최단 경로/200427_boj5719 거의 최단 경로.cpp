#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define INF 987654321
using namespace std;
int v, e;
int start, finish;

class pos
{
public : 
	int node;
	int dist;
	vector<int> status;
};

class comp
{
public :
	bool operator () (const pos &p1, const pos &p2)
	{
		return p1.dist > p2.dist;
	}
};

int edge[500][500] = { 0 };
int ans[500];
int ans2[500];
priority_queue<pos, vector<pos>, comp> pq;
vector<vector<int>> route;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1)
	{
		cin >> v >> e;
		if (v == 0)
			break;

		for (int i = 0; i < 500; i++)
			fill(edge[i], edge[i] + 500, 0);
		//fill(ans, ans + 500, 0);
		//fill(ans2, ans2 + 500, 0);

		cin >> start >> finish;

		int st, en, di;
		for (int i = 0; i < e; i++)
		{
			cin >> st >> en >> di;
			edge[st][en] = di;
		}

		for (int i = 0; i < v; i++)
		{
			ans[i] = INF;
			ans2[i] = INF;
		}
		ans[start] = 0;
		ans2[start] = 0;
		pos pp;
		pp.node = start;
		pp.dist = 0;
		pq.push(pp);

		while (!pq.empty())
		{
			pos t = pq.top();
			pq.pop();

			if (t.dist > ans[t.node])
			{
				continue;
			}
			for (int i = 0; i < v; i++)
			{
				if (edge[t.node][i] != 0)
				{
					if (ans[i] > ans[t.node] + edge[t.node][i])
					{
						ans[i] = ans[t.node] + edge[t.node][i];
						pos nt;
						nt.node = i;
						nt.dist = ans[i];
						nt.status = t.status;
						nt.status.push_back(i);
						pq.push(nt);

						if (i == finish)
						{
							route.clear();
							route.push_back(nt.status);
						}

					}
					else if (ans[i] == ans[t.node] + edge[t.node][i])
					{
						pos nt;
						nt.node = i;
						nt.dist = ans[i];
						nt.status = t.status;
						nt.status.push_back(i);
						pq.push(nt);

						if (i == finish)
						{
							route.push_back(nt.status);
						}
					}
				}
			}
		}
		/*
		cout << route.size() << "\n";

		for (int i = 0; i < route.size(); i++)
		{
			for (int j = 0; j < route[i].size(); j++)
			{
				cout << route[i][j] << ' '; 
			}
			cout << "\n";
		}
		*/

		for (int i = 0; i < route.size(); i++)
		{
			for (int j = 0; j < route[i].size() ; j++)
			{
				if (j == 0)
					edge[start][route[i][j]] = 0; // 여길 실수했다. 왜 start 대신 0을 넣었지;;;;
				else
					edge[route[i][j-1]][route[i][j]] = 0;
			}
		}

		pq.push(pp);

		while (!pq.empty())
		{
			pos t = pq.top();
			pq.pop();
			if (t.dist > ans2[t.node])
				continue;

			for (int i = 0; i < v; i++)
			{
				if (edge[t.node][i] != 0 && ans2[i] > ans2[t.node] + edge[t.node][i])
				{	
					ans2[i] = ans2[t.node] + edge[t.node][i];
					pos nt;
					nt.node = i;
					nt.dist = ans2[i];
					nt.status = t.status;
					pq.push(nt);
				}
			}
		
		}
		

		if (ans2[finish] == INF)
			cout << -1 << '\n';
		else
			cout << ans2[finish] << '\n';

	}
}


/*

7 9
0 6
0 1 1
0 2 1
0 3 2
0 4 3
1 5 2
2 6 4
3 6 2
4 6 4
5 6 1
0 0

2 2
1 0
0 1 5
1 0 5

3 1

1 2

1 2 1

-1

*/
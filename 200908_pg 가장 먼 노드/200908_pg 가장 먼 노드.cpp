#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

vector<int> edge[20001];
int check[20001] = { 0 };
int m_dist = 1;

int solution(int n, vector<vector<int>> e)
{
	

	for (int i = 0; i < e.size(); i++)
	{
		edge[e[i][0]].push_back(e[i][1]);
		edge[e[i][1]].push_back(e[i][0]);
	}

	
	check[1] = 1;

	queue<pii> q;
	q.push({ 1, 1 }); // node, cnt;


	while (!q.empty())
	{
		pii t = q.front();
		q.pop();
		m_dist = max(m_dist, t.second);

		for (int i = 0; i < edge[t.first].size(); i++)
		{
			int nnode = edge[t.first][i];
			if (check[nnode] != 0)
				continue;

			check[nnode] = t.second + 1;
			q.push({ nnode, t.second + 1 });
		}


	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == m_dist)
			ans++;
	}
	return ans;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int n = 6;
	vector<vector<int>> edge = { {3, 6},{4,3}, {3,2}, {1,3}, {1,2}, {2,4}, {5,2} };
	cout << solution(n, edge);

}

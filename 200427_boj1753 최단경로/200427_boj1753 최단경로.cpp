#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define INF 987654321
using namespace std;
int v, e,start;

class comp
{
public :
	bool operator () (const pii &p1, const pii &p2) const
	{
		return p1.second > p2.second;
	}
};


vector<pii> edge[20001]; // next, dist
priority_queue<pii , vector<pii>, comp> pq; //vertex, cur_dist
int vertex[20001]; // ans
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	cin >> v >> e>>start; 

	int st, en, di;
	for (int i = 0; i < e; i++)
	{
		cin >> st >> en >> di;
		edge[st].push_back({ en,di });
	}

	
	for (int i = 1; i <= v; i++)
	{
		if (i == start)
			vertex[i] = 0;
		else
			vertex[i] = INF;
		
		pq.push({ i, vertex[i] });
	}


	while (!pq.empty())
	{
		pii t = pq.top();
		pq.pop();

		if (t.second > vertex[t.first])
			continue;

		for (int i = 0; i < edge[t.first].size(); i++)
		{
			int next_node = edge[t.first][i].first;
			int next_dist = edge[t.first][i].second;

			if (vertex[next_node] > vertex[t.first] + next_dist)
			{
				vertex[next_node] = vertex[t.first] + next_dist;
				pq.push({ next_node,  vertex[t.first] + next_dist });
			}
		}

	}
	

	for (int i = 1; i <= v; i++)
	{
		if (vertex[i] == INF)
			cout << "INF" << "\n";
		else
			cout << vertex[i] << "\n";
	}
}

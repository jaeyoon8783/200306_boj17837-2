#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define pii pair<int, int>
using namespace std;


class comp
{
public :
	bool operator () (const pii & p1, const pii & p2)
	{
		return p1.second > p2.second;
	}
};


int v, e, t;
vector<pii> edge[2001];
int one[2001];  // start출발
int two[2001]; // g출발
int three[2001]; // h출발
priority_queue<pii,vector<pii>, comp> pq;
vector<int> candi;
vector<int> output;

void go(int ans[], int init)
{
	ans[init] = 0;

	
	pq.push({ init, 0 });

	while (!pq.empty())
	{
		pii t = pq.top(); // node, cur_dist
		pq.pop();

		if (t.second > ans[t.first])
			continue;

		for (int i = 0; i < edge[t.first].size(); i++)
		{
			int n_node = edge[t.first][i].first;
			int n_dist = edge[t.first][i].second;

			if (ans[n_node] > ans[t.first] + n_dist)
			{
				ans[n_node] = ans[t.first] + n_dist;
				pq.push({ n_node, ans[t.first] + n_dist });
			}
	
		}
	}

}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin >> tc;
	for (int z = 0; z < tc; z++)
	{
		for (int i = 1; i <= 2001; i++)
		{
			edge[i].clear();
		}
		candi.clear();
		output.clear();
		cin >> v >> e >> t; //
		int start, g, h; // g,h를 지나야 한다.
		cin >> start >> g >> h;
		int st, en, di;
		int gh_dist;

		for (int i = 0; i < e; i++)
		{
			cin >> st >> en >> di;
			edge[st].push_back({ en, di });
			edge[en].push_back({ st,di });

			if ((st == g && en == h) || (st == h && en == g))
				gh_dist = di;

		}
		int aa;
		for (int i = 0; i < t; i++)
		{
			cin >> aa;
			candi.push_back(aa);
		}

		for (int i = 1; i <= v; i++)
		{
			one[i] = INF;
			two[i] = INF;
			three[i] = INF;
		}

		go(one, start);
		go(two, g);
		go(three, h);
		//ans = dist, prev
		/*
		for (int i = 1; i <= v; i++)
		{
			cout << one[i] << ' ';
		}
		cout << "\n";
		for (int i = 1; i <= v; i++)
		{
			cout << two[i] << ' ';
		}
		cout << "\n";
		for (int i = 1; i <= v; i++)
		{
			cout << three[i] << ' ';
		}
		cout << "\n";
*/
		for (int i = 0; i < candi.size(); i++)
		{
			int who = candi[i];
		//	cout << one[who] << ' ' << one[g] + gh_dist + th[who] << ' ' << one[h] + gh_dist + three[who] << '\n';
			if ((one[who] == one[g] + gh_dist + three[who]) || (one[who] == one[h] + gh_dist + two[who]))
				output.push_back(who);
		}
		sort(output.begin(), output.end());
		for (int i = 0; i < output.size(); i++)
		{
			cout << output[i] << ' ';
		}

		cout << "\n";
	}

}


/*
1
6 9 2
2 3 1
1 2 1
1 3 3
2 4 4
2 5 5
3 4 3
3 6 2
4 5 4
4 6 3
5 6 7
5
6



*/
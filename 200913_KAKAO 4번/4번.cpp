#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define pii pair<int, int>
#define INF 987654321
using namespace std;


vector<pii> edge[201];

int ans[201];


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

	int map[201][201];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = INF;
		}
	}

	for (int i = 0; i < fares.size(); i++)
	{
		map[fares[i][0]][fares[i][1]] = fares[i][2];
		map[fares[i][1]][fares[i][0]] = fares[i][2];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	int ans = map[s][a] + map[s][b];

	for (int i = 1; i <= n; i++)
	{
		if (map[s][i] == INF || map[i][a] == INF || map[i][b] == INF)
			continue;
		ans = min(ans, map[s][i] + map[i][a] + map[i][b]);
	}

	
	return ans;


}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	/*
	int n = 6;
	int s = 4;
	int a = 6;
	int b = 2;

	vector<vector<int>> fares = { {4, 1, 10},{3, 5, 24},{5, 6, 2},{3, 1, 41},{5, 1, 24},{4, 6, 50},{2, 4, 66},{2, 3, 22},{1, 6, 25} };
	*/

	vector<vector<int>> fares = { {5, 7, 9},{4, 6, 4},{3, 6, 1},{3, 2, 3},{2, 1, 6} };
	cout << solution(7,3,4,1,fares);


}

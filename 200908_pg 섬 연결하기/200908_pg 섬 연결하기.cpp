#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

bool comp(const vector<int> &a, const vector<int> &b)
{
	return a[2] < b[2];
}
int parent[101];
int find(int node)
{
	if (parent[node] == node)
		return node;
	return parent[node] = find(parent[node]);
}

int solution(int n, vector<vector<int>> cost)
{
	sort(cost.begin(), cost.end(), comp);
	
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	
	int ans = 0;
	for (int i = 0; i < cost.size(); i++)
	{
		int aa = find(cost[i][0]);
		int bb = find(cost[i][1]);
		if (aa == bb)
			continue;

		ans += cost[i][2];
		parent[aa] = bb;

	}

	return ans;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int n = 4;
	vector<vector<int>> c = { {0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {2,3,8} };
	cout << solution(n,c);
}

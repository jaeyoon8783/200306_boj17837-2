//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <queue>
//#define pii pair<int, int>
//#define INF 987654321
//using namespace std;
//
//
//vector<pii> edge[201];
//
//int ans[201];
//int gogo(int node, int start, int end)
//{
//
//	for (int i = 1; i <= node; i++)
//	{
//		if (i == start)
//			ans[i] = 0;
//		else
//			ans[i] = INF;
//	}
//
//	priority_queue<pii, vector<pii>, less<pii>> pq; //vertex, cur_dist
//	pq.push({ start, 0 });
//
//	while (!pq.empty())
//	{
//		pii t = pq.top();
//		pq.pop();
//
//		if (t.second > ans[t.first])
//			continue;
//
//
//		for (int i = 0; i < edge[t.first].size(); i++)
//		{
//			int next = edge[t.first][i].first;
//			int dist = edge[t.first][i].second;
//
//			if (ans[t.first] + dist < ans[next])
//			{
//				ans[next] = ans[t.first] + dist;
//				pq.push({ next, ans[t.first] + dist });
//			}
//		}
//	}
//
//	return ans[end];
//}
//
//
//
//int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
//	
//	for (int i = 0; i < fares.size(); i++)
//	{
//		edge[fares[i][0]].push_back({ fares[i][1], fares[i][2] });
//		edge[fares[i][1]].push_back({ fares[i][0], fares[i][2] });
//	}
//
//	int aa= gogo(n, s, a) + gogo(n, s, b);
//	int bb = gogo(n, s, a) + gogo(n, a, b);
//	int cc = gogo(n, s, b) + gogo(n, b, a);
//
//	return min(aa, min(bb, cc));
//
//}
//
//
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	int n = 6;
//	int s = 4;
//	int a = 6;
//	int b = 2;
//
//	vector<vector<int>> fares = { {4, 1, 10},{3, 5, 24},{5, 6, 2},{3, 1, 41},{5, 1, 24},{4, 6, 50},{2, 4, 66},{2, 3, 22},{1, 6, 25} };
//
//	cout << solution(n, s, a, b, fares);
//
//
//}

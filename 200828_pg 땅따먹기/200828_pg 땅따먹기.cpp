#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

int solution(vector<vector<int>> land)
{
	int d[100000][4] = { 0 };

	d[0][0] = land[0][0];
	d[0][1] = land[0][1];
	d[0][2] = land[0][2];
	d[0][3] = land[0][3];

	for (int i = 1; i < land.size(); i++)
	{
		d[i][0] = max(d[i - 1][1], max(d[i - 1][2], d[i - 1][3])) + land[i][0];
		d[i][1] = max(d[i - 1][0], max(d[i - 1][2], d[i - 1][3])) + land[i][1];
		d[i][2] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][3])) + land[i][2];
		d[i][3] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2])) + land[i][3];
	}
	

	return max(d[land.size() - 1][0], max(d[land.size() - 1][1], max(d[land.size() - 1][2], d[land.size() - 1][3])));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	vector<vector<int>> land = { {1, 2, 3, 5},{5, 6, 7, 8},{4, 3, 2, 1} };
	cout << solution(land);

}

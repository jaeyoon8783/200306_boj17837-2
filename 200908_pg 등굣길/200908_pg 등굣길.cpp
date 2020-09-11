#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
#define NA 1000000007
using namespace std;

int solution(int x, int y, vector<vector<int>> no)
{
	int d[100][100] = { 0 };
	d[0][0] = 1;
	for (int i = 0; i < no.size(); i++)
	{
		d[no[i][0] - 1][no[i][1] - 1] = -1;
	}

	for (int i = 1; i < x; i++)
	{
		if (d[i][0] == -1)
			break;
		d[i][0] = d[i - 1][0];
	}
	for (int i = 1;i < y; i++)
	{
		if (d[0][i] == -1)
			break;
		d[0][i] = d[0][i - 1];
	}

	for (int i = 1; i < x; i++)
	{
		for (int j = 1; j < y; j++)
		{
			if (d[i][j] == -1)
				continue;
			if (d[i - 1][j] != -1)
				d[i][j] = (d[i][j] + d[i - 1][j])%NA;
			if (d[i][j - 1] != -1)
				d[i][j] = (d[i][j] + d[i][j - 1])%NA;
		}
	}

	return d[x - 1][y - 1];
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m = 4;
	int n = 3;

	vector<vector<int>> puddles = { {2,2} };
	cout << solution(m, n, puddles);

}

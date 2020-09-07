#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
#define MOD 20170805
using namespace std;

int d[501][501][2] = {0}; // left, up
int solution(int m, int n, vector<vector<int>> cm)
{
	d[1][1][0] = d[1][1][1] = 1; // 

	for (int i = 1; i <= m; i++)
	{
		for(int j = 1 ; j <= n ; j++)
		{ 
			if (cm[i - 1][j - 1] == 0)
			{
				//d[i][j][0] += (d[i])
			}
		}
	}
	return -1;
}
int solution2(int m, int n, vector<vector<int>> city_map) {

	int answer = 0;

	int fromLeft[501][501] = { 0 };
	int fromTop[501][501] = { 0 };

	fromTop[1][1] = fromLeft[1][1] = 1;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {


			if (city_map[i - 1][j - 1] == 0) {
				fromLeft[i][j] += (fromLeft[i][j - 1] + fromTop[i - 1][j]) % MOD;
				fromTop[i][j] += (fromLeft[i][j - 1] + fromTop[i - 1][j]) % MOD;
			}
			else if (city_map[i - 1][j - 1] == 1) {
				fromLeft[i][j] = 0;
				fromTop[i][j] = 0;
			}
			else {
				fromLeft[i][j] = fromLeft[i][j - 1];
				fromTop[i][j] = fromTop[i - 1][j];
			}
		}
	}
	/*
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << fromLeft[i][j] << '/' << fromTop[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	answer = (fromLeft[m][n - 1] + fromTop[m - 1][n]) % MOD;
	return answer;
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);



	vector<vector<int>> cm = { {0,2,2,2,2,2,2,0} };


	cout << solution2(cm.size(), cm[0].size(), cm);


}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;


int solution(int n, vector<vector<int>> arr)
{
	int map[101][101] = { 0 };
	
	for (int i = 0; i < arr.size(); i++)
	{
		int in = arr[i][0];
		int out = arr[i][1];
		map[in][out] = 1;
		map[out][in] = -1;
	}


	for (int i = 1; i <= n; i++)
	{
		vector<int> in; // 상위
		vector<int> out; // 하위
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == -1)
				in.push_back(j);
			else if (map[i][j] == 1)
				out.push_back(j);

		}

		for (int j = 0; j < in.size(); j++)
		{
			for (int k = 0; k < out.size(); k++)
			{
				map[in[j]][out[k]] = 1;
				map[out[k]][in[j]] = -1;
			}
		}
		
	}

	int ans = 0;
	for (int i = 1; i <= n ; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 1 || map[i][j] == -1)
				cnt++;
		}
		if (cnt == n - 1)
			ans++;
	}


	return ans;
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 6;
	//vector<vector<int>> arr = { {4,3}, {4,2}, {3,2}, {1,2}, {2,5} };
	vector<vector<int>> arr = { {1,4}, {2,4}, {3,4}, {4,5}, {4,6}, {5,6} };
	cout << solution(n, arr);


}
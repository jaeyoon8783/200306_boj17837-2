#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;


vector<int> solution(int n)
{
	vector<vector<int>> arr(n, vector<int>(n));

	int base_x = -1;
	int base_y = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		
		if (i % 3 == 0)
		{
			for (int j = 0; j < n - i; j++)
			{
				base_x++;
				cnt++;
				arr[base_x][base_y] = cnt;
			}
		}
		if (i % 3 == 1)
		{
			for (int j = 0; j < n - i; j++)
			{
				base_y++;
				cnt++;
				arr[base_x][base_y] = cnt;
			}
		}
		if (i % 3 == 2)
		{
			for (int j = 0; j < n - i; j++)
			{
				base_x--;
				base_y--;
				cnt++;
				arr[base_x][base_y] = cnt;
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			ans.push_back(arr[i][j]);
	}
	return ans;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int n = 6;
	solution(n);


}

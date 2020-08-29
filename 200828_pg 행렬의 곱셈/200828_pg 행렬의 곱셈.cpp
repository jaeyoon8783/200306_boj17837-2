#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;

	for (int i = 0; i < arr1.size(); i++)
	{
		vector<int> tmp;
		for (int j = 0; j < arr2[0].size(); j++)
		{
			int sum = 0;

			for (int k = 0; k < arr1[0].size(); k++)
			{
				sum += (arr1[i][k] * arr2[k][j]);
			}
			tmp.push_back(sum);

		}
		answer.push_back(tmp);
	}


	return answer;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	vector<vector<int>> a = { {1,4}, {3,2}, {4,1} };
	vector<vector<int>> b = { {3,3}, {3,3} };
	
	vector<vector<int>> ans = solution(a, b);

	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[0].size(); j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}

}

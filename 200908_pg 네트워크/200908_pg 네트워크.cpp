#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

int solution(int n, vector<vector<int>> com)
{
	int ans = 0;
	int check[200] = { 0 };
	for (int i = 0; i < n; i++)
	{
		if (check[i] == 0)
		{
			queue<int> q;
			check[i] = 1;
			q.push(i);
			while (!q.empty())
			{
				int tmp = q.front();
				q.pop();

				for (int j = 0; j < n; j++)
				{
					if (com[tmp][j] == 1 && check[j] == 0)
					{
						check[j] = 1;
						q.push(j);
					}
				}

			}
			ans++;
		}


	}

	return ans;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 3;
	vector<vector<int>> com = { {1,1,0}, {1,1,1,}, {0,1,1} };
	cout << solution(n, com);



}

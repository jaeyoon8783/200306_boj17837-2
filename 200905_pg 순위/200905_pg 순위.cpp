#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;


vector<int> edge[101];
int in[101] = { 0 };
int out[101] = { 0 };
int check[101] = { 0 };


void go(int cur_node, int n)
{
	if ( in[cur_node] + out[cur_node] == n-1)
	{
		check[cur_node] = 1;
		for (int i = 0; i < edge[cur_node].size(); i++)
		{
			if (check[edge[cur_node][i]] != 0)
				continue;
			go(edge[cur_node][i], n - in[cur_node]);
		}
	}

}


int solution(int n, vector<vector<int>> arr)
{

	for (int i = 0; i < arr.size(); i++)
	{
		out[arr[i][0]]++;
		in[arr[i][1]]++;

		edge[arr[i][0]].push_back(arr[i][1]);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << in[i] << ' ' << out[i] << '\n';
	}


	for (int i = 1; i <= n; i++)
	{
		if (check[i] != 0)
			continue;
		if ((in[i] + out[i]) == n - 1)
		{
			check[i] = 1;

			for (int j = 0; j < edge[i].size(); j++)
			{
				if (check[edge[i][j]] != 0)
					continue;
				go(edge[i][j] ,n - in[i]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += check[i];
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


/*



*/
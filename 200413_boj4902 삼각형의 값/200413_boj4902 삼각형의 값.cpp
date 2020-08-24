#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans;
int arr[1000][1000];

void expand( int cur_i, int start_j, int end_j, int sum)
{
	if (start_j == 0)
		sum += (arr[cur_i][end_j]);
	else
		sum += (arr[cur_i][end_j] - arr[cur_i][start_j-1]);

	/*
	for (int j = start_j; j <= end_j; j++)
		sum += arr[cur_i][j];
		*/
	ans = max(ans, sum);
	if (cur_i + 1 < n)
	{
		expand( cur_i + 1, start_j, end_j + 2, sum);
	}
}

void expand2(int cur_i, int start_j, int end_j, int sum)
{
	if (start_j == 0)
		sum += (arr[cur_i][end_j]);
	else
		sum += (arr[cur_i][end_j] - arr[cur_i][start_j-1]);
	/*
	for (int j = start_j; j <= end_j; j++)
		sum += arr[cur_i][j];
		*/
	ans = max(ans, sum);

	if (start_j - 2 >= 0 && end_j <= ((cur_i - 1) * 2))
		expand2(cur_i - 1, start_j - 2, end_j, sum);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int asd = 1;


	while (1)
	{
		cin >> n;
		
		for (int i = 0; i < 1000; i++)
		{
			fill(arr[i], arr[i] + 1000, 0);
		}

		if (n == 0)
			break;
		ans = -987654321;
		int t;
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < (i + 1) * 2 - 1; j++)
			{
				cin >> t;
				sum += t;
				arr[i][j] = sum;
				//	ans = max(ans, arr[i][j]);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i * 2; j++)
			{
				if (j % 2 == 0)
					expand( i, j, j, 0);
				else
					expand2( i, j, j, 0);
			}
		}

		cout << asd << ". " << ans << "\n";
		asd++;
	}


}
/*
4 1 2 -3 -4 1 13 50 4 2 -9 -2 -12 12 -1 -2 -1
5 1 2 -3 -4 1 13 50 4 2 -9 -2 -12 12 -1 -2 -1 10 -1 -2 -100 -4 100 1 2 3
6 1 2 -3 -4 1 13 50 4 2 -9 -2 -12 12 -1 -2 -1 10 -1 -2 -100 -4 100 1 2 3 1 1 1 1 1 1 1 1 1 1 1
0

*/
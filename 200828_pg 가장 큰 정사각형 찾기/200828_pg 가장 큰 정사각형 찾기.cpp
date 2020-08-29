#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>

using namespace std;

int solution(vector<vector<int>> sq)
{
	int ans = 0;
	int x = sq.size();
	int y = sq[0].size();

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (sq[i][j] == 0)
				continue;

			int size = 1;
			
			while((i + size < x) && (j + size < y))
			{
				int is_break = 0;
				for (int k = size; k >= 0; k--)
				{
					if (sq[i+size][j+k] == 0)
					{
						is_break = 1;
						break;
					}
					if (sq[i+k][j+size] == 0)
					{
						is_break = 1;
						break;
					}
				}
				if (is_break == 1)
					break;
				else
					size++;
			}
			ans = max(ans, size);

		}
	}

	return ans*ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<vector<int>> sq = { {0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0} };

	cout << solution(sq);

}

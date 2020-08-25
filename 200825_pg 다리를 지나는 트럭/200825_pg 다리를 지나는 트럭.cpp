#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

int solution(int bl, int w, vector<int> tw) {
	
	int ans = 0;

	vector<pii> cur; // weight, cur_position
	
	cur.push_back({ tw[0], 0 });
	int complete = 0;
	int cur_bw = tw[0];
	ans++;


	for (int i = 1; i < tw.size(); i++)
	{
		if (cur_bw + tw[i] > w)
		{
			int total = 0;
			for (int j = complete; j < cur.size(); j++)
			{
				
				total = (bl - cur[j].second);
				cur_bw -= cur[j].first;
				complete++;
				if (cur_bw + tw[i] <= w)
					break;
			}

			for (int j = complete; j < cur.size(); j++)
			{
				cur[j].second += total;
			}

			ans += total;

		}
		else
		{
			for (int j = complete; j < cur.size(); j++)
			{
				cur[j].second++;
				if (cur[j].second == bl)
				{
					complete++;
					cur_bw -= cur[j].first;
				}
			}
			ans++;
		}
		cur.push_back({ tw[i], 0 });
		cur_bw += tw[i];
		
		for (int j = complete; j < cur.size(); j++)
			cout << cur[j].first << '/' << cur[j].second << ' ';
		cout << '\n';
		

	}

	ans += bl;

	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int bl = 4;
	int w = 5;
	vector<int> tw = { 1,2,3,4,5 };

	cout << solution(bl, w, tw);

}

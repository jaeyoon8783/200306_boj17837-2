#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define pii pair<int, int>
using namespace std;


vector<int> solution(vector<string> str)
{
	priority_queue<pii, vector<pii>, less<pii>> max_pq; // su, arr의 위치
	priority_queue<pii, vector<pii>, greater<pii>> min_pq;
	vector<pii> arr; // 수, visited


	for (int i = 0; i < str.size(); i++)
	{
		if (str[i][0] == 'I') // insert
		{
			int su = stoi(str[i].substr(2, str[i].size()));
			cout << su << ' ';
			max_pq.push({ su, arr.size()});
			min_pq.push({ su, arr.size() });
			arr.push_back({ su, 0 });
		}
		else
		{
			if (str[i][2] == '-') // 최솟값 delete
			{
				while (!min_pq.empty())
				{
					pii tmp = min_pq.top();
					min_pq.pop();
					if (arr[tmp.second].second == 0)
					{
						arr[tmp.second].second = 1;
						break;
					}


				}
			}
			else   //최댓값 delete
			{
				while (!max_pq.empty())
				{
					pii tmp = max_pq.top();
					max_pq.pop();
					if (arr[tmp.second].second == 0)
					{
						arr[tmp.second].second = 1;
						break;
					}
				}
			}
		}
	}

	int ans_max = 0;
	int ans_min = 0;
	while (!min_pq.empty())
	{
		pii tmp = min_pq.top();
		min_pq.pop();
		if (arr[tmp.second].second == 0)
		{
			ans_min = tmp.first;
			break;
		}

	}
	while (!max_pq.empty())
	{
		pii tmp = max_pq.top();
		max_pq.pop();
		if (arr[tmp.second].second == 0)
		{
			ans_max = tmp.first;
			break;
		}

	}



	return { ans_max, ans_min };
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<string> str = {"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};
	vector<int> ans = solution(str);
	cout << ans[0] << ' ' << ans[1];
}

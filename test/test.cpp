#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define pii pair<int, int>
using namespace std;
bool comp(const pii& a, const pii& b)
{
	if (a.second != b.second)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int solution(vector<string> lines) {
	vector<pii> condition;
	int zero = 0;
	for (int i = 0; i < lines.size(); i++)
	{
		int h = stoi(lines[i].substr(11, 2));
		int m = stoi(lines[i].substr(14, 2));
		int s = stoi(lines[i].substr(17, 2));
		int ms = stoi(lines[i].substr(20, 3));

		int t_finish = ms;

		m += (h * 60);
		s += (m * 60);
		ms += (s * 1000);

		int ms2 = (lines[i][24] - '0') * 1000;
		string ms3 = "0";
		int j = 25;
		while (lines[i][j] != 's')
		{
			if (lines[i][j] == '.')
			{
				j++;
				continue;
			}
			ms3 += lines[i][j];
			j++;
		}
		ms2 += stoi(ms3);

		if (i == 0)
			zero = ms - ms2 + 1;

		condition.push_back({ ms - ms2 + 1 - zero, ms - zero }); //in


	}

	sort(condition.begin(), condition.end(), comp);
	//for (int i = 0; i < condition.size(); i++)
	//	cout << condition[i].first << ' ' << condition[i].second << '\n';

	int ans = 0;
	for (int i = 0; i < condition.size(); i++)
	{
		int base = condition[i].second;
		int base_thousand = condition[i].second + 999;
		int tmp = 0;

		for (int j = 0; j < condition.size(); j++)
		{
			if (base_thousand < condition[j].first || base > condition[j].second)
				continue;
			else
				tmp++;
		}
		//cout << tmp << ' ';
		ans = max(ans, tmp);

	}

	return ans;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pif pair<int, float>
using namespace std;
pif sta[200001]; // 사람수, 스테이지


bool comp(const pif &a, const pif &b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	
	int challenge[502] = { 0 };
	int fail[502] = { 0 };
	for (int i = 0; i < stages.size(); i++)
	{
		for (int j = stages[i]; j >= 1; j--)
		{
			challenge[j]++;
		}
		fail[stages[i]]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (challenge[i] == 0 || fail[i] == 0)
			sta[i] = { i, 0 };
		else
			sta[i] = { i,((float)fail[i] / challenge[i])};
	}

	sort(sta + 1, sta + N + 1, comp);
	vector<int> ans;
	for (int i = 1; i <= N; i++)
	{
		ans.push_back(sta[i].first);
		cout << sta[i].first << ' ' << sta[i].second << '\n';
	}

	
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 8;
	vector<int> stages = { 1,2,3,4,5,6,7 };

	solution(n, stages);


}

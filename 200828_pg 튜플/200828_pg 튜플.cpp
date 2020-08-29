#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define pii pair<int, int>
using namespace std;

using namespace std;

bool comp(const vector<int> a, vector<int> b)
{
	return a.size() < b.size();
}


vector<int> solution(string s) {
	vector<int> ans;
	vector<vector<int>> arr;
	vector<int> tmp;
	string su_tmp;
	for (int i = 1; i < s.size()-1; i++)
	{
		
		if (s[i] == '{')
			tmp.clear();
		else if (s[i] == '}')
		{
			tmp.push_back(stoi(su_tmp));
			su_tmp = "";
			arr.push_back(tmp);
		}
		else if (s[i] == ',')
		{
			if (s[i-1] == '}')
				continue;
			else
			{
				tmp.push_back(stoi(su_tmp));
				su_tmp = "";
			}
		}
		else
			su_tmp += s[i];
	}
	sort(arr.begin(), arr.end(), comp);
	map<int, int> m;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (m[arr[i][j]] == 0)
			{
				m[arr[i][j]] = 1;
				ans.push_back(arr[i][j]);
				break;
			}
		}
	}

	/*
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
	*/
	

	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
	vector<int> ans = solution(s);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';


}

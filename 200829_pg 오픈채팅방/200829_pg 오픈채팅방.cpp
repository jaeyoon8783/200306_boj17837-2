#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define pii pair<int, int>
using namespace std;

vector<string> solution(vector<string> str)
{
	int cnt = 0;
	map<string, int> mapp;
	vector<string> nick_arr;
	nick_arr.push_back("aa");
	vector<pii> alert; // mapp의 숫자 , 1=enter, 2=leave;
	for (int i = 0; i < str.size(); i++)
	{
		string what = "";
		string id = "";
		string nick = "";
		int j = 0;

		while(str[i][j] != ' ')
			what += str[i][j++];
		j++;

		if (what == "Enter")
		{
			while (str[i][j] != ' ')
				id += str[i][j++];
			j++;
			while (j < str[i].size())
				nick += str[i][j++];

			if (mapp[id] == 0)
			{
				mapp[id] = ++cnt;
				nick_arr.push_back(nick);
			}
			else
			{
				nick_arr[mapp[id]] = nick;
			}
			alert.push_back({ mapp[id], 1 });

		}
		else if (what == "Leave")
		{
			while (j < str[i].size())
				id += str[i][j++];

			alert.push_back({ mapp[id], 2 });

		}
		else
		{
			while (str[i][j] != ' ')
				id += str[i][j++];
			j++;
			while (j < str[i].size())
				nick += str[i][j++];

			nick_arr[mapp[id]] = nick;

		}
	}


	vector<string> ans;
	for (int i = 0; i < alert.size(); i++)
	{
		if (alert[i].second == 1)
			ans.push_back(nick_arr[alert[i].first] + "님이 들어왔습니다.");
		else
			ans.push_back(nick_arr[alert[i].first] + "님이 나갔습니다.");
		cout << ans[i] << '\n';
	}

	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };

	vector<string> ans = solution(record);

}

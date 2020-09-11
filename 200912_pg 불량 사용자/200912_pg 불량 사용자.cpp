#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define psi pair<string, int>
using namespace std;

int check[8] = { 0 };
int ans = 0;
map<string, int> mm;

void go(vector<vector<psi>> list, int cur_pos, vector<string> candi)
{

	if (cur_pos == list.size())
	{
		sort(candi.begin(), candi.end());

		string aa = "";
		for (int i = 0; i < candi.size(); i++)
			aa += candi[i];
		if (mm[aa] == 0)
		{
			ans++;
			mm[aa] = 1;
		}

		return;
	}

	for (int i = 0; i < list[cur_pos].size(); i++)
	{
		if (check[list[cur_pos][i].second] == 1)
			continue;
		check[list[cur_pos][i].second] = 1;
		candi[cur_pos] = list[cur_pos][i].first;
		go(list, cur_pos + 1, candi);
		check[list[cur_pos][i].second] = 0;


	}
}


int solution(vector<string> user_id, vector<string> banned_id) {
	vector<vector<psi>> list(banned_id.size()); // user_name, position

	for (int i = 0; i < banned_id.size(); i++)
	{
		string ban = banned_id[i];
		for (int j = 0; j < user_id.size(); j++)
		{
			string user = user_id[j];
			if (ban.size() != user.size())
				continue;

			int k;
			for (k = 0; k < user.size(); k++)
			{
				if (ban[k] == '*')
					continue;
				if (user[k] != ban[k])
					break;
			}
			if (k == user.size())
				list[i].push_back({ user,j });
		}
	}
	/*
	for (int i = 0; i < list.size(); i++)
	{
		for (int j = 0; j < list[i].size(); j++)
		{
			cout << list[i][j].first << ' ';
		}
		cout << '\n';
	}
	*/
	vector<string> candi(banned_id.size());
	
	go(list, 0, candi);

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<string> u_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> b_id = { "fr*d*", "*rodo", "******", "******" };

	cout << solution(u_id, b_id);



}

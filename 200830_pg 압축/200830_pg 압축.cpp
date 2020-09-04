#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define pii pair<int, int>
using namespace std;

vector<int> solution(string str)
{
	map<string, int> mapp;
	vector<int> ans;

	mapp["A"] = 1; mapp["B"] = 2; mapp["C"] = 3; mapp["D"] = 4;
	mapp["E"] = 5; mapp["F"] = 6; mapp["G"] = 7; mapp["H"] = 8;
	mapp["I"] = 9; mapp["J"] = 10; mapp["K"] =11; mapp["L"] = 12;
	mapp["M"] = 13; mapp["N"] = 14; mapp["O"] = 15; mapp["P"] = 16;
	mapp["Q"] =17; mapp["R"] = 18; mapp["S"] =19; mapp["T"] = 20;
	mapp["U"] = 21; mapp["V"] = 22; mapp["W"] = 23; mapp["X"] = 24;
	mapp["Y"] = 25; mapp["Z"] = 26;
	

	int cnt = 27;


	string cur = "";
	int complete_pos = 0;
	for (int i = 0; i < str.size(); i++)
	{
		cur += str[i];
		string tmp = cur.substr(complete_pos, cur.size());
		cout << tmp << ' ';
		int su = mapp[tmp];

		if (su != 0)
			continue;
		else
		{
			mapp[tmp] = cnt++;
			string tmp2 = tmp.substr(0, tmp.size() - 1);
			ans.push_back(mapp[tmp2]);
			complete_pos = i;
		}
	}
	string tmp = cur.substr(complete_pos, cur.size());
	int su = mapp[tmp];
	if (su != 0)
		ans.push_back(mapp[tmp]);
	else
		ans.push_back(cnt++);




	cout << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	

	return ans;


}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str = "KAKAO";

	vector<int> ans = solution(str);

}

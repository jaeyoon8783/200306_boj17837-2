#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define pii pair<int, int>
using namespace std;

bool comp(const string &a, const string &b)
{
	return a.size() < b.size();
}

bool solution(vector<string> pb)
{
	sort(pb.begin(), pb.end(), comp);
	map<string,int> s;

	for (int i = 0; i < pb.size(); i++)
	{
		string t;
		for (int j = 0; j < pb[i].size(); j++)
		{
			t += pb[i][j];
			if (s[t] != 0)
				return false;
		}
		s[t] = 1;
	}
	return true;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//vector<string> pb = { "119", "97674223", "1195524421" };
	vector<string> pb = { "123", "97674223", "1195524421" };
	cout << solution(pb);

}

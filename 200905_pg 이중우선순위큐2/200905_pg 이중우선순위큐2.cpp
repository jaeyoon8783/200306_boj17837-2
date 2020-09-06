#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define pii pair<int, int>
using namespace std;

vector<int> solution(vector<string> str)
{
	multiset<int> s;


	for (int i = 0; i < str.size(); i++)
	{
		if (str[i][0] == 'I')
		{
			int su = stoi(str[i].substr(2, str[i].size()));
			s.insert(su);
		}
		else
		{
			if (str[i][2] == '-')
			{
				if(s.size() > 0)
					s.erase(s.begin());
			}
			else
			{
				if (s.size() > 0)
					s.erase(--s.end());
			}
		}
	}


	if (s.size() == 0)
		return { 0,0 };
	else
	{
		auto itr = s.begin();
		auto itr2 = s.end();
		itr2--;

		return { *itr2, *itr };

	}


}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	vector<string> str = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
	vector<int> ans = solution(str);
	cout << ans[0] << ' ' << ans[1];

}

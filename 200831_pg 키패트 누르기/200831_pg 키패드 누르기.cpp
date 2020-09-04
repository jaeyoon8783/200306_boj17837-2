#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

string solution(vector<int> num, string hand)
{
	string ans = "";
	pii pos[10] = { {3,1},
					{0,0}, {0,1}, {0,2},
					{1,0}, {1,1}, {1,2},
					{2,0}, {2,1}, {2,2} };
	

	pii lh = { 3,0 };
	pii rh = { 3,2 };

	for (int i = 0; i < num.size(); i++)
	{

		if (num[i] == 1 || num[i] == 4 || num[i] == 7)
		{
			ans += "L";
			lh = { pos[num[i]].first , pos[num[i]].second };
		}
		else if (num[i] == 3 || num[i] == 6 || num[i] == 9)
		{
			ans += "R";
			rh = { pos[num[i]].first , pos[num[i]].second };
		}
		else
		{
			int ldir = abs(lh.first - pos[num[i]].first) + abs(lh.second - pos[num[i]].second);
			int rdir = abs(rh.first - pos[num[i]].first) + abs(rh.second - pos[num[i]].second);

			if (hand == "left")
			{
				if (ldir <= rdir)
				{
					ans += "L";
					lh = { pos[num[i]].first , pos[num[i]].second };
				}
				else
				{
					ans += "R";
					rh = { pos[num[i]].first , pos[num[i]].second };
				}
			}
			else
			{
				if (ldir < rdir)
				{
					ans += "L";
					lh = { pos[num[i]].first , pos[num[i]].second };
				}
				else
				{
					ans += "R";
					rh = { pos[num[i]].first , pos[num[i]].second };
				}
			}
		}



		

	}

	return ans;

}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> num = { 1,3,4,5,8,2,1,4,5,9,5 };
	string hand = "right";
	cout << solution(num, hand);
}

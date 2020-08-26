#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

int make(int n)
{
//	cout << min(n - 1, 27 - n) << ' ';
	return min(n - 1, 27 - n);
}


int solution(string s)
{
	int ans = 0;
	vector<int> pos;
	for (int i = 0; i < s.size(); i++)
	{
		ans += make(s[i] - 'A'+1);
		if (s[i] != 'A')
			pos.push_back(i);
	}

	int minn = min(pos[pos.size() - 1], (int) s.size() - pos[0]);

	for (int i = 0; i < pos.size() - 1; i++)
	{
		minn = min(minn, pos[i] + (pos[i] + (int)s.size()) - pos[i + 1]);
	}


	
	

	//cout << ans << ' ' << left_go << ' ' << right_go << '\n';

	return ans + minn;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s = "BAABBBBAA";
	cout << solution(s);
}

/*
FEDG

처음생각

int right_go = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] != 'A')
			right_go = i;
	}
	int left_go = 0;
	for (int i = s.size()-1; i >= 1; i--)
	{
		if (s[i] != 'A')
			left_go = s.size() - i;
	}

	//cout << ans << ' ' << left_go << ' ' << right_go << '\n';

	return ans += min(right_go, left_go);


	이러면 ABABABAAAAAAAAAAAAAABABA 라는 예외가 있다.

*/


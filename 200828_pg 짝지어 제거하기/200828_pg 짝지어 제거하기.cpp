#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#define pii pair<int, int>
using namespace std;

int solution(string str)
{
	stack<char> s;

	for (int i = 0; i < str.size(); i++)
	{
		if (s.empty())
			s.push(str[i]);
		else
		{
			char t = s.top();
			if (t == str[i])
				s.pop();
			else
				s.push(str[i]);
		}
	}

	return s.empty();



}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s = "dabbaccd";
	cout << solution(s);
}

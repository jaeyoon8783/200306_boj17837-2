#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
#define ll long long int
using namespace std;

string get_min(string str1, string str2)
{
	if (str1 == "")
		return str2;

	if (str1[0] == '-' && str2[0] != '-') // 왼쪽이 -
		return str1;
	else if (str1[0] != '-' && str2[0] == '-')
		return str2;
	else if (str1[0] == '-' && str2[0] == '-') // 둘다 음수
	{
		if (str1.size() < str2.size()) // -11, -111
			return str2;
		else if (str1.size() > str2.size())
			return str1;
		else
		{
			for (int i = 1; i < str1.size(); i++)
			{
				if (str1[i] < str2[i])  // -3  -4
					return str2;
				else if (str1[i] > str2[i])
					return str1;
			}
			return str1;
		}
	}
	else // 둘다 양수
	{
		if (str1.size() < str2.size()) // 11, 111
			return str1;
		else if (str1.size() > str2.size())
			return str2;
		else
		{
			for (int i = 0; i < str1.size(); i++)
			{
				if (str1[i] < str2[i])
					return str1;
				else if (str1[i] > str2[i])
					return str2;
			}
			return str1;
		}
	}
}

string get_max(string str1, string str2)
{
	if (str1 == "")
		return str2;

	if (str1[0] == '-' && str2[0] != '-') // 왼쪽이 -
		return str2;
	else if (str1[0] != '-' && str2[0] == '-')
		return str1;
	else if (str1[0] == '-' && str2[0] == '-') // 둘다 음수
	{
		if (str1.size() < str2.size()) // -11, -111
			return str1;
		else if (str1.size() > str2.size())
			return str2;
		else
		{
			for (int i = 1; i < str1.size(); i++)
			{
				if (str1[i] < str2[i]) // -1 -2
					return str1;
				else if (str1[i] > str2[i])
					return str2;
			}
			return str1;
		}
	}
	else // 둘다 양수
	{
		if (str1.size() < str2.size()) // 11, 111
			return str2;
		else if (str1.size() > str2.size())
			return str1;
		else
		{
			for (int i = 0; i < str1.size(); i++)
			{
				if (str1[i] < str2[i])
					return str2;
				else if (str1[i] > str2[i])
					return str1;
			}
			return str1;
		}
	}

}

string solution(string s)
{
	string minn = "";
	string maxx = "";
	string tmp = "";

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-')
			tmp += '-';
		else if (s[i] == ' ')
		{
			//cout << tmp << ' ' << minn <<' '<< maxx << '\n';
			minn = get_min(minn, tmp);
			maxx = get_max(maxx, tmp);
			tmp = "";
		}
		else
		{
			tmp += s[i];
		}

	}
	minn = get_min(minn, tmp);
	maxx = get_max(maxx, tmp);

	return minn + ' ' + maxx;



}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str = "123 514 259 -1 454 -512 63 1111 1111 -11111";
	cout << solution(str);

}


/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#define pii pair<int, int>
#define ll long long int
using namespace std;



string solution(string s)
{
	ll minn = LLONG_MAX;
	ll maxx = LLONG_MIN;
	ll tmp = 0;
	int bu = 1;

	for (int i = 0; i < s[i]; i++)
	{
		if (s[i] == '-')
			bu = -1;
		else if (s[i] == ' ')
		{
			minn = min(minn, bu * tmp);
			maxx = max(maxx, bu * tmp);
			bu = 1;
			tmp = 0;
		}
		else
		{
			tmp = (tmp * 10) + (s[i] - '0');
		}

	}
	minn = min(minn, bu * tmp);
	maxx = max(maxx, bu * tmp);
	return to_string(minn) + ' ' + to_string(maxx);



}

*/
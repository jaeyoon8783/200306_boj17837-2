#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define pii pair<int, int>
using namespace std;

bool is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return true;
	else
		return false;
}

bool is_upper(char c)
{
	if (c >= 'A'&& c <= 'Z')
		return true;
	else
		return false;
}
map<char, int> m;

pair<string, int> Rule_one(string str, int cur)
{
	char tmp = str[cur];
	if (m[tmp] != 0)
		return { "invalid", -1 };

	return { "aa", 1 };
}




string solution(string str)
{
	string ans = "";
	
	int i;
	for (i = 0; i < str.size() - 1; i++)
	{
		if (is_lower(str[i]) && is_lower(str[i + 1]))
		{
			return "invalid";
		}
		else if (is_lower(str[i]) && is_upper(str[i + 1])) // 소->대 == 규2, 규1,2;
		{
			pair<string, int> tmp = Rule_one(str, i);

		}


	}



}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	string str = "ObWORb";

	cout << solution(str);

	//testcase.push_back("aA"); //invalid
//	testcase.push_back("HaEaLaLObWORLDb"); //HELL O WORLD prob


}


/*

str[i] == 소 && str[i+1] == 대 => 규2만 , 규2+규1
str[i] == 소 && str[i+1] == 소 => invalid;
str[i] == 대 && str[i+1] == th => 규1만, 규2만!!!!!!!!!!!!!!!!!!!!!!!!!!
ObWORb


*/
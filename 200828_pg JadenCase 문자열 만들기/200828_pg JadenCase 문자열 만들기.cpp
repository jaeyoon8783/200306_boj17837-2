#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;


string solution(string s) 
{
	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 32;
	for (int i = 1; i < s.size(); i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') && s[i - 1] == ' ')
			s[i] -= 32;
		else if ((s[i] >= 'A' && s[i] <= 'Z') && s[i - 1] != ' ')
			s[i] += 32;
	}
	return s;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str = "3people unFollowed me";

	cout << solution(str);


}

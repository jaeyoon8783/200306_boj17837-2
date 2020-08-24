#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

string a; int b;
int ans;
int check[9] = { 0 };
int flag = 0;
void go(int cur, string s)
{
	if (cur >= a.size())
	{
		
		if (s[0] != '0')
		{
			
			int can = stoi(s);
			if (can <= b)
			{
				flag = 1;
				ans = max(ans, can);
			}
		}
			
		return;
	}

	for (int i = 0; i < a.size(); i++)
	{
		if (check[i] == 1)
			continue;

		check[i] = 1;
		go(cur + 1, s + a[i]);
		check[i] = 0;
	}
	

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	cin >> a >> b;
	go(0, "");

	if (flag == 0)
		cout << -1;
	else
		cout << ans;
}

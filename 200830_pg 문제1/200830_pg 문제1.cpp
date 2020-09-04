#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

string solution(int month, int day)
{
	int day_arr[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int ans = 0;
	for (int i = 1; i < month; i++)
	{
		ans += day_arr[i];
	}
	ans += day;

	string date[] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };

	return date[ans % 7];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a = 5;
		int b = 24;
	cout <<solution(a,b);

}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define pii pair<int, int>
using namespace std;

int era[10000000] = { 0 };
set<int> sett;
void make_era() // 0이면 소수임
{
	era[0] = 1;
	era[1] = 1;
	for (int i = 2; i <= 9999999; i++)
	{
		if (era[i] == 1)
			continue;

		for (int j = i * 2; j <= 9999999; j += i)
			era[j] = 1;
	}
}

int check[7] = { 0 };
void go(string num, string cur)
{
	
	if (cur.size() != 0)
	{
		int su = stoi(cur);
		if (era[su] == 0)
		{
		//	cout << su << ' ';
			sett.insert(su);
		}
	}
	
	for (int i = 0; i < num.size(); i++)
	{
		if (check[i] == 1)
			continue;

		check[i] = 1;
		go(num, cur + num[i]);
		check[i] = 0;

	}
}


int solution(string num)
{
	make_era();
	go(num, "");

	return (int)sett.size();

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string num = "17";
	cout << solution(num);
}

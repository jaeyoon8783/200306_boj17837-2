#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
#define INF 987654321
#define pii pair<int, int>
using namespace std;

class pos
{
public :
	int s, x, y;
};
int n, t;

int st, en; // 시작 , 끝
pos city[1001];

int d1[1001][1001] = { 0 };
pii d2[1001];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> t; 

	for (int i = 1; i <= n; i++)
		cin >> city[i].s >> city[i].x >> city[i].y;



	for (int i = 1; i <= n; i++)
	{
		d2[i].second = 99999;
		for (int j = 1; j <= n; j++)
		{
			d1[i][j] = abs(city[i].x - city[j].x) + abs(city[i].y - city[j].y);
			
			if (city[i].s == 1)
				d2[i] = { i, 0 };
			else if (city[j].s == 1 && d2[i].second > d1[i][j])
				d2[i] = { j, d1[i][j] };
		}
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		cout << d2[i].first << ' ' << d2[i].second << '\n';
	}
	cout << '\n';
	*/
	
	int c;
	cin >> c;
	int can1, can2;
	for (int i = 0; i < c; i++)
	{
		cin >> st >> en;
		can1 = d1[st][en];

		if (city[st].s == 1) // 시작이 1이면
			can2 = d2[en].second + t;
		else if (city[en].s == 1) // 끝이 1이면
			can2 = d2[st].second + t;
		else
			can2 = d2[st].second + t + d2[en].second;
		cout << min(can1, can2) << '\n';
	}

}

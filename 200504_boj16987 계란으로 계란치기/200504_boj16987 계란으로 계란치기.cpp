#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;


int n;
pii egg[8]; // 내구도, 무게
int ans = 0;

void go(int cnt)
{
	if (cnt == n)
	{
		int can = 0;
		for (int i = 0; i < n; i++)
		{
			// << egg[i].first << ' ';
			
			if (egg[i].first <= 0)
				can++;
				
		}
		//cout << can <<"\n";
		ans = max(ans, can);

		return;
	}
	if (egg[cnt].first <= 0)
	{
		go(cnt + 1);
		return;
	}
	int bc = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == cnt || egg[i].first <= 0)
			continue;
		bc++;
		egg[cnt].first -= egg[i].second;
		egg[i].first -= egg[cnt].second;
		go(cnt + 1);
		egg[cnt].first += egg[i].second;
		egg[i].first += egg[cnt].second;
	}
	if(bc == 0)
		go(cnt + 1);


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> egg[i].first >> egg[i].second;
	}


	go(0);
	cout << ans;
}


#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;

pii stick[100];
int ans = 0;
int x, y, n; // x<y

void make(int x1, int y1, int x2, int y2, int c)
{
	int hx = x1 + x2; 
	int hy = y1 + y2;

	if ((hx <= x && max(y1, y2) <= y) || (hx <= y && max(y1, y2) <= x))
	{
		ans = max(ans, c);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	cin >> x >> y>>n;

	for (int i = 0; i < n; i++)
		cin >> stick[i].first >> stick[i].second;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int x1 = stick[i].first;  int y1 = stick[i].second;
			int x2 = stick[j].first;  int y2 = stick[j].second;
			int s = x1 * y1 + x2 * y2;
			make(x1,y1,x2,y2,s);
			make(y1, x1, x2, y2, s);
			make(x1, y1, y2, x2, s);
			make(y1, x1, y2, x2, s);
		}
	}
	cout << ans;
}

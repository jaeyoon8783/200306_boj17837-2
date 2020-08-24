#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#define pii pair<int, int>
using namespace std;
//1734
class stone
{
public :
	int a, b, c;
};

int check[1501][1501] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	int hap = a + b + c;
	if (hap % 3 != 0)
	{
		cout << 0;
		return 0;
	}
	
	queue<stone> q;
	q.push({ a,b,c });
	check[a][b] = 1;

	while (!q.empty())
	{
		stone t = q.front();
		
		q.pop();
		cout << t.a << " " << t.b << ' ' << t.c << "\n";

		if (t.a < t.b)
		{
			int na = t.a + t.a;
			int nb = t.b - t.a;

			if (check[na][nb] == 0)
			{
				//cout <<t.a << ' ' << t.b << ' ' << t.c << " -> "<< na << " " << nb << " " << t.c << "\n";
				check[na][nb] = 1;
				q.push({ na, nb, t.c });
			}
		}
		else if (t.a > t.b)
		{
			int na = t.a - t.b;
			int nb = t.b + t.b;

			if (check[na][nb] == 0)
			{
			//	cout << t.a << ' ' << t.b << ' ' << t.c << " -> " << na << " " << nb << " " << t.c << "\n";
				check[na][nb] = 1;
				q.push({ na, nb, t.c });
			}
		}


		if (t.a < t.c)
		{
			int na = t.a + t.a;
			int nc = t.c - t.a;
			if (check[na][t.b] == 0)
			{
				//cout << t.a << ' ' << t.b << ' ' << t.c << " -> " << na << " " << t.b << " " << nc << "\n";
				check[na][t.b] = 1;
				q.push({ na, t.b, nc });
			}
		}
		else if (t.a > t.c)
		{
			int na = t.a - t.c;
			int nc = t.c + t.c;
			if (check[na][t.b] == 0)
			{
			//	cout << t.a << ' ' << t.b << ' ' << t.c << " -> " << na << " " << t.b<< " " << nc << "\n";
				check[na][t.b] = 1;
				q.push({ na, t.b ,nc });
			}
		}


		if (t.b < t.c)
		{
			int nb = t.b + t.b;
			int nc = t.c - t.b;

			if (check[t.a][nb] == 0)
			{
			//	cout << t.a << ' ' << t.b << ' ' << t.c << " -> " << t.a << " " << nb << " " << nc << "\n";
				check[t.a][nb] = 1;
				q.push({ t.a, nb, nc });
			}
		}
		else if (t.b > t.c)
		{
			int nb = t.b - t.c;
			int nc = t.c + t.c;

			if (check[t.a][nb] == 0)
			{
			//	cout << t.a << ' ' << t.b << ' ' << t.c << " -> " << t.a << " " << nb << " " << nc << "\n";
				check[t.a][nb] = 1;
				q.push({ t.a, nb, nc });
			}
		}
	}
	
	cout << check[hap / 3][hap / 3];

	
	
}

/*
21 32 43
*/





/*
map<string, int> m;
int check[50][50][50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c,su;
	cin >> a >> b >> c;
	if ((a + b + c) % 3 != 0)
	{
		cout << 0;
		return 0;
	}
	else
		su = (a + b + c) / 3;

	
	queue<stone> q;
	q.push({ a,b,c });
	string str = to_string(a) + to_string(b) + to_string(c);
	m[str] = 1;

	int flag = 0;
	while (!q.empty())
	{
		stone s = q.front();
		q.pop();

		if (s.a == s.b  && s.a == s.c && s.b == s.b)
		{
			flag == 1;
			break;
		}


		if (s.a < s.b) // b가 크면
		{
			int na = s.a + s.a;
			int nb = s.b - s.a;
			str = to_string(na) + to_string(nb) + to_string(s.c);
			if (m[str] == 0)
			{
				m[str] = 1;
				q.push({ na, nb, s.c });
			}
		}
		else if (s.a > s.b)
		{
			int na = s.a - s.b;
			int nb = s.b + s.b;
			str = to_string(na) + to_string(nb) + to_string(s.c);
			if (m[str] == 0)
			{
				m[str] = 1;
				q.push({ na, nb, s.c });
			}
		}
		
		if (s.b < s.c)
		{
			int nb = s.b + s.b;
			int nc = s.c - s.b;
			str = to_string(s.a) + to_string(nb) + to_string(nc);
			if (m[str] == 0)
			{
				m[str] = 1;
				q.push({ s.a, nb, nc });
			}
		}
		else if (s.b > s.c)
		{
			int nb = s.b - s.c;
			int nc = s.c + s.c;
			str = to_string(s.a) + to_string(nb) + to_string(nc);
			if (m[str] == 0)
			{
				m[str] = 1;
				q.push({ s.a, nb, nc });
			}
		}

		if (s.a < s.c)
		{
			int na = s.a + s.a;
			int nc = s.c - s.a;
			str = to_string(na) + to_string(s.b) + to_string(nc);
			if (m[str] == 0)
			{
				m[str] = 1;
				q.push({ na, s.b, nc });
			}

		}
		else if (s.a > s.c)
		{
			int na = s.a - s.c;
			int nc = s.c + s.c;
			str = to_string(na) + to_string(s.b) + to_string(nc);
			if (m[str] == 0)
			{
				m[str] = 1;
				q.push({ na, s.b, nc });
			}
		}
	}




}
*/
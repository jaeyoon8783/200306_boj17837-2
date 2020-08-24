#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int n, k;
int map[10][10];
int pa[10] = { 0 };
int pa_cnt = 0;
int p1[20];
int p2[20];



void fight(int bcnt, int ccnt, int awin, int bwin, int cwin, char x, char y)
{
	//cout << round << ' ' << awin << ' ' << bwin << ' ' << cwin << "\n";
	if (awin >= k || bwin >= k || cwin >= k)
	{
		if (awin == k)
		{
			cout << 1;
			exit(0);
		}
		return;
	}



	if (x == 'a' && y == 'b')
	{
		if (pa_cnt == n)
			return;
		for (int i = 1; i <= n; i++)
		{
			if (pa[i] == 1)
				continue;

			int cura = i;
			int curb = p1[bcnt];
			pa[i] = 1;
			pa_cnt++;
			if (map[cura][curb] == 2) // cura win
			{
				//cout << i << " ? " << "awin " << "\n";
				fight(bcnt+1, ccnt, awin + 1, bwin, cwin, 'a', 'c');
			}
			else if (map[cura][curb] == 1 || map[cura][curb] == 0) //curb win
			{
				//cout << i << ' ' << "bwin " << "\n";
				fight(bcnt + 1, ccnt, awin, bwin + 1, cwin, 'b', 'c');
			}
			pa[i] = 0;
			pa_cnt--;
		}

	}
	else if (x == 'a' && y == 'c')
	{
		if (pa_cnt == n)
			return;
		for (int i = 1; i <= n; i++)
		{
			if (pa[i] == 1)
				continue;
			int cura = i;
			int curc = p2[ccnt];
			pa[i] = 1;
			pa_cnt++;
			if (map[cura][curc] == 2) // cura win
			{
			//	cout << i << ' ' << "awin " << "\n";
				fight(bcnt, ccnt + 1, awin + 1, bwin, cwin, 'a', 'b');
			}
			else if (map[cura][curc] == 1 || map[cura][curc] == 0) //curc win
			{
				//cout << i << ' ' << "cwin " << "\n";
				fight(bcnt, ccnt + 1, awin, bwin, cwin + 1, 'c', 'b');
			}
			pa[i] = 0;
			pa_cnt--;
		}
	}
	else if (x == 'b' && y == 'a')
	{
		if (pa_cnt == n)
			return;
		for (int i = 1; i <= n; i++)
		{
			if (pa[i] == 1)
				continue;
			int curb = p1[bcnt];
			int cura = i;
			pa[i] = 1;
			pa_cnt++;
			if (map[curb][cura] == 2 || map[curb][cura] == 1) // curb win
			{
			//	cout << i << ' ' << "bwin " << "\n";
				fight(bcnt + 1, ccnt, awin, bwin + 1, cwin, 'b', 'c');
			}
			else if (map[curb][cura] == 0) //cura win
			{
			//	cout << i << ' ' << "awin " << "\n";
				fight(bcnt + 1, ccnt, awin + 1, bwin, cwin, 'a', 'c');
			}
			pa[i] = 0;
			pa_cnt--;
		}
	}
	else if (x == 'b' && y == 'c')
	{

		int curb = p1[bcnt];
		int curc = p2[ccnt];

		if (map[curb][curc] == 2) // curb win
		{
		//	cout << "bwin " << "\n";
			fight(bcnt + 1, ccnt + 1, awin, bwin + 1, cwin, 'b', 'a');
		}
		else if (map[curb][curc] == 1 || map[curb][curc] == 0) //curc win
		{
		//	cout << "cwin " << "\n";
			fight(bcnt + 1, ccnt + 1, awin, bwin, cwin + 1, 'c', 'a');
		}

	}
	else if (x == 'c' && y == 'a')
	{
		if (pa_cnt == n)
			return;
		for (int i = 1; i <= n; i++)
		{
			if (pa[i] == 1)
				continue;
			int curc = p2[ccnt];
			int cura = i;
			pa[i] = 1;
			pa_cnt++;
			if (map[curc][cura] == 2 || map[curc][cura] == 1) // curc win
			{
			//	cout << i << ' ' << "cwin " << "\n";
				fight(bcnt, ccnt + 1, awin, bwin, cwin + 1, 'c', 'b');
			}
			else if ( map[curc][cura] == 0) //cura win
			{
			//	cout << i << ' ' << "awin " << "\n";
				fight(bcnt, ccnt + 1, awin + 1, bwin, cwin, 'a', 'b');
			}
			pa[i] = 0;
			pa_cnt--;
		}
	}
	else if (x == 'c' && y == 'b')
	{
		int curc = p2[ccnt];
		int curb = p1[bcnt];

		if (map[curc][curb] == 2 || map[curc][curb] == 1) // curc win
		{
		//	cout << "cwin " << "\n";
			fight(bcnt + 1, ccnt + 1, awin, bwin, cwin + 1, 'c', 'a');
		}
		else if (map[curc][curb] == 0) //curb win
		{
		//	cout << "bwin " << "\n";
			fight(bcnt + 1, ccnt + 1, awin, bwin + 1, cwin, 'b', 'a');
		}

	}

}
/*
fight(round + 1, awin, bwin, cwin, 'c', 'b');
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> n >> k; // 손동작 수, 우승 필요수

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < 20; i++)
		cin >> p1[i];
	for (int i = 0; i < 20; i++)
		cin >> p2[i];

	fight(0,0, 0, 0, 0, 'a', 'b'); // bcnt,ccnt, 지우,경희,민호 승수, 'a'vs'b'
	cout << 0;
}

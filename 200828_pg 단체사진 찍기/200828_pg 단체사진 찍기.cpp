#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;


int ans = 0;
char c[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
int check[8] = { 0 };
int pos[8] = { 0 };

int asd(char c)
{
	if (c == 'A') return 0;
	else if (c == 'C') return 1;
	else if (c == 'F') return 2;
	else if (c == 'J') return 3;
	else if (c == 'M') return 4;
	else if (c == 'N')	return 5;
	else if (c == 'R')	return 6;
	else return 7;
}



void go(vector<string> data, int cnt)
{
	if (cnt == 8)
	{
		for (int i = 0; i < data.size(); i++)
		{
			int a = asd(data[i][0]);
			int b = asd(data[i][2]);
			char bu = data[i][3];
			int su = data[i][4] - '0';

			int cha = abs(pos[a] - pos[b]) -1; //거리
			if (bu == '>' && cha <= su)
				return;
			else if (bu == '<' && cha >= su)
				return;
			else if (bu == '=' &&  cha != su)
				return;

		}
		ans++;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		if (check[i] == 1)
			continue;

		check[i] = 1;
		pos[i] = cnt;
		go(data, cnt + 1);
		check[i] = 0;
	}

}


int solution(int n, vector<string> data) {

	go(data, 0);
	return ans;

}

int main()

{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 2;
	vector<string> data = { "N~F=0", "R~T>2" };

	cout << solution(n, data);


}



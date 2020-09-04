#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string su[16] = { "0","1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };

string solution(int n, int t, int m, int p) {
	string solution = "";
	

	int cnt = 0;
	int pos = 1;
	while (1)
	{
		string tmp = "";
		int tmp_cnt = cnt;
		while (1)
		{
			if (tmp_cnt / n == 0)
			{
				tmp += su[tmp_cnt%n];
				break;
			}
			else
			{
				tmp += su[tmp_cnt%n];
				tmp_cnt = tmp_cnt / n;
			}
		}

		for (int i = tmp.size() - 1; i >= 0; i--)
		{
			if (pos == p)
			{
				solution += tmp[i];
				if (solution.size() == t)
					return solution;
			}
			pos = pos % m + 1;
		}
		cnt++;

	}



}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int n = 16; // 진법
	int t = 16; // 리턴 사이즈
	int m = 2;  //참가인원
	int p = 2;  // 순서
	cout << solution(n, t, m, p);

}

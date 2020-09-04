#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int d[32001] = { 0 };


void go(int cur_su, int cur_num, int n)
{
	d[cur_su] = cur_num;
	//cout << cur_su << ' ' << cur_num << '\n';
	

	int tmp_su = n;
	int tmp_num = cur_num + 1;

	while (cur_su + tmp_su <= 32000 && tmp_num <= 8)
	{
		if(d[cur_su + tmp_su] > tmp_num)
			go(cur_su + tmp_su, tmp_num, n);
		tmp_su = tmp_su * 10 + n;
		tmp_num++;
	}

	tmp_su = n;
	tmp_num = cur_num + 1;

	while (cur_su - tmp_su >= 0 && tmp_num <= 8)
	{
		if (d[cur_su - tmp_su] > tmp_num)
			go(cur_su - tmp_su, tmp_num, n);
		tmp_su = tmp_su * 10 + n;
		tmp_num++;
	}

	tmp_su = n;
	tmp_num = cur_num + 1;
	while (cur_su * tmp_su <= 32000 && tmp_num <= 8)
	{
		if (d[cur_su * tmp_su] > tmp_num)
			go(cur_su * tmp_su, tmp_num, n);
		tmp_su = tmp_su * 10 + n;
		tmp_num++;
	}

	tmp_su = n;
	tmp_num = cur_num + 1;
	while (cur_su / tmp_su > 0 && tmp_num <= 8)
	{
		if (d[cur_su / tmp_su] > tmp_num)
			go(cur_su / tmp_su, tmp_num, n);
		tmp_su = tmp_su * 10 + n;
		tmp_num++;
	}

	tmp_su = cur_su + 1;
	tmp_num = cur_num + 2;
	if(tmp_su <= 32000 && tmp_num <= 8 && d[tmp_su] > tmp_num)
	{
		go(tmp_su, tmp_num, n);
	}

	tmp_su = cur_su - 1;
	tmp_num = cur_num + 2;
	if (tmp_su >= 0 && tmp_num <= 8 && d[tmp_su] > tmp_num)
	{
		go(tmp_su, tmp_num, n);
	}
}


int solution(int n, int num)
{
	for (int i = 0; i <= 32000; i++)
		d[i] = 9;

	go(0, 0, n);
	//go(22222, 5, n);
	if (d[num] == 9)
		return -1;
	return d[num];
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
/*
	int n = 8;
	int num;
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		cout << solution(n, num) << '?';
	}
	*/

	int n = 8;
	int num = 11095;
	cout << solution(n, num) << '?';


}

/*
8, 11095

8 8889 에서
잠시만 8888 + 8/8은 어떻게 나타내나?
8/8+8888 하면 된다.;;;;


9 8890 은 뭔가 8888+8/8+8/8 이라서 8인데 ..

(8+8)/8 + 8888 = 8890 

*/
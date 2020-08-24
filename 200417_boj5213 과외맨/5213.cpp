#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <IOMANIP>
#define pii pair<int, int>
using namespace std;

//0140
//0247
int n;
int map[500][1000] = { 0 };
int check[500][1000] = { 0 };
int number[500][1000] = { 0 };
pii prevv[500][1000];
int x, y;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1,0, -1,0 };


//int dx[] = { -1,1,0,0 };
//int dy[] = { 0,0,-1,1 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	
	cin >> n;
	x = n; y = 2 * n;
	int cnt = 1;


	
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j * 2] >> map[i][j * 2 + 1];
				number[i][j * 2] = number[i][j * 2 + 1] = cnt++;
			}
		}
		else
		{
			for (int j = 0; j < n - 1; j++)
			{
				cin >> map[i][j * 2 + 1] >> map[i][j * 2 + 2];
				number[i][j * 2 + 1] = number[i][j * 2 + 2] = cnt++;
			}
		}
	}
	
	
	
	deque<pii> q;
	q.push_back({ 0,0 });
	check[0][0] = 1;
	pii max_pos = { 0,0 };

	while (!q.empty())
	{
		pii t = q.front();
		q.pop_front();
		pii t2;
		if (number[t.first][t.second] == number[t.first][t.second + 1])
		{
			t2 = { t.first, t.second + 1 };
			check[t.first][t.second + 1] = check[t.first][t.second];
			prevv[t.first][t.second + 1] = prevv[t.first][t.second];
		}
		else
		{
			t2 = { t.first, t.second - 1 };
			check[t.first][t.second - 1] = check[t.first][t.second];
			prevv[t.first][t.second - 1] = prevv[t.first][t.second];
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];

			if (nx < 0 || nx >= x || ny < 0 || ny >= y || map[nx][ny] == 0)   // 먼저 같은 넘버링부터 잡아줘야겠네;;;
				continue;

			if (map[nx][ny] == map[t.first][t.second] && check[nx][ny] == 0)
			{
				check[nx][ny] = check[t.first][t.second] + 1;
				prevv[nx][ny] = { t.first, t.second };

				if (number[max_pos.first][max_pos.second] < number[nx][ny])
					max_pos = { nx, ny };
				q.push_back({ nx, ny });
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = t2.first + dx[i];
			int ny = t2.second + dy[i];

			if (nx < 0 || nx >= x || ny < 0 || ny >= y || map[nx][ny] == 0)   // 먼저 같은 넘버링부터 잡아줘야겠네;;;
				continue;

			if (map[nx][ny] == map[t2.first][t2.second] && check[nx][ny] == 0)
			{
				check[nx][ny] = check[t2.first][t2.second] + 1;
				prevv[nx][ny] = { t2.first, t2.second };

				if (number[max_pos.first][max_pos.second] < number[nx][ny])
					max_pos = { nx, ny };
				q.push_back({ nx, ny });
			}
		}
	}




		//for (int i = 0; i < 4; i++)
		//{
		//	int nx = t.first + dx[i];
		//	int ny = t.second + dy[i];

		//	if (nx < 0 || nx >= x || ny < 0 || ny >= y || map[nx][ny] == 0)   // 먼저 같은 넘버링부터 잡아줘야겠네;;;
		//		continue;
		//	
		//	
		//	if ((number[nx][ny] == number[t.first][t.second]) && check[nx][ny] == 0)
		//	{
		//		check[nx][ny] = check[t.first][t.second];
		//		prevv[nx][ny] = { t.first, t.second };

		//		q.push_front({ nx, ny });
		//	}
		//	else if((map[nx][ny] == map[t.first][t.second]) && check[nx][ny] == 0 )
		//	{
		//		check[nx][ny] = check[t.first][t.second] + 1;
		//		prevv[nx][ny] = { t.first, t.second };

		//		if (number[max_pos.first][max_pos.second] < number[nx][ny])
		//			max_pos = { nx, ny };
		//		q.push_back({ nx, ny });
		//	}
			
		
			//if (i == 2 && ((nx % 2 == 0 && ny % 2 == 0) || (nx % 2 == 1 && ny % 2 == 1))) //서   0줄일때 1->0
			//{
			//	if (check[nx][ny] == 0)
			//	{
			//			check[nx][ny] = check[t.first][t.second];
			//			prevv[nx][ny] = { t.first, t.second };

			//			if (number[max_pos.first][max_pos.second] < number[nx][ny])
			//				max_pos = { nx, ny };

			//			q.push_front({ nx, ny });
			//	}		
			//}
			//else if (i == 3 && ((nx % 2 == 0 && ny % 2 == 1) || (nx % 2 == 1 && ny % 2 == 0))) // 동    0줄일때 0->1
			//{

			//	if (check[nx][ny] == 0)
			//	{
			//		check[nx][ny] = check[t.first][t.second];
			//		prevv[nx][ny] = { t.first, t.second };

			//		if (number[max_pos.first][max_pos.second] < number[nx][ny])
			//			max_pos = { nx, ny };
			//		q.push_front({ nx, ny });
			//	}
			//}
			//else
			//{
			//	//if (map[nx][ny] == map[t.first][t.second] && (check[nx][ny] == 0 || check[nx][ny] > check[t.first][t.second]+1))
			//	if (map[nx][ny] == map[t.first][t.second] && check[nx][ny] == 0 )
			//	{
			//		check[nx][ny] = check[t.first][t.second] + 1;
			//		prevv[nx][ny] = { t.first, t.second };

			//		if (number[max_pos.first][max_pos.second] < number[nx][ny])
			//			max_pos = { nx, ny };
			//		q.push_back({ nx, ny });
			//	}
			//}
			

		//}
	
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n; j++)
		{
		//	cout << prevv[i][j].first << " " << prevv[i][j].second << "   ";
			cout << setw(3) << check[i][j] << " ";

		}
		cout << "\n";
	}
	*/


	if (number[max_pos.first][max_pos.second] == n*n - n/2)
	{

		int i = max_pos.first;
		int j = max_pos.second;
		stack<int> s;
		while (1)
		{
			
			int prev_x = prevv[i][j].first;
			int prev_y = prevv[i][j].second;
			if (prev_x == 0 && prev_y == 0)
			{
				s.push(number[prev_x][prev_y]);
				break;
			}

			if (number[i][j] != number[prev_x][prev_y])
				s.push(number[i][j]);
			i = prev_x; j = prev_y;

		}

		int size = s.size();
		cout << size << "\n";
		for (int i = 0; i < size; i++)
		{
			cout << s.top() << " ";
			s.pop();
		}
	}
	else
	{
		int i = max_pos.first;
		int j = max_pos.second;

		stack<int> s;
		while (1)
		{

			int prev_x = prevv[i][j].first;
			int prev_y = prevv[i][j].second;
			if (prev_x == 0 && prev_y == 0)
			{
				s.push(number[prev_x][prev_y]);
				break;
			}

			if (number[i][j] != number[prev_x][prev_y])
				s.push(number[i][j]);
			i = prev_x; j = prev_y;

		}

		int size = s.size();
		cout << size << "\n";
		for (int i = 0; i < size; i++)
		{
			cout << s.top() << " ";
			s.pop();
		}
	}


}


/*
5
1 4
4 5
3 4
5 4
5 2
4 2
5 6
4 4
6 5
2 4
5 1
6 2
1 6
2 3
4 2
5 3
1 2
5 5
4 1
2 2
4 3
2 3
3 4




7
1 4
4 5
3 4
5 4
5 2
8 8
8 8

4 2
5 6
4 4
6 5
8 8
8 8

2 4
5 1
6 1
1 6
2 3
8 8
8 8


4 2
5 3
1 2
5 5
8 8
8 8

4 1
2 2
4 3
2 3
3 4
8 8
8 8

3 2
2 5
2 4
4 2
8 8
8 8

6 3
3 6
6 1
1 6
6 3
3 2
2 1



7
1 4
4 5
3 4
5 4
5 2
8 8
8 8
4 2
5 6
4 4
6 5
8 8
8 8
2 4
5 1
6 1
1 6
2 3
8 8
8 8
4 2
5 3
1 2
5 5
8 8
8 8
4 1
2 2
4 3
2 3
3 4
8 8
8 8
3 2
2 5
2 4
4 2
8 8
8 8
6 3
3 6
6 1
1 6
6 3
3 2
2 1




*/
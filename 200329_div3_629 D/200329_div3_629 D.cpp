#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int z = 0; z < n; z++)
	{
		int arr[200001];

		int a;
		int min = 1;
		int same1 = -1;

		cin >> a;
		cin >> arr[0];

		for (int i = 1; i < a; i++)
		{
			cin >> arr[i];
			if (arr[i] == arr[i - 1])
				same1 = i;
			else
				min = 2;
		}

		if (min == 1)
		{
			cout << 1 << '\n';
			for (int i = 0; i < a; i++)
			{
				cout << 1 << ' ';
			}
			cout << '\n';
		}
		else if (a % 2 == 0)
		{
			cout << 2 << '\n';
			for (int i = 0; i < a; i++)
			{
				cout << i % 2 + 1 << ' ';
			}
			cout << '\n';
		}
		else if (same1 != -1 || arr[a-1] == arr[0])
		{
		
			cout << 2 <<"\n";
			int su2 = 0;
			for (int i = 0; i < a; i++)
			{
				if (i != same1)
					su2 = su2 % 2 + 1;
				cout << su2 << ' ';
			}
			cout << '\n';
		}
		else
		{
			cout << 3 << '\n';
			for (int i = 0; i < a - 1; i++)
				cout << i % 2 + 1 << ' ';
			cout << 3 << ' ';
			cout << '\n';
		}


	}
}


/*
19
8
13 13 9 12 13 1 13 1
19
18 8 15 5 8 4 18 16 11 5 9 4 17 14 16 13 2 17 2
12
8 10 5 5 2 3 13 11 2 9 1 13
7
5 6 6 1 3 5 4
3
1 1 1
3
1 1 2
3
1 1 3
3
1 2 1
3
1 2 2
3
1 2 3
4
3 2 2 3
4
1 3 2 3
4
2 3 2 3
4
3 3 2 3
4
1 1 3 3
4
2 1 3 3
4
3 1 3 3
4
1 2 3 3
4
2 2 3 3

*/
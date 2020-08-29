#include <iostream>
using namespace std;
int arr[8] = { 4,1,6,3,7,6,8,10 };
int su[8];

void go(int su_pos, int arr_pos, int n, int r)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				cout << arr[i] << ' ' << arr[j] << ' ' << arr[k] << '\n';
			}
		}
	}
}


int main()
{
	go(0, 0, 8, 3);
}

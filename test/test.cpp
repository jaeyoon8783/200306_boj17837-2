#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;

int arr[5];
int arr2[5];
int arr3[5];
void go(int v[], int size)
{
	for (int i = 0; i < size; i++)
		v[i] = 100;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	go(arr, 5);
	go(arr2, 5);


	cout << arr[4];
}

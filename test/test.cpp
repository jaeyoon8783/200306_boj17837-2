#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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

	string str = "123123";
	str.erase(2,3);

	cout << str;
}

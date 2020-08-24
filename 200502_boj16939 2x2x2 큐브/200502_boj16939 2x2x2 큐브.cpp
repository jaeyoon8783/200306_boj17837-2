//2030
#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;


int arr[25];
void turn(int a, int b, int c, int d, int e, int f, int g, int h)
{
	int arr2[25];
	copy(arr, arr + 25, arr2);

	int temp1 = arr2[a]; int temp2 = arr2[b];
	arr2[a] = arr2[c]; arr2[b] = arr2[d];
	arr2[c] = arr2[e]; arr2[d] = arr2[f];
	arr2[e] = arr2[g]; arr2[f] = arr2[h];
	arr2[g] = temp1;   arr2[h] = temp2;


	if (arr2[1] != arr2[2] || arr2[1] != arr2[3] || arr2[1] != arr2[4])
		return;
	if (arr2[5] != arr2[6] || arr2[5] != arr2[7] || arr2[5] != arr2[8])
		return;
	if (arr2[9] != arr2[10] || arr2[9] != arr2[11] || arr2[9] != arr2[12])
		return;
	if (arr2[13] != arr2[14] || arr2[13] != arr2[15] || arr2[13] != arr2[16])
		return;
	if (arr2[17] != arr2[18] || arr2[17] != arr2[19] || arr2[17] != arr2[20])
		return;
	if (arr2[21] != arr2[22] || arr2[21] != arr2[23] || arr2[21] != arr2[24])
		return;
	
	cout << 1;
	exit(0);

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 24; i++)
		cin >> arr[i];

	
	int arr2[25];
	int temp1, temp2;

	turn(13, 14, 5, 6, 17, 18, 21, 22);
	turn( 21,22, 17, 18, 5, 6, 13, 14);

	turn( 15, 16, 7, 8, 19, 20, 23, 24);
	turn( 23, 24, 19, 20, 7, 8, 15, 16);
	
	turn( 2, 4, 6, 8, 10, 12, 23, 21);
	turn( 23, 21, 10, 12, 6, 8, 2, 4);

	turn(1, 3, 5, 7, 9, 11, 24, 22);
	turn(24, 22, 9, 11, 5, 7, 1, 3);

	turn(3, 4, 17, 19, 10, 9, 16, 14);
	turn( 16, 14, 10, 9, 17, 19, 3, 4);

	turn( 1, 2, 18, 20, 12, 11, 15, 13);
	turn( 15, 13, 12, 11, 18, 20, 1, 2);

	cout << 0;

}
/*
2 5 4 6 1 
3 6 2 5 5 
1 2 3 5 3
1 1 2 4 6
6 4 3 4


*/
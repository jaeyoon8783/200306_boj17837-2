#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
#define NA 1000000007
using namespace std;

int solution(int n)
{
	int d[60001];
	int ans;

	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		d[i] = (d[i - 1] + d[i - 2])% NA;
	}


	return d[n];

}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 5;
	cout << solution(n);


}

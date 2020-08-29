#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
#define NA 1234567
using namespace std;


int fib[100001];
int solution(int n) {

	fib[0] = 0; fib[1] = 1;
	for (int i = 2; i <= n; i++)
		fib[i] = (fib[i - 2] + fib[i - 1]) % NA;


	return fib[n];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 5;

	cout << solution(n);

}

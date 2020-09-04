#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

int solution(int n, int a, int b)
{
	int logn = log2(n);
	
	vector<int> aa;
	vector<int> bb;

	aa.push_back(a);
	bb.push_back(b);
	for (int i = 0; i < logn -1; i++)
	{
		aa.push_back((a + 1) / 2);
		a = (a + 1) / 2;
		bb.push_back((b + 1) / 2);
		b = (b + 1) / 2;
	}

	for (int i = 0; i < aa.size(); i++)
	{
		if ((aa[i] + 1) / 2 == (bb[i] + 1) / 2)
			return i + 1;
	}

	return -1;

}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n = 8;
	int a = 4;
	int b = 7;

	cout << solution(n, a, b);


}

#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;


int solution(vector<int> a, vector<int> b)
{
	int ans = 0;
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), less<int>());

	for (int i = 0; i < a.size(); i++)
		ans += (a[i] * b[i]);

	
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	vector<int> a = { 1,4,2 };
	vector<int> b = { 5,4,4 };
	cout << solution(a, b);

}

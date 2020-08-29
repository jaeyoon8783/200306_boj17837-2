#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a%b);
}
int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}

int solution(vector<int> arr)
{
	if (arr.size() == 1)
		return arr[0];

	sort(arr.begin(), arr.end(), less<int>());
	int ans = LCM(arr[0], arr[1]);

	for (int i = 2; i < arr.size(); i++)
		ans = LCM(ans, arr[i]);

	return ans;



}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> arr = {14,2,7};
	cout << solution(arr);

}

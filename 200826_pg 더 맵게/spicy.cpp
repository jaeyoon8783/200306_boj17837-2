#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;


int solution(vector<int> sco, int k)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < sco.size(); i++)
		pq.push(sco[i]);

	int cnt = 0;
	while (1)
	{
		int min1 = pq.top();
		pq.pop();
		if (min1 > k)
			break;
		if (pq.empty())
			return -1;
		
		int min2 = pq.top();
		pq.pop();
		pq.push(min1 + 2 * min2);
		cnt++;

	}

	return cnt;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> sco = { 1,2,3,9,10,12 };
	int k = 7;
	cout << solution(sco, k);
}

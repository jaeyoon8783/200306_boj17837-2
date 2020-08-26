#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

int solution(vector<int>prior, int loc)
{
	queue<pii> q; // location , priority
	priority_queue<int, vector<int>, less<int>> pq;
	for (int i = 0; i < prior.size(); i++)
	{
		q.push({ i, prior[i] });
		pq.push(prior[i]);
	}

	int cnt = 1;
	while (!pq.empty())
	{
		int max = pq.top();
		pq.pop();
		pii t;
		while (1)
		{
			t = q.front();
			q.pop();
			if (max == t.second)
				break;
			else
				q.push(t);
		}

		if (t.first == loc)
			return cnt;
		else
			cnt++;


	}
	return -1;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> priority = { 1,1,9,1,1,1 };
	int loc = 0;
	cout << solution(priority, loc);
}

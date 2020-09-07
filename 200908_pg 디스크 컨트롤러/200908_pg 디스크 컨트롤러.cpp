#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;


class comp2
{
public : 
	bool operator() (const pii &a, const pii &b) const
	{
		return a.first > b.first;
	}
};


bool comp(const vector<int> &a, const vector<int> &b)
{
	if (a[0] == b[0])
		return a[1] < b[1];
	else
		return a[0] < b[0];
}


int solution(vector<vector<int>> jobs)
{
	sort(jobs.begin(), jobs.end(), comp);
	int time[500] = { 0 };
	priority_queue<pii, vector<pii>, comp2> pq; // 시간, pos
	int pos = 0;
	int cur_time = 0;
	
	cur_time = jobs[0][0] + jobs[0][1];
	time[0] = cur_time - jobs[0][0];
	pos++;
	while (1)
	{
		if (pos == jobs.size())
		{

			while (!pq.empty())
			{
				pii tmp = pq.top();
				pq.pop();

				cur_time += tmp.first;
				time[tmp.second] = cur_time - jobs[tmp.second][0];
			}

			break;
		}


		if (jobs[pos][0] <= cur_time)
		{
			pq.push({ jobs[pos][1] ,pos });
			pos++;
		}
		else if (jobs[pos][0] > cur_time && pq.empty())
		{
			pq.push({ jobs[pos][1] ,pos });
			cur_time = jobs[pos][0];
			pos++;
		}
		else
		{
			pii tmp = pq.top();
			pq.pop();

			cur_time += tmp.first;
			time[tmp.second] = cur_time - jobs[tmp.second][0];
		}
	}
	int ans = 0;
	for (int i = 0; i < jobs.size(); i++)
		ans += time[i];
	return ans / jobs.size();

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<vector<int>> jobs = { {0,3}, {1,9}, {2,6}, {30,3} };
	cout << solution(jobs);

}

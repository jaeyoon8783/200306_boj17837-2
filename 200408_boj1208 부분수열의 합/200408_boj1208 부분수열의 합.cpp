#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//23:00
int n, su;
int ans = 0;


vector<int> l;
vector<int> r;
vector<int> all_l;
vector<int> all_r;


void go1(int cur, int sum)
{
	if (cur == l.size())
	{
		all_l.push_back(sum);
		return;
	}
	go1(cur + 1, sum + l[cur]);
	go1(cur + 1, sum);
}

void go2(int cur, int sum)
{
	if (cur == r.size())
	{
		all_r.push_back(sum);
		return;
	}

	go2(cur + 1, sum + r[cur]);
	go2(cur + 1, sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);



	cin >> n >> su;
	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;

		if (i % 2 == 0)
			l.push_back(a);
		else
			r.push_back(a);
	}

	go1(0, 0);
	go2(0, 0);

	sort(all_r.begin(), all_r.end());
	int size = all_l.size();
	long long int ans = 0;


	for (int i = 0; i < size; i++)
	{
		int g = su - all_l[i];

		int aa = lower_bound(all_r.begin(), all_r.end(), g) - all_r.begin();
		int bb = upper_bound(all_r.begin(), all_r.end(), g) - all_r.begin();

		ans += (bb - aa);

	}

	if (su == 0)
		cout << ans - 1;
	else
		cout << ans;


}
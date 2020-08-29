#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define pii pair<int, int>
using namespace std;

vector<int> solution(int n, vector<string> w)
{
	map<string, int> m;
	string prev = w[0];
	m[prev] = 1;
	for (int i = 1; i < w.size(); i++)
	{
		if (m[w[i]] != 0 || prev[prev.size() - 1] != w[i][0])
			return  { i%n+1 , i/n+1};


		prev = w[i];
		m[prev] = 1;
	}

	return { 0,0 };
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
	//vector<string> words = {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" };
	int n = 3;
	vector<int> sol = solution(n, words);

	cout << sol[0] << ' ' << sol[1];


}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int check[8] = { 0 };
int ans = 0;

void make(vector<vector<string>> arr, int cur_pos, int cnt)
{
	if (cur_pos == arr[0].size())
	{

		map<string, int> m;
		for (int i = 0; i < arr.size(); i++)
		{
			
			string tmp = "";
			for (int j = 0; j < arr[0].size(); j++)
			{
				if (check[j] == 1)
					tmp += arr[i][j];
			}
			if (m[tmp] == 0)
				m[tmp] = 1;
			else
				return;

		}

		if (cnt == 1)
		{
			ans++;
			return;
		}


		m.clear();
		for (int i = 0; i < cur_pos; i++)
		{
			if (check[i] == 0)
				continue;
			check[i] = 0;
			map<string, int> mm;
			int is_candi = 1; // candi가 되면 안돼..
			
		
			for (int j = 0; j < arr.size(); j++)
			{
				string tmp = "";
				for (int k = 0; k < arr[j].size(); k++)
				{
					if (check[k] == 1)
						tmp += arr[j][k];
				}
				if (mm[tmp] == 0)
					mm[tmp] = 1;
				else
				{
					is_candi = 0;
					break;
				}

			}
			check[i] = 1;
			if (is_candi == 1)
				return;
			
		}
		
		/*
		for (int i = 0; i < arr[0].size(); i++)
			cout << check[i] << ' ';
		cout << '\n';
		*/
		
		ans++;
		return;
	}
	


	check[cur_pos] = 1;
	make(arr, cur_pos + 1, cnt + 1);
	check[cur_pos] = 0;
	make(arr, cur_pos + 1, cnt);

}




int solution(vector<vector<string>> arr)
{

	make(arr, 0, 0);
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	/*
	vector<vector<string>> str = { 
	{"100", "ryan", "music", "2"},
	{"200", "apeach", "math", "2"},
	{"300", "tube", "computer", "3"},
	{"400", "con", "computer", "4"},
	{"500", "muzi", "music", "3"},
	{"600", "apeach", "music", "2" }};
	

	vector<vector<string>> str = {
	{"100", "abc", "1"},
	{"100", "abd", "2"},
	{"100", "abd", "4"},
	{"200", "abc", "2"},
	{"200", "abd", "1"},
	{"200", "abd", "3"},
	};
	*/
	vector<vector<string>> str = {
		{"b","2","a","a","b"},
		{"b","2","7","1","b"},
		{"1","0","a","a","8"},
		{"7","5","a","a","9"},
		{"3","0","a","f","9"},
	};
	cout << solution(str);

}


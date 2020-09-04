#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;


string convert(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	}
	return str;
}
vector<string> file_header;
vector<string> file_number;


bool comp(const vector<string> &str1, const vector<string> &str2)
{
	if (str1[1] != str2[1])
		return str1[1] < str2[1];
	else
		return stoi(str1[2]) < stoi(str2[2]);
}


vector<string> solution(vector<string> files)
{
	vector<vector<string>> files_detail;
	for (int i = 0; i < files.size(); i++)
	{
		
		string str_h = "";
		string str_n = "";

		int j = 0;
		while (files[i][j] > '9' || files[i][j] < '0')
		{
			str_h += files[i][j++];
		}
		int cnt = 0;
		while (files[i][j] >= '0' && files[i][j] <= '9' && cnt < 5)
		{
			str_n += files[i][j++];
			cnt++;
		}
		str_h = convert(str_h);

		//file_header.push_back(str_h);
		//file_number.push_back(str_n);
		//cout << file_header[i] << ' ' << file_number[i] << '\n';
		files_detail.push_back({ files[i], str_h, str_n });
		
	}
	
	stable_sort(files_detail.begin(), files_detail.end(), comp);

	
	vector<string> ans;

	
	for (int i = 0; i < files.size(); i++)
	{
		ans.push_back(files_detail[i][0]);
		cout << files_detail[i][0] << ' ' << files_detail[i][1] << ' ' << files_detail[i][2] << '\n';

	}

	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	vector<string> files = { "iMg121112.png", "imG121113.Nng", "Img12112.pAg", "IMg12111.pnU", "IMG12111.FD", "iMG12111" };
	//vector<string> files = { "z", "x","y", "a" };
	solution(files);




}

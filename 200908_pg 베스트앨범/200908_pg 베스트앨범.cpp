#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define pii pair<int, int>
using namespace std;

class infor
{
public :
	int gen_hash;
	int play_time;
	int gen_total_time;
	int music_num;
};

bool comp(const infor &a, const infor &b)
{
	if (a.gen_total_time != b.gen_total_time)
		return a.gen_total_time > b.gen_total_time;
	else
	{
		if (a.play_time != b.play_time)
			return a.play_time > b.play_time;
		else
			return a.music_num < b.music_num;
	}
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	
	pii music[10000]; // 장르 해쉬, 고유번호
	int time[100] = { 0 };
	map<string, int> m;
	int cnt = 0;
	for (int i = 0; i < genres.size(); i++)
	{
		if (m[genres[i]] == 0)
			m[genres[i]] = ++cnt;
		time[m[genres[i]]] += plays[i];

	}

	vector<infor> in;
	for (int i = 0; i < genres.size(); i++)
		in.push_back({ m[genres[i]], plays[i], time[m[genres[i]]], i });
	sort(in.begin(), in.end(), comp);

	vector<int> answer;
	answer.push_back(in[0].music_num);
	int cur_hash = in[0].gen_hash;
	int su = 1;
	for (int i = 1; i < in.size(); i++)
	{
		if (cur_hash != in[i].gen_hash)
		{
			cur_hash = in[i].gen_hash;
			su = 1;
			answer.push_back(in[i].music_num);
		}
		else
		{
			if (su == 1)
			{
				su++;
				answer.push_back(in[i].music_num);
			}
		}
	}
	
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> time = { 500,600,150,800,2500 };
	vector<int> answer = solution(genres, time);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';

}

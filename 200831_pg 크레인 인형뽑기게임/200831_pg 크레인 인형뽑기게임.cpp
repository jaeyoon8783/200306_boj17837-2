#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	stack<int> s[30];

	stack<int> basket;
	for (int i = board.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if(board[i][j] != 0)
				s[j].push(board[i][j]);
		}
	}

	for (int i = 0; i < moves.size(); i++)
	{
		int pos = moves[i] - 

		if (s[pos].empty())
			continue;

		int su = s[pos].top();
		s[pos].pop();

		if (!basket.empty() && basket.top() == su)
		{
			answer += 2;
			basket.pop();
		}
		else
			basket.push(su);

	}

	return answer;
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	vector<vector<int>> arr = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
	vector<int> moves = { 1,5,3,5,1,2,1,4 };
	cout << solution(arr, moves);

}

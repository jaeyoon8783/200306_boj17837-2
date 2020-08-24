
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
	using namespace std;
	  int board[20][20];
	  int cccboard[20][20];
	  int N;
	  int max_num = 0;
	  void m(int dir) {
		  int flag[20][20] = { 0, };
		  //위쪽으로
		  if (dir == 0) {
			  for (int i = 1; i < N; i++) {
				  for (int j = 0; j < N; j++) {
					  if (board[i][j] != 0) {
						  int r = i;
						  do {
							  r--;
						  } while (board[r][j] == 0 && r >= 0);
						  if (board[r][j] == board[i][j] && flag[r][j] == 0) {
							  board[r][j] = board[i][j] * 2;
							  board[i][j] = 0;
							  flag[r][j] = 1;
						  }
						  else if (board[r + 1][j] == 0) {
							  board[r + 1][j] = board[i][j];
							  board[i][j] = 0;
						  }
					  }
				  }
			  }
		  }
		  //왼쪽으로
		  else if (dir == 1) {
			  for (int i = 0; i < N; i++) {
				  for (int j = 1; j < N; j++) {
					  if (board[i][j] != 0) {
						  int c = j;
						  do {
							  c--;
						  } while (board[i][c] == 0 && c >= 0);
						  if (board[i][c] == board[i][j] && flag[i][c] == 0) {
							  board[i][c] = board[i][j] * 2;
							  board[i][j] = 0;
							  flag[i][c] = 1;
						  }
						  else if (board[i][c + 1] == 0) {
							  board[i][c + 1] = board[i][j];
							  board[i][j] = 0;
						  }
					  }
				  }
			  }
		  }
		  //아래쪽으로
		  else if (dir == 2) {
			  for (int i = N - 2; i >= 0; i--) {
				  for (int j = 0; j < N; j++) {
					  if (board[i][j] != 0) {
						  int r = i;
						  do {
							  r++;
						  } while (board[r][j] == 0 && r <= N - 1);
						  if (board[r][j] == board[i][j] && flag[r][j] == 0) {
							  board[r][j] = board[i][j] * 2;
							  board[i][j] = 0;
							  flag[r][j] = 1;
						  }
						  else if (board[r - 1][j] == 0) {
							  board[r - 1][j] = board[i][j];
							  board[i][j] = 0;
						  }
					  }
				  }
			  }
		  }
		  //오른쪽으로
		  else {
			  for (int i = 0; i < N; i++) {
				  for (int j = N - 2; j >= 0; j--) {
					  if (board[i][j] != 0) {
						  int c = j;
						  do {
							  c++;
						  } while (board[i][c] == 0 && c <= N - 1);
						  if (board[i][c] == board[i][j] && flag[i][c] == 0) {
							  board[i][c] = board[i][j] * 2;
							  board[i][j] = 0;
							  flag[i][c] = 1;
						  }
						  else if (board[i][c - 1] == 0) {
							  board[i][c - 1] = board[i][j];
							  board[i][j] = 0;
						  }
					  }
				  }
			  }
		  }
	  }
	  void move(int cnt) {
		  if (cnt >= 5) {
			  int flag = 0;
			  for (int i = 0; i < N; i++) {
				  for (int j = 0; j < N; j++) {
					  if (board[i][j] > max_num) {
						  max_num = board[i][j];
						  flag = 1;
					  }
				  }
			  }
			  if (flag == 1) {
				  for (int i = 0; i < N; i++) {
					  for (int j = 0; j < N; j++) {
						  cccboard[i][j] = board[i][j];
					  }
				  }
			  }
		  }
		  else {
			  int cboard[20][20] = { 0, };
			  for (int i = 0; i < N; i++) {
				  for (int j = 0; j < N; j++) {
					  cboard[i][j] = board[i][j];
				  }
			  }
			  for (int k = 0; k < 4; k++) {
				  m(k);
				  move(cnt + 1);
				  for (int i = 0; i < N; i++) {
					  for (int j = 0; j < N; j++) {
						  board[i][j] = cboard[i][j];
					  }
				  }
			  }
		  }
	  }
	  int main() {
		  ios::sync_with_stdio(0);
		  cin.tie(0);
		//  freopen("input.txt", "r", stdin);
		  cin >> N;
		  for (int i = 0; i < N; i++) {
			  for (int j = 0; j < N; j++) {
				  cin >> board[i][j];
			  }
		  }
		  move(0);
		  for (int i = 0; i < N; i++) {
			  for (int j = 0; j < N; j++) {
				  cout << cccboard[i][j] << " ";
			  }
			  cout << "\n";
		  }
		  cout << max_num << "\n";
		  return 0;
	  }
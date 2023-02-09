#include <iostream>
#include <unordered_map>
#include <queue>
#include <memory.h>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int w;
string word;
int b;
char board[31][4][4];

bool check[9][27];//[i][j]:i번째 인덱스에 j번째(A는 1번째) 알파벳이 있으면 true
int scores[9] = {0,0,0,1,1,2,3,5,11};
pair<int,int> dir[8] = {{-1,0},{-1,1},
						{0,1},{1,1},
						{1,0},{1,-1},
						{0,-1},{-1,-1}};
bool visited[4][4];
unordered_map<string,bool> M;
int maxScore = 0;//최대 점수
string longest = "";//가장 긴 단어
int cnt = 0;

void INPUT()
{
	IAMFAST
	cin >> w;
	for(int i = 0; i < w; i++)
	{
		cin >> word;
		/*for(int a = 0; a < word.length(); a++)
			check[a][word[a]-'A'] = true;*/
		M.insert({ word, false });
	}
	cin >> b;
	for(int i = 0; i < b; i++)
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++)
				cin >> board[i][j][k];
}

void Init()
{
	memset(visited,false,sizeof visited);
	unordered_map<string,bool>::iterator it;
	for(it = M.begin(); it != M.end(); it++) it->second = false;
	maxScore = 0;
	longest = "";
	cnt = 0;
}

void setAns(string str)
{
	//최대 점수
	maxScore += scores[str.length()];
	//가장 긴 단어
	if(str.length() > longest.length()) longest = str;
	else if(str.length() == longest.length()) longest = min(str,longest);
	//찾은 단어의 갯수
	cnt++;

	M[str] = true;
}

void DFS(int tc,int x,int y,string str)
{
	if(str.length() == 8) return;
	//if(!check[str.length()][board[tc][x][y]-'A']) return;

	str += board[tc][x][y];
	if(M.find(str)!=M.end()&&!M[str]) setAns(str);

	for(int i = 0; i < 8; i++)
	{
		int nx = x + dir[i].first;
		int ny = y + dir[i].second;
		if(!(0<=nx&&nx<4&&0<=ny&&ny<4)) continue;
		if(visited[nx][ny]) continue;

		visited[nx][ny] = true;
		DFS(tc,nx,ny,str);
		visited[nx][ny] = false;
	}
	visited[x][y] = false;
}

void SOLVE()
{
	for (int i = 0; i < b; i++)
	{
		Init();

		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				visited[j][k] = true,
				DFS(i, j, k, "");
		cout << maxScore << " " << longest << " " << cnt << '\n';
	}
}

int main()
{
	INPUT();
	SOLVE();
}
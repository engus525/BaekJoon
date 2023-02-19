#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
string S,T;
int l,r;

char coin[2];
string target = "";

void INPUT()
{
	IAMFAST
	cin >> n >> S >> T >> l >> r;
}

bool DFS(int idx,int tIdx,int cnt)
{//target의 idx , T의 idx , 배치한 동전의 수
	bool rtn = false;

	if(tIdx == n) return rtn = true;

	if(cnt != 2 && coin[cnt] == T[tIdx])
		rtn = max(rtn,DFS(idx,tIdx+1,cnt+1));
	if(target[idx] == T[tIdx])
		rtn = max(rtn,DFS(idx+1,tIdx+1,cnt));

	return rtn;
}

void SOLVE()
{
	coin[0] = S[l]; coin[1] = S[r];
	for(int i = 0; i < n; i++)
		if(i != l && i != r)
			target += S[i];

	if(DFS(0,0,0)) cout << "YES";
	else cout << "NO";

}

int main()
{
	INPUT();
	SOLVE();
}
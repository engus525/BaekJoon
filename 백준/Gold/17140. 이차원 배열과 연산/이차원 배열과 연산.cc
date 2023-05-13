#include <iostream>
#include <map>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int r,c,k;
int rowNum = 3, colNum = 3;
int A[101][101];
typedef pair<int,int> pii;
bool comp(pii &a, pii &b)
{
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

void INPUT()
{
    IAMFAST
    cin >> r >> c >> k;
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            cin >> A[i][j];
}

vector<pii> sortMap(map<int,int> &M)
{
    vector<pii> v(M.begin(),M.end());
    sort(v.begin(),v.end(),comp);
    return v;
}


void R()
{
    priority_queue<int> pq;
    for(int i = 1; i <= rowNum; i++)
    {
        map<int,int> M;
        for(int j = 1; j <= colNum; j++)
        {
            if(A[i][j] == 0) continue;
            if(M.find(A[i][j]) == M.end()) M.insert({A[i][j],1});
            else M[A[i][j]]++;
        }

        //sort map by value
        vector<pii> v = sortMap(M);

        //colNum 갱신용 pq
        pq.push(2*v.size());

        //정렬 수행
        for(int j = 1; j <= 100; j++) A[i][j] = 0;
        int idx = 1;
        for(auto j : v)
        {
            if(idx > 100) break;
            A[i][idx] = j.first;
            A[i][idx+1] = j.second;
            idx += 2;
        }
    }
    //colNum 갱신
    colNum = min(100,pq.top());
}

void C()
{
    priority_queue<int> pq;
    for(int i = 1; i <= colNum; i++)
    {
        map<int,int> M;
        for(int j = 1; j <= rowNum; j++)
        {
            if(A[j][i] == 0) continue;
            if(M.find(A[j][i]) == M.end()) M.insert({A[j][i],1});
            else M[A[j][i]]++;
        }

        //sort map by value
        vector<pii> v = sortMap(M);

        //rowNum 갱신용 pq
        pq.push(2*v.size());

        //정렬 수행
        for(int j = 1; j <= 100; j++) A[j][i] = 0;
        int idx = 1;
        for(auto j : v)
        {
            if(idx > 100) break;
            A[idx][i] = j.first;
            A[idx+1][i] = j.second;
            idx += 2;
        }
    }

    //rowNum 갱신
    rowNum = min(100,pq.top());
}

void SOLVE()
{
    int ans = 0;
    while(A[r][c] != k)
    {
        if(ans == 101) break;
        ans++;

        if(rowNum >= colNum) R();
        else C();

    }
    if(ans==101) cout << -1;
    else cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
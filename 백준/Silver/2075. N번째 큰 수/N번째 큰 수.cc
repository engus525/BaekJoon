#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
int n;
//오름차순 정렬
priority_queue<ll,vector<ll>,greater<ll>> pq;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n*n; i++)
    {
        int num; cin >> num;
        pq.push(num);
        /*
        n번째로 큰 수는 어떤 수가 삽입되든 pq.top()으로부터 n개의 원소 내에 위치한다.
        따라서 n개 이상의 수가 삽입되면 즉시 pop 해준다.
        */
        if(pq.size() > n) pq.pop();
    }
}


void SOLVE()
{
    //pq에는 n개의 수가 남아있게 되고, 오름차순 정렬이므로 top에 n번째 큰 수가 위치한다.
    cout << pq.top();
}

int main()
{
    INPUT();
    SOLVE();
}
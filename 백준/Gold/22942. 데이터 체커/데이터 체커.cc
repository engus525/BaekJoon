#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef pair<int, int> pii;

int n;
struct Circle
{
    int pos;
    bool isOpen;
    int order;
};
vector<Circle> v;
stack<pii> st;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x,r; cin >> x >> r;
        v.push_back({x - r, true, i});
        v.push_back({x + r, false, i});
    }
}

void solution()
{
    sort(v.begin(),v.end(),
         [](Circle &a, Circle &b){return a.pos < b.pos;});

    bool ans = true;
    for(int i = 1; i < v.size(); i++)
        if(v[i-1].pos == v[i].pos) ans = false;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].isOpen)
        {
            st.emplace(v[i].pos,v[i].order);
        }
        else
        {
            if(st.empty()) ans = false;
            else if(st.top().second == v[i].order) st.pop();
            else ans = false;
        }
    }
    if(ans) cout << "YES";
    else cout << "NO";
}

int main()
{
    INPUT();
    solution();
}
#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, t, p;
bool visited[101];

bool comp(pii a, pii b)
{
    if (a.first == b.first)
        return a.second - a.first < b.second - a.first;
    else return a.first < b.first;
}

vector<pii> v;
priority_queue<pii, vector<pii>, greater<>> pq;

void INPUT()
{
    IAMFAST
    cin >> n >> t >> p;
    for (int i = 0; i < t; i++)
    {
        string a, b;
        cin >> a >> b;
        int h1, m1, h2, m2;
        h1 = stoi(a.substr(0, 2)) * 60;
        h2 = stoi(b.substr(0, 2)) * 60;
        m1 = stoi(a.substr(2));
        m2 = stoi(b.substr(2));

        v.emplace_back(h1 + m1, h2 + m2);
    }
}

int getBestSeat()
{
    bool noPerson = true;

    int maxDist = 0, bestSeat = 1;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            noPerson = false;
            continue;
        }

        for (int dist = 1; dist <= n; dist++)
        {
            int l = i - dist, r = i + dist;

            //L out, R out
            if (l < 1 && r > n) break;

            //L out, R in
            else if (l < 1 && r <= n)
            {
                if (!visited[r] && maxDist < dist) maxDist = dist, bestSeat = i;
                else if (visited[r]) break;
            }

            //L in, R out
            else if (l >= 1 && r > n)
            {
                if (!visited[l] && maxDist < dist) maxDist = dist, bestSeat = i;
                else if (visited[l]) break;
            }

            //L in, R in
            else if (1 <= l && r <= n)
            {
                if (!visited[l] && !visited[r] && maxDist < dist) maxDist = dist, bestSeat = i;
                else if (visited[l] || visited[r]) break;
            }

        }
    }

    if (maxDist == 0)
    {
        for (int i = 1; i <= n; i++)
            if (!visited[i])
            {
                bestSeat = i;
                break;
            }
    }

    return ((noPerson) ? 1 : bestSeat);
}

void solution()
{
    sort(v.begin(), v.end(), comp);

    int ans = 720;

    for (auto T: v)
    {
        while (!pq.empty() && pq.top().first <= T.first)
        {
            visited[pq.top().second] = false;
            pq.pop();
        }

        int bestSeat = getBestSeat();
        if (bestSeat == p) ans -= T.second - T.first;

        visited[bestSeat] = true;
        pq.emplace(T.second, bestSeat);

    }

    cout << ans;
}

int main()
{
    INPUT();
    solution();
}
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
//    cout << "mD = " << maxDist << '\n';
    if (maxDist == 0)
    {
        for (int i = 1; i <= n; i++)
            if (!visited[i])
            {
                bestSeat = i;
                break;
            }
    }
    //cout << "best : " << ((noPerson) ? 1 : bestSeat) << '\n';
    return ((noPerson) ? 1 : bestSeat);
}

void solution()
{
    sort(v.begin(), v.end(), comp);

    int Ans = 720;

    int ans = v[0].first - 9 * 60;
    int now = v[0].first;
    for (auto T: v)
    {
        //cout << T.first << " " << T.second << '\n';

        while (!pq.empty() && pq.top().first <= T.first)
        {
            if (!visited[p]) ans += pq.top().first - now;

            now = pq.top().first;
            //cout << now << " : " << ans << '\n';
            visited[pq.top().second] = false;
            pq.pop();
        }

        int bestSeat = getBestSeat();
        if (bestSeat == p) Ans -= T.second - T.first;
        if (!visited[p]) ans += T.first - now;
        //cout << now << " : " << ans << '\n';

        now = T.first;
        visited[bestSeat] = true;
        pq.emplace(T.second, bestSeat);

        //cout << now << " : " << ans << '\n';

    }

    while (!pq.empty())
    {
        if (!visited[p]) ans += pq.top().first - now;

        now = pq.top().first;
        //cout << now << " : " << ans << '\n';
        visited[pq.top().second] = false;
        pq.pop();
    }

    ans += 21 * 60 - now;
    cout << Ans;
}

int main()
{
    INPUT();
    solution();
}
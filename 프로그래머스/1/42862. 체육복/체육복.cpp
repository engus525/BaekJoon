#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int cnt[31];
bool noRest[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (auto val : lost) cnt[val]++;
    for (auto val : reserve)
    {
        cnt[val]++;
        // 여벌 학생이 도난 당하면 빌려줄 수 없다.
        if (cnt[val] == 2) noRest[val] = true;
    }
    int idx = 0;
    
    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (noRest[reserve[j]]) continue;
            // 도난 당했어도 여분 있으면 빌려주지 않는다.
            if (cnt[lost[i]] == 2) continue;
            
            if (reserve[j] - 1 == lost[i] || reserve[j] + 1 == lost[i])
            {
                answer++;
                noRest[reserve[j]] = true;
                break;
            }
        }
    }
    
    // 여벌 없고 도난 안 당한 학생
    for (int i = 1; i <= n; i++)
        if (!cnt[i]) answer++;

    return answer + reserve.size();
}
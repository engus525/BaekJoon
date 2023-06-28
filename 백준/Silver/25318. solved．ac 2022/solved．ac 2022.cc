#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
struct Submit
{
    chrono::system_clock::time_point datetime;
    double tier;
};
vector<Submit> v(1001);
chrono::system_clock::time_point Tn;

chrono::system_clock::time_point parseDatetime(const std::string& dateTimeString) {
    tm timeStruct = {};
    istringstream ss(dateTimeString);
    ss >> get_time(&timeStruct, "%Y/%m/%d%H:%M:%S");
    auto timePoint = std::chrono::system_clock::from_time_t(std::mktime(&timeStruct));
    return timePoint;
}

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string d,T; double t;
        cin >> d >> T >> t;
        auto pD = parseDatetime(d+T);
        v[i] = {pD,t};
        Tn = pD;
    }
}


void SOLVE()
{
    double Up = 0, Down = 0;
    for(int i = 1; i <= n; i++)
    {
        chrono::duration<double> timeDiff = Tn - v[i].datetime;
        chrono::duration<double,std::ratio<60 * 60 * 24 * 365>> yearsDiff =
                chrono::duration_cast<chrono::duration<double, ratio<60 * 60 * 24 * 365>>>(timeDiff);

        double p = max(pow(0.5,yearsDiff.count()),pow(0.9,n-i));
        double l = v[i].tier;

        Up += p*l; Down += p;
    }

    if(Down != 0) cout << round(Up/Down);
    else cout << 0;
}

int main()
{
    INPUT();
    SOLVE();
}
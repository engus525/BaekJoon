#include <iostream>
#include <string>
using namespace std;
int main() {
    string k,ans;
    int sum = 0,p=0,cnt=0;
    cin >> k;
    for (int i = 0; i < k.size(); i++)
    {
        if (k[i] == ',') { sum += stoi(ans); ans = "";}
        else
            ans += k[i];
    }
    cout << sum+stoi(ans)<<'\n';
}
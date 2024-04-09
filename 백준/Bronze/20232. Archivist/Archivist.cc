#include <iostream>
#include <map>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    map<int, string> M;

    // 데이터 추가
    M[1995] = "ITMO";
    M[1996] = "SPbSU";
    M[1997] = "SPbSU";
    M[1998] = "ITMO";
    M[1999] = "ITMO";
    M[2000] = "SPbSU";
    M[2001] = "ITMO";
    M[2002] = "ITMO";
    M[2003] = "ITMO";
    M[2004] = "ITMO";
    M[2005] = "ITMO";
    M[2006] = "PetrSU, ITMO";
    M[2007] = "SPbSU";
    M[2008] = "SPbSU";
    M[2009] = "ITMO";
    M[2010] = "ITMO";
    M[2011] = "ITMO";
    M[2012] = "ITMO";
    M[2013] = "SPbSU";
    M[2014] = "ITMO";
    M[2015] = "ITMO";
    M[2016] = "ITMO";
    M[2017] = "ITMO";
    M[2018] = "SPbSU";
    M[2019] = "ITMO";

    cout << M[n];
}

int main()
{
    INPUT();
    solution();
}
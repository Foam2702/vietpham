#include<iostream>
#include<string>
using namespace std;
const int mon7 = 215; //7 months' days

string solve(int year)
{
    short int feb; //days in february
    if (year < 1918) //julian
        feb = year % 4 ? 28 : 29;
    else if (year > 1918) //gregorian
        feb = (year % 400==0) || (year % 100!=0) && (year % 4==0) ? 29 : 28;
    else //dreaded 1918
        feb = 15;
    feb = 256 - (feb + mon7);
    return to_string(feb) + ".09." + to_string(year);
}
int main()
{
    int year; cin >> year;
    string ans = solve(year);
    cout << ans;
}
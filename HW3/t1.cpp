#include <iostream>
using namespace std;

int main(){
    int t_days;
    cin >> t_days;

    int years = (int)(t_days / 365);
    t_days = t_days - years * 365;

    int months = (int)(t_days / 30);
    t_days = t_days - months * 30;

    // the remaining of t_days is the days value no need to store it in another mem cell
    // int days = t_days;

    cout << years << " years\n";
    cout << months << " months\n";
    cout << t_days << " days";

    return 0;
}

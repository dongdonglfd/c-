#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

string convertToKBase(long long num, int k) {
    if (k < 2 || k > 36) return "";
    if (num == 0) return "0";

    long long n = num;
    bool isNegative = n < 0;
    if (isNegative) n = -n;

    string result;
    const char* digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (n > 0) {
        int remainder = static_cast<int>(n % k);  // 显式转换
        result.push_back(digits[remainder]);
        n = n / k;
    }

    if (isNegative) result.push_back('-');
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    int k=0;
    long long n=0;
    cin>>n>>k;
    string x=convertToKBase(n,k);
    cout<<x<<endl;

    return 0;
}

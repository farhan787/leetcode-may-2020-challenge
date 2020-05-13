// Problem link: https://leetcode.com/problems/remove-k-digits

#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

// Time complexity => O(n); n = size of num string
// Space complexity => O(n)
void removeKDigitsFromStk(stack<char>& stk, int k) {
    while (k > 0 && !stk.empty()) {
        stk.pop();
        k--;
    }
}

string buildNumFromStk(stack<char>& stk) {
    string num = "";
    while (!stk.empty()) {
        num += stk.top();
        stk.pop();
    }
    reverse(num.begin(), num.end());
    return num;
}

string removeLeadingZeroes(string& num) {
    // this method is much faster than using
    // while (!num.empty() && num[0] == '0') num.erase(0, 1);
    // becase num.erase() takes linear time and if there are 'l' leading zeroes then
    // it'd take O(l * num.len()) time and that's not good

    // below method takes O(num.len()) time
    // find first non-zero digit and then take the substring starting from there upto the end
    string numWithoutLeadingZeroes;
    for (int i = 0; i < (int)num.length(); i++) {
        char currDigit = num[i];
        if (currDigit != '0') {
            numWithoutLeadingZeroes = num.substr(i);
            break;
        }
    }

    if (numWithoutLeadingZeroes.empty()) {
        // for nums like 000000, numWithoutLeadingZeroes is empty
        numWithoutLeadingZeroes = "0";
    }

    return numWithoutLeadingZeroes;
}

string removeKdigits(string& num, int k) {
    if (k == (int)num.length()) {
        return "0";
    }

    stack<char> stk;
    for (char digit : num) {
        while (k > 0 && !stk.empty() && stk.top() > digit) {
            stk.pop();
            --k;
        }
        stk.push(digit);
    }

    if (k != 0) {
        removeKDigitsFromStk(stk, k);
    }

    num = buildNumFromStk(stk);

    if (!num.empty() && num[0] == '0') {
        num = removeLeadingZeroes(num);
    }

    return num;
}

int main() {
}

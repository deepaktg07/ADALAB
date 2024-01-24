#include <iostream>
#include <cstring>
using namespace std;
char str[100], ptn[20];
int res, m, n, len, len1, i, j, k, table[1000];
void shift(const char p[]) {
    len = strlen(p);
    for (i = 0; i < 1000; i++)
        table[i] = len;
    for (j = 0; j <= len - 2; j++)
        table[p[j]] = len - 1 - j;
}
int horspool(const char p[], const char t[]) {
    shift(p);
    m = strlen(p);
    n = strlen(t);
    i = m - 1;
    while (i <= n - 1) {
        k = 0;
        while (k <= m - 1 && (p[m - 1 - k] == t[i - k]))
            k++;
        if (k == m)
            return i - m + 1;
        else
            i = i + table[t[i]];
    }
    return -1;
}
int main() {
    cout << "Enter the text" << endl;
    cin.getline(str, 100);
    cout << "Enter the pattern to be found" << endl;
    cin.getline(ptn, 20);
    cout << "Length of the text: " << strlen(str) << " characters" << endl;
    cout << "Length of the pattern: " << strlen(ptn) << " characters" << endl;
    res = horspool(ptn, str);
    if (res == -1)
        cout << "\nPattern not found" << endl;
    else
        cout << "Pattern found at " << res + 1 << " position" << endl;
    return 0;
}

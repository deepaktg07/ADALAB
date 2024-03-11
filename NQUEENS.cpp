#include <iostream>
#include <cmath>
using namespace std;
int a[30], count = 0;
int place(int pos) {
    for (int i = 1; i < pos; i++) {
        if ((a[i] == a[pos]) || (abs(a[i] - a[pos]) == abs(i - pos)))
            return 0;
    }
    return 1;
}
void print_sol(int n) {
    count++;
    cout << "\n\nSolution #" << count << ":\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == j)
                cout << "Q\t";
            else
                cout << "*\t";
        }
        cout << "\n";
    }
}
void queen(int n, int k = 1) {
    if (k > n) {
        print_sol(n);
        return;
    }
    for (int i = 1; i <= n; i++) {
        a[k] = i;
        if (place(k))
            queen(n, k + 1);
    }
}
int main() {
    int n;
    cout << "Enter the number of Queens\n";
    cin >> n;
    queen(n);
    cout << "\nTotal solutions=" << count << endl;
    return 0;
}

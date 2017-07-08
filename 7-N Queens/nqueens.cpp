#include <bits/stdc++.h>
using namespace std;
const int n = 9;
int upperlim = (1<<n) -1;
vector<string> result;
void test(int row, int ld, int rd, int &sum, string res) {
    int pos, p;
    if (row != upperlim) {
        pos = upperlim & ~(row | ld | rd);
        while (pos != 0) {
            p = pos & -pos;
            pos = pos - p;
            int tmp = p, bit=0;
            while (tmp>>=1) bit++;
            test(row | p, (ld | p)<<1, (rd | p)>>1, sum, res+char(bit+'0'+1));
        }
    } else {
        result.push_back(res);
        sum++;
    }
}

int main() {
    int sum = 0;
    test(0, 0, 0, sum, "");
    cout << sum << endl; // 9 : 352
    ofstream fout("9-queens.txt");
    if (!result.empty()) fout << result[0];
    for (int i = 1; i < result.size(); i++)
        fout << "," << result[i];
    return 0;
}


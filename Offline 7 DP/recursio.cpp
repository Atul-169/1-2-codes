#include <bits/stdc++.h>
using namespace std;

string S, T;
int I, D, R;
int n, m;

vector<vector<int>> memo;

int solve(int i, int j){

    if(i == 0) return j * I;
    if(j == 0) return i * D;

    if(memo[i][j] != -1)
        return memo[i][j];

    if(S[i-1] == T[j-1])
        return memo[i][j] = solve(i-1, j-1);

    int insertCost = solve(i, j-1) + I;
    int deleteCost = solve(i-1, j) + D;
    int replaceCost = solve(i-1, j-1) + R;

    return memo[i][j] = min({insertCost, deleteCost, replaceCost});
}

int main(){

    cin >> I >> D >> R;
    cin >> S >> T;

    n = S.size();
    m = T.size();

    memo.assign(n+1, vector<int>(m+1, -1));

    int ans = solve(n, m);

    cout << "Minimum Cost: " << ans << endl;
}
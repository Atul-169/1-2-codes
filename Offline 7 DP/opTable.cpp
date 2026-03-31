#include <bits/stdc++.h>
using namespace std;

int main() {

    int I, D, R;
    cin >> I >> D >> R;

    string S, T;
    cin >> S >> T;

    int n = S.size();
    int m = T.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    vector<vector<char>> op(n+1, vector<char>(m+1));

    for(int i=0;i<=n;i++){
        dp[i][0] = i*D;
        if(i>0) op[i][0] = 'D';
    }

    for(int j=0;j<=m;j++){
        dp[0][j] = j*I;
        if(j>0) op[0][j] = 'I';
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(S[i-1] == T[j-1]){
                dp[i][j] = dp[i-1][j-1];
                op[i][j] = 'M';
            }

            else{

                int insertCost = dp[i][j-1] + I;
                int deleteCost = dp[i-1][j] + D;
                int replaceCost = dp[i-1][j-1] + R;

                dp[i][j] = min({insertCost, deleteCost, replaceCost});

                if(dp[i][j] == replaceCost)
                    op[i][j] = 'R';

                else if(dp[i][j] == insertCost)
                    op[i][j] = 'I';

                else
                    op[i][j] = 'D';
            }
        }
    }

    cout << "Minimum Cost: " << dp[n][m] << endl;
    cout << "Operations:" << endl;

    vector<string> operations;

    int i=n, j=m;

    while(i>0 || j>0){

        if(op[i][j]=='M'){
            operations.push_back("Match " + string(1,S[i-1]));
            i--; j--;
        }

        else if(op[i][j]=='R'){
            operations.push_back("Replace " + string(1,S[i-1]) + " with " + string(1,T[j-1]));
            i--; j--;
        }

        else if(op[i][j]=='I'){
            operations.push_back("Insert " + string(1,T[j-1]));
            j--;
        }

        else if(op[i][j]=='D'){
            operations.push_back("Delete " + string(1,S[i-1]));
            i--;
        }
    }

    reverse(operations.begin(), operations.end());

    for(auto &s : operations)
        cout << s << endl;
}
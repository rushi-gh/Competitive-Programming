#include <bits/stdc++.h>
using namespace std;

int Recurse(int liveCity, int runningMask, int &visitCompleteMask, vector<vector<int>> &dist, vector<vector<int>> &dp) {
    if (runningMask == visitCompleteMask) {
        return dist[liveCity][0];
    }

    if (dp[liveCity][runningMask] != -1) {
        return dp[liveCity][runningMask];
    }

    int ans = INT32_MAX;
    for (int choice = 0; choice < dist.size(); choice++) {
        int mask = (1LL << choice);
        if (!(runningMask & mask)) {
            ans = min(ans, dist[liveCity][choice] + Recurse(choice, (runningMask | mask), visitCompleteMask, dist, dp));
        }
    }
    return dp[liveCity][runningMask] = ans;
}

int main() {
    
    vector<vector<int>> dist = {
        {0, 29, 20, 21, 16, 31, 100, 12, 4, 29, 45},
        {29, 0, 15, 29, 28, 40, 72, 21, 19, 25, 37},
        {20, 15, 0, 15, 14, 25, 81, 9, 23, 16, 34},
        {21, 29, 15, 0, 4, 12, 92, 12, 18, 24, 39},
        {16, 28, 14, 4, 0, 16, 94, 9, 15, 30, 41},
        {31, 40, 25, 12, 16, 0, 98, 22, 27, 20, 35},
        {100, 72, 81, 92, 94, 98, 0, 90, 87, 75, 65},
        {12, 21, 9, 12, 9, 22, 90, 0, 11, 14, 29},
        {4, 19, 23, 18, 15, 27, 87, 11, 0, 5, 22},
        {29, 25, 16, 24, 30, 20, 75, 14, 5, 0, 19},
        {45, 37, 34, 39, 41, 35, 65, 29, 22, 19, 0},
    };

    int problemSize = dist.size();
    int visitCompleteMask = (1LL << problemSize) - 1;
    vector<vector<int>> dp(problemSize, vector<int>(visitCompleteMask, -1));

    cout << Recurse(0, 1, visitCompleteMask, dist, dp) << endl;
    return 0;
}
// Problem link: https://leetcode.com/problems/find-the-town-judge

#include <iostream>
#include <vector>
using namespace std;

// Time complexity => O(|trust|)
// Space complexity => O(N)
int findJudge(int N, vector<vector<int>>& trust) {
    // judge is a person who has indegree of trust = N - 1
    // and outdegree of trust = 0

    vector<int> indeg(N + 1, 0);
    vector<int> outdeg(N + 1, 0);

    for (vector<int>& t : trust) {
        // for a particular trust t: t[0] trusts t[1]
        ++outdeg[t[0]];
        ++indeg[t[1]];
    }

    for (int judgeCandidate = 1; judgeCandidate <= N; judgeCandidate++) {
        if (indeg[judgeCandidate] == N - 1 && outdeg[judgeCandidate] == 0) return judgeCandidate;
    }
    return -1;
}

int main() {
}

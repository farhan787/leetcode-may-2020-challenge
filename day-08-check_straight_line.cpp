// Problem link: https://leetcode.com/problems/check-if-it-is-a-straight-line/

#include <iostream>
#include <vector>

using namespace std;

// Time complexity => O(N) ; N = size of coordinates vector
// Space complexity => O(1)

pair<int, int> getDelta(vector<int>& coordinate1, vector<int>& coordinate2) {
    pair<int, int> delta;

    delta.first = coordinate2[0] - coordinate1[0];
    delta.second = coordinate2[1] - coordinate1[1];

    return delta;
}

bool haveEqualSlopes(pair<int, int>& delta1, pair<int, int>& delta2) {
    // to avoid dividing by zero runtime error, for three points
    // (y2 - y1) / (x2 - x1) == (y3 - y2) / (x3 - x2)

    // we're checking for multiplication
    // (x3 - x2) * (y2 - y1) == (x2 - x1) * (y3 - y2)

    // delta1 = delta([x1,y1],[x2,y2])
    // delta2 = delta([x2,y2],[x3,y3])

    if (delta2.first * delta1.second == delta1.first * delta2.second) {
        return true;
    }
    return false;
}

bool checkStraightLine(vector<vector<int>>& coordinates) {
    if ((int)coordinates.size() <= 2) {
        return true;
    }

    pair<int, int> delta1 = getDelta(coordinates[0], coordinates[1]);

    for (int i = 1; i < (int)coordinates.size() - 1; ++i) {
        pair<int, int> delta2 = getDelta(coordinates[i], coordinates[i + 1]);
        if (!haveEqualSlopes(delta1, delta2)) {
            return false;
        }
    }
    return true;
}

int main() {
}

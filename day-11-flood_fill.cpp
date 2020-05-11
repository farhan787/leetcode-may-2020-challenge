// Problem link: https://leetcode.com/problems/flood-fill/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Time complexity => O(row * col)
// Space complexity => O(row * col)

// Use BFS when you've densely condensed image in context of colors to change
// Use DFS when you've sparse image in context of colors to change

bool isValidPixel(vector<vector<int>>& image, int row, int col) {
    if (row < 0 || col < 0 || row >= (int)image.size() || col >= (int)image[0].size()) {
        return false;
    }
    return true;
}

// DFS Solution
void floodFillDfs(vector<vector<int>>& image, int row, int col, int newColor, int colorToChange) {
    if (!isValidPixel(image, row, col)) {
        return;
    }

    if (image[row][col] != colorToChange) {
        return;
    }

    image[row][col] = newColor;

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (vector<int>& direction : directions) {
        int newRow = row + direction[0];
        int newCol = col + direction[1];

        floodFillDfs(image, newRow, newCol, newColor, colorToChange);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    vector<vector<int>> newImage = image;
    int colorToChange = image[sr][sc];

    if (newColor == colorToChange) {
        return newImage;
    }

    floodFillDfs(newImage, sr, sc, newColor, colorToChange);
    return newImage;
}

// BFS Solution
void addNeighboursToQueue(vector<vector<int>>& image, int row, int col, int colorToChange, queue<pair<int, int>>& q) {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (vector<int>& direction : directions) {
        int newRow = row + direction[0];
        int newCol = col + direction[1];

        // only add valid pixels and those pixels whose color should be changed
        if (!isValidPixel(image, newRow, newCol) || image[newRow][newCol] != colorToChange) {
            continue;
        }

        pair<int, int> newCoordinate(newRow, newCol);
        q.push(newCoordinate);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    vector<vector<int>> newImage = image;
    int colorToChange = image[sr][sc];

    if (newColor == colorToChange) {
        return newImage;
    }

    queue<pair<int, int>> q;
    pair<int, int> coordinate(sr, sc);
    q.push(coordinate);

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        int row = front.first;
        int col = front.second;

        newImage[row][col] = newColor;
        addNeighboursToQueue(newImage, row, col, colorToChange, q);
    }
    return newImage;
}

int main() {
}

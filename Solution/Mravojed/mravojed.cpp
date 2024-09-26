#include <bits/stdc++.h>
using namespace std;

bitset<101> grid[101]; 

bool isFirstSquare = true; 
short n, m, firstRow, firstCol, secondRow, secondCol, firstSize, secondSize; 

// Idea: Find the first square, remove it from the grid, then find the second square.
// The first square is always the top-left square, and the second square is always the bottom-right square.
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;

    // Construct grid of 0 and 1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char cell;
            cin >> cell;
            grid[i][j] = (cell == 'x');
        }
    }

    // Find the first square.
    for (int i = 1; i <= n && isFirstSquare; i++) {
        for (int j = 1; j <= m && isFirstSquare; j++) {
            if (grid[i][j]) {
                isFirstSquare = false;
                
                int ii = i, jj = j;
                while (ii <= n && grid[ii][j]) ii++; // Expend horizontally
                while (jj <= m && grid[i][jj]) jj++; // Expend vertically

                firstSize = min(ii - i, jj - j); // As the square is always a square, we can take the minimum of the two sides.
                firstRow = i;
                firstCol = j;
            }
        }
    }

    cout << firstRow << " " << firstCol << " " << firstSize << "\n";

    // Remove the first square from the grid.
    for (int i = firstRow; i < firstRow + firstSize; i++) {
        for (int j = firstCol; j < firstCol + firstSize; j++) {
            grid[i][j] = 0;
        }
    }

    isFirstSquare = true;

    for (int i = n; i > 0 && isFirstSquare; i--) {
        for (int j = m; j > 0 && isFirstSquare; j--) {
            if (grid[i][j]) {
                isFirstSquare = false;

                int ii = i, jj = j;
                while (ii > 0 && grid[ii][j]) ii--; // Expend horizontally
                while (jj > 0 && grid[i][jj]) jj--; // Expend vertically

                secondSize = max(j - jj, i - ii); // As the square could be cut off by the deletion of the first square, we take the maximum of the two sides.
                
                secondRow = max(1, i - secondSize + 1);
                secondCol = max(1, j - secondSize + 1);
            }
        }
    }

    if (isFirstSquare) { // If there is no second square, the second square is the first square.
        secondRow = firstRow;
        secondCol = firstCol;
        secondSize = 1;
    }

    cout << secondRow << " " << secondCol << " " << secondSize;
}

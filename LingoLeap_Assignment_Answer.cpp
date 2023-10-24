#include <vector>
#include <iostream>

/*
Name: Name: Sumit Rajkumar Bashetwar
mail:sumitbashetwar@gmail.com
Contact: 8975688691
*/

using namespace std;

int maxMoves(vector<vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();
  
  //initializing the vector of vector grid havin m rows and n columns to -1
  vector<vector<int>> dp(m, vector<int>(n, -1));

  // Initializing the base cases.
  for (int i = 0; i < m; i++) {
    dp[i][0] = 0;
  }

  // Iterating over the grid in bottom-up order.
  for (int i = m - 1; i >= 0; i--) {
    for (int j = 1; j < n; j++) {
      // Finding the maximum number of moves that can be made from the current cell.
      int maxMoves = -1;
      for (int k = i - 1; k <= i + 1; k++) {
        if (k >= 0 && k < m && grid[k][j] > grid[i][j]) {
          maxMoves = max(maxMoves, dp[k][j] + 1);
        }
      }

      // Updating the dp table.
      dp[i][j] = maxMoves;
    }
  }

  // Returning the maximum number of moves that can be made from any cell in the first column.
  int maxMoves = -1;
  for (int i = 0; i < m; i++) {
    maxMoves = max(maxMoves, dp[i][0]);
  }
  return maxMoves;
}

int main() {
  // Getting the input from the user.
  int m, n;
  cout << "Enter the number of rows: ";
  cin >> m;
  cout << "Enter the number of columns: ";
  cin >> n;

  vector<vector<int>> grid(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << "Enter the value at row " << i << " and column " << j << ": ";
      cin >> grid[i][j];
    }
  }

  // Finding the maximum number of moves that can be made.
  int max = maxMoves(grid);

  // Printing the output.
  cout << "The maximum number of moves that can be made is: " << max << endl;
  return 0;
}


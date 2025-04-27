// Problem: Find the minimum time to reach the bottom-right corner of a grid
// Approach: Dijkstra-like BFS using priority queue

#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    // Define directions for up, down, left, and right moves
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // Define a shorthand for the priority queue's element type
    #define P pair<int, pair<int, int>>

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // If both immediate neighbors (right and down) are inaccessible initially, return -1
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        
        // Initialize visited matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // Initialize result matrix with maximum integer values
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        
        // Min-heap to prioritize cells with lower time cost
        priority_queue<P, vector<P>, greater<P>> pq;
        
        // Start from (0, 0) with the grid's initial value
        pq.push({grid[0][0], {0, 0}});
        result[0][0] = 0;

        // Main loop: process cells
        while (!pq.empty()) {
            // Extract the top element
            int time = pq.top().first;
            int row  = pq.top().second.first;
            int col  = pq.top().second.second;
            pq.pop();
            
            // If destination is reached, return the result
            if (row == m - 1 && col == n - 1)
                return result[m-1][n-1];
            
            // Skip if already visited
            if (visited[row][col]) continue;
            visited[row][col] = true;
            
            // Check all 4 possible directions
            for (auto dir : direction) {
                int r = row + dir[0];
                int c = col + dir[1];

                // Check boundaries and if already visited
                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c])
                    continue;
                
                // If we can immediately move into the cell
                if (grid[r][c] <= time + 1) {
                    pq.push({time + 1, {r, c}});
                    result[r][c] = time + 1;
                }
                // If the time to move into the cell is even relative to current time
                else if ((grid[r][c] - time) % 2 == 0) {
                    pq.push({grid[r][c] + 1, {r, c}});
                    result[r][c] = grid[r][c] + 1;
                }
                // Otherwise, we can move exactly at grid[r][c]
                else {
                    pq.push({grid[r][c], {r, c}});
                    result[r][c] = grid[r][c];
                }
            }
        }

        // If destination is unreachable
        return -1;
    }
};

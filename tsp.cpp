#include <iostream>
using namespace std;

const int INF = 1e9;

int tsp(int mask, int pos, int dist[4][4], int dp[16][4], int n) {
    // If all cities have been visited
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Return to the starting city
    }

    // If this subproblem has already been solved
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    // Try visiting each unvisited city
    for (int city = 0; city < n; ++city) {
        if ((mask & (1 << city)) == 0) { // Check if the city is unvisited
            int newDist = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp, n);
            ans = min(ans, newDist);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    // Example data
    int n = 4; // Number of cities

    // Distance matrix (dist[i][j] represents the distance from city i to city j)
    int dist[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Initialize DP memoization table
    int dp[16][4];
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = -1;
        }
    }

    // Solve the TSP
    int minCost = tsp(1, 0, dist, dp, n); // Start from city 0, with the first city visited

    cout << "Minimum cost of TSP: " << minCost << endl;

    return 0;
}

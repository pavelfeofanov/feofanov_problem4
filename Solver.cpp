#include "Solver.h"
#include <iostream>
#include <vector>

Solver::Solver(int capacity, const std::vector<std::pair<int, int>>& items)
    : knapsackCapacity(capacity), items(items), takenItems(items.size()) {}

void Solver::solve() {
    int N = items.size();
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(knapsackCapacity + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= knapsackCapacity; w++) {
            if (items[i-1].second <= w) {
                dp[i][w] = std::max(dp[i-1][w], dp[i-1][w - items[i-1].second] + items[i-1].first);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    
    int w = knapsackCapacity;
    for (int i = N; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            takenItems[i-1] = 1; 
            w -= items[i-1].second;
        } else {
            takenItems[i-1] = 0; 
        }
    }
}

void Solver::printSolution() {
    int totalValue = 0;
    for (int i = 0; i < takenItems.size(); i++) {
        if (takenItems[i]) {
            totalValue += items[i].first;
        }
    }
    std::cout << totalValue << " 0" << std::endl;
    for (int taken : takenItems) {
        std::cout << taken << ' ';
    }
    std::cout << std::endl;
}

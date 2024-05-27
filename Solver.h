#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <utility> 

class Solver {
private:
    int knapsackCapacity;
    std::vector<std::pair<int, int>> items;
    std::vector<int> takenItems;

public:
    Solver(int capacity, const std::vector<std::pair<int, int>>& items);
    void solve();
    void printSolution();
};

#endif 

#include "Parser.h"
#include "Solver.h"

int main() {
    try {
        Parser parser("ks_100_2");
        Solver solver(parser.capacity, parser.items);
        solver.solve();
        solver.printSolution();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

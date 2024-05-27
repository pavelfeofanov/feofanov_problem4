#include "Parser.h"
#include <fstream>
#include <sstream>

Parser::Parser(const char* filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        std::getline(file, line); 
        std::istringstream iss(line);
        int num_items;
        iss >> num_items >> capacity;

        int value, weight;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            iss >> value >> weight;
            items.push_back(std::make_pair(value, weight));
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open the file.");
    }
}

void Parser::parse() {
   
}

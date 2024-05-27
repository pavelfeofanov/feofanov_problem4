#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <utility> 

class Parser {
public:
    int capacity; 
    std::vector<std::pair<int, int>> items; 

    Parser(const char* filename);
    void parse();
};

#endif

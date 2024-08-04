//
//  main.cpp
//  cpp-challenges
//
//  Created by Albany Patriawan on 7/23/24.
//

#include <iostream>
#include "./1-test-driven-development/1-test-driven-development.hpp"
#include "./2-max-depth-tree.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    // 1
    tdd tdd;
    tdd.runTests();
    
    // 2
    MaxDepthTree tree;
    tree.runTests();
    
    return 0;
}

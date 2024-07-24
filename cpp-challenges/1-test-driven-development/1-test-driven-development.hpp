//
//  1-test-driven-development.hpp
//  cpp-challenges
//
//  Created by Albany Patriawan on 7/23/24.
//

#ifndef __test_driven_development_hpp
#define __test_driven_development_hpp

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

class tdd {
    public:
        void runTests();
        vector<std::string> sortNames(vector<string> names);
};
    

#endif /* __test_driven_development_hpp */

//
//  2-max-depth-tree.cpp
//  cpp-challenges
//
//  Created by Albany Patriawan on 8/3/24.
//

#include "2-max-depth-tree.hpp"

int recurse(string tree, int left, int right, int depth) {
    // Base
    if (left >= right)
        return 0;
        
    // Running sum
    int maxDepth = depth;
    
    stack<char> stack; // To be added to the stack is to be an OPEN and to not have found a CLOSE (yet?)
                       // To be removed from the stack is to have found a CLOSE
    
    int childStartIndex = left + 1;
    
    // Iterate through this substring
    for (int i = left; i < right; i ++) {
        char curChar = tree[i];
        
        // Found opening
        if (curChar == '(')
        {
            // Found beginning of new child
            if (stack.size() == 0)
                childStartIndex = i + 1;
            
            stack.push(curChar);
        } 
        
        // Closed is met
        else if ( curChar == ')')
        {
            // A close is met but there is no matching open, so invalid
            if (stack.size() == 0)
                return -1;
        
            stack.pop();
            
            // New child is found, find max depth of this child
            if (stack.size() == 0)
            {
                int childEndIndex = i;
                int maxDepthOfChildren = recurse(tree, childStartIndex, childEndIndex, depth + 1);
                maxDepth = maxDepthOfChildren != - 1 ? max(maxDepth, maxDepthOfChildren) : -1;
            }
                
        }
    }
    
    // There are still open parenthesis expecting a close and all chars in this tree have been checked, so this tree is invalid
    if (stack.size() > 0)
        return -1;
    
    return maxDepth;
}

/* Returns the maximum depth of a binary tree represented as a string with open and closing parentheses. If the tree is invalid, return -1
 
 @params  string  tree  The tree represented as a string. Eg: (()()()) or ((()))
 */
int MaxDepthTree::Solution(string tree) {
    // Pseudo:
    // Find each immediate child with this string and recurse. Each recursive call adds a depth of 1.
    // To find an immediate child through a string-represented tree:
    // 1. Grab the first index of an OPEN bracket
    // 2. Iterate through the string, adding to a stack when an OPEN is met and popping the stack with a CLOSE is met
    //         - If a closing bracket is met and it matches with the last OPEN in the stack, then a child is found where the
    //           start and end index of the its tree is the index of the open bracket and index of the close bracket
    
    // 3. To find more children within this tree, store the start index of the next child if an OPEN is met and the stack is empty
    //    - Edge: If a CLOSE is met and the stack is empty, then the tree is invalid and return -1
    
    return recurse(tree, 0, tree.size(), 1);
}

void MaxDepthTree::runTests() {
    MaxDepthTree alg;
    
    string s1 = "((()))"; // depth of 3
    string s2 = "(()())"; // depth of 2, multiple children in one node
    string s3 = "(()()(()))"; // depth of 3 multiple children in one node
    string s4 = "())"; // invalid
    string s5 = "(()"; // invalid
    
    assert(alg.Solution(s1) == 3);
    assert(alg.Solution(s2) == 2);
    assert(alg.Solution(s3) == 3);
    assert(alg.Solution(s4) == -1);
    assert(alg.Solution(s5) == -1);
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumGain(std::string s, int x, int y) {
        int totalScore = 0;
        std::string highPriorityPair = (x > y) ? "ab" : "ba";
        std::string lowPriorityPair = (x > y) ? "ba" : "ab";
        int highPriorityScore = std::max(x, y);
        int lowPriorityScore = std::min(x, y);

        // First pass: remove the highest-scoring pair
        std::string stringAfterFirstPass;
        totalScore += removeSubstring(s, highPriorityPair, highPriorityScore, stringAfterFirstPass);
        
        // Second pass: remove the lower-scoring pair from the result of the first pass
        std::string finalString;
        totalScore += removeSubstring(stringAfterFirstPass, lowPriorityPair, lowPriorityScore, finalString);

        return totalScore;
    }

private:
    // Helper function to remove a specific substring and calculate the score
    int removeSubstring(const std::string& input, const std::string& targetPair, int scorePerRemoval, std::string& remainingString) {
        int score = 0;
        std::vector<char> stack;

        for (char c : input) {
            // Check if the current character and the top of the stack form the target pair
            if (c == targetPair[1] && !stack.empty() && stack.back() == targetPair[0]) {
                stack.pop_back(); // Remove the matching character from the stack
                score += scorePerRemoval;
            } else {
                stack.push_back(c);
            }
        }
        
        // The remaining string is what's left in the stack
        for (char c : stack) {
            remainingString += c;
        }

        return score;
    }
};




#include <vector>
using namespace std;

class Solution {
    
public:
    int hIndex(const vector<int>& citations) const {
        vector<int> sortedCitationsPerFrequency(citations.size() + 1);
        for (const auto& current : citations) {
            int frequency = current < citations.size() ? current : citations.size();
            ++sortedCitationsPerFrequency[frequency];
        }

        int frequency = 0;
        int maxValue_H_index = 0;

        for (size_t i = sortedCitationsPerFrequency.size() - 1; i >= 0; --i) {
            frequency += sortedCitationsPerFrequency[i];
            if (frequency >= i) {
                maxValue_H_index = i;
                break;
            }
        }
        return maxValue_H_index;
    }
};

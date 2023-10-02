
public class Solution {

    public int hIndex(int[] citations) {
        int[] sortedCitationsPerFrequency = new int[citations.length + 1];
        for (int frequency : citations) {
            frequency = frequency < citations.length ? frequency : citations.length;
            ++sortedCitationsPerFrequency[frequency];
        }

        int frequency = 0;
        int maxValue_H_index = 0;

        for (int i = sortedCitationsPerFrequency.length - 1; i >= 0; --i) {
            frequency += sortedCitationsPerFrequency[i];
            if (frequency >= i) {
                maxValue_H_index = i;
                break;
            }
        }
        return maxValue_H_index;
    }
}

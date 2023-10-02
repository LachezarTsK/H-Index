
using System;

public class Solution
{
    public int HIndex(int[] citations)
    {
        int frequency = 0;
        int[] sortedCitationsPerFrequency = new int[citations.Length + 1];
        foreach (int current in citations)
        {
            frequency = current < citations.Length ? current : citations.Length;
            ++sortedCitationsPerFrequency[frequency];
        }

        frequency = 0;
        int maxValue_H_index = 0;

        for (int i = sortedCitationsPerFrequency.Length - 1; i >= 0; --i)
        {
            frequency += sortedCitationsPerFrequency[i];
            if (frequency >= i)
            {
                maxValue_H_index = i;
                break;
            }
        }
        return maxValue_H_index;
    }
}

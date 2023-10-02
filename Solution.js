
/**
 * @param {number[]} citations
 * @return {number}
 */
var hIndex = function (citations) {
    const sortedCitationsPerFrequency = new Array(citations.length + 1).fill(0);
    for (let frequency of citations) {
        frequency = frequency < citations.length ? frequency : citations.length;
        ++sortedCitationsPerFrequency[frequency];
    }

    let frequency = 0;
    let maxValue_H_index = 0;

    for (let i = sortedCitationsPerFrequency.length - 1; i >= 0; --i) {
        frequency += sortedCitationsPerFrequency[i];
        if (frequency >= i) {
            maxValue_H_index = i;
            break;
        }
    }
    return maxValue_H_index;
};

class MedianFinder {
public:
    priority_queue<int> maxNums;
    priority_queue<int, vector<int>, greater<int>> minNums;
    MedianFinder() {}

    void addNum(int num) {
        maxNums.push(num);
        if (!maxNums.empty() && !minNums.empty() &&
            (maxNums.top() > minNums.top())) {
            minNums.push(maxNums.top());
            maxNums.pop();
        }

        if (maxNums.size() - 1 > minNums.size()) {
            minNums.push(maxNums.top());
            maxNums.pop();
        } else if (minNums.size() > maxNums.size()) {
            maxNums.push(minNums.top());
            minNums.pop();
        }
    }

    double findMedian() {
        if (maxNums.size() > minNums.size()) {
            return maxNums.top();
        } else {
            return (maxNums.top() + minNums.top()) / 2.0;
        }
    }
};
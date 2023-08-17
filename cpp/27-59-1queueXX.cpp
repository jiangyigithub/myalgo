#include "head.hpp"

class Solution
{
public:
    /// priority queue
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.empty())
            return {};
        priority_queue<pair<int, int>> q; // 优先级队列，默认最大值在堆顶
        for (int i = 0; i < k; ++i)
        {
            q.emplace(nums[i], i);
        }
        vector<int> res = {q.top().first};
        for (int i = k; i < nums.size(); ++i)
        {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k)
            {
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }


    /// monotone deque
    vector<int> maxSlidingWindow(vector<int> &nums, int k, string sol)
    {
        /// sol=="deque"
        
        deque<int> deq;
        // "[1, 3,-1,-3, 5, 3, 6, 7]"
        /// handle the first window
        for (int i = 0; i < k; i++)
        {
            while (!deq.empty() && nums[i] > nums[deq.back()])
            {
                deq.pop_back(); // remove element
            }
            deq.push_back(i); // add element
        }
        /// let the window slding at the step = 1
        vector<int> res = {nums[deq.front()]};
        for (int i=k;i<nums.size();i++){
            while(!deq.empty()&&nums[i]>nums[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(i);
            while(deq.front()<=i-k){
                deq.pop_front();
            }
            res.push_back(nums[deq.front()]);
        }
        return res;
    }
};

    void trimLeftTrailingSpaces(string &input)
    {
        input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
                                           { return !isspace(ch); }));
    }

    void trimRightTrailingSpaces(string &input)
    {
        input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
                            { return !isspace(ch); })
                        .base(),
                    input.end());
    }

    vector<int> stringToIntegerVector(string input)
    {
        vector<int> output;
        trimLeftTrailingSpaces(input);
        trimRightTrailingSpaces(input);
        input = input.substr(1, input.length() - 2);
        stringstream ss;
        ss.str(input);
        string item;
        char delim = ',';
        while (getline(ss, item, delim))
        {
            output.push_back(stoi(item));
        }
        return output;
    }

    int stringToInteger(string input)
    {
        return stoi(input);
    }

    string integerVectorToString(vector<int> list, int length = -1)
    {
        if (length == -1)
        {
            length = list.size();
        }

        if (length == 0)
        {
            return "[]";
        }

        string result;
        for (int index = 0; index < length; index++)
        {
            int number = list[index];
            result += to_string(number) + ", ";
        }
        return "[" + result.substr(0, result.length() - 2) + "]";
    }

    int main()
    {
        // string line = "[1,3,-1,-3,2,1,1,0]";
        string line = "[8, 3,-1,-3, 5, 3, 6, 4]";
        vector<int> nums = stringToIntegerVector(line);

        int k = 3;

        // vector<int> ret = Solution().maxSlidingWindow(nums, k);
        vector<int> ret = Solution().maxSlidingWindow(nums, k, "deque");

        string out = integerVectorToString(ret);
        cout << out << endl;

        return 0;
    }
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequencyMap;

        // 1. Count occurrences of each element
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // 2. Move data to a vector of pairs to sort
        vector<pair<int, int>> frequencyVector(frequencyMap.begin(),
                                               frequencyMap.end());
        // 3. sort
        sort(frequencyVector.begin(), frequencyVector.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second > b.second;
             });

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(frequencyVector[i].first);
        }
        return ans;
    }
};
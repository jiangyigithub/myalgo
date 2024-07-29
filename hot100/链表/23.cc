#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();

        return mergeKLists(lists,0,n);
    }
    
    /// @brief 怎么把一个vector递归分为两半，通过左闭右开区间，保证可以直接合并区间
    /// @param lists 
    /// @param i 
    /// @param j 
    /// @return 
    ListNode* mergeKLists(vector<ListNode*>& lists,int i,int j){
        int len = j-i;
        if(len==0) return nullptr;
        if(len==1) return lists[i];
        ListNode* left = mergeKLists(lists,i,i+len/2);
        ListNode* right = mergeKLists(lists,i+len/2,j);
        return mergeTwoLists(left,right);


    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0), *cur = dummy;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy->next;
}

    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        
        // Add the first node of each list to the min-heap
        for (auto list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }
        
        // Create a dummy node to start the merged list
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        
        while (!minHeap.empty()) {
            // Pop the smallest element from the heap
            ListNode* node = minHeap.top();
            minHeap.pop();
            current->next = node;
            current = current->next;
            if (node->next) {
                minHeap.push(node->next);
            }
        }
        
        return dummy->next;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* node) {
    while (node) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "nullptr" << endl;
}

// Helper function to convert a linked list to a vector
vector<int> linkedListToVector(ListNode* node) {
    vector<int> result;
    while (node) {
        result.push_back(node->val);
        node = node->next;
    }
    return result;
}

// Structure to store test cases
struct TestCase {
    vector<vector<int>> input;
    vector<int> expectedOutput;
};

int main() {
    Solution solution;
    
    // Test cases
    vector<TestCase> testCases = {
        {{{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6}},
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2, 3, 4, 5, 6, 7, 8, 9}},
        {{}, {}},
        {{{}}, {}}
    };
    
    for (size_t i = 0; i < testCases.size(); ++i) {
        // Convert input vectors to linked lists
        vector<ListNode*> lists;
        for (const auto& arr : testCases[i].input) {
            lists.push_back(createLinkedList(arr));
        }
        
        // Get the actual output from the solution
        ListNode* mergedList = solution.mergeKLists(lists);
        vector<int> actualOutput = linkedListToVector(mergedList);
        
        // Check if the test passed
        bool passed = (actualOutput == testCases[i].expectedOutput);
        
        // Output the test case details
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Input: ";
        for (const auto& arr : testCases[i].input) {
            cout << "[";
            for (size_t j = 0; j < arr.size(); ++j) {
                cout << arr[j] << (j == arr.size() - 1 ? "" : ", ");
            }
            cout << "] ";
        }
        cout << "\nExpected Output: [";
        for (size_t j = 0; j < testCases[i].expectedOutput.size(); ++j) {
            cout << testCases[i].expectedOutput[j] << (j == testCases[i].expectedOutput.size() - 1 ? "" : ", ");
        }
        cout << "]\nActual Output: [";
        for (size_t j = 0; j < actualOutput.size(); ++j) {
            cout << actualOutput[j] << (j == actualOutput.size() - 1 ? "" : ", ");
        }
        cout << "]\nTest " << (passed ? "PASSED" : "FAILED") << "\n\n";
    }

    return 0;
}

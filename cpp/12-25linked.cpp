#include "head.hpp"

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* cur = dummy;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
                cur=cur->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
                cur=cur->next;
            }
        }
        if(l1!=nullptr){
            cur->next=l1;
        }
        if(l2!=nullptr){
            cur->next=l2;
        }
        return dummy->next;
   
    }

};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line = "[1,3,5]";
  
    ListNode* l1 = stringToListNode(line);
    line = "[2,4,6]";
    ListNode* l2 = stringToListNode(line);
    
    ListNode* ret = Solution().mergeTwoLists(l1, l2);

    string out = listNodeToString(ret);
    cout << out << endl;
    
    return 0;
}
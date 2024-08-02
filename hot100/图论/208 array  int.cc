#include <iostream>
using namespace std;

class Trie {
    int isEnd;
    Trie* next[26];

public:
    Trie() : isEnd(0) {
        for (int i = 0; i < 26; i++) {
            this->next[i] = nullptr;
        }
    }
    // 为一个词，创建边和值。一个完整的词是既包含边，要包含值的
    void insert(string word) {
        Trie* cur = this;
        for (auto ch : word) {
            int idx = ch - 'a';
            if (cur->next[idx] == nullptr) {
                cur->next[idx] = new Trie();
            }
            cur = cur->next[idx];
        }
        cur->isEnd=1;// 值
    }

    // 既看边又看值
    bool search(string word) {
        Trie* cur = this; 
        for (auto ch : word) {
            int idx = ch - 'a';
            cur = cur->next[idx];
            if (cur == nullptr)
                return false;
        }
        return cur->isEnd == 1;
    }
    
    // 只看边
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (auto ch : prefix) {
            int idx = ch - 'a';
            cur = cur->next[idx];
            if (cur == nullptr) //不存在这条边，既该字母不存在
                return false;
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << boolalpha << trie.search("apple") << endl;   // 返回 true
    cout << boolalpha << trie.search("app") << endl;     // 返回 false
    cout << boolalpha << trie.startsWith("app") << endl; // 返回 true
    trie.insert("app");
    cout << boolalpha << trie.search("app") << endl;     // 返回 true

    return 0;
}

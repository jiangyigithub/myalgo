#include <iostream>
using namespace std;

// 带标记的多叉树

class Trie {
private:
    int isEnd;
    Trie* next[26];

public:
    // 构造函数
    Trie() : isEnd(0) {
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
    }

    // 插入单词
    void insert(const string& word) {
        Trie* node = this;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->next[index] == nullptr) {
                node->next[index] = new Trie();
            }
            node = node->next[index];
        }
        node->isEnd = 1;
    }

    // 搜索单词， 路径题
    bool search(const string& word) {
        Trie* node = this;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->next[index] == nullptr) {
                return false;
            }
            node = node->next[index];
        }
        return node->isEnd == 1;
    }

    // 判断是否有前缀， 路径题
    bool startsWith(const string& prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (node->next[index] == nullptr) {
                return false;
            }
            node = node->next[index];
        }
        return true;
    }

    // 析构函数，释放所有节点
    ~Trie() {
        for (int i = 0; i < 26; ++i) {
            if (next[i] != nullptr) {
                delete next[i];
            }
        }
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

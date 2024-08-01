#include <iostream>
using namespace std;

class Trie {
private:
bool isEnd;
Trie* next[26]


public:

    // 插入单词
    void insert(const string& word) {
        Trie* node = this;
        for(auto c:word){
            int idx=c-'a';
            if(node->next[idx] == nullptr){
                node->next[idx]== new Trie();
            }
            node = node->next[index];
        }
        node->isEnd = true;
 

    }

    // 搜索单词
    bool search(const string& word) {

    }

    // 判断是否有前缀
    bool startsWith(const string& prefix) {

    }
    
    // 构造函数
    Trie() : isEnd(false) {
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
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

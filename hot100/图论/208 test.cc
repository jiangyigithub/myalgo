#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;
// https://leetcode.cn/problems/implement-trie-prefix-tree/solutions/98390/trie-tree-de-shi-xian-gua-he-chu-xue-zhe-by-huwt/?envType=study-plan-v2&envId=top-100-liked
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEnd;

    TrieNode() : isEnd(false) {}
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    // 插入一个单词到Trie中
    void insert(const string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->children.find(ch) == node->children.end())
            {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    // 搜索一个单词在Trie中是否存在
    bool search(const string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->children.find(ch) == node->children.end())
            {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEnd;
    }

    // 判断Trie中是否有以某个前缀开始的单词
    bool startsWith(const string &prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            if (node->children.find(ch) == node->children.end())
            {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }

    // 析构函数，释放所有的节点
    ~Trie()
    {
        clear(root);
    }

private:
    // 递归释放所有节点的内存
    void clear(TrieNode *node)
    {
        for (auto &pair : node->children)
        {
            clear(pair.second);
        }
        delete node;
    }
};

// Function to run tests
void runTests()
{
    Trie trie;

    // Insert words
    trie.insert("a");
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");
    trie.insert("batman");
    trie.insert("cherry");

    // Search for words
    cout << "Searching for 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'appl': " << (trie.search("appl") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'bat': " << (trie.search("bat") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'bats': " << (trie.search("bats") ? "Found" : "Not Found") << endl;

    // Check startsWith
    cout << "Prefix 'app': " << (trie.startsWith("app") ? "Exists" : "Does not exist") << endl;
    cout << "Prefix 'bat': " << (trie.startsWith("bat") ? "Exists" : "Does not exist") << endl;
    cout << "Prefix 'ba': " << (trie.startsWith("ba") ? "Exists" : "Does not exist") << endl;
    cout << "Prefix 'bats': " << (trie.startsWith("bats") ? "Exists" : "Does not exist") << endl;
}

int main()
{
    runTests();
    return 0;
}

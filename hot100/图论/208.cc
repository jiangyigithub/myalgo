#include <iostream>
#include <cstring>
using namespace std;
// https://leetcode.cn/problems/implement-trie-prefix-tree/solutions/98390/trie-tree-de-shi-xian-gua-he-chu-xue-zhe-by-huwt/?envType=study-plan-v2&envId=top-100-liked
class Trie
{

private:
    bool isEnd;

    Trie *next[26];

public:
    Trie()
    {

        isEnd = false;

        memset(next, 0, sizeof(next));
    }

    void insert(string word)
    {

        Trie *node = this;

        for (char c : word)
        {

            if (node->next[c - 'a'] == NULL)
            {

                node->next[c - 'a'] = new Trie();
            }

            node = node->next[c - 'a'];
        }

        node->isEnd = true;
    }

    bool search(string word)
    {

        Trie *node = this;

        for (char c : word)
        {

            node = node->next[c - 'a'];

            if (node == NULL)
            {

                return false;
            }
        }

        return node->isEnd;
    }

    bool startsWith(string prefix)
    {

        Trie *node = this;

        for (char c : prefix)
        {

            node = node->next[c - 'a'];

            if (node == NULL)
            {

                return false;
            }
        }

        return true;
    }
};

// Function to run tests
void runTests() {
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

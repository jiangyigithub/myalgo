class Trie(object):
    N = 100009
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = [[0] * self.N for i in range(26)]
        self.count = [0] * self.N
        self.index = 0

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: None
        """
        p = 0
        for i in range(len(word)):
            u = ord(word[i]) - ord('a')
            if self.trie[u][p] == 0:
                self.index += 1
                self.trie[u][p] = self.index
            p = self.trie[u][p]
        self.count[p] += 1

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        p = 0
        for i in range(len(word)):
            u = ord(word[i]) - ord('a')
            if self.trie[u][p] == 0:
                return False
            p = self.trie[u][p]
        return self.count[p] != 0

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        p = 0
        for i in range(len(prefix)):
            u = ord(prefix[i]) - ord('a')
            if self.trie[u][p] == 0:
                return False
            p = self.trie[u][p]
        return True

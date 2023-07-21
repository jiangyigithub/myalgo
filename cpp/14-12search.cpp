#include "head.hpp"

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    int rows, cols;
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int k)
    {
        if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k])
            return false;
        if (k == word.size() - 1)
            return true;
        board[i][j] = '\0';
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
                   dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = word[k];
        return res;
    }
};

int main()
{
    vector<char> broad1 = {'A', 'B', 'C', 'E'};
    vector<char> broad2 = {'S', 'F', 'C', 'S'};
    vector<char> broad3 = {'A', 'D', 'E', 'F'};
    vector<vector<char>> broads;
    broads.push_back(broad1);
    broads.push_back(broad2);
    broads.push_back(broad3);

    string line = "ABCCED";
    bool ret = Solution().exist(broads, line);
    cout << ret << endl;

    return 0;
}
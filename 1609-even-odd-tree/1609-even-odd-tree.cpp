class Solution
{
    public:
        bool isEvenOddTree(TreeNode *root)
        {
            TreeNode *current = root;
            return dfs(current, 0);
        }

    private:
        vector<int> prev;
    bool dfs(TreeNode *current, size_t level)
    {
        if (current == nullptr)
        {
            return true;
        }

        if (current->val % 2 == level % 2)
        {
            return false;
        }

        prev.resize(max(prev.size(), level + 1));

        if (prev[level] != 0 &&
            ((level % 2 == 0 && current->val <= prev[level]) ||
                (level % 2 == 1 && current->val >= prev[level])))
        {
            return false;
        }

        prev[level] = current->val;

        return dfs(current->left, level + 1) && dfs(current->right, level + 1);
    }
};
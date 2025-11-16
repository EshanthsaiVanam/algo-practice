// Binary Tree Level Order Traversal.
//
// Given the root of a binary tree, return level-order traversal (BFS).
//
// Time: O(n)
// Space: O(n)

#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> out;
    if (!root) return out;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = static_cast<int>(q.size());
        std::vector<int> level;
        level.reserve(sz);
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        out.push_back(std::move(level));
    }
    return out;
}

int main() {
    // Build tree:    3
    //               / \
    //              9  20
    //                /  \
    //               15   7
    TreeNode root(3);
    TreeNode l(9);
    TreeNode r(20);
    TreeNode rl(15);
    TreeNode rr(7);
    root.left = &l;
    root.right = &r;
    r.left = &rl;
    r.right = &rr;

    auto result = levelOrder(&root);
    assert(result.size() == 3);
    assert(result[0] == std::vector<int>({3}));
    assert(result[1] == std::vector<int>({9, 20}));
    assert(result[2] == std::vector<int>({15, 7}));
    std::cout << "OK\n";
    return 0;
}

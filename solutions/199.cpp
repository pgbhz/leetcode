/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 right(right) {}
 * };

 Definitely recursion. Ok, not definitely, but maybe.
 Ok. If there are no nodes, on the same level, to the left of a node, we print
 that node. How do we check that? What if we do a level-traverse (whatever that
 means) and then we print the rightmost node? How would that work? A list of
 lists, print the .pop node of each list. Ok, level-order traversal can be
 mapped to BFS. Let's go.

 */
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {

        // my flawed human code
        // if (root == nullptr) {
        //     return std::vector<int> {};
        // }
        // std::unordered_map<int, std::vector<int>> levels;
        // // std::unordered_set<int> enqueued; // (node, level)
        // // IT IS A BIN TREE BRO, no cycles.
        // std::deque<std::pair<TreeNode*, int>> to_visit;

        // // enqueued.push_back(root.val); IT IS A BIN TREE BRO, no cycles.
        // to_visit.push_back(std::pair(root, 0));

        // while (!to_visit.empty()) {
        //     std::pair<TreeNode*, int> curr_node = to_visit.front();
        //     to_visit.pop_front();

        //     TreeNode* curr = curr_node.first;
        //     int level = curr_node.second;

        //     levels[level].push_back(curr->val);
        //     if (curr->left != nullptr) {
        //         to_visit.push_back(std::pair(curr->left, level + 1));
        //     }
        //     if (curr->right != nullptr) {
        //         to_visit.push_back(std::pair(curr->right, level + 1));
        //     }
        // }

        // std::vector<int> result;
        // for (const auto& pair : levels) {
        //     int rightmost = pair.second.back();
        //     result.push_back(rightmost);
        // }
        // std::reverse(result.begin(), result.end());
        // return result;

        // gift of the computer god
        std::vector<int> result;
        if (root == nullptr) {
            return result;
        }

        std::deque<TreeNode*> q;
        q.push_back(root);

        while (!q.empty()) {
            int level_size = q.size();
            for (int i = 0; i < level_size; ++i) {
                TreeNode* curr = q.front();
                q.pop_front();

                if (i == level_size - 1) {
                    result.push_back(curr->val);
                }

                if (curr->left != nullptr) {
                    q.push_back(curr->left);
                }

                if (curr->right != nullptr) {
                    q.push_back(curr->right);
                }
            }
        }
        return result;
    }
};

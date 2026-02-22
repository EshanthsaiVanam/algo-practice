/*
 * Binary Tree Level Order Traversal.
 *
 * BFS by level using a queue.
 *
 * Time: O(n)
 * Space: O(n)
 */

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class BinaryTreeLevelOrder {

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int v) {
            this.val = v;
        }
    }

    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> out = new ArrayList<>();
        if (root == null) {
            return out;
        }
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> level = new ArrayList<>(size);
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                level.add(node.val);
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }
            out.add(level);
        }
        return out;
    }

    public static void main(String[] args) {
        // Tree:    3
        //         / \
        //        9  20
        //          /  \
        //         15   7
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        List<List<Integer>> result = levelOrder(root);
        assert result.size() == 3;
        assert result.get(0).size() == 1 && result.get(0).get(0) == 3;
        assert result.get(1).size() == 2 && result.get(1).get(0) == 9 && result.get(1).get(1) == 20;
        assert result.get(2).size() == 2 && result.get(2).get(0) == 15 && result.get(2).get(1) == 7;
        System.out.println("OK");
    }
}

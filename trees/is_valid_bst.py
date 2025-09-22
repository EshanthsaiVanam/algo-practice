"""Validate Binary Search Tree.

Time: O(n)
Space: O(h)
"""

from dataclasses import dataclass


@dataclass
class TreeNode:
    val: int
    left: "TreeNode | None" = None
    right: "TreeNode | None" = None


def is_valid_bst(root, low=float("-inf"), high=float("inf")) -> bool:
    if not root:
        return True
    if not (low < root.val < high):
        return False
    return (is_valid_bst(root.left, low, root.val) and
            is_valid_bst(root.right, root.val, high))

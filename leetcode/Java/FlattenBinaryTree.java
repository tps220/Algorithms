import java.util.*;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { this -> val = x; }
}

class Solution {
	public void flatten(TreeNode root) {
		root = flatten(root, null);
	}
	public TreeNode flatten(TreeNode root, TreeNode prev) {
		if (root == null) {
			return prev;
		}
		prev = flatten(root.right, prev);
		prev = flatten(root.left, prev);
		root.right = prev;
		root.left = null;
		prev = root;
		return prev;
	}
}
import java.util.*;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int val) { this.val = val; }
}

class Solution {
	public List<Integer> inorderTraversal(TreeNode root) {
		List<Integer> res = new ArrayList<>();
		Stack<TreeNode> stack = new Stack<>();
		TreeNode runner = root;
		while (runner != null || !stack.empty()) {
			while (runner != null) {
				stack.push(runner);
				runner = runner.left;
			}
			runner = stack.pop();
			res.add(runner.val);
			runner = runner.right;
		}
		return res;
	}
	public List<Integer> inorderTraversalRecursive(TreeNode root) {
		List<Integer> res = new ArrayList<>();
		inorderTraversal(root, res);
		return res;
	}
	private void inorderTraversal(TreeNode root, List<Integer> res) {
		if (root == null) {
			return;
		}
		inorderTraversal(root.left, res);
		res.add(root.val);
		inorderTraversal(root.right, res);
	}
}
import java.io;

public class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;
  TreeNode(int x) {
    this.val = x;
    this.left = null;
    this.right = null;
  }
}

public class Solution {
  public int pathSum(TreeNode root, int sum) {
    if (root == null) {
      return 0;
    }
    return pathSumHelper(root, sum) + pathSum(root.left, sum) + pathSum(root.right, sum);
  }
  private int pathSumHelper(TreeNode root, int sum) {
    if (root == null) {
      return 0;
    }
    return pathSumHelper(root.left, sum - root.val) + pathSumHelper(root.right, sum - root.val) + (sum == root.val ? 1 : 0);
  }
}

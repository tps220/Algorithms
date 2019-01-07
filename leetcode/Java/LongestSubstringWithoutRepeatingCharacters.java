class Solution {
	public int lengthOfLongestSubstring(String s) {
		int retval = 0;
    	int[] map = new int[256];
    	for (int i = 0, start = 0; i < s.length(); i++) {
    		char ch = s.charAt(i);
    		start = max(start, map[ch]);
    		retval = max(retval, i - start + 1);
    		map[ch] = i + 1;
    	}
    	return retval;
	}

	private int max(int a, int b) {
		return (a > b) ? a : b;
	}
}
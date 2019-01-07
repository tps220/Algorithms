import java.util.*;
import java.io.*;

class Solution {
	public List<Integer> findAnagrams(String s, String p) {
		if (s.length() < p.length() || s.length() == 0 || p.length() == 0) {
			return new ArrayList<Integer>();
		}
		//create map
		List<Integer> retval = new ArrayList<Integer>();
		int[] map = new int[128];
		for (char c : p.toCharArray()) {
			map[c]++;
		}
		//handle initial window
		int diff = p.length();
		for (int i = 0; i < p.length(); i++) {
			char c = s.charAt(i);
			map[c]--;
			if (map[c] >= 0) {
				diff--;
			}
		}
		if (diff == 0) {
			retval.add(0);
		}
		
		//handle sliding window
		int start = 0;
		for (int i = p.length(); i < s.length(); i++) {
			char bound = s.charAt(start);
			if (map[bound] >= 0) {
				diff++;
			}
			map[bound]++;
			start++;

			bound = s.charAt(i);
			map[bound]--;
			if (map[bound] >= 0) {
				diff--;
			}
			if (diff == 0) {
				retval.add(start);
			}
		}
		return retval;
	}
}
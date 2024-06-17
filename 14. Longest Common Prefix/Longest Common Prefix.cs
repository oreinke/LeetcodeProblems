public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        String prefix = strs[0];

        foreach (String str in strs)
        {
            if (str.Length < prefix.Length)
                prefix = prefix.Substring(0, str.Length);
            while (!prefix.Equals(str.Substring(0, prefix.Length)))
                prefix = prefix.Substring(0, prefix.Length - 1);            
        } 
        return prefix;
    }
}

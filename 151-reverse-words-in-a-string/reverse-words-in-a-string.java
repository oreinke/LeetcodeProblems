class Solution {
    public String reverseWords(String s) {
        String newStr = "";
        while (s.charAt(s.length() - 1) == ' ')
        {
            s = s.substring(0, s.length() - 1);
        }
        
        while (s.charAt(0) == ' ')
        {
            s = s.substring(1, s.length());
        }


        int lastIndex = s.length();
        for (int i = (s.length() - 1); i > -1; i--)
        {
            if (s.charAt(i) == ' ' && s.substring(i + 1, lastIndex).trim().length() > 0)
            {
                newStr += s.substring(i + 1, lastIndex).trim() + " ";
                lastIndex = i;
            }


        }       
        if (lastIndex != 0)
            newStr += s.substring(0, lastIndex).trim();
        
        return newStr;
    }
}
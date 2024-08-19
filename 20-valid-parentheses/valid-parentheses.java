class Solution {
    public boolean isValid(String s) {
        Stack<Character> lastOpen = new Stack<Character>();
        char[] chars = s.toCharArray();

        for (char chr : chars)
        {
            String str = "";
            if (lastOpen.empty())
                str = "None";
            else
                str += lastOpen.peek();
            if (chr == '(')
            {
                lastOpen.push('(');
            }
            else if (chr == '[')
            {
                lastOpen.push('[');
            }
            else if (chr == '{')
            {
                lastOpen.push('{');
            }
            else if (chr == ')')
            {
                if (lastOpen.empty() || lastOpen.pop() != '(')
                {
                    return false;
                }
            }
            else if (chr == ']')
            {
                if (lastOpen.empty() || lastOpen.pop() != '[')
                    return false;
            }
            else if (chr == '}')
            {
                if (lastOpen.empty() || lastOpen.pop() != '{')
                    return false;
            }
        }
        String str = "";
        if (lastOpen.empty())
            str = "None";
        else
            str += lastOpen.peek();
        if (lastOpen.empty())
            return true;
        else
            return false;
    }
}
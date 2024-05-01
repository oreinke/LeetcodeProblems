class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        ArrayList<String> result = new ArrayList<String>();

        String str = words[0];
        int numWords = 1;
        for (int i = 1; i < words.length; i++)
        {
            if (str.length() + words[i].length() < maxWidth)
            {
                str += " " + words[i];
                numWords++;
            }
            else
            {
                if (numWords == 1)
                {
                    while (str.length() < maxWidth)
                        str += " ";
                }
                else
                {
                    int numSpaces = (maxWidth - str.length()) / (numWords - 1); 
                    int numExtra = (maxWidth - str.length()) % (numWords - 1); 
                    String pad = "";
                    String extraPad = "";

                    while (pad.length() < numSpaces)
                        pad += " ";
                    extraPad = pad + " ";

                    for (int j = 0; j < maxWidth; j++)
                    {
                        if (str.charAt(j) == ' ')
                        {
                            if (numExtra > 0)
                            {
                                str = str.substring(0, j + 1) + extraPad + str.substring(j + 1);
                                numExtra--;
                                j += extraPad.length();
                            } 
                            else
                            {
                                str = str.substring(0, j + 1) + pad + str.substring(j + 1);
                                j += pad.length();
                            }
                        }
                    }
                }
                result.add(str);
                str = words[i];
                numWords = 1;
            }
        }

        while (str.length() < maxWidth)
            str += " ";
        result.add(str);
        return result;
    }
}
class Solution {
    public String intToRoman(int num) {
        String romanNum = "";
        while (num != 0)
        {
            if (num - 1000 >= 0)
            {
                num -= 1000;
                romanNum += "M";
            }
            else if (num - 900 >= 0)
            {
                num -= 900;
                romanNum += "CM";
            }
            else if (num - 500 >= 0)
            {
                num -= 500;
                romanNum += "D";
            }
            else if (num - 400 >= 0)
            {
                num -= 400;
                romanNum += "CD";
            }
            else if (num - 100 >= 0)
            {
                num -= 100;
                romanNum += "C";
            }
            else if (num - 90 >= 0)
            {
                num -= 90;
                romanNum += "XC";
            }
            else if (num - 50 >= 0)
            {
                num -= 50;
                romanNum += "L";
            }
            else if (num - 40 >= 0)
            {
                num -= 40;
                romanNum += "XL";
            }
            else if (num - 10 >= 0)
            {
                num -= 10;
                romanNum += "X";
            }
            else if (num - 9 >= 0)
            {
                num -= 9;
                romanNum += "IX";
            }
            else if (num - 5 >= 0)
            {
                num -= 5;
                romanNum += "V";
            }
            else if (num - 4 >= 0)
            {
                num -= 4;
                romanNum += "IV";
            }
            else
            {
                num -= 1;
                romanNum+= "I";
            }
        }
        return romanNum;
    }
}
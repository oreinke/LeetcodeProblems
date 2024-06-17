public class Solution {
    public bool IsPalindrome(int x) {
        if (x < 0)
            return false;
        
        int count = 0;
        int num = x;
        while (num != 0)
        {
            count++;
            num /= 10;
        }
        
        while (count > 1)
        {
            // Console.WriteLine($"{count}, First number: {x / ((int) Math.Pow(10, count - 1))}, Second number: {x % 10}");

            if (x / ((int) Math.Pow(10, count - 1)) != x % 10)
                return false;
            
            x = (x % ((int)Math.Pow(10, count - 1)));
            // Console.WriteLine(x);
            x /= 10;
            // Console.WriteLine(x);
            count -= 2;
        }
        return true;
    }
}

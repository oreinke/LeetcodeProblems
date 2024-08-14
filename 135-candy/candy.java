class Solution {
    public int candy(int[] ratings) {
        int total = 0;
        int[] candies = new int[ratings.length];

        if (ratings.length == 1){
            return 1;
        }

        for (int i = 0; i < ratings.length; i++)
        {
            total += candyRecursion(i, ratings, candies);
        }

        return total;
    }

    int candyRecursion(int step, int[] ratings, int[] candies)
    {
        if (candies[step] > 0)
            return candies[step];

        if (step == 0)
        {
            if (ratings[step] <= ratings[step + 1])
            {
                candies[step] = 1;
            }
            else
            {
                candies[step] = candyRecursion(step + 1, ratings, candies) + 1;
            }

            return candies[step];
        }

        if (step == candies.length - 1)
        {
            if (ratings[step] <= ratings[step - 1])
            {
                candies[step] = 1;
            }
            else
            {
                candies[step] = candyRecursion(step - 1, ratings, candies) + 1;
            }

            return candies[step];
        }
        
        // cur child is lesser / = than left child
        if (ratings[step] <= ratings[step - 1])
        {
            // and cur child lesser / = to right child
            if (ratings[step] <= ratings[step + 1])
            {
                candies[step] = 1;
                return candies[step];
            }
            // and cur child greater than right child
            else
            {
                candies[step] = candyRecursion(step + 1, ratings, candies) + 1;
                return candies[step];
            }
        }
        // cur child greater than left child
        else 
        {
            // and cur child lesser / = to right child
            if (ratings[step] <= ratings[step + 1])
            {
                candies[step] = candyRecursion(step - 1, ratings, candies) + 1;
                return candies[step];
            }
            // cur child defeats all challengers.
            else
            {
                candies[step] = Math.max(candyRecursion(step - 1, ratings, candies),
                                         candyRecursion(step + 1, ratings, candies)) + 1;
                return candies[step];
            }
        }
        
    }
}
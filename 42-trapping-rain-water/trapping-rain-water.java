class Solution {
    public int trap(int[] height) {
        int[] maxLeft = new int[height.length];
        int[] maxRight = new int[height.length];
        maxLeft[0] = height[0];
        maxRight[height.length - 1] = height[height.length - 1];
        int total = 0;

        for (int i = 1; i < height.length - 1; i++)
            maxLeft[i] = (height [i] < maxLeft[i - 1]) ? maxLeft[i - 1] : height[i];
        
        for (int i = height.length - 2; i > 0; i--)
            maxRight[i] = (height[i] < maxRight[i + 1]) ? maxRight[i + 1] : height[i];

        for (int i = 1; i < height.length - 1; i++)
        {
            int heightAtI = (Math.min(maxLeft[i], maxRight[i]) - height[i]) > 0 ? Math.min(maxLeft[i], maxRight[i]) - height[i] : 0;
            total += heightAtI;
            System.out.println("water height at " + i + " is " + heightAtI);
        }

        

        return total;
    }
}
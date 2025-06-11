public class Solution {
    public int MinCost(string colors, int[] neededTime) {
        if(colors == "") return 0;

        int time = 0;
        int maxTime = neededTime[0];
        for(int i = 1;i < colors.Length; i++)
        {
            if(colors[i - 1] == colors[i])
            {
                time += Math.Min(maxTime,neededTime[i]);
                maxTime = Math.Max(maxTime,neededTime[i]);
            }
            else{
                maxTime = neededTime[i];
            }
        }

        return time;
    }
}
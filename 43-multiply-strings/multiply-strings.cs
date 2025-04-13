public class Solution {
    public string Multiply(string num1, string num2) {
        int n = num1.Length, m = num2.Length;
        int[] result = new int[n + m];

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        for (int i = result.Length - 1; i > 0; i--)
        {
            result[i - 1] += result[i] / 10;
            result[i] = result[i] % 10;
        }

        StringBuilder sb = new StringBuilder();
        bool leadingZero = true;

        foreach (int digit in result)
        {
            if (leadingZero && digit == 0)
            {
                continue;
            }
            leadingZero = false;
            sb.Append(digit);
        }

        string finalResult = sb.Length == 0 ? "0" : sb.ToString();

        return finalResult;
    }
}
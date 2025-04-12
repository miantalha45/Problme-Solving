public class Solution {
    public int MyAtoi(string s) {

         if (string.IsNullOrEmpty(s))
            return 0;

        s = s.Trim();
        if (s.Length == 0)
            return 0;
        
        int sign = 1, i = 0, res = 0, n = s.Length;


        if(s[0] == '+' || s[0] == '-')
        {
            sign = (s[0] == '-') ? -1 : 1;
            i++;
        }

        while(i < n && Char.IsDigit(s[i]))
        {
            int digit = s[i] - '0';
            if (res > (int.MaxValue - digit) / 10) {
              return sign == 1 ? int.MaxValue : int.MinValue;
            }
            res = res * 10 + digit;
            i++;
        }
        return res * sign;
    }
}
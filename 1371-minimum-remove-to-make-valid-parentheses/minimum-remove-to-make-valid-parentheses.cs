public class Solution {
    public string MinRemoveToMakeValid(string s) {
        Stack<int> stack = new Stack<int>();
        HashSet<int> toRemove = new HashSet<int>();

        for(int i = 0; i < s.Length; i++)
        {
            if(s[i] == '(')
            {
                stack.Push(i);
            }
            else if(s[i] == ')')
            {
                if(stack.Count > 0)
                {
                    stack.Pop();
                }
                else{
                    toRemove.Add(i);
                }
            }
        }

        while(stack.Count > 0)
        {
            toRemove.Add(stack.Pop());
        }

        StringBuilder result = new StringBuilder();
        for(int i = 0; i < s.Length; i++)
        {
            if(!toRemove.Contains(i))
            {
                result.Append(s[i]);
            }
        }

        return result.ToString();

    }
}
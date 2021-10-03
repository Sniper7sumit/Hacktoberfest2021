/*


            Hey there This is Om Duragkar wanted to chare a problem optimized solution to duplicate bracket
1. You are given a string exp representing an expression.
2. Assume that the expression is balanced  i.e. the opening and closing brackets match with each other.
3. But, some of the pair of brackets maybe extra/needless. 
4. You are required to print true if you detect extra brackets and false otherwise.

e.g.
((a + b) + (c + d)) -> false
(a + b) + ((c + d)) -> true
 */

import java.io.*;
import java.util.*;

public class duplicatebracket{

    public static void main(String[] args) throws Exception {
        Stack<Character> s=new Stack<Character>();
        Scanner sc= new Scanner(System.in);
        String str=sc.nextLine();
        s.push(str.charAt(0));
        int i=1;
        while(i<str.length())
        {
            if(str.charAt(i) ==')')
            {
                if(s.peek()=='(')
                {
                    System.out.println(true);
                    return;
                }
                else
                {
                    while(s.peek()!='(')
                    {
                        s.pop();
                    }
                    s.pop();
                }
            }
            else
            {
                s.push(str.charAt(i));
            }
            i++;
        }
        System.out.print(false);
    }

}
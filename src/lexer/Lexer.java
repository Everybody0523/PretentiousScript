package lexer;

import com.sun.deploy.util.ArrayUtil;
import com.sun.tools.javac.util.ArrayUtils;

import java.util.ArrayList;
import java.util.regex.*;
import java.util.Arrays;
import java.util.List;

public class Lexer
{
    public static final String[] COND_KEYWORDS = {"Suppose", "Alternatively", "Otherwise"};
    public static final String[] OPERATORS = {"=", "+", "-"};
    public static final String[] PRIMITIVES = {"Member_of_Z", "Character"};
    public static final String[] BREAK_STATEMENTS = {"DELIMIT", "Cease_pondering_of_possibilities"};
    public static final String[] THINGS = {"Function", "Class"};
    public static final String[] COMMENT = {"#"};


    public static List<Token> scanLine(String line)
    {
        //Handle Comments
        if (line.charAt(0) == '#')
        {
            Token tk = new Token("COMMENT", line.substring(1, (line.length())));
            List<Token> output = new ArrayList<>();
            output.add(tk);
            return output;

        }
        else
        {
            //Everything else
            String[] components = line.split(" ");
            List<Token> output = new ArrayList<>();
            for (String component : components){
                //Checking for primitive
                if (Helpers.containsInArray(PRIMITIVES, component)){
                    Token tk = new Token("PRIMITIVE", component);
                    output.add(tk);
                }

                else if (component.matches("(\\w)*")){
                    Token tk = new Token("IDENTIFIER", component);
                    output.add(tk);
                }

                else if (Helpers.containsInArray(OPERATORS, component)){
                    Token tk = new Token("OPERATOR", component);
                    output.add(tk);
                }



            }
            return output;

        }
    }

    public static void main(String[] args)
    {
        List<Token> test = scanLine("Member_of_Z x = 69");
        for (Token t : test){
            System.out.println(t);
        }
    }


}


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
    public static final String[] COMMENT = {"Contemplation:"};


    /**
     * Takes in one line of PretentiousScript(tm) code and returns a list of tokens.
     * Precondition: line cannot have trailing whitespace
     *
     * @param line: This is the line of PretentiousScript code that is to be converted into Tokens.
     * @return Token: A list of Tokens representing the line of PretentiousScript code.
     *
     */
    public static List<Token> scanLine(String line)
    {
        //Handle Comments
        String[] components = line.split(" ");
        if (components[0].equals("Contemplation:"))
        {
            //Token tk = new Token("COMMENT", line.substring(1, (line.length())));
            StringBuilder sb = new StringBuilder();
            for (int i = 1; i < components.length; i++){
                sb.append(components[i]);
                sb.append(" ");
            }
            Token tk = new Token("COMMENT", sb.toString());
            List<Token> output = new ArrayList<>();
            output.add(tk);
            return output;

        }
        else
        {
            //Everything else
            List<Token> output = new ArrayList<>();
            for (String component : components){
                //Checking for primitive
                if (Helpers.containsInArray(PRIMITIVES, component)){
                    Token tk = new Token("PRIMITIVE", component);
                    output.add(tk);
                }

                else if (component.matches("(\\w)*") && !(component.matches("(\\d)*"))){
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
        List<Token> test = scanLine("Contemplation: Asic is a meanie face");
        for (Token t : test){
            System.out.println(t);
        }
    }
}


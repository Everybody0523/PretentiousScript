package lexer;

import java.util.regex;
import java.lang.StringBuilder;

public class Lexer
{
    public static final String[] COND_KEYWORDS = {"Suppose", "Alternatively", "Otherwise"};
    public static final String[] OPERATORS = {"=", "+", "-"};
    public static final String[] PRIMITIVES = {"Member_of_Z", "Character"};
    public static final String[] BREAK_STATEMENTS = {";", "Cease_pondering_of_possibilities"};
    public static final Stirng[] THINGS = {"Function", "Class"};
    public static final String[] COMMENT = {"#"};


    public static Token[] scanLine(String line)
    {
        //Handle Comments
        if (line.charAt(0) == '#')
        {
            Token tk = new Token();
            tk.setType("COMMENT");
            tk.setValue(line.substring(1, (line.length())));
            Token[] output = new Token[1];
            output[0] = tk;
            return output;
        }
        else
        {
            //Everything else
            //String[] components = line.split(" ");
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < line.length(); i++)
            {

            }

        }

        return null;
    }

    public static void main(String[] args)
    {
        Token[] test = scanLine("#meep");
        System.out.println(test[0].getValue());
    }


}


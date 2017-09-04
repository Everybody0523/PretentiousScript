package lexer;

import java.util.Objects;

public class Token {
    private String Type;
    private String value;

    public static final String[] COND_KEYWORDS = {"Suppose", "Alternatively", "Otherwise"};
    public static final String[] OPERATORS = {"=", "+", "-"};
    public static final String[] PRIMITIVES = {"Member_of_Z", "Character"};
    public static final String[] BREAK_STATEMENTS = {"DELIMIT", "Cease_pondering_of_possibilities"};
    public static final String[] THINGS = {"Function", "Class"};
    public static final String[] COMMENT = {"Contemplation:"};


    public Token(String Type, String value){
        this.Type = Type;
        this.value = value;
    }

    @Override
    public String toString() {
        return "Token{" +
                "Type='" + Type + '\'' +
                ", value='" + value + '\'' +
                '}';
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public String getType() {

        return Type;
    }

    public void setType(String type) {
        Type = type;
    }

    @Override
    public int hashCode(){
        return Objects.hash(this.Type, this.value);
    }

    @Override
    public boolean equals(Object other){
        if (this == other){ //Always return true if we compare the same thing
            return true;
        }

        else if (other == null){ //This isn't null
            return false;
        }

        else if (getClass() != other.getClass()){
            return false;
        }

        else{
            Token otherToken = (Token) other;
            return (this.getType().equals(otherToken.getType()) && this.getValue().equals(otherToken.getValue()));
        }

    }
}


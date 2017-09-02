package lexer;

public class Token {
    private String Type;
    private String value;

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


}


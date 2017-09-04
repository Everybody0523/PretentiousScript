package lexer;

public class TokenNode {
    private Token value;
    private TokenNode next;

    public TokenNode(Token value, TokenNode next) {
        this.value = value;
        this.next = next;
    }

    public Token getValue() {
        return value;
    }

    public void setValue(Token value) {
        this.value = value;
    }

    public TokenNode getNext() {
        return next;
    }

    public void setNext(TokenNode next) {
        this.next = next;
    }
}

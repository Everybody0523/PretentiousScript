package test;

import static org.junit.Assert.*;

import lexer.Token;
import lexer.Lexer;
import org.junit.Test;

import java.util.List;
import java.util.ArrayList;


public class LexerTest {

    @org.junit.Before
    public void setUp() throws Exception
    {
    }

    @Test
    public void testCommentTextOnly()
    {
        List<Token> testComment = Lexer.scanLine("Contemplation: A comment");
        ArrayList<Token> tkArrayList = new ArrayList<Token>();
        tkArrayList.add(new Token("COMMENT", "A comment"));
        assertEquals(tkArrayList, testComment);
    }

    @Test
    public void testCommentNumbers()
    {
        List<Token> testComment = Lexer.scanLine("Contemplation: 12345");
        ArrayList<Token> tkArrayList = new ArrayList<Token>();
        tkArrayList.add(new Token("COMMENT", "12345"));
        assertEquals(tkArrayList, testComment);
    }

    @Test
    public void testCommentEmpty()
    {
        List<Token> testComment = Lexer.scanLine("Contemplation:");
        ArrayList<Token> tkArrayList = new ArrayList<Token>();
        tkArrayList.add(new Token("COMMENT", ""));
        assertEquals(tkArrayList, testComment);
    }

    @Test
    public void testCommentOnlyWhitespace()
    {
        List<Token> testComment = Lexer.scanLine("Contemplation:                           ");
        ArrayList<Token> tkArrayList = new ArrayList<Token>();
        tkArrayList.add(new Token("COMMENT", "                          "));
        assertEquals(tkArrayList, testComment);
    }


    @Test
    public void testCommentLettersAndNumbers()
    {
        List<Token> testComment = Lexer.scanLine("Contemplation: Meep 343");
        ArrayList<Token> tkArrayList = new ArrayList<Token>();
        tkArrayList.add(new Token("COMMENT", "Meep 343"));
        assertEquals(tkArrayList, testComment);
    }
}
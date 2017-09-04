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
    public void testComment1()
    {
        List<Token> testComment = Lexer.scanLine("Contemplation: A comment");
        ArrayList<Token> tkArrayList = new ArrayList<Token>();
        tkArrayList.add(new Token("COMMENT", "A comment"));
        assertEquals(tkArrayList, testComment);
    }

    @Test
    public void testComment2()
    {
        List<Token> testComment = Lexer.scanLine("Contemplation: 12345");
        ArrayList<Token> tkArrayList = new ArrayList<Token>();
        tkArrayList.add(new Token("COMMENT", "12345"));
        assertEquals(tkArrayList, testComment);
    }

    @org.junit.After
    public void tearDown() throws Exception
    {
    }

}
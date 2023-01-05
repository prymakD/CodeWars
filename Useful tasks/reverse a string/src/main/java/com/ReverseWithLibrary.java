/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com;

/**
 *
 * @author prima
 */
public class ReverseWithLibrary {
    public static String reverseString(String in) {
        char ch[] = in.toCharArray();
        String out = "";
        
        for (int start = ch.length - 1; start >= 0; start--) {
            out += ch[start];
        }
        
        return "Result is: " + out;
    }
    
    public static String rvrsBuilder(String in) {
        StringBuilder line = new StringBuilder(in);
        
        return line.reverse().toString();
    }
}

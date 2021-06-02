import java.util.*;

public class LineNumbering {
    public static List<String> number(List<String> lines) {
        List<String> newLine = new ArrayList<String>();
        int k = 1;
        for (String i : lines) {
            newLine.add((k++) + ": " + i);
        }
        return newLine;
    }
}
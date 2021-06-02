import org.junit.Test;
import java.util.*;
import java.util.stream.*;
import static org.junit.Assert.assertEquals;

public class LineNumberingTest {
    @Test
    public void basicTests() {
        assertEquals(Arrays.asList(), LineNumbering.number(Arrays.asList()));
        assertEquals(Arrays.asList("1: a", "2: b", "3: c"), LineNumbering.number(Arrays.asList("a", "b", "c")));
        assertEquals(Arrays.asList("1: ", "2: ", "3: ", "4: ", "5: "), LineNumbering.number(Arrays.asList("", "", "", "", "")));
    }

    private List<String> sol(List<String> lines) {
        return IntStream.range(0, lines.size()).mapToObj(i -> (i + 1) + ": " + lines.get(i)).collect(Collectors.toList());
    }

    @Test
    public void randomTests() {
        Random r = new Random();
        for (int i = 0; i < 100; i++) {
            List<String> l = IntStream.range(0, r.nextInt(20)).mapToObj(k -> {
                StringBuilder s = new StringBuilder();
                for (int j = 0, len = r.nextInt(10); j < len; j++)
                    s.append("abcdefghijklmnopqrstuvwxyz".charAt(r.nextInt(26)));
                return s.toString();
            }).collect(Collectors.toList());
            assertEquals(sol(l), LineNumbering.number(l));
        }
    }
}
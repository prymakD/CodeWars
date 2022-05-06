import java.util.Arrays;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

    public static void main(String[] args) {
        String step0Reg = "^0+$";
        Pattern zeroS = Pattern.compile(step0Reg);

        String step1Reg = "^((1+)|(01+))$";
        Pattern firstS = Pattern.compile(step1Reg);

        String step2Reg = "^10+$";
        Pattern secondS = Pattern.compile(step2Reg);


        Scanner scanner = new Scanner(System.in);
        int numOfSets = scanner.nextInt();

        String[] pages = new String[numOfSets];

        for (int i = 0; i < numOfSets; i++) {
            int numOfCards = scanner.nextInt();
            StringBuilder rotationNum = new StringBuilder(numOfCards);

            for (int j = 0; j < numOfCards; j++) {
                rotationNum.append(scanner.nextInt());
            }

            Matcher match0 = zeroS.matcher(rotationNum);
            Matcher match1 = firstS.matcher(rotationNum);
            Matcher match2 = secondS.matcher(rotationNum);

            if (match1.matches()) {
                pages[i] = "1";
            } else if (match2.matches()) {
                pages[i] = "2";
            } else if (match0.matches()) {
                pages[i] = "0";
            } else {
                pages[i] = "NIGDY";
            }
        }

        Arrays.stream(pages).forEach(System.out::println);
    }
}
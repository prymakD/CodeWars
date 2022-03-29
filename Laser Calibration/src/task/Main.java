package task;

import java.lang.Math;

import java.util.Locale;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
        int numOfSets = scanner.nextInt();
        for (int i = 0; i < numOfSets; i++) {
            double firstNum = scanner.nextDouble();
            double secondNum = scanner.nextDouble();
            double numOfRefl = Math.floor((180 - 2 * secondNum) / firstNum);
            System.out.println(numOfRefl);
        }
    }
}
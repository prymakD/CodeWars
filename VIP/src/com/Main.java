package com;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numOfSets = scanner.nextInt();

        for (int a = 0; a < numOfSets; a++) {
            int numOfPeople = scanner.nextInt();
            int matrix[][] = new int[numOfPeople][numOfPeople];

            for (int row = 0; row < numOfPeople; row++) {
                    String line = scanner.nextLine();
                    String[] parts = line.split(" ");

                for (int col = 0; col < numOfPeople; col++) {
                    matrix[row][col] = Integer.valueOf(parts[col]);
                }
            }

            for (int row = 0; row < numOfPeople; row++) {
                int ones = 0;
                for (int col = 0; col < numOfPeople; col++) {
                    if (matrix[row][col] == 1) ones++;
                }

                if (ones == 1) System.out.println(row + 1);
            }
        }
    }

}


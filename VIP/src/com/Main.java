package com;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numOfSets = Integer.parseInt(scanner.nextLine());
        for (int a = 0; a < 2; a++) {
            int numOfPeople = Integer.parseInt(scanner.nextLine());
            int matrix[][] = new int[numOfPeople][numOfPeople];
            for (int i=0; i<numOfPeople; i++) {
                for (int j=0; j<numOfPeople; j++) {
                    matrix[i][j] = Integer.parseInt(scanner.nextLine());
                }
            }
        }

    }
}

package com;

public class Main {
    public static void main(String[] args) {
        System.out.println(solution(1, 6));
    }

    public static int solution(int start, int finish)
    {
        int count = 0;
        int i = start;

        while (i != finish) {

            if (i + 3 <= finish) {
                i += 3;
                count++;
            }else {
                i++;
                count++;
            }

        }
        return count;
    }
}

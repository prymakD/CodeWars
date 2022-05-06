import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.Math;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int numOfSets = Integer.parseInt(reader.readLine());

        for (int step = 0; step < numOfSets; step++) {
            int numOfCards = Integer.parseInt(reader.readLine());
            int cards[] = new int[numOfCards];

            String line = reader.readLine();
            String[] strs = line.trim().split(" ");
            for (int i = 0; i < strs.length; i++) {
                cards[i] = Integer.parseInt(strs[i]);
            }
            System.out.println(Math.abs(LongestIncreasingSubsequenceLength(cards, numOfCards) - numOfCards));
        }

    }

    public static int CeilIndex(int A[], int l, int r, int key) {
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (A[m] >= key)
                r = m;
            else
                l = m;
        }

        return r;
    }

    public static int LongestIncreasingSubsequenceLength(int A[], int size) {

        int[] tailTable = new int[size];
        int len; // always points empty slot

        tailTable[0] = A[0];
        len = 1;
        for (int i = 1; i < size; i++) {
            if (A[i] < tailTable[0])
                // new smallest value
                tailTable[0] = A[i];

            else if (A[i] > tailTable[len - 1])
                tailTable[len++] = A[i];

            else
                tailTable[CeilIndex(tailTable, -1, len - 1, A[i])] = A[i];
        }

        return len;
    }
}

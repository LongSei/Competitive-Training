import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'plusMinus' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void plusMinus(List<Integer> arr) {
    // Write your code here
        int positive = 0;
        int zero = 0;
        int negative = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i) < 0) {
                negative += 1;
            }
            if (arr.get(i) == 0) {
                zero += 1;
            }
            if (arr.get(i) > 0) {
                positive += 1;
            }
        }
        
        String pos = String.format("%.6f", (float)positive / arr.size());
        String neg = String.format("%.6f", (float)negative / arr.size());
        String zeo = String.format("%.6f", (float)zero / arr.size());
        
        System.out.println(pos + "\n" + neg + "\n" + zeo);
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        Result.plusMinus(arr);

        bufferedReader.close();
    }
}

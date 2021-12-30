import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = 1;
        String line;

        while(in.hasNext()){
            line = in.nextLine();
            System.out.printf("%d %s%n", num++, line);
        }
        in.close();
    }
}
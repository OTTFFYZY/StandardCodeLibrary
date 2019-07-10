import java.util.*;
import java.io.*;

public class JavaIO {
    public static void main(String[] args) {
        Scanner jin = new Scanner(new BufferedInPutStream(System.in));
        // Scanner jin = new Scanner(System.in);
        
        // jin.hasNextInt()
        // jin.hasNextLong()
        // jin.hasNextDouble()
        // jin.hasNextBoolean()
        // jin.hasNextLine()
        while(jin.hasNext()) {
            // int i = jin.nextInt();
            // int i = jin.nextInt(int radix)
            // long l = jin.nextLong();
            // double d = jin.nextDouble();
            // boolean b = jin.nextBoolean();
            // String s = jin.nextLine();
            // String s = jin.next(Pattern pattern)
            // String s = jin.next(String pattern)
            String s = jin.next();
        }
        

        // System.out.print()
        // System.out.println()
        // System.out.format()
        System.out.printf("%d %s\n", 233, "123");
    }
}
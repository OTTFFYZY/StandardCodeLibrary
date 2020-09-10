import java.util.*;

public class JavaHashMap {
    public static void main(String[] args) {
        HashMap<Integer,Integer> map = new HashMap<>();

        map.put(1, 1);

        System.out.println("map.get(2) " + map.get(2)); // null

        System.out.println("map.get(2) " + map.getOrDefault(2, 5)); // 5

        System.out.println("map.get(1) " + map.get(1)); // 1

        map.put(1, 3);

        System.out.println("map.get(1) " + map.get(1)); // 3

        HashMap<A,Integer> map2 = new HashMap<>();

        A objA = new A();
        objA.a = 1; objA.b = 2;

        map2.put(objA, 10);

        System.out.println("map2.get(objA) " + map2.get(objA)); // 10

        objA.a = 5;

        System.out.println("map2.get(objA) " + map2.get(objA)); // 10
    }
}

class A {
    int a, b;
}
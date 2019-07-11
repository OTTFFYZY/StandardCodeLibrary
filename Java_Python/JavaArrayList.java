import java.util.*;

public class JavaArrayList {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>(100);
        list.add(3);
        list.add(5);
        list.add(4);
        list.add(17);
        list.add(2);

        System.out.println("list.size() : " + list.size());

        System.out.println("\ntranversal list : ");
        for(int i = 0; i < list.size(); i++)
            System.out.print(list.get(i) + " ");

        System.out.println("\n\nshow list (toString) : \n" + list);

        Collections.sort(list);
        System.out.println("\nsorted list : \n" + list);

        list.clear();
        System.out.println("\nclear list : \n" + list);

        System.out.println("\n\n======================\n");

        // add(index, element)
        for(int i = 0; i < 10; i++)
            list.add(0, i);
        System.out.println("list : " + list);

        //remove(Object)
        //remove(index)
        list.remove(1);                  // remove element of index 1
        list.remove(Integer.valueOf(3)); // remove Integer(3)
        System.out.println("\nafter remove list.size : " + list.size()
            + "\n list : " + list);
    }
}
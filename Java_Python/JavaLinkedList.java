import java.util.LinkedList;

public class JavaLinkedList {
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        list.addFirst(3);
        list.addFirst(2);
        list.addLast(4);
        list.addLast(5);
        list.add(6);
        System.out.println("org list : " + list);

        // pollFirst pollLast
        // getFirst getLast
        // peekFirst peekLast
        // size
        // push pop
    }
}
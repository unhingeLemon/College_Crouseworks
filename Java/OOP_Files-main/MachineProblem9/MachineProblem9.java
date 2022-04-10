import java.util.*;

public class MachineProblem9 {

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        Boolean loop = true;

        while (loop) {

            System.out.println("Select a collection: ");
            System.out.println("[1]: Array List ");
            System.out.println("[2]: Linked List ");
            System.out.println("[3]: Priority Queue");
            System.out.println("[4]: Exit");
            System.out.print("Choice: ");
            int choice = input.nextInt();

            switch (choice) {
                case 1:
                    ArrayList<String> list = new ArrayList<String>();// Creating arraylist

                    System.out.println("Adding 4 object in arraylist");
                    list.add("Mark");
                    list.add("Angelo");
                    list.add("Basas");
                    list.add("Capili");
                    // Traversing list through Iterator
                    Iterator listIterator = list.iterator();
                    while (listIterator.hasNext()) {
                        System.out.println(listIterator.next());
                    }

                    break;
                case 2:
                    LinkedList<String> al = new LinkedList<String>();

                    al.add("Mark");
                    al.add("Angelo");
                    al.add("Basas");
                    al.add("Capili");
                    System.out.println("4 elements added to the list");

                    Iterator<String> linkedListIterator = al.iterator();

                    // Traversing list through Iterator
                    while (linkedListIterator.hasNext()) {
                        System.out.println(linkedListIterator.next());
                    }

                    break;
                case 3:
                    PriorityQueue<String> queue = new PriorityQueue<String>();

                    queue.add("Mark");
                    queue.add("Angelo");
                    queue.add("Basas");
                    queue.add("Capili");

                    System.out.println("head:" + queue.peek());
                    System.out.println("Iterating the queue elements:");
                    Iterator itr = queue.iterator();
                    while (itr.hasNext()) {
                        System.out.println(itr.next());
                    }

                    queue.remove();

                    System.out.println("Removed head element: ");
                    Iterator<String> itr2 = queue.iterator();
                    while (itr2.hasNext()) {
                        System.out.println(itr2.next());
                    }

                    break;

                case 4:
                    loop = false;
                    break;
                default:
                    System.out.println("Invalid Choice!");
            }
        }

    }
}
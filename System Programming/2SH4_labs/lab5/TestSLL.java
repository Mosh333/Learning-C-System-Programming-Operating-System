package lab5_2sh4;

public class TestSLL {
    public static void main(String[] args)
    {
        //============================================================
        // Set Implemented via Singly Linked List
        //============================================================
        //------------------------------------------------------------
        // constructor
        //------------------------------------------------------------
        // test constructor1; invalid inputs
        int[] arr1 = {1,2,3,4,5,6,7};
        SLLSet list1 = new SLLSet(arr1);
        System.out.println("Test constructor1--simple valid inputs: (1,2,3)");
        System.out.println(list1.toString());
        System.out.println("The length of list1 is: "+list1.getSize());
        System.out.println("The memory address of list1 is " + list1.hashCode());

        SLLSet list2_copyOfList1 = list1.copy();
        System.out.println(list2_copyOfList1.toString());
        System.out.println("The length of list2_copyOfList1 is: "+list2_copyOfList1.getSize());
        System.out.println("The memory address of list2 is " + list2_copyOfList1.hashCode());
        // System.out.println();
        // System.out.println(a.getDim().toString());
        

        System.out.println("Is 5 in arr1 = {1,2,3,4,5,6,7}?: "+list1.isIn(5));
        System.out.println("Is 20 in arr1 = {1,2,3,4,5,6,7}?: "+list1.isIn(20));
        System.out.println("Is 7 in arr1 = {1,2,3,4,5,6,7}?: "+list1.isIn(7));


        int[] arr2 = {5};
        int[] arr3 = {5};
        int[] arr4 = {-200, -20, -4, 0, 1, 6, 20, 40, 60,75};
        int[] arr5 = {};
        int[] arr6 ={1,5};
        int[] arr7 ={1,5};
        SLLSet list2 = new SLLSet(arr2);
        SLLSet list3 = new SLLSet(arr3);
        SLLSet list4 = new SLLSet(arr4);
        SLLSet list5 = new SLLSet(arr5);
        SLLSet list6 = new SLLSet(arr6);
        SLLSet list7 = new SLLSet(arr7);

        System.out.println("list1 before is: ["+list1.toString()+"] has size of "+list1.getSize());
        list1.add(8);
        System.out.println("list1 now is: ["+list1.toString()+"] has size of "+list1.getSize());

        System.out.println("list2 before is: ["+list2.toString()+"] has size of "+list2.getSize());
        list2.add(1);
        System.out.println("list2 now is: ["+list2.toString()+"] has size of "+list2.getSize());
        
        System.out.println("list3 before is: ["+list3.toString()+"] has size of "+list3.getSize());
        list3.add(7);
        System.out.println("list3 now is: ["+list3.toString()+"] has size of "+list3.getSize());


        System.out.println("list4 before is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.add(-1);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.add(-1);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.add(76);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.add(-18);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.add(-201);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.add(-203);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.add(-202);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.add(74);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.add(73);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.add(77);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.add(58);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.add(59);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.remove(77);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.remove(77);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.remove(77);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.remove(-203);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.remove(-202);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.remove(-201);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.remove(6);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());
        list4.remove(73);
        System.out.println("list4 now is: ["+list4.toString()+"] has size of "+list4.getSize());

        int[] arr8 = {5};
        int[] arr9 = {5};
        int[] arr10 = {};
        int[] arr11 ={1,5};
        int[] arr12 ={1,5};
        SLLSet list8 = new SLLSet(arr8);
        SLLSet list9 = new SLLSet(arr9);
        SLLSet list10 = new SLLSet(arr10);
        SLLSet list11 = new SLLSet(arr11);
        SLLSet list12 = new SLLSet(arr12);

        System.out.println("list8 before is: ["+list8.toString()+"] has size of "+list8.getSize());
        list8.remove(73);
        System.out.println("list8 now is: ["+list8.toString()+"] has size of "+list8.getSize());
        list8.remove(5);
        System.out.println("list8 now is: ["+list8.toString()+"] has size of "+list8.getSize());
        System.out.println("list11 before is: ["+list11.toString()+"] has size of "+list11.getSize());
        list11.remove(5);
        System.out.println("list11 now is: ["+list11.toString()+"] has size of "+list11.getSize());
        list11.remove(1);
        System.out.println("list11 now is: ["+list11.toString()+"] has size of "+list11.getSize());
        System.out.println("list12 before is: ["+list12.toString()+"] has size of "+list12.getSize());
        list12.remove(1);
        System.out.println("list12 now is: ["+list12.toString()+"] has size of "+list12.getSize());
        list12.remove(5);
        System.out.println("list12 now is: ["+list12.toString()+"] has size of "+list12.getSize());

        //demonstrating basics mechanics of adding elements to a linked list
        int[] arr0 = {1,2,3,4};
        SLLNode node0, node1, node2, node3;
        //i=0
        node0 = new SLLNode(arr0[0], null);
        //i=1
        node1 = new SLLNode(arr0[1], null);
        node0.next = node1;

        //i=2
        node2 = new SLLNode(arr0[2], null);
        node1.next = node2;

        //i=3
        node3 = new SLLNode(arr0[3], null);
        node2.next = node3;

        SLLNode iterNode=node0;
        while(iterNode.next!=null){
            System.out.print(iterNode.value+" ");
            iterNode=iterNode.next;
            if(iterNode.next==null){
                System.out.print(iterNode.value);
            }
        }
    }
}

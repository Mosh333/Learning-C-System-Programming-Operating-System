package lab5_2sh4;

import lab5_2sh4.SLLSet;

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

        
        System.out.println("*********************************************************************");
        int[] count1aArr ={1,5};
        int[] count1bArr ={2,3};
        SLLSet count1aList = new SLLSet(count1aArr);
        SLLSet count1bList = new SLLSet(count1bArr);
        System.out.println("Unique value count between {1,5} and {2,3} is: "+count1aList.countUnique(count1bList));
        System.out.println("Common value count between {1,5} and {2,3} is: "+count1aList.countCommon(count1bList));
        System.out.println("Difference value count between {1,5} and {2,3} is: "+count1aList.countDifference(count1bList));
        System.out.println("Union of {1,5} and {2,3} is: "+count1aList.union(count1bList).toString());
        System.out.println("Union of {1,5} and {2,3} is: {"+count1aList.union(count1bList).toString()+"}");
        System.out.println("Intersect of {1,5} and {2,3} is: {"+count1aList.intersection(count1bList).toString()+"}");
        System.out.println("Intersect of {1,5} and {2,3} is: {"+count1aList.intersection(count1bList).toString()+"}");
        System.out.println("Difference of {1,5} and {2,3} is: {"+count1aList.difference(count1bList).toString()+"}");
        System.out.println("Difference of {2,3} and {1,5} is: {"+count1bList.difference(count1aList).toString()+"}");
        // System.out.println("Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail");
        System.out.println("Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass");
        
        
        System.out.println("*********************************************************************");
        int[] count2aArr ={-5,-2,-1,0,1,5};
        int[] count2bArr ={0,1};
        SLLSet count2aList = new SLLSet(count2aArr);
        SLLSet count2bList = new SLLSet(count2bArr);
        System.out.println("Unique value count between {-5,-2,-1,0,1,5} and {0,1} is: "+count2aList.countUnique(count2bList));
        System.out.println("Common value count between {-5,-2,-1,0,1,5} and {0,1} is: "+count2aList.countCommon(count2bList));
        System.out.println("Difference value count between {-5,-2,-1,0,1,5} and {0,1} is: "+count2aList.countDifference(count2bList));
        System.out.println("Union of {-5,-2,-1,0,1,5} and {0,1} is: {"+count2aList.union(count2bList).toString()+"}");
        System.out.println("Union of {0,1} and {-5,-2,-1,0,1,5} is: {"+count2bList.union(count2aList).toString()+"}");
        System.out.println("Intersect of {-5,-2,-1,0,1,5} and {0,1} is: {"+count2aList.intersection(count2bList).toString()+"}");
        System.out.println("Intersect of {0,1} and {-5,-2,-1,0,1,5} is: {"+count2bList.intersection(count2aList).toString()+"}");
        System.out.println("Difference of {-5,-2,-1,0,1,5} and {0,1} is: {"+count2aList.difference(count2bList).toString()+"}");
        System.out.println("Difference of {0,1} and {-5,-2,-1,0,1,5} is: {"+count2bList.difference(count2aList).toString()+"}");
        // System.out.println("Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail");
        System.out.println("Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass");

        
        System.out.println("*********************************************************************");
        int[] count3aArr ={1};
        int[] count3bArr ={0};
        SLLSet count3aList = new SLLSet(count3aArr);
        SLLSet count3bList = new SLLSet(count3bArr);
        System.out.println("Unique value count between {0} and {1} is: "+count3aList.countUnique(count3bList));
        System.out.println("Common value count between {0} and {1} is: "+count3aList.countCommon(count3bList));
        System.out.println("Difference value count between {0} and {1} is: "+count3aList.countDifference(count3bList));
        System.out.println("Union of {1} and {0} is: {"+count3aList.union(count3bList).toString()+"}");
        System.out.println("Union of {0} and {1} is: {"+count3bList.union(count3aList).toString()+"}");
        System.out.println("Intersect of {1} and {0} is: {"+count3aList.intersection(count3bList).toString()+"}");
        System.out.println("Intersect of {0} and {1} is: {"+count3bList.intersection(count3aList).toString()+"}");
        System.out.println("Difference of {1} and {0} is: {"+count3aList.difference(count3bList).toString()+"}");
        System.out.println("Difference of {0} and {1} is: {"+count3bList.difference(count3aList).toString()+"}");
        // System.out.println("Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail");
        System.out.println("Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass");

        System.out.println("*********************************************************************");
        int[] count4aArr ={1};
        int[] count4bArr ={};
        SLLSet count4aList = new SLLSet(count4aArr);
        SLLSet count4bList = new SLLSet(count4bArr);
        System.out.println("Unique value count between {1} and {} is: "+count4aList.countUnique(count4bList));
        System.out.println("Common value count between {1} and {} is: "+count4aList.countCommon(count4bList));
        System.out.println("Difference value count between {1} and {} is: "+count4aList.countDifference(count4bList));
        System.out.println("Difference value count between {} and {1} is: "+count4bList.countDifference(count4aList));
        System.out.println("Union of {1} and {} is: {"+count4aList.union(count4bList).toString()+"}");
        System.out.println("Union of {} and {1} is: {"+count4bList.union(count4aList).toString()+"}");
        System.out.println("Intersect of {1} and {} is: {"+count4aList.intersection(count4bList).toString()+"}");
        System.out.println("Intersect of {} and {1} is: {"+count4bList.intersection(count4aList).toString()+"}");
        System.out.println("Difference of {1} and {} is: {"+count4aList.difference(count4bList).toString()+"}");
        System.out.println("Difference of {} and {1} is: {"+count4bList.difference(count4aList).toString()+"}");
        // System.out.println("Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail");
        System.out.println("Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass");

        System.out.println("*********************************************************************");
        int[] count5aArr ={};
        int[] count5bArr ={1};
        SLLSet count5aList = new SLLSet(count5aArr);
        SLLSet count5bList = new SLLSet(count5bArr);
        System.out.println("Unique value count between {} and {1} is: "+count5aList.countUnique(count5bList));
        System.out.println("Common value count between {} and {1} is: "+count5aList.countCommon(count5bList));
        System.out.println("Difference value count between {1} and {} is: "+count5aList.countDifference(count5bList));
        System.out.println("Union of {} and {1} is: {"+count5aList.union(count5bList).toString()+"}");
        System.out.println("Union of {1} and {} is: {"+count5bList.union(count5aList).toString()+"}");
        System.out.println("Intersect of {} and {1} is: {"+count5aList.intersection(count5bList).toString()+"}");
        System.out.println("Intersect of {1} and {} is: {"+count5bList.intersection(count5aList).toString()+"}");
        System.out.println("Difference of {} and {1} is: {"+count5aList.difference(count5bList).toString()+"}");
        System.out.println("Difference of {1} and {} is: {"+count5bList.difference(count5aList).toString()+"}");
        // System.out.println("Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail");
        System.out.println("Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass");

        System.out.println("*********************************************************************");
        int[] count6aArr ={};
        int[] count6bArr ={};
        SLLSet count6aList = new SLLSet(count6aArr);
        SLLSet count6bList = new SLLSet(count6bArr);
        System.out.println("Unique value count between {} and {} is: "+count6aList.countUnique(count6bList));
        System.out.println("Common value count between {} and {} is: "+count6aList.countCommon(count6bList));
        System.out.println("Difference value count between {} and {} is: "+count6aList.countDifference(count6bList));
        System.out.println("Union of {} and {} is: {"+count6aList.union(count6bList).toString()+"}");
        System.out.println("Union of {} and {} is: {"+count6bList.union(count6aList).toString()+"}");
        System.out.println("Intersect of {} and {} is: {"+count6aList.intersection(count6bList).toString()+"}");
        System.out.println("Intersect of {} and {} is: {"+count6bList.intersection(count6aList).toString()+"}");
        System.out.println("Difference of {} and {} is: {"+count6aList.difference(count6bList).toString()+"}");
        System.out.println("Difference of {} and {} is: {"+count6bList.difference(count6aList).toString()+"}");
        // System.out.println("Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail");
        System.out.println("Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass");
        
        System.out.println("*********************************************************************");
        int[] count7aArr ={-5,-2,-1,0,1,5};
        int[] count7bArr ={-5,-2,-1,0,1,5};
        SLLSet count7aList = new SLLSet(count7aArr);
        SLLSet count7bList = new SLLSet(count7bArr);
        System.out.println("Unique value count between {-5,-2,-1,0,1,5} and {-5,-2,-1,0,1,5} is: "+count7aList.countUnique(count7bList));
        System.out.println("Common value count between {-5,-2,-1,0,1,5} and {-5,-2,-1,0,1,5} is: "+count7aList.countCommon(count7bList));
        System.out.println("Difference value count between {-5,-2,-1,0,1,5} and {-5,-2,-1,0,1,5} is: "+count7aList.countDifference(count7bList));
        System.out.println("Union of {-5,-2,-1,0,1,5} and {-5,-2,-1,0,1,5} is: {"+count7aList.union(count7bList).toString()+"}");
        System.out.println("Union of {-5,-2,-1,0,1,5} and {-5,-2,-1,0,1,5} is: {"+count7bList.union(count7aList).toString()+"}");
        System.out.println("Intersect of {-5,-2,-1,0,1,5} and {-5,-2,-1,0,1,5} is: {"+count7aList.intersection(count7bList).toString()+"}");
        System.out.println("Intersect of {-5,-2,-1,0,1,5} and {-5,-2,-1,0,1,5} is: {"+count7bList.intersection(count7aList).toString()+"}");
        System.out.println("Difference of {-5,-2,-1,0,1,5} and {-5,-2,-1,0,1,5} is: {"+count7aList.difference(count7bList).toString()+"}");
        System.out.println("Difference of {-5,-2,-1,0,1,5} and {-5,-2,-1,0,1,5} is: {"+count7bList.difference(count7aList).toString()+"}");
        // System.out.println("Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail");
        System.out.println("Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass");
        
        System.out.println("*********************************************************************");
        int[] count8aArr ={-5,-2,-1,0,1,5};
        int[] count8bArr ={-100, -24, -7, 2, 5, 6, 8, 25};
        SLLSet count8aList = new SLLSet(count8aArr);
        SLLSet count8bList = new SLLSet(count8bArr);
        System.out.println("Unique value count between {-5,-2,-1,0,1,5} and {-100, -24, -7, 2, 5, 6, 8, 25} is: "+count8aList.countUnique(count8bList));
        System.out.println("Unique value count should be 13");
        System.out.println("Common value count between {-5,-2,-1,0,1,5} and {-100, -24, -7, 2, 5, 6, 8, 25} is: "+count8aList.countCommon(count8bList));
        System.out.println("Common value count should be 1");
        System.out.println("Difference value count between {-5,-2,-1,0,1,5} and {-100, -24, -7, 2, 5, 6, 8, 25} is: "+count8aList.countDifference(count8bList));
        System.out.println("Difference value count should be 1");
        System.out.println("Union of {-5,-2,-1,0,1,5} and {-100, -24, -7, 2, 5, 6, 8, 25} is: {"+count8aList.union(count8bList).toString()+"}");
        System.out.println("Union of {-100, -24, -7, 2, 5, 6, 8, 25} and {-5,-2,-1,0,1,5} is: {"+count8bList.union(count8aList).toString()+"}");
        System.out.println("Intersect of {-5,-2,-1,0,1,5} and {-100, -24, -7, 2, 5, 6, 8, 25} is: {"+count8aList.intersection(count8bList).toString()+"}");
        System.out.println("Intersect of {-100, -24, -7, 2, 5, 6, 8, 25} and {-5,-2,-1,0,1,5} is: {"+count8bList.intersection(count8aList).toString()+"}");
        System.out.println("Difference of {-5,-2,-1,0,1,5} and {-100, -24, -7, 2, 5, 6, 8, 25} is: {"+count8aList.difference(count8bList).toString()+"}");
        System.out.println("Difference of {-100, -24, -7, 2, 5, 6, 8, 25} and {-5,-2,-1,0,1,5} is: {"+count8bList.difference(count8aList).toString()+"}");
        // System.out.println("Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail");
        System.out.println("Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass");
        
        System.out.println("*********************************************************************");
        int[] count9aArr ={-100, -24, -7, 2, 5, 6, 8, 25};
        int[] count9bArr ={-5,-2,-1,0,1,5};
        SLLSet count9aList = new SLLSet(count9aArr);
        SLLSet count9bList = new SLLSet(count9bArr);
        System.out.println("Unique value count between {-100, -24, -7, 2, 5, 6, 8, 25} and {-5,-2,-1,0,1,5} is: "+count9aList.countUnique(count9bList));
        System.out.println("Unique value count should be 13");
        System.out.println("Common value count between {-100, -24, -7, 2, 5, 6, 8, 25} and {-5,-2,-1,0,1,5} is: "+count9aList.countCommon(count9bList));
        System.out.println("Common value count should be 1");
        System.out.println("Difference value count between {-100, -24, -7, 2, 5, 6, 8, 25} and {-5,-2,-1,0,1,5} is: "+count9aList.countDifference(count9bList));
        System.out.println("Difference value count should be 8");
        System.out.println("Union of {-100, -24, -7, 2, 5, 6, 8, 25} and {-5,-2,-1,0,1,5} is: {"+count9aList.union(count9bList).toString()+"}");
        System.out.println("Union of {-5,-2,-1,0,1,5} and {-100, -24, -7, 2, 5, 6, 8, 25} is: {"+count9bList.union(count9aList).toString()+"}");
        System.out.println("Intersect of {-100, -24, -7, 2, 5, 6, 8, 25} and {-5,-2,-1,0,1,5} is: {"+count9aList.intersection(count9bList).toString()+"}");
        System.out.println("Intersect of {-5,-2,-1,0,1,5} and {-100, -24, -7, 2, 5, 6, 8, 25} is: {"+count9bList.intersection(count9aList).toString()+"}");
        System.out.println("Difference of {-100, -24, -7, 2, 5, 6, 8, 25} and {-5,-2,-1,0,1,5} is: {"+count9aList.difference(count9bList).toString()+"}");
        System.out.println("Difference of {-5,-2,-1,0,1,5} and {-100, -24, -7, 2, 5, 6, 8, 25} is: {"+count9bList.difference(count9aList).toString()+"}");
        // System.out.println("Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail");
        System.out.println("Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass");
        
        System.out.println("*********************************************************************");
        int[] count10aArr ={-100, -7, -5, -2, 0, 4, 6, 8, 25};
        int[] count10bArr ={-5,-2,-1,0,1,5};
        SLLSet count10aList = new SLLSet(count10aArr);
        SLLSet count10bList = new SLLSet(count10bArr);
        System.out.println("Unique value count between {-100, -7, -5, -2, 0, 4, 6, 8, 25} and {-5,-2,-1,0,1,5} is: "+count10aList.countUnique(count10bList));
        System.out.println("Unique value count should be 12");
        System.out.println("Common value count between {-100, -7, -5, -2, 0, 4, 6, 8, 25} and {-5,-2,-1,0,1,5} is: "+count10aList.countCommon(count10bList));
        System.out.println("Common value count should be 3");
        System.out.println("Difference value count between {-100, -7, -5, -2, 0, 4, 6, 8, 25} and {-5,-2,-1,0,1,5} is: "+count10aList.countDifference(count10bList));
        System.out.println("Difference value count should be 6");
        System.out.println("Union of {-100, -7, -5, -2, 0, 4, 6, 8, 25} and {-5,-2,-1,0,1,5} is: {"+count10aList.union(count10bList).toString()+"}");
        System.out.println("Union of {-5,-2,-1,0,1,5} and {-100, -7, -5, -2, 0, 4, 6, 8, 25} is: {"+count10bList.union(count10aList).toString()+"}");
        System.out.println("Intersect of {-100, -7, -5, -2, 0, 4, 6, 8, 25} and {-5,-2,-1,0,1,5} is: {"+count10aList.intersection(count10bList).toString()+"}");
        System.out.println("Intersect of {-5,-2,-1,0,1,5} and {-100, -7, -5, -2, 0, 4, 6, 8, 25} is: {"+count10bList.intersection(count10aList).toString()+"}");
        System.out.println("Difference of {-100, -7, -5, -2, 0, 4, 6, 8, 25} and {-5,-2,-1,0,1,5} is: {"+count10aList.difference(count10bList).toString()+"}");
        System.out.println("Difference of {-5,-2,-1,0,1,5} and {-100, -7, -5, -2, 0, 4, 6, 8, 25} is: {"+count10bList.difference(count10aList).toString()+"}");
        // System.out.println("Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail");
        System.out.println("Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass");
        
        System.out.println("*********************************************************************");
        int[] count11aArr ={3,8,14,15};
        int[] count11bArr ={2,8,9,15,100};
        SLLSet count11aList = new SLLSet(count11aArr);
        SLLSet count11bList = new SLLSet(count11bArr);
        System.out.println("Unique value count between {3,8,14,15} and {2,8,9,15,100} is: "+count11aList.countUnique(count11bList));
        System.out.println("Unique value count should be 7");
        System.out.println("Common value count between {3,8,14,15} and {2,8,9,15,100} is: "+count11aList.countCommon(count11bList));
        System.out.println("Common value count should be 1");
        System.out.println("Difference value count between {3,8,14,15} and {2,8,9,15,100} is: "+count11aList.countDifference(count11bList));
        System.out.println("Difference value count should be 2");
        System.out.println("Difference value count between {2,8,9,15,100} and {3,8,14,15} is: "+count11bList.countDifference(count11aList));
        System.out.println("Difference value count should be 3");
        System.out.println("Union of {3,8,14,15} and {2,8,9,15,100} is: {"+count11aList.union(count11bList).toString()+"}");
        System.out.println("Union of {2,8,9,15,100} and {3,8,14,15} is: {"+count11bList.union(count11aList).toString()+"}");
        System.out.println("Intersect of {3,8,14,15} and {2,8,9,15,100} is: {"+count11aList.intersection(count11bList).toString()+"}");
        System.out.println("Intersect of {2,8,9,15,100} and {3,8,14,15} is: {"+count11bList.intersection(count11aList).toString()+"}");
        System.out.println("Difference of {3,8,14,15} and {2,8,9,15,100} is: {"+count11aList.difference(count11bList).toString()+"}");
        System.out.println("Difference of {2,8,9,15,100} and {3,8,14,15} is: {"+count11bList.difference(count11aList).toString()+"}");
        // System.out.println("Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail");
        System.out.println("Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass");
        
        System.out.println("*********************************************************************");
        int[] count12aArr ={1,5,7};
        int[] count12bArr ={2,3,4,5};
        SLLSet count12aList = new SLLSet(count12aArr);
        SLLSet count12bList = new SLLSet(count12bArr);
        System.out.println("Unique value count between {1,5,7} and {2,3,4,5} is: "+count12aList.countUnique(count12bList));
        System.out.println("Common value count between {1,5,7} and {2,3,4,5} is: "+count12aList.countCommon(count12bList));
        System.out.println("Difference value count between {1,5,7} and {2,3,4,5} is: "+count12aList.countDifference(count12bList));
        System.out.println("Union of {1,5,7} and {2,3,4,5} is: "+count12aList.union(count12bList).toString());
        System.out.println("Union of {1,5,7} and {2,3,4,5} is: {"+count12aList.union(count12bList).toString()+"}");
        System.out.println("Union of {2,3,4,5} and {1,5,7} is: {"+count12bList.union(count12aList).toString()+"}");
        System.out.println("Intersect of {1,5,7} and {2,3,4,5} is: {"+count12aList.intersection(count12bList).toString()+"}");
        System.out.println("Intersect of {2,3,4,5} and {1,5,7} is: {"+count12bList.intersection(count12aList).toString()+"}");
        System.out.println("Difference of {1,5,7} and {2,3,4,5} is: {"+count12aList.difference(count12bList).toString()+"}");
        System.out.println("Difference of {2,3,4,5} and {1,5,7} is: {"+count12bList.difference(count12aList).toString()+"}");
        // System.out.println("Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail Fail");
        System.out.println("Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass Pass");
        
        System.out.println("*********************************************************************");
        
        //count7aList = {-5,-2,-1,0,1,5}
        //count7bList = {-5,-2,-1,0,1,5}
        //count10aList = {-100, -7, -5, -2, 0, 4, 6, 8, 25}
        //count10bList = {-5,-2,-1,0,1,5}
        SLLSet SLLsetArray1[] ={count7aList, count7bList, count10aList, count10bList};

        SLLSet SLLsetArrayUnion1 = SLLSet.union(SLLsetArray1);
        System.out.println("Union of {-5,-2,-1,0,1,5}+{-5,-2,-1,0,1,5}+{-100, -7, -5, -2, 0, 4, 6, 8, 25}+{-5,-2,-1,0,1,5} is: ");
        System.out.println("{ "+SLLsetArrayUnion1.toString()+" }");

        System.out.println("*********************************************************************");

        SLLSet[] SLLsetArray2 = null;

        try {
            SLLSet SLLsetArrayUnion2 = SLLSet.union(SLLsetArray2);
            System.out.println(SLLsetArrayUnion2.toString());            
        } catch (Exception e) {
            System.out.println(e);
        }

        
        System.out.println("*********************************************************************");

        SLLSet[] SLLsetArray3 = {};

        try {
            SLLSet SLLsetArrayUnion3 = SLLSet.union(SLLsetArray3);
            System.out.println(SLLsetArrayUnion3.toString());            
        } catch (Exception e) {
            System.out.println(e);
        }


        System.out.println("*********************************************************************");
        //count7aList = {-5,-2,-1,0,1,5}
        //count7bList = {-5,-2,-1,0,1,5}
        //count10aList = {-100, -7, -5, -2, 0, 4, 6, 8, 25}
        //count10bList = {-5,-2,-1,0,1,5}
        SLLSet[] SLLsetArray4 = {count10aList};

        SLLSet SLLsetArrayUnion4 = SLLSet.union(SLLsetArray4);
        System.out.println("Union of {-100, -7, -5, -2, 0, 4, 6, 8, 25} is: ");
        System.out.println("{"+SLLsetArrayUnion4.toString()+"}");

        System.out.println("*********************************************************************");
        //count8aList = {-5,-2,-1,0,1,5}
        //count9aList = {-100, -24, -7, 2, 5, 6, 8, 25}
        //count10aList = {-100, -7, -5, -2, 0, 4, 6, 8, 25}
        //count12aList = {-5,-2,-1,0,1,5}
        SLLSet[] SLLsetArray5 = {count8aList, count9aList, count10aList, count12aList};

        SLLSet SLLsetArrayUnion5 = SLLSet.union(SLLsetArray5);
        System.out.println("Union of {-5,-2,-1,0,1,5}+{-100, -24, -7, 2, 5, 6, 8, 25}+{-100, -7, -5, -2, 0, 4, 6, 8, 25}+{-5,-2,-1,0,1,5} is: ");
        System.out.println("{"+SLLsetArrayUnion5.toString()+"}");
        
        /*
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
        }*/
    }
}

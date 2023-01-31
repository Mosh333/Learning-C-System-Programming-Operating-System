package lab5_2sh4;

import java.util.concurrent.TimeUnit;
import java.util.Arrays;

public class SLLSet {
    private int setSize;
    private SLLNode headNode;   //represents the beginning of the linked list

    public SLLSet(){
        this.setSize = 0;
        this.headNode = null;
    }

    public SLLSet(int[] sortedArray){
        this.setSize = sortedArray.length;
        //use a tempNode to traverse singly linked list
        SLLNode pointerNode = null;
        SLLNode tempNode = null;
        

        for (int i = 0; i < sortedArray.length; i++) {
            // System.out.println(sortedArray[i]);
            if(i==0){
                //create the first node
                pointerNode = new SLLNode(sortedArray[0], null);
                //set the first node to be the headNode of the linked list
                this.headNode = pointerNode;
            }else{
                if(pointerNode.next==null){
                    tempNode = new SLLNode(sortedArray[i], null);
                    pointerNode.next = tempNode;
                }else{
                    tempNode.next = new SLLNode(sortedArray[i], null);
                    tempNode = tempNode.next;
                }
            }
        }

    }

    public int getSize(){
        int counter=0;
        if(this.headNode == null){
            return counter;
        }else{
            SLLNode tempNode = this.headNode;
            counter++;
            while(tempNode.next!=null){
                tempNode = tempNode.next;
                counter++;
            }
        }

        return counter;
    }

    public SLLSet copy(){
        SLLNode pointerNode;
        pointerNode = this.headNode;

        int[] sortedArray = new int[this.setSize];
        for (int i = 0; i < this.setSize; i++) {
            sortedArray[i] = pointerNode.value;
            pointerNode = pointerNode.next;
        }
        SLLSet newLLNodeHead= new SLLSet(sortedArray);

        return newLLNodeHead;
    }

    public boolean isIn(int v){
        boolean result = false;

        if(this.getSize()==0){
            return result;
        }

        SLLNode pointerNode = this.headNode;

        while(pointerNode!=null){
            if(pointerNode.value==v){
                result = true;
                return result;
            }
            pointerNode = pointerNode.next;
        }

        return result;
    }

    public void add(int v){
        if(this.isIn(v)==true){
            System.out.println("Element "+v+" is already in linked list!");
            return;
        }
        boolean addedElem = false;
        SLLNode nodeToAdd = new SLLNode(v, null);
        SLLNode tempNode = new SLLNode(0, null);
        SLLNode pointerNode = this.headNode;

        if(this.getSize()==0){
            this.headNode = new SLLNode(v, null);
            this.setSize=1;
            addedElem = true;
        }else if(this.getSize()==1){
            if(headNode.value>v){
                tempNode = this.headNode;
                this.headNode = nodeToAdd;
                this.headNode.next = tempNode; 
                addedElem = true;
            }else{
                this.headNode.next = nodeToAdd;
                addedElem = true;
            }
            this.setSize++;
        }else if(this.getSize()>1){
            pointerNode = this.headNode;
            if(pointerNode.value>v){
                tempNode=pointerNode;
                this.headNode = nodeToAdd;
                this.headNode.next = tempNode;
                addedElem = true;
            }else{
                while(pointerNode.next!=null){
                    //only add elem once
                    if(pointerNode.next.value>v && addedElem==false){
                        //pointerNode.next>v here
                        tempNode=pointerNode.next;
                        pointerNode.next=nodeToAdd;
                        nodeToAdd.next=tempNode;
                        addedElem = true;
                        break;
                    }
                    pointerNode = pointerNode.next;
                }
                //last node.next is null and we didn't add yet
                if(addedElem==false && pointerNode.value<v){
                    pointerNode.next=nodeToAdd;
                }                
            }

            this.setSize++;
        }

    }

    public void remove(int v){
        if(this.isIn(v)==false){
            System.out.println("Element "+v+" is not in linked list!");
            return;
        }
        boolean removedElem = false;
        SLLNode tempNode = new SLLNode(0, null);
        SLLNode pointerNode = this.headNode;
        if(this.getSize()==0){
            return;
        }else if(this.getSize()==1){
            if(this.headNode.value==v){
                this.headNode = null;
                this.setSize = 0;
            }
        }else{
            if(pointerNode.value == v){
                //eliminate the first node
                this.headNode=pointerNode.next;
                removedElem=true;
            }
            while(pointerNode.next!=null && removedElem==false){
                //only add elem once
                if(pointerNode.next.value==v){
                    //store the node after the matching node
                    tempNode=pointerNode.next.next;
                    //get rid of the node containing the v value and let java garbage collector eliminate the node with v
                    pointerNode.next=tempNode;
                    break;
                }
                pointerNode = pointerNode.next;
            }
        }
    }

    public int countUnique(SLLSet s){
        //count number of unique entries between 
        // 1) SLLSet thisSet and
        // 2) SLLSet s
        int uniqueElem = this.setSize + s.setSize;
        SLLNode thisPointer, sPointer;
        thisPointer = this.headNode;
        sPointer = s.headNode;
        if(this.setSize>0 && s.setSize==0){
            return this.setSize;
        }

        if(s.setSize>0 && this.setSize==0){
            return s.setSize;
        }

        if(s.setSize==0 && this.setSize==0){
            return 0;
        }

        //make sure we iterate through all the elements in the larger set
        if(this.setSize>s.setSize){
            while(thisPointer.next!=null){
                // System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
                if(thisPointer.value==sPointer.value){
                    uniqueElem--;
                    thisPointer = thisPointer.next;
                    if(sPointer.next!=null){
                        sPointer = sPointer.next;
                    }
                }else if(thisPointer.value<sPointer.value){
                    thisPointer=thisPointer.next;
                }else{
                    if(sPointer.next!=null){
                        sPointer=sPointer.next;
                    }else{
                        //sPointer at its limit, increment thisPointer to iterate
                        thisPointer=thisPointer.next;                        
                    }
                    
                }                
            }
            // System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
            //at the very end, do a final comparison
            if(thisPointer.value == sPointer.value){
                uniqueElem--;
            }
        }else{
            while(sPointer.next!=null){
                // System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
                if(thisPointer.value==sPointer.value){
                    uniqueElem--;
                    sPointer = sPointer.next;
                    if(thisPointer.next!=null){
                        thisPointer = thisPointer.next;
                    }
                }else if(sPointer.value<thisPointer.value){
                    sPointer=sPointer.next;
                }else{
                    if(thisPointer.next!=null){
                        thisPointer=thisPointer.next;
                    }else{
                        //thisPointer at its limit, increment sPointer to iterate
                        sPointer=sPointer.next;
                    }
                }                
            }
            // System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
            //at the very end, do a final comparison
            if(thisPointer.value == sPointer.value){
                uniqueElem--;
            }
        }

        return uniqueElem;
    }

    
    public int countCommon(SLLSet s){
        //count number of unique entries between 
        // 1) SLLSet thisSet and
        // 2) SLLSet s

        if(this.setSize==0 || s.setSize==0){
            return 0;
        }
        
        SLLNode thisPointer, sPointer;
        thisPointer = this.headNode;
        sPointer = s.headNode;
        int commonElem = 0;

        //make sure we iterate through all the elements in the larger set
        if(this.setSize>s.setSize){
            while(thisPointer.next!=null){
                // System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
                if(thisPointer.value==sPointer.value){
                    commonElem++;
                    thisPointer = thisPointer.next;
                    if(sPointer.next!=null){
                        sPointer = sPointer.next;
                    }
                }else if(thisPointer.value<sPointer.value){
                    thisPointer=thisPointer.next;
                }else{
                    if(sPointer.next!=null){
                        sPointer=sPointer.next;
                    }else{
                        //sPointer at its limit, increment thisPointer to iterate
                        thisPointer=thisPointer.next;                        
                    }
                    
                }                
            }
            // System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
            //at the very end, do a final comparison
            if(thisPointer.value == sPointer.value){
                commonElem++;
            }        
        }else{
            while(sPointer.next!=null){
                // System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
                if(thisPointer.value==sPointer.value){
                    commonElem++;
                    sPointer = sPointer.next;
                    if(thisPointer.next!=null){
                        thisPointer = thisPointer.next;
                    }
                }else if(sPointer.value<thisPointer.value){
                    sPointer=sPointer.next;
                }else{
                    if(thisPointer.next!=null){
                        thisPointer=thisPointer.next;
                    }else{
                        //thisPointer at its limit, increment sPointer to iterate
                        sPointer=sPointer.next;
                    }
                }                
            }
            // System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
            //at the very end, do a final comparison
            if(thisPointer.value == sPointer.value){
                commonElem++;
            }
        }

        return commonElem;
    }

    
    public int countDifference(SLLSet s){
        //count number of unique entries between 
        // 1) SLLSet thisSet and
        // 2) SLLSet s
        if(this.setSize==0){
            return 0;
        }
        if(s.setSize==0){
            return this.setSize;
        }
        
        SLLNode thisPointer, sPointer;
        thisPointer = this.headNode;
        sPointer = s.headNode;
        int uniqueInThisListElem = this.setSize;

        //make sure we iterate through all the elements in the larger set
        if(this.setSize>s.setSize){
            while(thisPointer.next!=null){
                // System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
                if(thisPointer.value==sPointer.value){
                    uniqueInThisListElem--;
                    thisPointer = thisPointer.next;
                    if(sPointer.next!=null){
                        sPointer = sPointer.next;
                    }
                }else if(thisPointer.value<sPointer.value){
                    thisPointer=thisPointer.next;
                }else{
                    if(sPointer.next!=null){
                        sPointer=sPointer.next;
                    }else{
                        //sPointer at its limit, increment thisPointer to iterate
                        thisPointer=thisPointer.next;                        
                    }
                    
                }                
            }
            // System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
            //at the very end, do a final comparison
            if(thisPointer.value == sPointer.value){
                uniqueInThisListElem--;
            }        
        }else{
            while(sPointer.next!=null){
                // System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
                if(thisPointer.value==sPointer.value){
                    uniqueInThisListElem--;
                    sPointer = sPointer.next;
                    if(thisPointer.next!=null){
                        thisPointer = thisPointer.next;
                    }
                }else if(sPointer.value<thisPointer.value){
                    sPointer=sPointer.next;
                }else{
                    if(thisPointer.next!=null){
                        thisPointer=thisPointer.next;
                    }else{
                        //thisPointer at its limit, increment sPointer to iterate
                        sPointer=sPointer.next;
                    }
                }                
            }
            // System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
            //at the very end, do a final comparison
            if(thisPointer.value == sPointer.value){
                uniqueInThisListElem--;
            }
        }
        
        return uniqueInThisListElem--;
    }
    
    
    public SLLSet union(SLLSet s){
        //Return the union of:
        // 1) SLLSet thisSet and
        // 2) SLLSet s        
        SLLSet unionSet = null;
        SLLNode thisPointer, sPointer;
        
        //below are the respective counters
        int thisCounter =0, sCounter=0;
        int thisHop = this.setSize-1;
        int sHop = s.setSize-1;

        //below are the respective counters
        int arrayCounter = 0;
        int countUnique = countUnique(s);
        int[] sortedUniqueElem = new int[countUnique];

        boolean thisLastElemAdded = false;
        boolean sLastElemAdded = false;

        int maxIter = 20;
        
        //this.SLLSet starts with this.headNode
        //s starts with s.headNode
        thisPointer = this.headNode;
        sPointer = s.headNode;

        if(this.setSize>0 && s.setSize==0){
            while(thisPointer.next!=null){
                sortedUniqueElem[arrayCounter] = thisPointer.value;
                arrayCounter++;
                thisPointer = thisPointer.next;
            }
            sortedUniqueElem[arrayCounter] = thisPointer.value;
            return new SLLSet(sortedUniqueElem);
        }

        if(s.setSize>0 && this.setSize==0){
            while(sPointer.next!=null){
                sortedUniqueElem[arrayCounter] = sPointer.value;
                arrayCounter++;
                sPointer = sPointer.next;
            }
            sortedUniqueElem[arrayCounter] = sPointer.value;
            return new SLLSet(sortedUniqueElem);
        }

        if(s.setSize==0 && this.setSize==0){
            return new SLLSet();
        }

        int x=0,y=0;
        //having issues with while(node.next!=null) logic, migrating to setSize to implement logic
        while((thisCounter+sCounter)!=(thisHop+sHop)){
            x = thisCounter+sCounter;
            y = thisHop+sHop;
            System.out.println("(thisCounter+sCounter)="+x+" and (thisHop+sHop)="+y);
            System.out.println("sortedUniqueElem is:"+Arrays.toString(sortedUniqueElem));
            System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
            if(thisPointer.value==sPointer.value){
                System.out.println("Branch A");
                sortedUniqueElem[arrayCounter]=thisPointer.value;
                arrayCounter++;
                
                if(thisPointer.next!=null && sPointer.next!=null){
                    System.out.println("Branch A1");
                    thisPointer = thisPointer.next;
                    sPointer = sPointer.next;
                    thisCounter++;
                    sCounter++;
                }else if(thisPointer.next!=null && sPointer.next==null){
                    System.out.println("Branch A2");
                    thisPointer = thisPointer.next;
                    thisCounter++;
                }else if(thisPointer.next==null && sPointer.next!=null){
                    System.out.println("Branch A3");
                    sPointer = sPointer.next;
                    sCounter++;
                }
            }else if(thisPointer.value<sPointer.value){
                System.out.println("Branch B");

                if(thisPointer.next!=null){
                    System.out.println("Branch B1");
                    sortedUniqueElem[arrayCounter]=thisPointer.value;
                    arrayCounter++;
                    thisPointer = thisPointer.next;
                    thisCounter++;
                }else if(thisPointer.next==null && thisLastElemAdded==false){
                    System.out.println("Branch B2");
                    System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
                    System.out.println("sortedUniqueElem[arrayCounter]="+sortedUniqueElem[arrayCounter]);
                    if(thisPointer.value==sortedUniqueElem[arrayCounter-1]){
                        thisLastElemAdded=true;
                    }else if(thisPointer.value>sortedUniqueElem[arrayCounter-1]){
                        sortedUniqueElem[arrayCounter]=thisPointer.value;
                        arrayCounter++;
                        thisLastElemAdded=true;
                    }
                }else if(thisPointer.next==null && sPointer.next!=null){
                    System.out.println("Branch B3");
                    sortedUniqueElem[arrayCounter]=sPointer.value;
                    arrayCounter++;
                    sPointer = sPointer.next;
                    sCounter++;
                }
            }else if(sPointer.value<thisPointer.value){
                System.out.println("Branch C");
                if(sPointer.next==null && sPointer.value==sortedUniqueElem[arrayCounter]){
                    sLastElemAdded=true;
                }
                if(sPointer.next!=null){
                    sortedUniqueElem[arrayCounter]=sPointer.value;
                    arrayCounter++;
                    sPointer = sPointer.next;
                    sCounter++;
                }else if(sPointer.next==null && sLastElemAdded==false){
                    if(sPointer.value==sortedUniqueElem[arrayCounter-1]){
                        sLastElemAdded=true;
                    }else if(sPointer.value>sortedUniqueElem[arrayCounter-1]){
                        sortedUniqueElem[arrayCounter]=sPointer.value;
                        arrayCounter++;
                        sLastElemAdded=true;
                    }
                }else if(sPointer.next==null && thisPointer.next!=null){
                    sortedUniqueElem[arrayCounter]=thisPointer.value;
                    arrayCounter++;
                    thisPointer = thisPointer.next;
                    thisCounter++;                    
                }
            }
            // System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);
            // System.out.println("sortedUniqueElem is:"+Arrays.toString(sortedUniqueElem));
            if(thisPointer.next==null && sPointer.next==null){
                
                if(sortedUniqueElem[sortedUniqueElem.length-2]==sortedUniqueElem[sortedUniqueElem.length-1]){
                    if(thisPointer.value>sPointer.value){
                        sortedUniqueElem[sortedUniqueElem.length-2]=sPointer.value;
                        sortedUniqueElem[sortedUniqueElem.length-1]=thisPointer.value;
                    }
                    if(sPointer.value>thisPointer.value){
                        sortedUniqueElem[sortedUniqueElem.length-2]=thisPointer.value;
                        sortedUniqueElem[sortedUniqueElem.length-1]=sPointer.value;
                    }

                    
                }else if(sortedUniqueElem[sortedUniqueElem.length-2]!=sortedUniqueElem[sortedUniqueElem.length-1]){
                    if(thisPointer.value>sPointer.value){
                        sortedUniqueElem[sortedUniqueElem.length-1]=thisPointer.value;
                    }
                    if(sPointer.value>thisPointer.value){
                        sortedUniqueElem[sortedUniqueElem.length-1]=sPointer.value;
                    }                    
                }
                if(thisPointer.value==sPointer.value){
                    sortedUniqueElem[sortedUniqueElem.length-1]=thisPointer.value;
                }
                x = thisCounter+sCounter;
                y = thisHop+sHop;
                System.out.println("Exiting loop: (thisCounter+sCounter)="+x+" and (thisHop+sHop)="+y);
            }
            // maxIter--;
            // if(maxIter==0){
            //     break;
            // }
            // try {
            //     Thread.sleep(5000);
            // } catch (InterruptedException e) {
            //     System.err.format("IOException: %s%n", e);
            // }
        }


        System.out.println("Am I out this loop?");
        System.out.println("thisPointer.value="+thisPointer.value+" and sPointer.value="+sPointer.value);

        System.out.println("sortedUniqueElem is:"+Arrays.toString(sortedUniqueElem));
        
        unionSet = new SLLSet(sortedUniqueElem);
        return unionSet;
    }

    public SLLSet intersection(SLLSet s){
        SLLSet intersectSet = null;
        int[] sortedUniqueElem = new int[countCommon(s)];
        //to do

        return intersectSet;
    }

    public SLLSet difference(SLLSet s){
        SLLSet differenceSet = null;
        int[] sortedUniqueElem = new int[countCommon(s)];
        //to do

        return intersectSet;
    }

    public static SLLSet union(SLLSet[] sArray){
        //given an array of SLLSet, find the union between this and sArray[]
        SLLSet intersectSet = null;
        int[] sortedUniqueElem = new int[countDifference(s)];
        //to do

        return intersectSet;
    }
    

    @Override
    public String toString(){
        SLLNode tempNode;
        String result="";
        if(this.headNode==null){
            result = "";
        }else{
            tempNode = this.headNode;
            if(this.getSize()==1){
                result+=tempNode.value;
            }else{
                result+=tempNode.value+"  ";
            }

            while(tempNode.next!=null){
                tempNode = tempNode.next;
                if(tempNode.next!=null){
                    result+=tempNode.value+"  ";
                }else{
                    result+=tempNode.value;
                }
            }
        }

        // result+="\n";

        return result;
    }
}

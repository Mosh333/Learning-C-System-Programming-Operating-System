package lab5_2sh4;

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

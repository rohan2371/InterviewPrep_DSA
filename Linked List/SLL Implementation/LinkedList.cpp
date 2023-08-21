

public class LinkedList {
    private Node head;

    public void insertAtBeg(int data){
        // creating a new node
        Node newNode = new Node(data);

        // adding newnode.next = head
        // even if head is null then newNode.next = head(null)
        // is works on all the cases
        newNode.next = head;
        head = newNode;
    }

    public void insertAtEnd(int data){
        // first creating a newNode
        Node newNode = new Node(data);
        // there are two cases to be consider to add element at last
        // 1. list is empty , 2. list is not empty
        // for the first case the i create a newNode assign this node as headNode
        // for the 2. case i traverse to last node of the list i maintain a temp node that point last node
        // then assign lastnode temp.next = newNode that's it

        Node temp = head;
        while(temp.next != null)
        {
            temp = temp.next;
        }

        temp.next = newNode;
    }

    // delete node in LinkedList by key
    public void deleteByKey(int key)
    {
        // store the head node
        Node currNode = head,prev = null;

        // case 1 : if head node itself holds key to be deleted then just change the head
        if(currNode != null && currNode.data == key)
        {
            head = currNode.next;//  changed the head
            System.out.println(key+" founded and deleted");
            return;// end the function
        }
        // case 2 : if the key is somewhere other than the head
        // search for the key to be deleted
        // keep track of the previous node
        // as it is needed to change currNode.next

        while(currNode != null && currNode.data != key)
        {
            prev = currNode;
            currNode = currNode.next;
        }

        // if the key was present , it should be at currNode
        // then currNode should not be null if is null that means currNode don't holds the key

        if(currNode != null)
        {
            // since the key is at currNode
            // unlink currNode from linkedlist

            prev.next = currNode.next;
            System.out.println(key+" found and deleted");
        }
        // case 3 : the key is not present
        // if the key was not present in linkedList currNode should be null

        if(currNode == null)
        {
            System.out.println(key+" key not found");
        }
        return ;
    }

    /*
    * Delete at position
    * To be done :
    * Given a position delete the node at this position from linkedlist
    *
    * Algorithm :
    * 1.Traverse the list by counting the index of the nodes.
    * 2. for each index , match the index to be same as position
    * 3.Now , any of 3 conditions can be there
    *
    * Case 1 : The position is 0 , then head is to be deleted
    * ( change head of the node by currNode.next -> head = currNode.next or head = head.next
    *  because head or currNode are same)
    *
    * Case 2 : The position is greater than 0 but less than size of the list
    *   i. in this case , find previous node of the node to be deleted or maintain previous node
    *  ii. change the next of previous node to the next of currNode
    *  ( previous.next = currNode.next)
    *
    * Case 3 : The position is greater than the size of list
    *   ( no operation needs to be done)
    * */


    public void deleteAtPosition(int pos)
    {
        Node currNode = head,prev = null;
        int idx = 0;

        // Case 1 : currNode idx == pos

        if(currNode != null && idx == pos)
        {
            head = currNode.next;// changed the head
            System.out.println(pos+" position element deleted");
            return ;

        }
        // Case 2 :
        // if the index greater than 0 but less than size

        else {
            while(currNode != null && pos != idx)
            {
                idx++;
                prev = currNode;
                currNode = currNode.next;
            }

            if(currNode != null && pos == idx)
            {
                prev.next = currNode.next;
                System.out.println(pos+" position found and deleted");
            }
            else{
                System.out.println("position is greater than list");
            }

        }

    }

    /*
    * Reverse a LinkedList method 1 : using iteration
    *
    *          a1       a2           a3
    *        _____     ______      ______
    *       |     |   |     |     |      |
    *       |5|200|-->|6|300|---->|6|null|
    *       |_____|   |_____|     |______|
    *          100     200          300
    *         prev       curr         temp
    *
    *
    *           a1        a2           a3
    *         _____     ______      ______
     *       |     |   |     |     |      |
     *       |5| x |<--|6|100|---->|   a5 |
     *       |_____|   |_____|     |______|
     *         100        200
     *         prev       curr         temp
    *
    *
    *       consider that a1 already reverse node i want to reverse a2 node
    *
    *   here i am trying to reverse the node a and i am not reversing the node a3
    *   algo :
    *        1.first i crate temp node that point the nextnode of curr node
    *         (because i am changing the curr.next value so don't want to dislink the nextnode
    *           so i am storing the nextnode in temp node
    *           (temp = curr.next)
    *
    *       2.according to diagram i want to change curr.next to previous node
    *           (curr.next = previous)
    *       3.so a2 node is reverse now i want to move next node before that i want to maintain previouse node
    *       (prev = curr)
    *       4. after currnode move to next node that is stored in temp node
    *           (curr = temp)
    *
    *
    * */

    public void reverseLinkedList()
    {
        Node curr = head,prev = null;

        while(curr != null)
        {
            Node temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
    }


    public void display(){
        Node current = head;
        while(current != null){
            System.out.print(current.data+" ");
            current = current.next;
        }
        System.out.println();
    }



    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.insertAtBeg(5);
        list.insertAtBeg(10);
        list.insertAtBeg(18);

        list.insertAtEnd(20);
//        list.deleteByKey(25);
//        list.deleteAtPosition(0);
        list.display();
        list.reverseLinkedList();
        list.display();

    }
}

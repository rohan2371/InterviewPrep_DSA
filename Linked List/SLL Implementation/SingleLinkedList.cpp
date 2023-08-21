package linked_list;
import java.util.*;
public class SingleLinkedList {
    Node head;

    static class Node{
        int data;
        Node next;

        Node(int data){
            this.data = data;
            next = null;
        }
    }

    // insert node at end
    public static SingleLinkedList insert(SingleLinkedList list,int data)
    {
        // creating a new node
        Node new_node = new Node(data);

        // if the linked list is empty
        // then  make the new node as head
        if(list.head == null){

            list.head = new_node;
        }else{
            // else traveling to the last node
            // insert  the new  node there

            Node last = list.head;
            while(last.next != null)
            {
                last = last.next;
            }

            last.next = new_node;
        }
        // return the list by head
        return list;
    }

    // method to print the linked list

    public static void printList(SingleLinkedList list)
    {
        Node currNode = list.head;;
        System.out.print("linkedList....: ");
        while(currNode != null)
        {
            System.out.print(currNode.data+" ");
            // Go to next node
            currNode = currNode.next;
        }
        System.out.println();
    }
    // Method to delete a node in the LinkedList by KEY
    public static SingleLinkedList deleteByKey(SingleLinkedList list, int key)
    {
        // Store head node
        Node currNode = list.head,prev = null;

        // CASE : 1
        // If the head node itself holds the key to be deleted
        if(currNode != null && currNode.data == key)
        {
            list.head = currNode.next;// changed the head
            System.out.println(key + " found and deleted");

            // return the updated list
            return list;
        }

        // CASE 2:
        // If the key is somewhere else other than the head

        // search for the key to be deleted
        // keep the track of previous node
        // as it is needed to change the currNode.next

        while(currNode != null && currNode.data != key)
        {
            prev = currNode;
            currNode = currNode.next;
        }

        // if the key was present, it should be at currNode
        // Therefore the currNode shall not be null

        if(currNode != null)
        {
            // Since the key is at currNode
            // Unlink the currNode from linkedList
            prev.next = currNode.next;
            System.out.println(key+" found and deleted");
        }

        // CASE 3 : The key is not present
        // if the key was not present in linked list then currNode should be null

        if(currNode == null)
        {
            System.out.println(key + " not found");
        }
        // return the list
        return list;
    }

    // method to delete a node of linked list  by position
    public static SingleLinkedList deleteByPosition(SingleLinkedList list,int index)
    {
        // store the head node
        Node currNode = list.head,prev = null;

        // case 1
        // if index is 0 , then head of node itself is to be deleted

        if(index == 0 && currNode != null)
        {
            list.head = currNode.next;// changed the head
            System.out.println(index+" position element deleted");
            return list;
        }

        // CASE 2 :
        // if the index is greater than 0 but less than list size

        int cnt = 0;
        while(currNode != null)
        {
            // count for index to be deleted
            // keep track of the previous node

            if(cnt == index)
            {
                // Since the currNode is the required
                // position Unlink currNode from linked list
                prev.next = currNode.next;
                System.out.println(index+" position element deleted");
                break;
            }
            else {
                // if current position is not the index
                prev = currNode;
                currNode = currNode.next;
                cnt++;
            }
        }
            // if the position element was found , it should be at currNode
            // Therefore the currNode shall not be null

            // CASE 3 : the index is greater than size of linked list
            // in this case currNode should be null
            if(currNode == null){
                System.out.println(index+" position element not found");
            }


            return list;

    }

    // insert the element at beginning
    public static SingleLinkedList insertAtBeg(SingleLinkedList list,int data)
    {
        Node new_node = new Node(data);
        // CASE 1 : if the list is empty the newnode will become the head
        if(list.head == null)
        {
            list.head = new_node;
        }
        // CASE 2 : if the list is not empty then
        // new_node next store the list of head
        // new_node become the list.head
        else{
            new_node.next = list.head;
            list.head = new_node;
        }
        return list;
    }

    public static void main(String[] args) {
        SingleLinkedList list = new SingleLinkedList();

        list = insert(list,1);
        list = insert(list,3);
        list = insert(list,5);
        list = insert(list,10);

        printList(list);
//        list = deleteByKey(list,5);

        list = deleteByPosition(list,1);

        list = insertAtBeg(list,18);
        printList(list);
    }
}

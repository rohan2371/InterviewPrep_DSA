package sorting_algorithm;
import java.util.*;
public class SelectionSort {

    static void swap(int arr[],int min,int i)
    {
        arr[min] = arr[min]^arr[i];
        arr[i] = arr[min]^arr[i];
        arr[min] = arr[min]^arr[i];

    }

    public static void sort(int arr[],int n)
    {
        for(int i=0;i<n-1;i++)
        {
            int min = i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]<arr[min])
                {
                    min = j;
                }
            }
            swap(arr,min,i);


        }
    }
    static void printArr(int arr[])
    {
        for(int i=0;i<arr.length;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i]  = sc.nextInt();
        }

        sort(arr,n);

        printArr(arr);
    }
}

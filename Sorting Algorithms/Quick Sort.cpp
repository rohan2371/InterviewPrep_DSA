package sorting_algorithm;

import java.util.Scanner;

public class QuickSort {
    public static void swap(int arr[],int i,int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static int fun(int arr[],int low,int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while(i<j)
        {
            while(arr[i]<=pivot && i<=high-1){
                i++;
            }
            while(arr[j]>pivot && j>=low-1){
                j--;
            }
            if(i<j){
                swap(arr,i,j);
            }
        }
        swap(arr,low,j);
        return j;
    }
    public static void quickSort(int arr[],int low,int high)
    {
        if(low < high){
            int partition  = fun(arr,low,high);
            quickSort(arr,low,partition-1);
            quickSort(arr,partition+1,high);
        }
    }

    public static void printArray(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
    public static void main(String[] args){
        int arr[] = {4,6,2,5,7,9,1,3};
        int n = arr.length;
        quickSort(arr,0,n-1);
        printArray(arr,n);
    }
}

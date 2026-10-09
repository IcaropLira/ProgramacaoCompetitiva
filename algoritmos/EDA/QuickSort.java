import java.util.*;

public class QuickSort {
    public static void sort(int[] arr, int low, int high) {
        if (low >= high) return;
        
        int pivot = arr[high], i = low;
        for(int j = low; j < high; j++){
            if (arr[j] < pivot) swap(arr, i++, j);
        }
        swap(arr, i, high);

        sort(arr, low, i-1);
        sort(arr, i + 1, high);
    }

    private static void swap(int[] a, int i, int j){
        int temp = a[i]; a[i] = a[j] ; a[j] = temp;
    }
}

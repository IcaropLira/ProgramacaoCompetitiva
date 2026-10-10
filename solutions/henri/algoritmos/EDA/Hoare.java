public class Hoare {
    public static void sort(int[] arr, int low, int high){
        if (low >= high) return;

        int pivot = arr[low], i = low - 1, j = high + 1;
        while (true) {
            while (arr[++i] < pivot);
            while (arr[--j] > pivot);
            if (i >= j) break;
                
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
        }

        sort(arr, low, j);
        sort(arr, j + 1, high);
    }
}

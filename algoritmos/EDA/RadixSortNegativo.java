import java.util.*;

public class RadixSortNegativo{

    public static void radixSort(int[] arr){
        if (arr == null || arr.length <= 1) return;
        
        int min = arr[0];
        int max = arr[0];
        for (int i = 1; i < arr.length; i++){
            if (arr[i] > max) max = arr[i];
            if (arr[i] < min) min = arr[i];
        }

        int offset = 0;
        if (min < 0){
            offset = -min;
            for(int i = 0; i < arr.length; i++){
                arr[i] += offset;
            }
            max += offset;
        }

        int n = arr.length;
        int[] output = new int[n];

        for(int exp = 1; max/ exp > 0; exp *= 10){
            int[] count = new int[10];

            for (int i = 0; i < n; i++){
                int digit = (arr[i] / exp) % 10;
                count[digit]++;
            }

            for (int i = 1; i < 10; i++){
                count[i] += count[i-1];
            }

            for (int i = n -1; i >= 0; i--){
                int digit = (arr[i] / exp) % 10;
                output[count[digit]-1] = arr[i];
                count[digit]--;
            }

            System.arraycopy(output, 0, arr, 0, n);
        }

        if(offset > 0){
            for (int i = 0; i < arr.length; i++){
                arr[i] -= offset;
            }
        }
    }

     public static void main(String[] args) {
        int[] data = {-170, 45, 75, -90, 802, -24, 2, 0, -66};
        System.out.println("Original: " + Arrays.toString(data));
        
        radixSort(data);
        
        System.out.println("Ordenado: " + Arrays.toString(data));
    }

}
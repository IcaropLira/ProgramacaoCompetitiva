public class MergeCleu {
    
    public static void sort(int[] array, int ini, int fim) {
        if (ini < fim) {
            int meio = ini + (fim - ini) / 2;
            sort(array, ini, meio);
            sort(array, meio + 1, fim);
            merge(array, ini, meio, fim);
        }
    }

    private static void merge(int[] arr, int ini, int meio, int fim){
        int[] temp = new int[fim - ini + 1];
        int i = ini, j = meio + 1, k = 0;

        while ( i <= meio && j <= fim){
            temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
        }

        while (i <= meio) {
            temp[k++] = arr[i++];
        }
        while (j <= fim) {
            temp[k++] = arr[j++];
        }

        System.arraycopy(temp, 0, arr, ini, temp.length);
    }


}

import java.util.Arrays;

public class Heap {
    
    private int[] heap;
    private int tail;

    // construtor que já recebe um max-heap válido. feito para facilitar os testes.
    public Heap(int[] heap) {
        this.heap = heap;
        this.tail = this.heap.length - 1;
    }
    public Heap(int capacidade) {
        this.heap = new int[capacidade];
        this.tail = -1;
    }


    public boolean isEmpty() {
        return this.tail == -1;
    }

    public int left(int i) {
        return 2*i+1;
    }

    public int right(int i) {
        return (i+1)*2;
    }

    public int parent(int i) {
        return Math.floorDiv(i-1, 2);
    }

    public void heapify(int index) {
        if (isLeaf(index) || !isValidIndex(index)){
            return;
        }
        int index_max = max_index(index, left(index), right(index));
        if(index_max != index){
            swap(index_max, index);
            heapify(index_max);
        }
    }

    private int max_index(int index, int left, int right){
        if(this.heap[index] > this.heap[left]){
            if(isValidIndex(right) && this.heap[index] < this.heap[right]){
                return right;
            } return index;
        } else {
            if(isValidIndex(right) && this.heap[left] < this.heap[right]){
                return right;
            } return left;
        }
        
    }

    private boolean isValidIndex(int index) {
        return index >= 0 && index <= tail;
    }
    
    private boolean isLeaf(int index) {
        return index > parent(tail) && index <= tail; 
    } 
    
    private void swap(int i, int j) {
        int aux = this.heap[i];
        this.heap[i] = this.heap[j];
        this.heap[j] = aux;
    }
    
    public int size() {
        return this.tail + 1;
    }
    
    @Override 
    public String toString() {
        return Arrays.toString(this.heap);
    }

}

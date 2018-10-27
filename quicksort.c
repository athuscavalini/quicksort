#define CUTOFF 12 // valor de CUTOFF, ou seja, vetores menores que o tamanho definido aqui serao ordenados por insertion sort;

// funcao auxiliar para trocar dois elementos do vetor:
void exchange(int* v, int A, int B) {
    int t = v[A];
    v[A] = v[B];
    v[B] = t;
}

// insertion sort usado para CUTOFF:
void insertion_sort(int* a, int lo, int hi) {
    for (int i = hi; i > lo; i--) {
        if (a[i] < a[i-1]) exchange(a, i-1, i);
    }
    for (int i = lo+2; i <= hi; i++) {
        int j = i;
        int v = a[i];
        while (v < a[j-1]) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}

// funcao auxiliar para realizar a particao do vetor para o quick sort:
int partition(int* a, int lo, int hi) {
    int i = lo, j = hi+1;
    int v = a[lo];
    while(1) {
        while (a[++i] < v) {
            if (i == hi) break;
        }
        while (v < a[--j]) {
            if (j == lo) break;
        }
        if (i >= j) break;
        exchange(a, i, j);
    }
    exchange(a, lo, j);
    return j;
}

// funcao usada para encontrar o pivo usando a tecnica Mediana de 3:
int median_of_3(int* a, int lo, int hi) {
    int mid = lo + (hi-lo)/2;
    if (a[hi] < a[lo]) exchange(a, lo, hi);
    if (a[mid] < a[lo]) exchange(a, lo, mid);
    if (a[hi] < a[mid]) exchange(a, mid, hi);
    return mid;
}

// implementacao do quick sort usando CUTOFF e pivô com Mediana de 3:
void quick_sort(int* a, int lo, int hi) {
     if (hi <= lo + CUTOFF - 1) {
        insertion_sort(a, lo, hi);
        return;
    }
    int median = median_of_3(a, lo, hi);
    exchange(a, lo, median);
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}

#include <iostream>
#include <vector>
#include <random>
using namespace std;

// Função para imprimir o array
void printArray(vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

// Função para trocar elementos
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

// Algoritmos de ordenação

// Merge Sort
void merge(vector<int> &v, int low, int high, int mid){
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high){
        if (v[i] < v[j]){
            c[k] = v[i];
            k++;
            i++;
        }
        else{
            c[k] = v[j];
            k++;
            j++;
        }
    }
    while (i <= mid){
        c[k] = v[i];
        k++;
        i++;
    }
    while (j <= high){
        c[k] = v[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++){
        v[i] = c[i];
    }
}

void mergeSort(vector<int> &v, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        merge(v, low, high, mid);
    }
}

// Quick Sort
int partition(vector<int> &v, int low, int high){
    int pivot = v[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (v[j] < pivot) {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[high]);
    return (i + 1);
}

void quickSort(vector<int> &v, int low, int high){
    if (low < high) { 
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

// Shell Sort
void shellSort(vector<int> &v){
    int n = v.size();
    for (int h = n / 2; h > 0; h /= 2){
        for (int i = h; i < n; i += 1){
            int temp = v[i];
            int j;
            for (j = i; j >= h && v[j - h] > temp; j -= h)
                v[j] = v[j - h];
            v[j] = temp;
        }
    }
}

// Insertion Sort
void insertionSort(vector<int> &v){
    int n = v.size();
    int i, key, j;
    for(i = 1; i < n; i++){
        key = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > key){
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j + 1]){
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            } 
        }
    }
}

// Selection Sort
void selectionSort(vector<int> &v){
    int min_idx;
    int n = v.size();
    for(int i = 0; i < n - 1; i++){
        min_idx = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[min_idx])
                min_idx = j;
        }
        if(min_idx != i){
            int temp = v[min_idx];
            v[min_idx] = v[i];
            v[i] = temp;
        }
    }
}

//////////////////////////////////////////////////////////////


// Algoritmos de ordenação...

int main(){
    int tamanho = 10;
    vector<int> vetor(tamanho);

    // Inicializando o gerador de números aleatórios
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 100); // Gera números inteiros entre 1 e 100

    // Preenchendo o vetor com números aleatórios
    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = dist(mt);
    }

    // Exibindo o vetor
    cout << "Vetor aleatório:" << endl;
    printArray(vetor);

    // Ordenando o vetor
    bubbleSort(vetor);
    //selectionSort(vetor);
    //insertionSort(vetor);
    //shellSort(vetor);
    //quickSort(vetor, 0, vetor.size() - 1);
    //mergeSort(vetor, 0, vetor.size() - 1);

    cout << "Vetor ordenado:" << endl;
    printArray(vetor);

    return 0;
}

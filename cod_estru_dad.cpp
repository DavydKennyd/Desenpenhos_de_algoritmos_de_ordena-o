#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Função para imprimir o array
void printArray(vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        cout << v[i] << " | ";
    }
    cout << endl;
}

// Função para trocar elementos
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

// Algoritmos de ordenação...

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

// Merge Sort
void merge(vector<int> &v, int low, int high, int mid){
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Alocação dinâmica da matriz temporária
    vector<int> c(n1);
    vector<int> d(n2);

    for (i = 0; i < n1; i++)
        c[i] = v[low + i];
    for (j = 0; j < n2; j++)
        d[j] = v[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) {
        if (c[i] <= d[j]) {
            v[k] = c[i];
            i++;
        } else {
            v[k] = d[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = c[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = d[j];
        j++;
        k++;
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

//////////////////////////////////////////////////////////////

// Algoritmos de ordenação com medição de tempo e cout

void printDurationInMinutes(long long microseconds){
    long long seconds = microseconds / 1000000;
    long long minutes = seconds / 60;
    cout << "Tempo de execução em minutos: " << minutes << " minutos e " << seconds % 60 << " segundos" << endl;
}

void measureBubbleSort(vector<int> &v){
    auto start = high_resolution_clock::now();
    bubbleSort(v);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tempo de execução do Bubble Sort: " << duration.count() << " microseconds" << endl;
    printDurationInMinutes(duration.count());
}

void measureSelectionSort(vector<int> &v){
    auto start = high_resolution_clock::now();
    selectionSort(v);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tempo de execução do Selection Sort: " << duration.count() << " microseconds" << endl;
    printDurationInMinutes(duration.count());
}

void measureInsertionSort(vector<int> &v){
    auto start = high_resolution_clock::now();
    insertionSort(v);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tempo de execução do Insertion Sort: " << duration.count() << " microseconds" << endl;
    printDurationInMinutes(duration.count());
}

void measureShellSort(vector<int> &v){
    auto start = high_resolution_clock::now();
    shellSort(v);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tempo de execução do Shell Sort: " << duration.count() << " microseconds" << endl;
    printDurationInMinutes(duration.count());
}

void measureQuickSort(vector<int> &v){
    auto start = high_resolution_clock::now();
    quickSort(v, 0, v.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tempo de execução do Quick Sort: " << duration.count() << " microseconds" << endl;
    printDurationInMinutes(duration.count());
}

void measureMergeSort(vector<int> &v){
    auto start = high_resolution_clock::now();
    mergeSort(v, 0, v.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tempo de execução do Merge Sort: " << duration.count() << " microseconds" << endl;
    printDurationInMinutes(duration.count());
}

//////////////////////////////////////////////////////////////

int main(){
    vector<int> tamanhos = {10, 100, 1000, 10000, 100000, 1000000};

    for (int tamanho : tamanhos) {
        vector<int> vetor(tamanho);

        // Inicializando o gerador de números aleatórios
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> dist(1, 100); // Gera números inteiros entre 1 e 100

        // Preenchendo o vetor com números aleatórios
        for (int i = 0; i < tamanho; ++i) {
            vetor[i] = dist(mt);
        }

        cout << "\nVetor aleatório de tamanho " << tamanho << ":" << endl;

        // Testando o tempo de execução de cada algoritmo de ordenação
        cout << "Testando Bubble Sort para vetor de tamanho " << tamanho << endl;
        measureBubbleSort(vetor);

        cout << "Testando Selection Sort para vetor de tamanho " << tamanho << endl;
        measureSelectionSort(vetor);

        cout << "Testando Insertion Sort para vetor de tamanho " << tamanho << endl;
        measureInsertionSort(vetor);

        cout << "Testando Shell Sort para vetor de tamanho " << tamanho << endl;
        measureShellSort(vetor);

        cout << "Testando Quick Sort para vetor de tamanho " << tamanho << endl;
        measureQuickSort(vetor);

        cout << "Testando Merge Sort para vetor de tamanho " << tamanho << endl;
        measureMergeSort(vetor);
    }

    return 0;
}

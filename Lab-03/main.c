#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void shuffle(int [], int);

void merge(int [], int [], int , int [], int , long long int* , long long int* );
void mergeSort(int [], int , long long int* , long long int* );
void repeat_mergesort(int []);

void swap(int*, int*);
int partition_a(int [], int , int ,long long int* , long long int* );
void quickSort_a(int [], int , int , long long int* , long long int* );
void repeat_quicksort_a(int array[]);

int partition_b(int [], int , int , long long int* , long long int* );
void quickSort_b(int [], int , int , long long int* , long long int* );
void repeat_quicksort_b(int []);

int median(int arr[], int a, int b, int c);
int partition_c(int [], int , int , int* ,  int* );
void quickSort_c(int [], int , int , int* , int* );
void repeat_quicksort_c(int []);

void insertionSort(int [], int , long long int *, long long int *);

void repeat_insertionsort_short(int array[]);
void repeat_mergesort_short(int array[]);
void repeat_quicksort_short(int array[]);

int main() {
   printf("Lab-03 Prueba de funciones:\n| Quick Sort | Merge Sort |\n\n[Peor caso]\n\n");
   int *array=NULL;

   repeat_mergesort(array);
   repeat_quicksort_a(array);
   repeat_quicksort_b(array);
   repeat_quicksort_c(array);

   printf("Lab-03 Pruebas cortas de funciones:\n| Insertion Sort | Quick Sort | Merge Sort |\n\n");
   repeat_insertionsort_short(array);
   repeat_mergesort_short(array);
   repeat_quicksort_short(array);

   return 0;
}

void shuffle( int arr[], int val)
{
   srand(time(NULL));
   for (int i = 0; i < val; ++i) {
      arr[i] =rand()%val; //Para el peor caso es val-i; para el mejor caso es i+1;
      }
}

void merge(int arr[], int left[], int left_size, int right[], int right_size, long long int* swaps, long long int* comps) {
   int i = 0, j = 0, k = 0;
   while (i < left_size && j < right_size) {
      (*comps)++;
      if (left[i] <= right[j]) {
         arr[k++] = left[i++];
      } else {
         arr[k++] = right[j++];
         (*swaps)++;
      }
   }
   while (i < left_size) {
      arr[k++] = left[i++];
   }
   while (j < right_size) {
      arr[k++] = right[j++];
   }
}

void mergeSort(int arr[], int n, long long int* swaps, long long int* comps) {
   int size = 1; // tamaño actual de los subarreglos
   (*comps) = 0;
   (*swaps) = 0;

   while (size < n) {
      int i = 0;
      while (i < n - size) {
         merge(arr + i, arr + i, size, arr + i + size, size < n - i - size ? size : n - i - size, swaps, comps);
         i += size * 2;
      }
      size *= 2;
   }
}

void repeat_mergesort(int array[])
{
   int val, vueltas=5, n=8, v=0;
   double prom_01= 0.0f, prom_02= 0.0f, prom_03 = 0.0f, prom_04= 0.0f, prom_05 = 0.0f;
   float prom_cond_01 = 0.0f, prom_cond_02 = 0.0f, prom_cond_03 = 0.0f, prom_cond_04 = 0.0f, prom_cond_05 = 0.0f;
   float prom_swap_01 = 0.0f, prom_swap_02 = 0.0f, prom_swap_03 = 0.0f, prom_swap_04 = 0.0f, prom_swap_05 = 0.0f;

   long long int comparaciones, swaps;
   long long int Comparaciones_01[n], Comparaciones_02[n], Comparaciones_03[n], Comparaciones_04[n], Comparaciones_05[n];
   long long int Swaps_01[n], Swaps_02[n], Swaps_03[n], Swaps_04[n], Swaps_05[n];
   double timesaver_01[n], timesaver_02[n], timesaver_03[n], timesaver_04[n], timesaver_05[n];

   printf("\nMerge Sort\n", 163);
   while(v!= vueltas){

      val = 1000;
      printf("\t\t\t\t\t\t PRUEBA [%d]\t\n", v+1);

      for(int i = 0; i < n; i++)
      {
         array = malloc(sizeof(int) * val);
         //Llenar el arreglo
         shuffle(array, val);
         clock_t start = clock();
         mergeSort(array, val-1, &comparaciones, &swaps);
         clock_t end = clock();
         double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
         printf("| Condicionales: %*d | Swap: %*d | Tiempo: %*f segundos | Tama%co: %*d |\n", 14, comparaciones, 14, swaps, 14, time_taken, 164, 14, val);

         if(v == 0){
            Comparaciones_01[i] = comparaciones;
            Swaps_01[i] = swaps;
            timesaver_01[i] = time_taken;

            prom_01+=timesaver_01[i];
            prom_cond_01+=(float)Comparaciones_01[i];
            prom_swap_01+=(float)Swaps_01[i];

         }else if(v == 1){
            Comparaciones_02[i] = comparaciones;
            Swaps_02[i] = swaps;
            timesaver_02[i] = time_taken;

            prom_02+=timesaver_02[i];
            prom_cond_02+=(float)Comparaciones_02[i];
            prom_swap_02+=(float)Swaps_02[i];

         }else if(v == 2){
            Comparaciones_03[i] = comparaciones;
            Swaps_03[i] = swaps;
            timesaver_03[i] = time_taken;

            prom_03+=timesaver_03[i];
            prom_cond_03+=(float)Comparaciones_03[i];
            prom_swap_03+=(float)Swaps_03[i];

         }else if(v == 3){
            Comparaciones_04[i] = comparaciones;
            Swaps_04[i] = swaps;
            timesaver_04[i] = time_taken;

            prom_04+=timesaver_04[i];
            prom_cond_04+=(float)Comparaciones_04[i];
            prom_swap_04+=(float)Swaps_04[i];

         }else if(v == 4){
            Comparaciones_05[i] = comparaciones;
            Swaps_05[i] = swaps;
            timesaver_05[i] = time_taken;

            prom_05+=timesaver_05[i];
            prom_cond_05+=(float)Comparaciones_05[i];
            prom_swap_05+=(float)Swaps_05[i];
         }

         free(array);

         if(i==0){
            val = 10000;
         }else if(i==1){
            val = 50000;
         }else if(i==2){
            val = 80000;
         }else if(i==3){
            val = 100000;
         }else if(i==4){
            val = 500000;
         }else if(i==5){
            val = 750000;
         }else if(i==6){
            val = 1000000;
         }

      }

      if(v == 0){
         prom_01/=(float)n;
         prom_cond_01/=(float)n;
         prom_swap_01/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_01, prom_swap_01, prom_01);
      }else if(v == 1){
         prom_02/=(float)n;
         prom_cond_02/=(float)n;
         prom_swap_02/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_02, prom_swap_02, prom_02);
      }else if(v == 2){
         prom_03/=(float)n;
         prom_cond_03/=(float)n;
         prom_swap_03/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_03, prom_swap_03, prom_03);
      }else if(v == 3){
         prom_04/=(float)n;
         prom_cond_04/=(float)n;
         prom_swap_04/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_04, prom_swap_04, prom_04);
      }else if(v == 4){
         prom_05/=(float)n;
         prom_cond_05/=(float)n;
         prom_swap_05/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_05, prom_swap_05, prom_05);
      }

      v++;
   }

}

void swap(int* a, int* b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

/*
 * versión que siempre utiliza el último elemento del arreglo como el pivote
 */

int partition_a(int arr[], int low, int high, long long int* comparisons, long long int* swaps) {
   int pivot = arr[high];
   int i = low - 1;

   for (int j = low; j <= high - 1; j++) {
      (*comparisons)++;
      if (arr[j] <= pivot) {
         i++;
         swap(&arr[i], &arr[j]);
         (*swaps)++;
      }
   }
   swap(&arr[i+1], &arr[high]);
   (*swaps)++;
   return i+1;
}

void quickSort_a(int arr[], int low, int high, long long int* comparisons, long long int* swaps) {
   if (low < high) {
      int pi = partition_a(arr, low, high, comparisons, swaps);
      quickSort_a(arr, low, pi - 1, comparisons, swaps);
      quickSort_a(arr, pi + 1, high, comparisons, swaps);
   }
}

void repeat_quicksort_a(int array[])
{
   int val, vueltas=5, n=8, v=0;
   double prom_01= 0.0f, prom_02= 0.0f, prom_03 = 0.0f, prom_04= 0.0f, prom_05 = 0.0f;
   float prom_cond_01 = 0.0f, prom_cond_02 = 0.0f, prom_cond_03 = 0.0f, prom_cond_04 = 0.0f, prom_cond_05 = 0.0f;
   float prom_swap_01 = 0.0f, prom_swap_02 = 0.0f, prom_swap_03 = 0.0f, prom_swap_04 = 0.0f, prom_swap_05 = 0.0f;

   long long int comparaciones=0, swaps=0;
   long long int Comparaciones_01[n], Comparaciones_02[n], Comparaciones_03[n], Comparaciones_04[n], Comparaciones_05[n];
   long long int Swaps_01[n], Swaps_02[n], Swaps_03[n], Swaps_04[n], Swaps_05[n];
   double timesaver_01[n], timesaver_02[n], timesaver_03[n], timesaver_04[n], timesaver_05[n];

   printf("\nQuick Sort (a) que utiliza el %cltimo elemento del arreglo como el pivote:\n", 163);
   while(v!= vueltas){

      val = 1000;
      printf("\t\t\t\t\t\t PRUEBA [%d]\t\n", v+1);

      for(int i = 0; i < n; i++)
      {
         comparaciones=0, swaps=0;
         array = malloc(sizeof(int) * val);
         //Llenar el arreglo
         shuffle(array, val);
        clock_t start = clock();
         quickSort_a(array, 0, val-1, &comparaciones, &swaps);
         clock_t end = clock();
         double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
         printf("| Condicionales: %*d | Swap: %*d | Tiempo: %*f segundos | Tama%co: %*d |\n", 14, comparaciones, 14, swaps, 14, time_taken, 164, 14, val);

         if(v == 0){
            Comparaciones_01[i] = comparaciones;
            Swaps_01[i] = swaps;
            timesaver_01[i] = time_taken;

            prom_01+=timesaver_01[i];
            prom_cond_01+=(float)Comparaciones_01[i];
            prom_swap_01+=(float)Swaps_01[i];

         }else if(v == 1){
            Comparaciones_02[i] = comparaciones;
            Swaps_02[i] = swaps;
            timesaver_02[i] = time_taken;

            prom_02+=timesaver_02[i];
            prom_cond_02+=(float)Comparaciones_02[i];
            prom_swap_02+=(float)Swaps_02[i];

         }else if(v == 2){
            Comparaciones_03[i] = comparaciones;
            Swaps_03[i] = swaps;
            timesaver_03[i] = time_taken;

            prom_03+=timesaver_03[i];
            prom_cond_03+=(float)Comparaciones_03[i];
            prom_swap_03+=(float)Swaps_03[i];

         }else if(v == 3){
            Comparaciones_04[i] = comparaciones;
            Swaps_04[i] = swaps;
            timesaver_04[i] = time_taken;

            prom_04+=timesaver_04[i];
            prom_cond_04+=(float)Comparaciones_04[i];
            prom_swap_04+=(float)Swaps_04[i];

         }else if(v == 4){
            Comparaciones_05[i] = comparaciones;
            Swaps_05[i] = swaps;
            timesaver_05[i] = time_taken;

            prom_05+=timesaver_05[i];
            prom_cond_05+=(float)Comparaciones_05[i];
            prom_swap_05+=(float)Swaps_05[i];
         }

         free(array);

         if(i==0){
            val = 10000;
         }else if(i==1){
            val = 50000;
         }else if(i==2){
            val = 80000;
         }else if(i==3){
            val = 100000;
         }else if(i==4){
            val = 500000;
         }else if(i==5){
            val = 750000;
         }else if(i==6){
            val = 1000000;
         }

      }

      if(v == 0){
         prom_01/=(float)n;
         prom_cond_01/=(float)n;
         prom_swap_01/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_01, prom_swap_01, prom_01);
      }else if(v == 1){
         prom_02/=(float)n;
         prom_cond_02/=(float)n;
         prom_swap_02/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_02, prom_swap_02, prom_02);
      }else if(v == 2){
         prom_03/=(float)n;
         prom_cond_03/=(float)n;
         prom_swap_03/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_03, prom_swap_03, prom_03);
      }else if(v == 3){
         prom_04/=(float)n;
         prom_cond_04/=(float)n;
         prom_swap_04/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_04, prom_swap_04, prom_04);
      }else if(v == 4){
         prom_05/=(float)n;
         prom_cond_05/=(float)n;
         prom_swap_05/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_05, prom_swap_05, prom_05);
      }

      v++;
   }

}

/*
 * versión que utiliza como pivote un elemento aleatorio del mismo.
 */

int partition_b(int arr[], int low, int high, long long int* comparaciones, long long int* swaps) {
   srand(time(NULL));
   int random_pivot = low + rand() % (high - low + 1);
   swap(&arr[random_pivot], &arr[high]);
   int pivot = arr[high];
   int i = (low - 1);
   for (int j = low; j <= high - 1; j++) {
      (*comparaciones)++;
      if (arr[j] < pivot) {
         i++;
         swap(&arr[i], &arr[j]);
         (*swaps)++;
      }
   }
   swap(&arr[i + 1], &arr[high]);
   (*swaps)++;
   return (i + 1);
}

void quickSort_b(int arr[], int low, int high, long long int* comparaciones, long long int* swaps) {
   if (low < high) {
      int pi = partition_b(arr, low, high, comparaciones, swaps);
      quickSort_b(arr, low, pi - 1, comparaciones, swaps);
      quickSort_b(arr, pi + 1, high, comparaciones, swaps);
   }
}

void repeat_quicksort_b(int array[])
{
   int val= 1000, vueltas=5, n=8, v=0;
   double prom_01= 0.0f, prom_02= 0.0f, prom_03 = 0.0f, prom_04= 0.0f, prom_05 = 0.0f;
   float prom_cond_01 = 0.0f, prom_cond_02 = 0.0f, prom_cond_03 = 0.0f, prom_cond_04 = 0.0f, prom_cond_05 = 0.0f;
   float prom_swap_01 = 0.0f, prom_swap_02 = 0.0f, prom_swap_03 = 0.0f, prom_swap_04 = 0.0f, prom_swap_05 = 0.0f;

   long long int comparaciones=0, swaps=0;
   long long int Comparaciones_01[n], Comparaciones_02[n], Comparaciones_03[n], Comparaciones_04[n], Comparaciones_05[n];
   long long int Swaps_01[n], Swaps_02[n], Swaps_03[n], Swaps_04[n], Swaps_05[n];
   double timesaver_01[n], timesaver_02[n], timesaver_03[n], timesaver_04[n], timesaver_05[n];

   printf("\nQuick Sort (b) que utiliza como pivote un elemento aleatorio del mismo:\n");
   while(v!= vueltas){

      printf("\t\t\t\t\t\t PRUEBA [%d]\t\n", v+1);

      for(int i = 0; i < n; i++)
      {
         comparaciones=0, swaps=0;
         array = malloc(sizeof(int) * val);
         for (int j = 0; j < val; ++j) {
            array[j]= j+1;
         }
         clock_t start = clock();
         quickSort_b(array, 0, val-1, &comparaciones, &swaps);
         clock_t end = clock();
         double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
         printf("| Condicionales: %*ld | Swap: %*ld | Tiempo: %*f segundos | Tama%co: %*d |\n", 14, comparaciones, 14, swaps, 14, time_taken, 164, 14, val);

         if(v == 0){
            Comparaciones_01[i] = comparaciones;
            Swaps_01[i] = swaps;
            timesaver_01[i] = time_taken;

            prom_01+=timesaver_01[i];
            prom_cond_01+=(float)Comparaciones_01[i];
            prom_swap_01+=(float)Swaps_01[i];

         }else if(v == 1){
            Comparaciones_02[i] = comparaciones;
            Swaps_02[i] = swaps;
            timesaver_02[i] = time_taken;

            prom_02+=timesaver_02[i];
            prom_cond_02+=(float)Comparaciones_02[i];
            prom_swap_02+=(float)Swaps_02[i];

         }else if(v == 2){
            Comparaciones_03[i] = comparaciones;
            Swaps_03[i] = swaps;
            timesaver_03[i] = time_taken;

            prom_03+=timesaver_03[i];
            prom_cond_03+=(float)Comparaciones_03[i];
            prom_swap_03+=(float)Swaps_03[i];

         }else if(v == 3){
            Comparaciones_04[i] = comparaciones;
            Swaps_04[i] = swaps;
            timesaver_04[i] = time_taken;

            prom_04+=timesaver_04[i];
            prom_cond_04+=(float)Comparaciones_04[i];
            prom_swap_04+=(float)Swaps_04[i];

         }else if(v == 4){
            Comparaciones_05[i] = comparaciones;
            Swaps_05[i] = swaps;
            timesaver_05[i] = time_taken;

            prom_05+=timesaver_05[i];
            prom_cond_05+=(float)Comparaciones_05[i];
            prom_swap_05+=(float)Swaps_05[i];
         }

         free(array);

         if(i==0){
            val = 10000;
         }else if(i==1){
            val = 50000;
         }else if(i==2){
            val = 80000;
         }else if(i==3){
            val = 100000;
         }else if(i==4){
            val = 500000;
         }else if(i==5){
            val = 750000;
         }else if(i==6){
            val = 1000000;
         }

      }

      if(v == 0){
         prom_01/=(float)n;
         prom_cond_01/=(float)n;
         prom_swap_01/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_01, prom_swap_01, prom_01);
      }else if(v == 1){
         prom_02/=(float)n;
         prom_cond_02/=(float)n;
         prom_swap_02/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_02, prom_swap_02, prom_02);
      }else if(v == 2){
         prom_03/=(float)n;
         prom_cond_03/=(float)n;
         prom_swap_03/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_03, prom_swap_03, prom_03);
      }else if(v == 3){
         prom_04/=(float)n;
         prom_cond_04/=(float)n;
         prom_swap_04/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_04, prom_swap_04, prom_04);
      }else if(v == 4){
         prom_05/=(float)n;
         prom_cond_05/=(float)n;
         prom_swap_05/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_05, prom_swap_05, prom_05);
      }

      v++;
   }

}

/*
 * Calcula la media de tres elementos aleatorios del arreglo y elige el pivote en base a esa mediana.
 * Si el arreglo tiene menos de tres elementos, el pivote se elige de manera aleatoria entre los elementos restantes.
 */

int median(int arr[], int a, int b, int c) {
   if (arr[a] < arr[b]) {
      if (arr[b] < arr[c]) {
         return b;
      } else if (arr[a] < arr[c]) {
         return c;
      } else {
         return a;
      }
   } else {
      if (arr[c] < arr[b]) {
         return b;
      } else if (arr[c] < arr[a]) {
         return c;
      } else {
         return a;
      }
   }
}

int partition_c(int arr[], int low, int high, int* comparaciones, int* swaps) {
   int pivot_index;
   if (high - low >= 2) {
      srand(time(NULL));
      int random1 = rand() % (high - low + 1) + low;
      int random2 = rand() % (high - low + 1) + low;
      int random3 = rand() % (high - low + 1) + low;
      pivot_index = median(arr, random1, random2, random3);
   } else if (high - low == 1) {
      pivot_index = high;
   } else {
      pivot_index = rand() % (high - low + 1) + low;
   }
   swap(&arr[pivot_index], &arr[high]);
   int pivot = arr[high];
   int i = low - 1;
   for (int j = low; j < high; j++) {
      (*comparaciones)++;
      if (arr[j] <= pivot) {
         i++;
         swap(&arr[i], &arr[j]);
         (*swaps)++;
      }
   }
   swap(&arr[i + 1], &arr[high]);
   (*swaps)++;
   return i + 1;
}

void quickSort_c(int arr[], int low, int high, int* comparaciones, int* swaps) {
   if (low < high) {
      int pivot = partition_c(arr, low, high, comparaciones, swaps);
      quickSort_c(arr, low, pivot - 1, comparaciones, swaps);
      quickSort_c(arr, pivot + 1, high, comparaciones, swaps);
   }
}


void repeat_quicksort_c(int array[])
{
   int val, vueltas=5, n=8, v=0;
   double prom_01= 0.0f, prom_02= 0.0f, prom_03 = 0.0f, prom_04= 0.0f, prom_05 = 0.0f;
   float prom_cond_01 = 0.0f, prom_cond_02 = 0.0f, prom_cond_03 = 0.0f, prom_cond_04 = 0.0f, prom_cond_05 = 0.0f;
   float prom_swap_01 = 0.0f, prom_swap_02 = 0.0f, prom_swap_03 = 0.0f, prom_swap_04 = 0.0f, prom_swap_05 = 0.0f;

   int comparaciones, swaps;
   long long int Comparaciones_01[n], Comparaciones_02[n], Comparaciones_03[n], Comparaciones_04[n], Comparaciones_05[n];
   long long int Swaps_01[n], Swaps_02[n], Swaps_03[n], Swaps_04[n], Swaps_05[n];
   double timesaver_01[n], timesaver_02[n], timesaver_03[n], timesaver_04[n], timesaver_05[n];

   printf("\nQuick Sort (b) que calcula la media de tres elementos aleatorios del arreglo y elige el pivote en base a esa mediana.:\n");
   while(v!= vueltas){

      val = 1000;
      printf("\t\t\t\t\t\t PRUEBA [%d]\t\n", v+1);

      for(int i = 0; i < n; i++)
      {
         comparaciones=0, swaps=0;
         array = malloc(sizeof(int) * val);
         shuffle(array, val);
         clock_t start = clock();
         quickSort_c(array, 0, val-1, &comparaciones, &swaps);
         clock_t end = clock();
         double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
         printf("| Condicionales: %*d | Swap: %*d | Tiempo: %*f segundos | Tama%co: %*d |\n", 14, comparaciones, 14, swaps, 14, time_taken, 164, 14, val);

         if(v == 0){
            Comparaciones_01[i] = comparaciones;
            Swaps_01[i] = swaps;
            timesaver_01[i] = time_taken;

            prom_01+=timesaver_01[i];
            prom_cond_01+=(float)Comparaciones_01[i];
            prom_swap_01+=(float)Swaps_01[i];

         }else if(v == 1){
            Comparaciones_02[i] = comparaciones;
            Swaps_02[i] = swaps;
            timesaver_02[i] = time_taken;

            prom_02+=timesaver_02[i];
            prom_cond_02+=(float)Comparaciones_02[i];
            prom_swap_02+=(float)Swaps_02[i];

         }else if(v == 2){
            Comparaciones_03[i] = comparaciones;
            Swaps_03[i] = swaps;
            timesaver_03[i] = time_taken;

            prom_03+=timesaver_03[i];
            prom_cond_03+=(float)Comparaciones_03[i];
            prom_swap_03+=(float)Swaps_03[i];

         }else if(v == 3){
            Comparaciones_04[i] = comparaciones;
            Swaps_04[i] = swaps;
            timesaver_04[i] = time_taken;

            prom_04+=timesaver_04[i];
            prom_cond_04+=(float)Comparaciones_04[i];
            prom_swap_04+=(float)Swaps_04[i];

         }else if(v == 4){
            Comparaciones_05[i] = comparaciones;
            Swaps_05[i] = swaps;
            timesaver_05[i] = time_taken;

            prom_05+=timesaver_05[i];
            prom_cond_05+=(float)Comparaciones_05[i];
            prom_swap_05+=(float)Swaps_05[i];
         }

         free(array);

         if(i==0){
            val = 10000;
         }else if(i==1){
            val = 50000;
         }else if(i==2){
            val = 80000;
         }else if(i==3){
            val = 100000;
         }else if(i==4){
            val = 500000;
         }else if(i==5){
            val = 750000;
         }else if(i==6){
            val = 1000000;
         }

      }

      if(v == 0){
         prom_01/=(float)n;
         prom_cond_01/=(float)n;
         prom_swap_01/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_01, prom_swap_01, prom_01);
      }else if(v == 1){
         prom_02/=(float)n;
         prom_cond_02/=(float)n;
         prom_swap_02/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_02, prom_swap_02, prom_02);
      }else if(v == 2){
         prom_03/=(float)n;
         prom_cond_03/=(float)n;
         prom_swap_03/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_03, prom_swap_03, prom_03);
      }else if(v == 3){
         prom_04/=(float)n;
         prom_cond_04/=(float)n;
         prom_swap_04/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_04, prom_swap_04, prom_04);
      }else if(v == 4){
         prom_05/=(float)n;
         prom_cond_05/=(float)n;
         prom_swap_05/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_05, prom_swap_05, prom_05);
      }

      v++;
   }

}
/////////////////////////////////////////////////////////////////////////
void insertionSort(int arr[], int n, long long int *cont, long long int *contSwap) {
   int i, key, j;

   for (i = 1; i < n; i++) {
      key = arr[i];
      j = i - 1;
      /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
      (*cont)++;
      while (j >= 0 && arr[j] > key) {
         arr[j + 1] = arr[j];
         j = j - 1;
         (*contSwap)++;
      }
      arr[j + 1] = key;

   }

}

void repeat_insertionsort_short(int array[]){
   int val, vueltas=5, n=12, v=0;
   double prom_01= 0.0f, prom_02= 0.0f, prom_03 = 0.0f, prom_04= 0.0f, prom_05 = 0.0f;
   float prom_cond_01 = 0.0f, prom_cond_02 = 0.0f, prom_cond_03 = 0.0f, prom_cond_04 = 0.0f, prom_cond_05 = 0.0f;
   float prom_swap_01 = 0.0f, prom_swap_02 = 0.0f, prom_swap_03 = 0.0f, prom_swap_04 = 0.0f, prom_swap_05 = 0.0f;

   long long int comparaciones=0, swaps=0;
   long long int Comparaciones_01[n], Comparaciones_02[n], Comparaciones_03[n], Comparaciones_04[n], Comparaciones_05[n];
   long long int Swaps_01[n], Swaps_02[n], Swaps_03[n], Swaps_04[n], Swaps_05[n];
   double timesaver_01[n], timesaver_02[n], timesaver_03[n], timesaver_04[n], timesaver_05[n];

   printf("\nInsertion Sort Corrida Corta\n");
   while(v!= vueltas){

      val = 4;
      printf("\t\t\t\t\t\t PRUEBA [%d]\t\n", v+1);

      for(int i = 0; i < n; i++)
      {
         comparaciones=0, swaps=0;
         array = malloc(sizeof(int) * val);
         shuffle(array, val);
         clock_t start = clock();
         insertionSort(array, val-1, &comparaciones, &swaps);
         clock_t end = clock();
         double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
         printf("| Condicionales: %*d | Swap: %*d | Tiempo: %*f segundos | Tama%co: %*d |\n", 14, comparaciones, 14, swaps, 14, time_taken, 164, 14, val);

         if(v == 0){
            Comparaciones_01[i] = comparaciones;
            Swaps_01[i] = swaps;
            timesaver_01[i] = time_taken;

            prom_01+=timesaver_01[i];
            prom_cond_01+=(float)Comparaciones_01[i];
            prom_swap_01+=(float)Swaps_01[i];

         }else if(v == 1){
            Comparaciones_02[i] = comparaciones;
            Swaps_02[i] = swaps;
            timesaver_02[i] = time_taken;

            prom_02+=timesaver_02[i];
            prom_cond_02+=(float)Comparaciones_02[i];
            prom_swap_02+=(float)Swaps_02[i];

         }else if(v == 2){
            Comparaciones_03[i] = comparaciones;
            Swaps_03[i] = swaps;
            timesaver_03[i] = time_taken;

            prom_03+=timesaver_03[i];
            prom_cond_03+=(float)Comparaciones_03[i];
            prom_swap_03+=(float)Swaps_03[i];

         }else if(v == 3){
            Comparaciones_04[i] = comparaciones;
            Swaps_04[i] = swaps;
            timesaver_04[i] = time_taken;

            prom_04+=timesaver_04[i];
            prom_cond_04+=(float)Comparaciones_04[i];
            prom_swap_04+=(float)Swaps_04[i];

         }else if(v == 4){
            Comparaciones_05[i] = comparaciones;
            Swaps_05[i] = swaps;
            timesaver_05[i] = time_taken;

            prom_05+=timesaver_05[i];
            prom_cond_05+=(float)Comparaciones_05[i];
            prom_swap_05+=(float)Swaps_05[i];
         }

         free(array);

         if(i==0){
            val = 10;
         }else if(i==1){
            val = 15;
         }else if(i==2){
            val = 20;
         }else if(i==3){
            val = 35;
         }else if(i==4){
            val = 45;
         }else if(i==5){
            val = 50;
         }else if(i==6){
            val = 60;
         }else if(i==7){
            val=70;
         }else if(i==8){
            val=85;
         }else if(i==9){
            val=90;
         }else if(i==10){
         val=100;
      }

      }

      if(v == 0){
         prom_01/=(float)n;
         prom_cond_01/=(float)n;
         prom_swap_01/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_01, prom_swap_01, prom_01);
      }else if(v == 1){
         prom_02/=(float)n;
         prom_cond_02/=(float)n;
         prom_swap_02/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_02, prom_swap_02, prom_02);
      }else if(v == 2){
         prom_03/=(float)n;
         prom_cond_03/=(float)n;
         prom_swap_03/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_03, prom_swap_03, prom_03);
      }else if(v == 3){
         prom_04/=(float)n;
         prom_cond_04/=(float)n;
         prom_swap_04/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_04, prom_swap_04, prom_04);
      }else if(v == 4){
         prom_05/=(float)n;
         prom_cond_05/=(float)n;
         prom_swap_05/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_05, prom_swap_05, prom_05);
      }

      v++;
   }
}

void repeat_mergesort_short(int array[]){
   int val, vueltas=5, n=12, v=0;
   double prom_01= 0.0f, prom_02= 0.0f, prom_03 = 0.0f, prom_04= 0.0f, prom_05 = 0.0f;
   float prom_cond_01 = 0.0f, prom_cond_02 = 0.0f, prom_cond_03 = 0.0f, prom_cond_04 = 0.0f, prom_cond_05 = 0.0f;
   float prom_swap_01 = 0.0f, prom_swap_02 = 0.0f, prom_swap_03 = 0.0f, prom_swap_04 = 0.0f, prom_swap_05 = 0.0f;

   long long int comparaciones=0, swaps=0;
   long long int Comparaciones_01[n], Comparaciones_02[n], Comparaciones_03[n], Comparaciones_04[n], Comparaciones_05[n];
   long long int Swaps_01[n], Swaps_02[n], Swaps_03[n], Swaps_04[n], Swaps_05[n];
   double timesaver_01[n], timesaver_02[n], timesaver_03[n], timesaver_04[n], timesaver_05[n];

   printf("\nMerge Sort Corrida Corta\n");
   while(v!= vueltas){

      val = 4;
      printf("\t\t\t\t\t\t PRUEBA [%d]\t\n", v+1);

      for(int i = 0; i < n; i++)
      {
         comparaciones=0, swaps=0;
         array = malloc(sizeof(int) * val);
         shuffle(array, val);
         clock_t start = clock();
         mergeSort(array, val-1, &comparaciones, &swaps);
         clock_t end = clock();
         double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
         printf("| Condicionales: %*d | Swap: %*d | Tiempo: %*f segundos | Tama%co: %*d |\n", 14, comparaciones, 14, swaps, 14, time_taken, 164, 14, val);

         if(v == 0){
            Comparaciones_01[i] = comparaciones;
            Swaps_01[i] = swaps;
            timesaver_01[i] = time_taken;

            prom_01+=timesaver_01[i];
            prom_cond_01+=(float)Comparaciones_01[i];
            prom_swap_01+=(float)Swaps_01[i];

         }else if(v == 1){
            Comparaciones_02[i] = comparaciones;
            Swaps_02[i] = swaps;
            timesaver_02[i] = time_taken;

            prom_02+=timesaver_02[i];
            prom_cond_02+=(float)Comparaciones_02[i];
            prom_swap_02+=(float)Swaps_02[i];

         }else if(v == 2){
            Comparaciones_03[i] = comparaciones;
            Swaps_03[i] = swaps;
            timesaver_03[i] = time_taken;

            prom_03+=timesaver_03[i];
            prom_cond_03+=(float)Comparaciones_03[i];
            prom_swap_03+=(float)Swaps_03[i];

         }else if(v == 3){
            Comparaciones_04[i] = comparaciones;
            Swaps_04[i] = swaps;
            timesaver_04[i] = time_taken;

            prom_04+=timesaver_04[i];
            prom_cond_04+=(float)Comparaciones_04[i];
            prom_swap_04+=(float)Swaps_04[i];

         }else if(v == 4){
            Comparaciones_05[i] = comparaciones;
            Swaps_05[i] = swaps;
            timesaver_05[i] = time_taken;

            prom_05+=timesaver_05[i];
            prom_cond_05+=(float)Comparaciones_05[i];
            prom_swap_05+=(float)Swaps_05[i];
         }

         free(array);

         if(i==0){
            val = 10;
         }else if(i==1){
            val = 15;
         }else if(i==2){
            val = 20;
         }else if(i==3){
            val = 35;
         }else if(i==4){
            val = 45;
         }else if(i==5){
            val = 50;
         }else if(i==6){
            val = 60;
         }else if(i==7){
            val=70;
         }else if(i==8){
            val=85;
         }else if(i==9){
            val=90;
         }else if(i==10){
            val=100;
         }

      }

      if(v == 0){
         prom_01/=(float)n;
         prom_cond_01/=(float)n;
         prom_swap_01/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_01, prom_swap_01, prom_01);
      }else if(v == 1){
         prom_02/=(float)n;
         prom_cond_02/=(float)n;
         prom_swap_02/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_02, prom_swap_02, prom_02);
      }else if(v == 2){
         prom_03/=(float)n;
         prom_cond_03/=(float)n;
         prom_swap_03/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_03, prom_swap_03, prom_03);
      }else if(v == 3){
         prom_04/=(float)n;
         prom_cond_04/=(float)n;
         prom_swap_04/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_04, prom_swap_04, prom_04);
      }else if(v == 4){
         prom_05/=(float)n;
         prom_cond_05/=(float)n;
         prom_swap_05/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_05, prom_swap_05, prom_05);
      }

      v++;
   }

}
void repeat_quicksort_short(int array[]){

   int val, vueltas=5, n=12, v=0;
   double prom_01= 0.0f, prom_02= 0.0f, prom_03 = 0.0f, prom_04= 0.0f, prom_05 = 0.0f;
   float prom_cond_01 = 0.0f, prom_cond_02 = 0.0f, prom_cond_03 = 0.0f, prom_cond_04 = 0.0f, prom_cond_05 = 0.0f;
   float prom_swap_01 = 0.0f, prom_swap_02 = 0.0f, prom_swap_03 = 0.0f, prom_swap_04 = 0.0f, prom_swap_05 = 0.0f;

   long long int comparaciones=0, swaps=0;
   long long int Comparaciones_01[n], Comparaciones_02[n], Comparaciones_03[n], Comparaciones_04[n], Comparaciones_05[n];
   long long int Swaps_01[n], Swaps_02[n], Swaps_03[n], Swaps_04[n], Swaps_05[n];
   double timesaver_01[n], timesaver_02[n], timesaver_03[n], timesaver_04[n], timesaver_05[n];

   printf("\nQuick Sort (b) Corrida Corta\n");
   while(v!= vueltas){

      val = 4;
      printf("\t\t\t\t\t\t PRUEBA [%d]\t\n", v+1);

      for(int i = 0; i < n; i++)
      {
         comparaciones=0, swaps=0;
         array = malloc(sizeof(int) * val);
         shuffle(array, val);
         clock_t start = clock();
         quickSort_b(array, 0, val-1, &comparaciones, &swaps);
         clock_t end = clock();
         double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
         printf("| Condicionales: %*d | Swap: %*d | Tiempo: %*f segundos | Tama%co: %*d |\n", 14, comparaciones, 14, swaps, 14, time_taken, 164, 14, val);

         if(v == 0){
            Comparaciones_01[i] = comparaciones;
            Swaps_01[i] = swaps;
            timesaver_01[i] = time_taken;

            prom_01+=timesaver_01[i];
            prom_cond_01+=(float)Comparaciones_01[i];
            prom_swap_01+=(float)Swaps_01[i];

         }else if(v == 1){
            Comparaciones_02[i] = comparaciones;
            Swaps_02[i] = swaps;
            timesaver_02[i] = time_taken;

            prom_02+=timesaver_02[i];
            prom_cond_02+=(float)Comparaciones_02[i];
            prom_swap_02+=(float)Swaps_02[i];

         }else if(v == 2){
            Comparaciones_03[i] = comparaciones;
            Swaps_03[i] = swaps;
            timesaver_03[i] = time_taken;

            prom_03+=timesaver_03[i];
            prom_cond_03+=(float)Comparaciones_03[i];
            prom_swap_03+=(float)Swaps_03[i];

         }else if(v == 3){
            Comparaciones_04[i] = comparaciones;
            Swaps_04[i] = swaps;
            timesaver_04[i] = time_taken;

            prom_04+=timesaver_04[i];
            prom_cond_04+=(float)Comparaciones_04[i];
            prom_swap_04+=(float)Swaps_04[i];

         }else if(v == 4){
            Comparaciones_05[i] = comparaciones;
            Swaps_05[i] = swaps;
            timesaver_05[i] = time_taken;

            prom_05+=timesaver_05[i];
            prom_cond_05+=(float)Comparaciones_05[i];
            prom_swap_05+=(float)Swaps_05[i];
         }

         free(array);

         if(i==0){
            val = 10;
         }else if(i==1){
            val = 15;
         }else if(i==2){
            val = 20;
         }else if(i==3){
            val = 35;
         }else if(i==4){
            val = 45;
         }else if(i==5){
            val = 50;
         }else if(i==6){
            val = 60;
         }else if(i==7){
            val=70;
         }else if(i==8){
            val=85;
         }else if(i==9){
            val=90;
         }else if(i==10){
            val=100;
         }

      }

      if(v == 0){
         prom_01/=(float)n;
         prom_cond_01/=(float)n;
         prom_swap_01/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_01, prom_swap_01, prom_01);
      }else if(v == 1){
         prom_02/=(float)n;
         prom_cond_02/=(float)n;
         prom_swap_02/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_02, prom_swap_02, prom_02);
      }else if(v == 2){
         prom_03/=(float)n;
         prom_cond_03/=(float)n;
         prom_swap_03/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_03, prom_swap_03, prom_03);
      }else if(v == 3){
         prom_04/=(float)n;
         prom_cond_04/=(float)n;
         prom_swap_04/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_04, prom_swap_04, prom_04);
      }else if(v == 4){
         prom_05/=(float)n;
         prom_cond_05/=(float)n;
         prom_swap_05/=(float)n;
         printf("[ Promedio Cond: %.2f | Promedio Swaps: %.2f | Promedio Tiempo: %f ]\n\n", prom_cond_05, prom_swap_05, prom_05);
      }

      v++;
   }
}
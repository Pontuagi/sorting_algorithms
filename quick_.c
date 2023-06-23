int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, high + 1);
        }
    }

    swap(&array[i + 1], &array[high]);
    print_array(array, high + 1);

    return (i + 1);
}

void quick_sort_recursive(int *array, int low, int high) {
    if (low < high) {
        int pivot_index = partition(array, low, high);
        quick_sort_recursive(array, low, pivot_index - 1);
        quick_sort_recursive(array, pivot_index + 1, high);
    }
}

void quick_sort(int *array, size_t size) {
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}

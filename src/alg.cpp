// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int temp = 0;
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (arr[i] + arr[j] == value) {
                temp++;
            }
    return temp;
}

int countPairs2(int* arr, int len, int value) {
    int temp = 0;
    for (int i = 0; i < len - 1; i++)
        if (arr[i] <= value) {
            for (int j = i + 1; j < len; j++)
                if (arr[i] + arr[j] == value)
                    temp++;
        }
    return temp;
}

void quickSort(int* arr, int len) {
    int l = 0;
    int r = len - 1;
    int m = arr[len / 2];

    do {
        while (arr[l] < m)
            l++;
        while (arr[r] > m)
            r--;
        if (l <= r) {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    } while (l <= r);

    if (r > 0)
        quickSort(arr, r + 1);
    if (l < len)
        quickSort(&arr[l], len - l);
}

int binSearch(int* arr, int l, int r, int value) {
    if (r >= l) {
        int m = l + (r - l) / 2;
        if (arr[m] == value)
            return binSearch(arr, l, m - 1, value)
            + binSearch(arr, m + 1, r, value) + 1;
        if (arr[m] > value)
            return binSearch(arr, l, m - 1, value);
        return binSearch(arr, m + 1, r, value);
    }
    return 0;
}

int countPairs3(int* arr, int len, int value) {
    quickSort(arr, len);
    int temp = 0;
    for (int i = 0; i < len; i++) {
        temp += binSearch(&arr[i+1], 0, len-i, value - arr[i]);
    }
    return temp;
}

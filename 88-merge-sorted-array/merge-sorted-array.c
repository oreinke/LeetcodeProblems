void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int *arr;
    int i, j;

    if ( m + n == 0)
    {
        return;
    }

    arr = malloc(sizeof(int) * m);
    for (i = 0; i < m; i++)
    {
        arr[i] = nums1[i];
    }

    i = 0;
    j = 0;
    while ( i < m && j < n)
    {
        if (arr[i] < nums2[j])
        {
            nums1[i + j] = arr[i];
            i++;
        }
        else
        {
            nums1[i + j] = nums2[j];
            j++;
        }
    }

    while (i < m)
    {
        nums1[i + j] = arr[i];
        i++;
    }

    while (j < n)
    {
        nums1[i + j] = nums2[j];
        j++;
    }

    free(arr);
    return;

}
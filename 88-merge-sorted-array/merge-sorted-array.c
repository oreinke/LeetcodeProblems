void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    n--;
    m--;
    short curi = nums1Size - 1;
    while (n >= 0 && m >= 0) {
        if (nums1[m] > nums2[n]) {
            nums1[curi] = nums1[m];
            m--;
        }
        else {
            nums1[curi] = nums2[n];
            n--;
        }
        curi--;
    }

    while (m >= 0) {
        nums1[curi] = nums1[m];
        m--;
        curi--;
    }

    while (n >= 0) {
        nums1[curi] = nums2[n];
        n--;
        curi--;
    }
    return;

}
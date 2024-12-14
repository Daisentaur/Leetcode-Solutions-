int findKth(int* nums1, int nums1Size, int* nums2, int nums2Size, int i, int j, int k) {
    if (i >= nums1Size) {
        return nums2[j + k - 1];
    }
    if (j >= nums2Size) {
        return nums1[i + k - 1];
    }
    if (k == 1) {
        return nums1[i] < nums2[j] ? nums1[i] : nums2[j];
    }

    int p = k / 2;
    int x = (i + p - 1 < nums1Size) ? nums1[i + p - 1] : INT_MAX;
    int y = (j + p - 1 < nums2Size) ? nums2[j + p - 1] : INT_MAX;

    if (x < y) {
        return findKth(nums1, nums1Size, nums2, nums2Size, i + p, j, k - p);
    } else {
        return findKth(nums1, nums1Size, nums2, nums2Size, i, j + p, k - p);
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int a = findKth(nums1, nums1Size, nums2, nums2Size, 0, 0, (totalSize + 1) / 2);
    int b = findKth(nums1, nums1Size, nums2, nums2Size, 0, 0, (totalSize + 2) / 2);
    return (a + b) / 2.0;
}
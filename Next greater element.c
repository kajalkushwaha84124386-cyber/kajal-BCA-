#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size,
                        int* nums2, int nums2Size,
                        int* returnSize) {
    int* ans = malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;

    for (int i = 0; i < nums1Size; i++) {
        ans[i] = -1;
        int j = 0;

        /* nums1[i] ko nums2 mein dhoondho */
        while (j < nums2Size && nums2[j] != nums1[i]) {
            j++;
        }

        /* Uske right mein pehla greater element dhoondho */
        for (int k = j + 1; k < nums2Size; k++) {
            if (nums2[k] > nums1[i]) {
                ans[i] = nums2[k];
                break;
            }
        }
    }

    return ans;
}
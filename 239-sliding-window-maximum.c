int* maxSlidingWindow(int* arr, int N, int k, int* returnSize) {
    if (N == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = N - k + 1;
    int* M = (int*)malloc(*returnSize * sizeof(int));
    int* deque = (int*)malloc(N * sizeof(int)); 
    int front = 0, back = 0; 

    for (int i = 0; i < N; i++) {
        
        if (front < back && deque[front] < i - k + 1) {
            front++;
        }

        while (front < back && arr[deque[back - 1]] <= arr[i]) {
            back--;
        }

        deque[back++] = i;  

        if (i >= k - 1) {
            M[i - k + 1] = arr[deque[front]];
        }
    }

    free(deque);
    return M;
}
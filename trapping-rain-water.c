int trap(int* height, int heightSize) {
    if (heightSize == 0) {
        return 0;
    }

    int ans = 0;
    int l = 0;
    int h = heightSize - 1;
    int maxl = height[l];
    int maxh = height[h];

    while (l < h) {
        if (maxl < maxh) {
            l++;
            maxl = (height[l] > maxl) ? height[l] : maxl;
            ans += (maxl - height[l]);
        } else {
            h--;
            maxh = (height[h] > maxh) ? height[h] : maxh;
            ans += (maxh - height[h]);
        }
    }

    return ans;
}
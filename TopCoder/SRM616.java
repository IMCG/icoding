// removing the first element of the list and adding it back to the tail
public int countAlarms(int[] volume, int S) {
    int c = 0;
    while (S > 0) {
        c++; //increase count 
        int x = volume[0];
        S -= x;
        // move the first alarm to the end of the list:
        for (int i = 0; i < volume.length - 1; i++) {
            volume[i] = volume[i + 1];
        }
        volume[ volume.length - 1] = x; 
    }
    return c;
}

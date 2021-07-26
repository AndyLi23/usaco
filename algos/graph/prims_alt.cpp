//USE FOR WHEN EVERY NODE IS CONNECTED TO EVERY OTHER - COMPLEX GRAPH O(N^2)

void prims(int source) {
    FOR2(i, 1, N+1) {
        D[i] = INT_MAX; // set to max num
    }    
    FOR(iter, N) {
        //find closest unexplored node
        int min_i = 0;
        FOR2(i, 1, N+1) {
            if (!visited[i] && (min_i==0 || D[i] < D[min_i])) {
                min_i = i;
            }
        }
        //mark as explored
        visited[min_i] = 1;

        //update all unvisited nodes - if they have minimum distance to the current mode
        FOR2(j, 1, N+1) {
            if (!visited[j]) {
                D[j] = min(D[j], cost);
            }
        }
    }
}
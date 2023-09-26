#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100001

int heights[MAX_NODES]; // Memoization array to store computed heights

int calculateHeight(int* parents, int node) {
    if(heights[node] != -1){
        return heights[node];
    }

    if(parents[node] == -1){
        heights[node] = 1;
    }else{
        heights[node] = calculateHeight(parents, parents[node]) + 1;
    }
    return heights[node];
}

int main() {
    int n;
    scanf("%d", &n);

    int parents[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &parents[i]);
    }

    for (int i = 0; i < n; i++) {
        heights[i] = -1;
    }

    int max = 0;
    for(int i = 0; i<n; i++){
        calculateHeight(parents, i);
        if(heights[i] > max){
            max = heights[i];
        }
    }

    printf("%d", max);
    return 0;
}

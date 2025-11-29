#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float *a, *b, dot = 0;
    
    printf("Enter number of nutritional attributes: ");
    scanf("%d", &n);
    
    a = (float*)malloc(n * sizeof(float));
    b = (float*)malloc(n * sizeof(float));
    
    printf("\nEnter values for Food Item 1:\n");
    for(int i = 0; i < n; i++) {
        printf("Attribute %d: ", i + 1);
        scanf("%f", &a[i]);
    }
    
    printf("\nEnter values for Food Item 2:\n");
    for(int i = 0; i < n; i++) {
        printf("Attribute %d: ", i + 1);
        scanf("%f", &b[i]);
    }
    
    for(int i = 0; i < n; i++) {
        dot += a[i] * b[i];
    }
    
    printf("\nDot Product: %.2f\n", dot);
    
    if(dot > 50) {
        printf("Highly similar food items\n");
    } else if(dot >= 20) {
        printf("Moderately similar food items\n");
    } else {
        printf("Low similarity food items\n");
    }
    
    free(a);
    free(b);
    
    return 0;
}

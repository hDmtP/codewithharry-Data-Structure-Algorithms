#include <stdio.h>

int main() {
    int a[10],n, i;
    printf("Enter the decimal value: ");
    scanf("%d", &n);
    for(i=0;n>0;i++){
        a[i] = n%2;
        n = n/2;
    }
    printf("\nDecimal to Binary: ");
    // for(i = i-1; i >= 0; i--){
    //     printf("%d", a[i]);
    // }
    for (int j = i-1; j >= 0; j--)
    {
        printf("%d", a[j]);
    }
    
    
    return 0;
}

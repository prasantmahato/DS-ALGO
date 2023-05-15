#include <stdio.h>
 
long dec_to_bin(long n)
{
    long bin = 0;
    long dec = n;
    long i = 1;
 
    while (dec > 0) {
        bin += (dec % 2) * i;
        printf("(%ld, %ld)\t",bin,i);
        dec /= 2;
        i *= 10;
    }
 
    return bin;
}
 
int main(void)
{
    long n;
    printf("Enter a decimal number: ");
    scanf("%ld", &n);
    printf("Binary equivalent of %ld = %ld\n", n, dec_to_bin(n));
    return 0;
}
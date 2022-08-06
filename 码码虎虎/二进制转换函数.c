void dectobin(int n) 
{
    int q, sum, k = 1;
    scanf("%d", &n);
    while(n) {
        q = n%2;
        sum += q*k;
        n /= 2;
        k *= 10;
    }
    printf("%d", sum);
}
#include <stdio.h>

int main(void)
{
    int m, n, even_sum, odd_sum, i;

    while(scanf("%d%d", &m, &n) != EOF) {
        odd_sum = even_sum = 0;
        if(m > n) {  
            i = m;
            m = n;
            n = i;
        }
        for(i=m; i<=n; i++) {
            if(i & 1)        
                odd_sum += i * i * i;  
            else
                even_sum += i * i; 
        }
        printf("%d %d\n", even_sum, odd_sum);
    }

    return 0;
}

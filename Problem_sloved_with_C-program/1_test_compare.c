#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int t;
    int i;
    int val, pos, k = 1;
    scanf("%d", &t);
    while (t--)
    {
        int flag = 0;
        int num;
        scanf("%d", &num);
        int arr[num];
        for (int i = 1; i <= num; i++)
        {
            scanf("%d", &arr[i]);
        }

        scanf("%d", &val);
        for (i = 1; i <= num; i++)
        {
            if (arr[i] == val)
            {
                pos = i;
                flag = 1;
            }
        }
        if (flag)
            printf("Case %d: %d\n", k, pos);
        else
            printf("Case %d: Not Found\n", k);
        k++;
    }
    return 0;
}
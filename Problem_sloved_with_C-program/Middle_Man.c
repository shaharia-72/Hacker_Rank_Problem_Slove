#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void solve()
{
    int num, temp = 0;
    scanf("%d", &num);
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    // sort(arr,arr+num);

    for (int i = 0; i < num; ++i)
    {

        for (int j = i + 1; j < num; ++j)
        {

            if (arr[i] > arr[j])
            {

                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }

    temp = (num + 1) / 2;
    if (num % 2 == 1)
    {
        for (int i = 0; i < num; i++)
        {
            if (i == temp)
            {
                printf("%d", arr[i - 1]);
            }
        }
    }
    else if (num % 2 == 0)
    {
        for (int i = 0; i < num; i++)
        {
            if (i == temp)
            {
                printf("%d ", arr[i - 1]);
                printf("%d\n", arr[i]);
            }
        }
    }
}

int main()
{
    // S_Fastio;
    solve();

    return 0;
}

// #include <stdio.h>
// int main()
// {
//     int n, temp;
//     scanf("%d", &n);
//     int arr[n];

//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }

//     if (n % 2 == 1)
//     {
//         printf("%d", arr[n / 2]);
//     }
//     else
//     {
//         printf("%d %d", arr[n / 2 - 1], arr[n / 2]);
//     }

//     return 0;
// }

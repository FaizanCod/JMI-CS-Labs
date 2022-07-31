#include <stdio.h>

// #define min(x,y) (x<y ? x : y)

void min_sum_of_max_subarray (int arr[], int n)
{
    int sum = __INT16_MAX__;
    int s =0, e = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = i; j<n; j++)
        {
            int pref_sum = 0;
            for(int k = i; k<=j; k++)
                pref_sum += arr[k];
            if(pref_sum < sum)
            {
                sum = pref_sum;
                s = i;
                e = j;
            }
            else if(pref_sum == sum && (j - i) > (e - s))
            {
                s = i;
                e = j;
            }
        }
    }

    printf("\nThe minimum sum of the largest subarray is: \n");
    for (int i=s; i<=e; i++)
        printf("%d ", arr[i]);
    printf("= %d\n", sum);
}

int main()
{
    printf("\nFAIZAN CHOUDHARY\n20BCS021\n\n");

    int n;
    char ch;
    do
    {

        printf("\nEnter the size of the array: ");
        scanf("%d", &n);
        int arr[n];

        printf("\nEnter the array elements: ");
        for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
        min_sum_of_max_subarray(arr,n);

        printf("\nDo you want to enter again? (y/n): ");
        getchar();
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
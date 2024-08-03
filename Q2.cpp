#include<stdio.h>

int main()
{
    int n;
    printf("Input size of Matrix: ");
    scanf("%d",&n);
    int arr[n][n];
    int trans[n][n];
    printf("Input Matrix Elements: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
        printf("\n");
    }

    printf("Matrix Elements before Transpose are:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }

    printf("After Transpose:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            trans[j][i] = arr[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",trans[i][j]);
        }
        printf("\n");
    }

}

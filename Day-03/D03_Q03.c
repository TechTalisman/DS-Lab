#include<stdio.h>
int main() {
    int od,i,j,count=0;
    printf("Enter size of the square matrix: ");
    scanf("%d",&od);
    int mat[od][od];
    printf("Enter %d elements in the square matrix: ",od*od);
    for(i=0;i<od;i++) {
        for(j=0;j<od;j++) {
            scanf("%d",&mat[i][j]);
            if(mat[i][j]!=0) {
                count++;
            }
        }
    }
    printf("\nNo.of nonzero elements: %d\n",count);
    printf("\nUpper Triangular mAtrix:\n");
    for(i=0;i<od;i++) {
        for(j=0;j<od;j++) {
            if(j>=i) {
                printf("%d ",mat[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\nElements just below main diagonal: \n");
    for(i=0;i<od;i++) {
        for(j=0;j<od;j++) {
            if(i==j+1) {
                printf("%d ",mat[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\nElements just above main diagonal: \n");
    for(i=0;i<od;i++) {
        for(j=0;j<od;j++) {
            if(j==i+1) {
                printf("%d ",mat[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}

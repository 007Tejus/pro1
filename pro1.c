#include<stdio.h>
#include<stdlib.h>

int main() {
    int *arr;
    int i, n, pos, key, x, choice, found = 0;

    printf("\nEnter the number of elements in the Array: ");
    scanf("%d", &n);
    
    arr = (int*)malloc(n * sizeof(int));

    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    printf("\nThe elements of the array are:\n");
    for (int i = 0; i < n; i++) {
        printf("*(arr+%d)=%d\n", i, *(arr + i));
    }

    do {
        printf("\n1->INSERT\n2->DELETE\n3->SEARCH\n4->EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                printf("Enter the position at which the element must be inserted: ");
                scanf("%d", &pos);

                n++;
                for (i = n - 1; i >= pos; i--) {
                    *(arr + i) = *(arr + i - 1);
                }
                *(arr + pos - 1) = x;

                printf("\nThe elements of the array are:\n");
                for (int i = 0; i < n; i++) {
                    printf("*(arr+%d)=%d\n", i, *(arr + i));
                }
                break;

            case 2:
                printf("Enter the position of the element to be deleted: ");
                scanf("%d", &pos);

                for (int i = pos; i <= n - 1; i++) {
                    *(arr + i - 1) = *(arr + i);
                }
                n--;

                printf("\nThe elements of the array are:\n");
                for (int i = 0; i < n; i++) {
                    printf("*(arr+%d)=%d\n", i, *(arr + i));
                }
                break;

            case 3:
                found = 0;
                printf("Enter the element to be searched: ");
                scanf("%d", &key);

                for (int i = 0; i < n; i++) {
                    if (*(arr + i) == key) {
                        found = 1;
                        printf("The key element %d is found at position %d\n", key, i + 1);
                        break;
                    }
                }

                if (found == 0) {
                    printf("The key element is not present in the array\n");
                }
                break;

            case 4:
                exit(1);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 4);

    
    return 0;
}

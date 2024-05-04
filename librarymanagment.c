#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library {
    int book_id;
    char book_name[100];
    char author_name[100];
    float cost;
    int no_of_pages;
};

void addBook(struct library *lib, int *count) {
    printf("\nYou can add the details of the book\n");
    printf("Enter the book ID: ");
    scanf("%d", &lib[*count].book_id);
    printf("Enter the book name: ");
    scanf(" %[^\n]", lib[*count].book_name);
    printf("Enter the author name: ");
    scanf(" %[^\n]", lib[*count].author_name);
    printf("Enter the number of pages: ");
    scanf("%d", &lib[*count].no_of_pages);
    printf("Enter the cost of the book: ");
    scanf("%f", &lib[*count].cost);
    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(struct library *lib, int count) {
    if (count == 0) {
        printf("\nThere are no books stored!\n\n");
    } else {
        printf("\nList of books:\n");
        for (int i = 0; i < count; i++) {
            printf("Book ID: %d\n", lib[i].book_id);
            printf("Book Name: %s\n", lib[i].book_name);
            printf("Author Name: %s\n", lib[i].author_name);
            printf("Number of Pages: %d\n", lib[i].no_of_pages);
            printf("Cost: %.2f\n\n", lib[i].cost);
        }
    }
}

void deleteBook(struct library *lib, int *count, int bookId) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (lib[i].book_id == bookId) {
            found = 1;
            
            for (int j = i; j < *count - 1; j++) {
                lib[j] = lib[j + 1];
            }
            (*count)--;
            printf("Book with ID %d deleted successfully!\n", bookId);
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found!\n", bookId);
    }
}

int main() {
    struct library lib[100];
    int count = 0;
    int choice;

    do {
        printf("\n\n1. Add Book details\n");
        printf("2. Display the list of books and its details\n");
        printf("3. Display the total number of books in the library\n");
        printf("4. Exit\n");
        printf("5. Delete a Book\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(lib, &count);
                break;
            case 2:
                displayBooks(lib, count);
                break;
            case 3:
                printf("\nTotal number of books in the library: %d\n", count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            case 5:
                if (count == 0) {
                    printf("There are no books to delete!\n");
                } else {
                    int bookId;
                    printf("Enter the book ID to delete: ");
                    scanf("%d", &bookId);
                    deleteBook(lib, &count, bookId);
                }
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 4);

    return 0;
}

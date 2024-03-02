#include<stdio.h>

struct Book {
    char title[51];
    char author[51];
    int pages = 0;

    void registerBook() {
        printf("Digite o nome do livro: ");
        scanf("%[^\n]%*c", title);

        printf("Digite o autor do livro: ");
        scanf("%[^\n]%*c", author);

        printf("Digite o numero de paginas do livro: ");
        scanf("%d", &pages);
    }

    void showBook() {
        printf("Título do livro: %s\n", title);
        printf("Autor do livro: %s\n", author);
        printf("Numero de paginas do livro: %d\n\n", pages);
    }
};

struct Library {
    Book books[10];
    int amountOfBooks = 0;
    
    void registerBook() {
        if (amountOfBooks == 10) {
            printf("Não é possível registrar mais livros (só é possível registrar até 10 livros).\n\n");
        } else {
            books[amountOfBooks].registerBook();
            printf("\n");
            
            amountOfBooks += 1;   
        }
    }

    void showAllBooks() {
        if (amountOfBooks == 0) {
            printf("Não há nenhum livro registrado.\n");
            printf("\n");
        } else {
            for (int i = 0; i < amountOfBooks; i++) {
                printf("Livro %d:\n", i + 1);
                books[i].showBook();
            } 
        }
    }

    void showBookWithMostPages() {
        if (amountOfBooks == 0) {
            printf("Não há nenhum livro registrado.\n");
            printf("\n");
        } else {
            int numberOfPages = 0;
        
            for (int i = 0; i < amountOfBooks; i++) {
                if (books[i].pages > numberOfPages) {
                    numberOfPages = books[i].pages;
                }
            }
        
            printf("Livro(s) com o maior número de páginas:\n\n");    
        
            for (int i = 0; i < amountOfBooks; i++) {
                if (books[i].pages >= numberOfPages) {
                    books[i].showBook();
                }
            }
        }
    }
};

int main() {
    Library library;

    int choice = 0;

    do {
        printf("O que deseja fazer?\n\n");
        printf("1. Registrar livro (já registrou %d livros de 10 livros)\n", library.amountOfBooks);
        printf("2. Mostrar os livros registrados\n");
        printf("3. Mostrar livro(s) com o maior numero de paginas\n");
        printf("4. Sair do programa\n\n");
        printf("Digite sua escolha: ");
        
        scanf("%d%*c", &choice);
        
        printf("\n");

        switch (choice) {
        case 1:
            library.registerBook();
            break;
            
        case 2:
            library.showAllBooks();
            break;
            
        case 3:
            library.showBookWithMostPages();
            break;
        }
    } while (choice != 4);

    return 0;
}
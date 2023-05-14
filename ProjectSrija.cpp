#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
main() {
    void crtfile(void);
    void writefile(void);
    void readfile(void);
    void modifyfile(void);
    void deletefile(void);
	int n;

    	
    do {
		printf("\n\t	Main menu for File Management System\n");
        printf("\n\t Press	1 - file creation ");
        printf("\n\t        2 - write in the file");
        printf("\n\t        3 - read from the file");
        printf("\n\t        4 - modifying the file");
        printf("\n\t        5 - deleting the file");
        printf("\n\t        6 - quit");
        printf("\n\n Enter your choice: ");
        scanf("%d", &n);
	     
        switch (n) {
            case 1:
                crtfile();
                break;
            case 2:
                writefile();
                break;
            case 3:
                readfile();
                break;
            case 4:
                modifyfile();
                break;
            case 5:

                deletefile();
                break;
            case 6:
                printf("End of Program\n");
                exit (0);
				break;        
        }
    } while (n!=5);

}/* end of main program */

void crtfile(void) {
    FILE *file;
    char fileName[100];

    printf("Enter the name of the file to be created: ");
    scanf("%s", fileName);

    file = fopen(fileName, "w");

    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }

    printf("File created successfully.\n");

    fclose(file);
}

void writefile(void) {
    FILE *file;
    char fileName[100];
    char content[1000];

    printf("Enter the name of the file: ");
    scanf("%s", fileName);

    file = fopen(fileName, "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter the content to write (max 1000 characters):\n");
    scanf(" %[^\n]", content);

    fprintf(file, "%s\n", content);
    printf("Content written to the file.\n");

    fclose(file);
}

void readfile(void) {
    FILE *file;
    char fileName[100];
    char content[1000];

    printf("Enter the name of the file: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("File content:\n");

    while (fgets(content, sizeof(content), file) != NULL) {
        printf("%s", content);
    }

    fclose(file);
}

void modifyfile(void)
{
   FILE *ft;
   char fileName[100];

    printf("Enter the name of the file: ");
    scanf("%s", fileName);
    ft = fopen(fileName, "r+");
    if (ft == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char ch;
    int loc;
 	printf("\n Enter a character to be put in the file: ");
    scanf("%c",&ch);
    printf("\n Enter the location where the character is to be put: ");
    scanf("%d",&loc);
    fseek(ft,loc-1,SEEK_SET);
    putc(ch,ft);
    fclose(ft);
    printf("Content modified with the given input \n");
}
void deletefile(void) {
    char fileName[100];

    printf("Enter the name of the file: ");
    scanf("%s", fileName);

    if (remove(fileName) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error deleting file.\n");
    }
}



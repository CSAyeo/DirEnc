#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include<conio.h>

int fixedKey = 2;

int getHash (char * s) {
    printf("Getting hash");
    char * t; // first copy the pointer to not change the original
    int hash = 0;
    for (t = s; *t != '\0'; t++) {
        hash = (hash + (int)*t)%26;
        printf("Val: %ld", hash);
    }
    return hash+fixedKey;
}

int main() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }
    return 0
}
int encrypt(){
    char pass[20], ch;
    FILE *fps, *fpt;
    puts("Enter your password:");
    gets(pass);
    int hash = getHash(pass);
    printf("Hash: %ld", hash);
    char fname[30]= "../flower.jpg";
    fps = fopen(fname, "r");
    if(fps == NULL)
        return 1;
    fpt = fopen(fname, "w");
    if(fpt == NULL)
        return 1;
    ch = fgetc(fps);
    while(ch != EOF)
    while(ch != EOF)
    {
        ch = ch+hash;
        fputc(ch, fpt);
        ch = fgetc(fps);
    }
    fclose(fps);
    fclose(fpt);
    fps = fopen(fname, "w");
    if(fps == NULL)
        return 0;
    fpt = fopen(fname, "r");
    if(fpt == NULL)
        return 0;
    ch = fgetc(fpt);
    while(ch != EOF)
    {
        ch = fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
    printf("\nFile %s Encrypted Successfully!", fname);
    getch();
    return 0;
}

    /*std::cout << "Hello, World!" << std::endl;
    int x  = 3;
    Console.Writeli
    return 0;
}
     */

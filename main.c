#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include "function.c"

// Fonction pour lire le "perroquet" depuis un fichier
void read_perroquet(char *perroquet, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", filename);
        exit(1);
    }
    fscanf(file, "%s", perroquet);
    fclose(file);
}

// La fonction qui permet de chiffrer
void encrypt_text(const char *source, const char *dest, const char *perroquet) {
    FILE *srcFile = fopen(source, "r");
    FILE *destFile = fopen(dest, "w");
    if (srcFile == NULL || destFile == NULL) {
        printf("Il faut creer le fichier source\n");
        exit(1);
    }

    int c, i = 0, perroquet_len = strlen(perroquet);
    while ((c = fgetc(srcFile)) != EOF) {
        fputc(c - perroquet[i % perroquet_len], destFile);
        i++;
    }

    fclose(srcFile);
    fclose(destFile);
    // Permet la suppression du fichier qui à été chiffré
    remove(source);
}

int main() {
    char perroquet[100];
    read_perroquet(perroquet, "peroq.def");

    // Menu utilisateur
    int choice;
    printf("1. Chiffrer le fichier source.txt\n");
    printf("2. Dechiffrer le fichier dest.crt\n");
    printf("3. Quitter\n");
    printf("Votre choix: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        encrypt_text("source.txt", "dest.crt", perroquet);
        printf("Le fichier a ete chiffre et sauvegarde dans dest.crt\n");
        break;
    case 2:
        decrypt_text("dest.crt", "decrypted.txt", perroquet);
        printf("Le fichier a ete déchiffre et sauvegarde dans decrypted.txt\n");
        break;
    case 3:
        printf("Au revoir!\n");
        break;
    default:
        printf("Choix non valide.\n");
    }

    return 0;
}


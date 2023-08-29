void decrypt_text(const char *source, const char *dest, const char *perroquet) {
    FILE *srcFile = fopen(source, "r");
    FILE *destFile = fopen(dest, "w");

    if (srcFile == NULL || destFile == NULL) {
        printf("Erreur lors de l'ouverture des fichiers.\n");
        exit(1);
    }

    int c, i = 0, perroquet_len = strlen(perroquet);

    while ((c = fgetc(srcFile)) != EOF) {
        fputc(c + perroquet[i % perroquet_len], destFile);
        i++;
    }

    fclose(srcFile);
    fclose(destFile);
}


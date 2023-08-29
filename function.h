#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype pour lire le "perroquet" depuis un fichier
void read_perroquet(char *perroquet, const char *filename);

// Prototype pour la fonction qui permet de chiffrer
void encrypt_text(const char *source, const char *dest, const char *perroquet);

// Prototype pour la fonction qui permet de déchiffrer
void decrypt_text(const char *source, const char *dest, const char *perroquet);

#endif // FUNCTION_H

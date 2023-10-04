#ifndef ETAT_H
#define ETAT_H
#include <stdbool.h>
/**
 * @brief Structure représentant un état
 * @param name Nom de l'état
 * @param isInitial Booléen indiquant si l'état est initial
 * @param isFinal Booléen indiquant si l'état est final
*/
typedef struct State State;
struct State
{
    char name[20];
    bool isInitial;
    bool isFinal;
};
#endif

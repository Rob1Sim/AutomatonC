#include <stdbool.h>
#include "State.h"

/**
 * @brief Structure représentant une transition
 * @param initialState State de départ de la transition
 * @param finalState State d'arrivée de la transition
 * @param symbol Symbole de la transition
*/
typedef struct Transition Transition;
struct Transition
{
    State *initialState;
    State *finalState;
    char symbol;
};

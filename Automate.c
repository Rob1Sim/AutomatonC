#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "State.h"
#include "Transition.h"

int main(int argc, char const *argv[])
{
    /* code */
    // 1 : Demander combien il veut d'etat
    // 2 : Créer un tableau dynamique
    // 3 : On lui demande de renseigner les noms de états
    // 4 : On affiche les états de la façon suivante : 1: nomEtat1, 2: nomEtat2, ...
    // 5 : On demande quel état est initial et terminal
    // 6 : On demande combien il veut de transition
    // 7 : On crée un tableau dynamique
    // 8 : On lui demande de renseigner les transitions
    State etat1 = {"q1", true, true};
    State etat2 = {"q2", false, false};
    Transition transition1 = {&etat1, &etat2, 'a'};
    Transition transition2 = {&etat2, &etat1, 'b'};
    Transition transition3 = {&etat1, &etat1, 'b'};
    Transition transitions[3] = {transition1, transition2, transition3};
    runDfa(&etat1, transitions, 3, "abba"); // Mot par reconnue
    runDfa(&etat1, transitions, 3, "bbbb"); // Mot reconnue


    return 0;
}

/**
 * @brief Look for a transition in a transition array by a letter and an initial state
 * @param state The initial state of the transition
 * @param transitions The transition array
 * @param transitionSize The size of the transition array
 * @param letter The letter of the transition
 * @return State ou NULL
*/
Transition findTransition(State *state, Transition *transitions, int transitionSize, char *letter){
    for (int i = 0; i < transitionSize; i++)
    {
        if (transitions[i].initialState == state && transitions[i].symbol == letter)
        {
            return transitions[i];
            break;
        }
        
    }
    Transition transitionFinal = {NULL, NULL, '\0'};
    return transitionFinal;
}
/**
 * @brief Verify if a word is recognize by a DFA
 * @param initialState Initial state of the DFA
 * @param transitions Transitions of the DFA
 * @param transitionSize Transition size
 * @param word Word to verify
 * @return void
*/
void runDfa(State *initialState, Transition *transitions, int transitionSize, char *word)
{
    int wordSize = strlen(word);
    bool isWordRecognize = true;
    for (int i = 0; i < wordSize; i++)
    {
        Transition transition = findTransition(initialState, transitions, transitionSize, word[i]);
        if (transition.initialState == NULL)
        {
            if (i == 0){
                printf("The first letter of the word is not a part of the initial state\n");
            }else{
                printf("The letter %c is not a part of %s state's\n", word[i], initialState->name);
            }
            break;
        }else if (i == wordSize - 1 && !transition.finalState->isFinal)
        {
            printf("The word is not recognize by the Automaton\n");
            isWordRecognize = false;
            break;
        }else{
        
            initialState = transition.finalState;
        }
    }
    if (isWordRecognize == true)
    {
        printf("The word has been recognize by the Automaton\n");

    }
}

// TODO: Faire des tests unitaires pour la résolution de l'automate
// TODO: Vérifier si un automate est complet
// TODO: Vérifier si un automate est déterministe (Vérifier que chaque transition est unique)
// TODO: Completer un automate
// TODO: Déterminiser un automate
// TODO: Faire un menu pour l'utilisateur (Créer/Importer un automate, résoudre un automate, etc.)
// TODO: Sauvegardez un automates dans un fichier
// TODO: Charger un automate depuis un fichier
// TODO: Supprimer un automate
// TODO: Modifier un automate
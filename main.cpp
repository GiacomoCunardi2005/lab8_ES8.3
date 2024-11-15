#include <iostream>

using namespace std;

// Definizione della struttura per un elemento della lista
struct typeSTR_EntitaLista
{
    int i_ValoreInformativo;                                // Campo che contiene il valore informativo dell'elemento
    typeSTR_EntitaLista* STR_p_PuntatoreProssimoElemento;   // Puntatore al prossimo elemento nella lista
};

// Funzione per controllare la presenza di un ciclo nella lista collegata
bool FX_bool_ControllaCiclo(typeSTR_EntitaLista* STR_p_Testa)
{
    void* arr_p_ArrayCelleMemoria[2];  // Array per memorizzare gli ultimi due puntatori visitati

    // Itera attraverso la lista
    while(STR_p_Testa->STR_p_PuntatoreProssimoElemento != nullptr)
    {
        // Controlla se il puntatore attuale è uguale a uno dei due memorizzati (indicando un ciclo)
        if((STR_p_Testa->STR_p_PuntatoreProssimoElemento == arr_p_ArrayCelleMemoria[0]) ||
           (STR_p_Testa->STR_p_PuntatoreProssimoElemento == arr_p_ArrayCelleMemoria[1])) {
            return true; // Rilevato un ciclo
        }

        // Aggiorna l'array con i puntatori visitati
        arr_p_ArrayCelleMemoria[1] = arr_p_ArrayCelleMemoria[0];                      // Sposta il puntatore più recente nel secondo slot
        arr_p_ArrayCelleMemoria[0] = STR_p_Testa->STR_p_PuntatoreProssimoElemento; // Salva il puntatore attuale nel primo slot
    }

    return false; // Nessun ciclo rilevato
}

int main()
{
    // Dichiarazione di tre nodi della lista
    typeSTR_EntitaLista* STR_p_Testa = nullptr;         // Puntatore alla testa della lista
    typeSTR_EntitaLista *STR_p_CodaLista1 = new typeSTR_EntitaLista; // Nodo intermedio
    typeSTR_EntitaLista *STR_p_CodaLista2 = new typeSTR_EntitaLista; // Nodo finale

    // Creazione del primo nodo (testa della lista)
    STR_p_Testa = new typeSTR_EntitaLista;
    STR_p_Testa->i_ValoreInformativo = 1;                               // Assegna il valore informativo
    STR_p_Testa->STR_p_PuntatoreProssimoElemento = STR_p_CodaLista1;    // Collega il primo nodo al secondo

    // Creazione del secondo nodo
    STR_p_CodaLista1->i_ValoreInformativo = 2;                          // Assegna il valore informativo
    STR_p_CodaLista1->STR_p_PuntatoreProssimoElemento = STR_p_CodaLista2; // Collega il secondo nodo al terzo

    // Creazione del terzo nodo (con ciclo)
    STR_p_CodaLista2->i_ValoreInformativo = 3;                          // Assegna il valore informativo
    STR_p_CodaLista2->STR_p_PuntatoreProssimoElemento = STR_p_Testa;    // Collega il terzo nodo al primo, formando un ciclo
    STR_p_Testa = STR_p_CodaLista2;                                     // Aggiorna la testa della lista (opzionale)

    /*
    Per disattivare il ciclo, decommenta questo blocco:
    STR_p_CodaLista2->i_ValoreInformativo = 3;
    STR_p_CodaLista2->STR_p_PuntatoreProssimoElemento = nullptr;  // Fine della lista senza ciclo
    STR_p_Testa = STR_p_CodaLista2;                              // Aggiorna la testa
    */

    // Verifica della presenza di un ciclo nella lista
    if(FX_bool_ControllaCiclo(STR_p_Testa) == true) {
        cout << "ciclo" << endl; // Stampa "ciclo" se è stato rilevato un ciclo
    }
    else{
        cout << "non ciclo" << endl; // Stampa "non ciclo" se la lista non contiene cicli
    }
}

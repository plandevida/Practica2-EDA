/**
 * Práctica que resuelve el problema de la estación de tren
 * que solo tiene una vía de entrada y salida del hangar.
 *
 * @author Daniel Serrano Torres
 * @author Juan Pérez Valbuena
 */

#include <iostream>
#include <string.h>
#include "Pila.h"
#include "Lista.h"

using namespace std;

/**
 * Función que se encarga de leer los datos por la salida estandar
 * y de inicializar los datos del sistema.
 *
 * @return int El numero de vagones de entrada al hangar.
 */
int viaDeEntrada(Pila<int> &entrada, Lista<int> &secuenciaSalida);
/**
 * Función que determiana si una combinación de bagones en el hangar
 * es posible de realizar.
 */
void hangarDeVagones(const int &numeroVagones, Pila<int> &entrada, Lista<int> &secuenciaSalida);

int main (int argv, char** argc) {
    
    Pila<int> entrada;
    Lista<int> secuenciaSalida;
    
    int numeroVagones = viaDeEntrada(entrada, secuenciaSalida);
    
    while ( numeroVagones != 0 ) {
        
        hangarDeVagones(numeroVagones, entrada, secuenciaSalida);
        
        entrada = Pila<int>();
        secuenciaSalida = Lista<int>();
        
        numeroVagones = viaDeEntrada(entrada, secuenciaSalida);
    }
    
    return 0;
}

int viaDeEntrada(Pila<int> &entrada, Lista<int> &secuenciaSalida) {
    
    int numeroVagones = 0;
    
    //cout << "Introduzce el número de bagones: ";
    
    cin >> numeroVagones;
    
    if ( numeroVagones != 0) {
        //cout << endl << "Escriba la secuencia resultante de los bagones: " << endl;
        
        for (int n = 0; n < numeroVagones; n++) {
            
            //if( n > 0 ) cout << "Queda/n " << numeroVagones-n << " bagón/es." << endl;
            
            int a;
            
            cin >> a;
            
            secuenciaSalida.ponDr(a);
        }
        
        for (int j = numeroVagones; j > 0 ; j--) {
            entrada.apila(j);
        }
    }
    
    return numeroVagones;
}

void hangarDeVagones(const int &numeroVagones, Pila<int> &entrada, Lista<int> &secuenciaSalida) {
    
    Pila<int> hangar;
    
    bool resultado = true;
    
    while( resultado && (! secuenciaSalida.esVacia() || ! hangar.esVacia()) ) {
        
        // Si el elemento de la cima es igual que el primer elemento
        // de la secuencia resultante lo sacamos de la pila.
        if (hangar.esVacia() || (! entrada.esVacia() && hangar.cima() < secuenciaSalida.primero()) ) {
            hangar.apila( entrada.cima() );
            entrada.desapila();
        }
        else if  (hangar.cima() == secuenciaSalida.primero() ) {
            
            hangar.desapila();
            secuenciaSalida.resto();
        }
        else if (hangar.cima() > secuenciaSalida.primero()) {
            resultado = false;
        }
    }
    
    if( resultado ) cout << "POSIBLE" << endl;
    else cout << "IMPOSIBLE" << endl;
}
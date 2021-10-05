/*
 * Alimentos.h
 *
 *  Created on: 12/09/2021
 *      Author: Jordana Betancourt Menchaca
 * 
 * La clase alimentos en donde se aplican los ordenamientos, a partir de la 
 * creación de objetos tipo Alimento en un vector
 */

#ifndef ALIMENTOS_H_
#define ALIMENTOS_H_

#include <string> 
#include <iostream> 
#include <vector>
#include <list>
#include <sstream>   
#include <fstream>
#include <iomanip>
#include "Alimento.h"

 using namespace std; 


class Alimentos {
private:
    vector <string> datos; //Para almacenar datos del archivo
    list<Alimento> alimentosR; //Lista doblemente ligada de Alimentos a partir de CSV

    //Para los métodos de ordenamiento
    void swap(vector<Alimento> &, int, int);
	void copyVector(vector<Alimento>&,vector<Alimento>&, int, int);
	void mergeArrayCal(vector<Alimento>&,vector<Alimento>&, int, int, int);
    void mergeArrayAlf(vector<Alimento>&,vector<Alimento>&, int, int, int);
	void mergeSplitCal(vector<Alimento>&,vector<Alimento>&, int, int);
    void mergeSplitAlf(vector<Alimento>&,vector<Alimento>&, int, int);
public:
    //Constructor
	Alimentos();
//Función para leer archivo CSV
    list<Alimento>leerAlimentos();
//Funciones para listas
	//Función para eliminar nodo
	void eliminaAlimento(string);
	//Función para insertar nodo
	void agregaAlimento(Alimento);
	//Función para mosntrar elementos de lista por más recientes
	void mostrarRecientes();
//Funciones para ordenamientos
    //Uso de merge sort para ordenamiento de alimentos por calorías o por orden 
    //alfabético
    void mostrarPorCalorias(list<Alimento>); 
    void mostrarPorOrdenA(list<Alimento>);
};

//Constructor default
/*
 * Constructor por default
 *
 * @param
 * return Objeto Alimentos
*/
Alimentos :: Alimentos(){
	datos ={};
}


//Lectura de archivo .csv para crear objetos de tipo alimento
/*
 * leerAlimentos
 *
 * @param 
 * @return vector<Alimento> 
 * 
 * Cambio de valores en un vector
 * 
*/
list<Alimento> Alimentos::leerAlimentos(){

    //Se lee el archivo 
    ifstream archivo("CaloriasAlimentosPrueba.csv");
    string linea,cal;
    char delimitador = ',';
    vector <string> datos;

//Leemos la primer línea y la descartamos porque es el encabezado
    getline(archivo,linea);
//Leemos todas las líneas
    while(getline(archivo,linea)){
        stringstream stream(linea); //Convertir cadena a stream
        string tipo,nombre,calorias;
        getline(stream,tipo,delimitador);
        getline(stream,nombre,delimitador);
        getline(stream,calorias,delimitador);

		Alimento aux(tipo,nombre,calorias);
		//Los alimentos se agregan al principio de la lista para simular que
		//son los que se agregaron recientemente
        alimentosR.push_front(aux); //Lista ligada de Alimentos
    }
     archivo.close();	
    return alimentosR;
}

//Métodos de double linked list
/*
 * eliminaAlimento
 *
 * @param string nombre
 * @return void
 * 
 * Elimina un nodo de la lista
 * 
*/
void Alimentos:: eliminaAlimento(string nombre){
	list<Alimento>::iterator it = alimentosR.begin();
	int aux;
	while( it != alimentosR.end() )
    {
	//Si el iterador encuentra el nombre del Alimento a borrar elimina ese nodo
       if(it->get_nombre() == nombre){
		   cout<<"El Alimento eliminado es: "<<endl;
		   it->printAlimentos();
		   alimentosR.erase(it);
		   break;
	   }
	   it ++;
	}
	//Si el iterador ya se encuentra al final de la lista y no hizo break
	// significa que dicho elemento no existe.
	if(it == alimentosR.end()){
		 cout<<"Alimento "<<nombre<<" no ha sido encontrado en la lista.\n"<<endl;
	}	
   
}
/*
 * añadeAlimento
 *
 * @param Alimento nuevo
 * @return void
 * 
 * Elimina un nodo de la lista
 * 
*/
void Alimentos:: agregaAlimento(Alimento nuevo){

	cout<<"Último Alimento agregado "<<endl;
	list<Alimento>::iterator it = alimentosR.begin();
	it->printAlimentos();
	while( it != alimentosR.end() )
    {
	//Para verificar que no existan Alimentos repetidos
       if(it->get_nombre() == nuevo.get_nombre()){
		   cout<<"\nAlimento "<<nuevo.get_nombre()<<" ya existe "<<endl;
		   break;
	   }
	   it ++;
	}
	//Si el iterador ya se encuentra al final de la lista y no hizo break
	// significa que dicho Alimento no existe y se puede agregar
	if(it == alimentosR.end()){
		alimentosR.push_front(nuevo);
		it = alimentosR.begin();
		cout<<"\nNuevo Alimento agregado "<<endl;
		it->printAlimentos();
	}	
 	
}
/*
 * mostrarRecientes
 *
 * @param list<Alimento>
 * @return void
 * 
 * Muestra los elementos agregados del más reciente al más antiguo
 * 
*/
void Alimentos:: mostrarRecientes(){
	
	list<Alimento>::iterator it = alimentosR.begin();
	int aux = 0;
	while( it != alimentosR.end() )
    {
	//Para imprimir todos los elementos de la lista
       cout<<"\n"<<aux<<". ";
	   it->printAlimentos();
	   it ++;
	   aux++;
	}		
}

//Métodos de ordenamiento
/*
 * swap
 *
 * @param vector<Alimento> por referencia, int i, int j
 * @return 
 * 
 * Cambio de valores en un vector
 * 
*/
void Alimentos::swap(vector<Alimento> &v, int i, int j) {
	Alimento aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

//Equivalente a un merge sort para acomodar por calorías
/*
 * mostrarPorCalorias
 *
 * @param vector<Alimento> con referencia
 * @return 
 * 
*/
void Alimentos :: mostrarPorCalorias(list<Alimento> pruebas){
	
	vector <Alimento> v(pruebas.begin(), pruebas.end());
	vector <Alimento> tmp(v.size());

	mergeSplitCal(v, tmp, 0, v.size() - 1);
    for (int i = 0; i<v.size(); i++){
        v[i].printAlimentos();  
    }

}


/*
 * mergeSplitCal
 *
 * @param vector<Alimento> &A, vector<Alimento> &B, int low, int mid, int high
 * @return 
 * 
 * Se encarga de usar recursión hasta llegar a los casos base
 * 
*/
void Alimentos::mergeSplitCal(vector<Alimento> &A, vector<Alimento> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplitCal(A, B, low, mid);
	mergeSplitCal(A, B, mid + 1, high);
	mergeArrayCal(A, B, low, mid, high);
	copyVector(A, B, low, high);
}

/*
 * mergeArreyCal
 *
 * @param vector<Alimento> &A, vector<Alimento> &B, int low, int mid, int high
 * @return 
 * 
 * Se encarga de acomodar el vector y agregar los valores al temporal
 * 
*/
void Alimentos::mergeArrayCal(std::vector<Alimento> &A, std::vector<Alimento> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i].get_calorias() < A[j].get_calorias()) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

/*
 * copyVector
 *
 * @param vector<T> con referencia
 * @return 
 * 
*/
void Alimentos::copyVector(std::vector<Alimento> &A, std::vector<Alimento> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

//Equivalente a un merge sort para ordenar alimentos alfabéticamente
void Alimentos :: mostrarPorOrdenA(list<Alimento> pruebas){
	
	vector <Alimento> v(pruebas.begin(), pruebas.end());
	vector <Alimento> tmp(v.size());

	mergeSplitAlf(v, tmp, 0, v.size() - 1);
    for (int i = 0; i<v.size(); i++){
        v[i].printAlimentos();  
    }
}

/*
 * mergeSplitAlf
 *
 * @param vector<Alimento> &A, vector<Alimento> &B, int low, int mid, int high
 * @return 
 * 
 * Se encarga de usar recursión hasta llegar a los casos base
 * 
*/
void Alimentos::mergeSplitAlf(vector<Alimento> &A, std::vector<Alimento> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplitAlf(A, B, low, mid);
	mergeSplitAlf(A, B, mid + 1, high);
	mergeArrayAlf(A, B, low, mid, high);
	copyVector(A, B, low, high);
}

/*
 * mergeArreyAlf
 *
 * @param vector<Alimento> &A, vector<Alimento> &B, int low, int mid, int high
 * @return 
 * 
 * Se encarga de acomodar alfabeticamente los alimentos  y agregar los valores al temporal
 * 
*/
void Alimentos::mergeArrayAlf(std::vector<Alimento> &A, std::vector<Alimento> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i].get_nombre() < A[j].get_nombre()) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

#endif

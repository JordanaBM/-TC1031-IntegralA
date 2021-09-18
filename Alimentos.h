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
    vector <Alimento> alimentosR; //Para crear objetos alimento

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
    //Función
    vector<Alimento>leerAlimentos();
    //Uso de merge sort para ordenamiento de alimentos por calorías o por orden 
    //alfabético
    void mostrarPorCalorias(vector<Alimento> &); 
    void mostrarPorOrdenA(vector<Alimento> &);
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
vector<Alimento> Alimentos::leerAlimentos(){

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
        datos.push_back(tipo);
        getline(stream,nombre,delimitador);
        datos.push_back(nombre);
        getline(stream,calorias,delimitador);
        datos.push_back(calorias); 

    }
     archivo.close();

     for (int i = 0; i<datos.size(); i = i+3){
         Alimento auxA(datos[i],datos[i+1],datos[i+2]);
         alimentosR.push_back(auxA);   
     }
    return alimentosR;
}

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
void Alimentos :: mostrarPorCalorias(vector<Alimento> &pruebas){
	vector<Alimento> v(pruebas);
	vector<Alimento> tmp(v.size());

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
void Alimentos :: mostrarPorOrdenA(vector<Alimento> &pruebas){
	vector<Alimento> v(pruebas);
	vector<Alimento> tmp(v.size());

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

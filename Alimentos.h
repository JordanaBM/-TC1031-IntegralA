/*
 * Alimentos.h
 *
 *  Created on: 12/09/2021
 *      Author: Jordana Betancourt Menchaca
 * 
 * La clase alimentos en donde se aplican los ordenamientos,  y métodos a partir 
 * de la creación de objetos tipo Alimento en lista y árbol BST
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
	BST bst; //Árbol para encontrar alimentos con calorías similares 

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
	string eliminaAlimento(string);
	//Función para insertar nodo
	string agregaAlimento(Alimento);
	//Función para mostrar elementos de lista por más recientes
	string mostrarRecientes();
//Funciones para ordenamientos
    //Uso de merge sort para ordenamiento de alimentos por calorías o por orden 
    //alfabético
    string mostrarPorCalorias(); 
    string mostrarPorOrdenA();
	//Recorrido inorder para encontrar Alimentos en un rango de calorías
	string encuentraNombre(string nom);
	string alimentosCalSimilares(int val);
	string alimentoCalIgual(int val);

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
    ifstream archivo("CaloriasAlimentos.csv");
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
		bst.add(aux); //Árbol Binario de Alimentos
    }
     archivo.close();	
    return alimentosR;
}

//Métodos de double linked list y árboles binarios
/*
 * eliminaAlimento
 *
 * @param string nombre
 * @return string
 * 
 * Elimina un nodo de la lista y árbol
 * 
*/
string Alimentos:: eliminaAlimento(string nombre){
	std::stringstream auxstr;
	list<Alimento>::iterator it = alimentosR.begin();
	int aux;
	while( it != alimentosR.end() )
    {
	//Si el iterador encuentra el nombre del Alimento a borrar elimina ese nodo
       if(it->get_nombre() == nombre){
		   auxstr <<"El Alimento eliminado es: "<<endl;
		   auxstr << it->printAlimentos();
		   alimentosR.erase(it);
		   //Removemos objeto alimento del árbol
		   bst.remove(*it);
		   return auxstr.str();
		   break;
	   }
	   it ++;
	}
	//Si el iterador ya se encuentra al final de la lista y no hizo break
	// significa que dicho elemento no existe.
	if(it == alimentosR.end()){
		 auxstr<<"Alimento "<<nombre<<" no ha sido encontrado en la lista.\n"<<endl;
	}
	return auxstr.str();	
   
}
/*
 * agregaAlimento
 *
 * @param Alimento nuevo
 * @return string
 * 
 * Elimina un nodo de la lista
 * 
*/
string Alimentos:: agregaAlimento(Alimento nuevo){
	std::stringstream aux;

	aux<<"Último Alimento agregado "<<endl;
	list<Alimento>::iterator it = alimentosR.begin();
	aux<< it->printAlimentos();
	while( it != alimentosR.end() )
    {
	/*Para verificar que no existan duplicados (Ya sea dos alimentos con mismo)
	 nombre o calorías*/
       if(it->get_calorias() == nuevo.get_calorias() || it->get_nombre() == nuevo.get_nombre()){
		   aux<<"\nYa existe un alimento con ese nombre o calorías "<<endl;
		   return aux.str();
		   break;
	   }
	   it ++;
	}
	//Si el iterador ya se encuentra al final de la lista y no hizo break
	// significa que dicho Alimento no existe y se puede agregar
	if(it == alimentosR.end()){
		//Agregamos alimento a la lista
		alimentosR.push_front(nuevo);
		//Agregamos alimento al árbol
		bst.add(nuevo);
		//Devolvemos el iterador al principio
		it = alimentosR.begin();
		aux<<"\nNuevo Alimento agregado "<<endl;
		//Imprimimos el último Alimento agregado
		aux << it->printAlimentos();

		//Escribimos el nuevo Alimento en el archivo .csv
		ofstream misAlimentos;
		misAlimentos.open("CaloriasAlimentos.csv", ios :: app);
		misAlimentos<<nuevo.get_tipo()<<","<<nuevo.get_nombre()<<",";
		misAlimentos<<nuevo.get_calorias()<<endl;
		misAlimentos.close();
	}	
 	return aux.str();
}
/*
 * mostrarRecientes
 *
 * @param 
 * @return string
 * 
 * Muestra los elementos agregados del más reciente al más antiguo
 * 
*/
string Alimentos:: mostrarRecientes(){
	std::stringstream auxstr;
	list<Alimento>::iterator it = alimentosR.begin();
	int aux = 1;
	while( it != alimentosR.end() )
    {
	//Para imprimir todos los elementos de la lista
       auxstr<<"\n"<<aux<<". ";
	   auxstr << it->printAlimentos();
	   it ++;
	   aux++;
	}		
	return auxstr.str();
}
/*
 * encuentraNombre
 *
 * @param string nom
 * @return string
 * 
 * Imprime alimento del nombre buscado
 * 
*/
string Alimentos :: encuentraNombre(string nom){
	std::stringstream aux;
	list<Alimento>::iterator it = alimentosR.begin();
	while( it != alimentosR.end() )
    {
	//Buscamos el nombre en la lista
       if(it->get_nombre() == nom){
		   aux<< it->printAlimentos();
		   return aux.str();
		   break;
	   }
	   it ++;
	   if(it == alimentosR.end()){
		   aux<<"Alimento no encontrado"<<endl;
	   }
	}
	return aux.str();
}
/*
 * alimentosCalSimilares
 *
 * @param int val
 * @return string
 * 
 * Imprime alimentos en un rango de +-5 del valor de calorías dado
 * 
*/
string Alimentos:: alimentosCalSimilares(int val){
	//Llamamos el método calSimilar de la clase BST
	 return bst.calSimilar(val);
}

/*
 * alimentoCalIguale
 *
 * @param int val
 * @return string
 * 
 * Imprime alimentos con calorías iguales a las ingresadas
 * 
*/
string Alimentos:: alimentoCalIgual(int val){
	//Llamamos al método buscaCal de la clase BST
	return bst.buscaCal(val);
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
 * @param 
 * @return string
 * 
*/
string Alimentos :: mostrarPorCalorias(){

	std::stringstream aux;
	
	vector <Alimento> v(alimentosR.begin(), alimentosR.end());
	vector <Alimento> tmp(v.size());

	mergeSplitCal(v, tmp, 0, v.size() - 1);
    for (int i = 0; i<v.size(); i++){
        aux << v[i].printAlimentos();  
    }
	return aux.str();

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
/*
 * mostrarPorOrdenA
 *
 * @param 
 * @return string
 * 
*/
string Alimentos :: mostrarPorOrdenA(){
	std::stringstream aux;

	vector <Alimento> v(alimentosR.begin(), alimentosR.end());
	vector <Alimento> tmp(v.size());

	mergeSplitAlf(v, tmp, 0, v.size() - 1);
    for (int i = 0; i<v.size(); i++){
        aux << v[i].printAlimentos();  
    }
	return aux.str();
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


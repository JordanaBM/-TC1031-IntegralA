/*
 * pruebas.cpp
 *
 *  Created on: 15/09/2021
 *      Author: Jordana Betancourt Menchaca A01707434
 * 
 * Al realizar la prueba se añadirán 3 alimentos más, por lo cual si se desea
 * realizar nuevamente deberán ser eliminados de CaloriasAlimentos.csv
 * 
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include "Alimentos.h"
#include "Alimento.h"

using namespace std;
int main(int argc, char* argv[]) {
  string in_ans = "", pre_ans = "";

  
  Persona persona; //Creo un objeto persona
  Alimentos my_alimento; //Creo objeto alimentos
  my_alimento.leerAlimentos(); //Leo los alimentos del archivo
  std::stringstream aux;
 
// El archivo inicia con 2 alimentos 
  Alimento manzana("Fruta","Manzana","52");
  Alimento pina("Fruta","Piña","55");

//Demostración de funcionamiento de ordenamientos merge sort

  in_ans = manzana.printAlimentos() + pina.printAlimentos();

	cout << "\n" <<"1.- Respuesta esperada en orden alfabético\n " << in_ans << 
  "\n Respuesta programa\n " << my_alimento.mostrarPorOrdenA()<< "\n";
  cout <<	(!in_ans.compare(my_alimento.mostrarPorOrdenA()) ? "success\n" : "fail\n");

  cout << "\n" <<"2.- Respuesta esperada en orden de calorías\n " << in_ans <<
   "\n Respuesta programa\n " << my_alimento.mostrarPorCalorias()<< "\n";
  cout <<	(!in_ans.compare(my_alimento.mostrarPorCalorias()) ? "success\n" : "fail\n");


// Funcionamiento métodos de consulta listas 
 in_ans = "\n1. "+ pina.printAlimentos() + "\n2. "+ manzana.printAlimentos();

   cout << "\n" <<"3.- Respuesta esperada en orden de agregación reciente\n " << in_ans <<
   "\n Respuesta programa\n " << my_alimento.mostrarRecientes()<< "\n";
  cout <<	(!in_ans.compare(my_alimento.mostrarRecientes()) ? "success\n" : "fail\n");

  in_ans = manzana.printAlimentos();

  cout << "\n" <<"4.- Respuesta esperada busqueda nombre Manzana \n " << in_ans <<
   "\n Respuesta programa\n " << my_alimento.encuentraNombre("Manzana")<< "\n";
  cout <<	(!in_ans.compare(my_alimento.encuentraNombre("Manzana")) ? "success\n" : "fail\n");

  in_ans = "Alimento no encontrado\n";
  cout << "\n" <<"5.- Respuesta esperada busqueda nombre Cebolla \n " << in_ans <<
   "\n Respuesta programa\n " << my_alimento.encuentraNombre("Cebolla")<< "\n";
  cout <<	(!in_ans.compare(my_alimento.encuentraNombre("Cebolla")) ? "success\n" : "fail\n");


// Funcionamiento de agregación de Alimentos en list y árbol
  Alimento albaricoque("Fruta","Albaricoque","43");
  Alimento pera("Fruta","Pera","54");
  Alimento platano("Fruta","Plátano","88");
  my_alimento.agregaAlimento(albaricoque);
  my_alimento.agregaAlimento(pera);
  my_alimento.agregaAlimento(platano);

  in_ans =	albaricoque.printAlimentos() + manzana.printAlimentos() + 
    pera.printAlimentos() + pina.printAlimentos() + platano.printAlimentos();

  cout << "\n" <<"6.- Respuesta esperada en orden alfabético\n " << in_ans 
  << "\n Respuesta programa\n " << my_alimento.mostrarPorOrdenA()<< "\n";
  cout <<	(!in_ans.compare(my_alimento.mostrarPorOrdenA()) ? "success\n" : "fail\n");

  cout << "\n" <<"7.- Respuesta esperada en orden de calorías\n " << in_ans <<
 "\n Respuesta programa\n " << my_alimento.mostrarPorCalorias()<< "\n";
  cout <<	(!in_ans.compare(my_alimento.mostrarPorCalorias()) ? "success\n" : "fail\n");


//Intentando agregar un mismo Alimento nuevamente
  string alimentoPera = my_alimento.agregaAlimento(pera);

  in_ans = "Último Alimento agregado \n" + platano.printAlimentos() + 
  "\nYa existe un alimento con ese nombre o calorías \n";

  cout << "\n" <<"8.- Respuesta esperada al agregar pera nuevamente \n " << in_ans <<
 "\n Respuesta programa\n " << alimentoPera<< "\n";
   cout <<	(!in_ans.compare(alimentoPera) ? "success\n" : "fail\n");


//Funcionamiento métodos de consulta árbol BST

 in_ans = "Alimentos con calorías similares a 47 kcal.\n" + albaricoque.printAlimentos() +
 manzana.printAlimentos();

   cout << "\n" <<"9.- Respuesta esperada Alimentos cal similar a 47\n" << in_ans <<
   "\n Respuesta programa\n " << my_alimento.alimentosCalSimilares(47)<< "\n";
  cout <<	(!in_ans.compare(my_alimento.alimentosCalSimilares(47)) ? "success\n" : "fail\n");

   in_ans = "Mostando resultados para alimento con 54 calorías\n" + pera.printAlimentos();

   cout << "\n" <<"10.- Respuesta esperada busqueda 54 calorías\n" << in_ans <<
   "\n Respuesta programa\n " << my_alimento.alimentoCalIgual(54)<< "\n";
  cout <<	(!in_ans.compare(my_alimento.alimentoCalIgual(54)) ? "success\n" : "fail\n");

// Funcionamiento de eliminación de Alimentos en list y árbol

string eliminaAlbaricoque = my_alimento.eliminaAlimento("Albaricoque");

  in_ans = "El Alimento eliminado es: \n" + albaricoque.printAlimentos();

 cout << "\n" <<"11.- Respuesta esperada al eliminar Albaricoque \n " << in_ans <<
 "\n Respuesta programa\n " << eliminaAlbaricoque<< "\n";
   cout <<	(!in_ans.compare(eliminaAlbaricoque) ? "success\n" : "fail\n");


  in_ans = "Alimento Fresa no ha sido encontrado en la lista.\n\n";

   cout << "\n" <<"12.- Respuesta esperada al eliminar Fresa \n " << in_ans <<
 "\n Respuesta programa\n " << my_alimento.eliminaAlimento("Fresa")<< "\n";
   cout <<	(!in_ans.compare(my_alimento.eliminaAlimento("Fresa")) ? "success\n" : "fail\n");

  //Prueba nuevamente de métodos de ordenamiento 

  in_ans =	manzana.printAlimentos() + 
    pera.printAlimentos() + pina.printAlimentos() + platano.printAlimentos();

	cout << "\n" <<"13.- Respuesta esperada en orden alfabético\n " << in_ans << 
  "\n Respuesta programa\n " << my_alimento.mostrarPorOrdenA()<< "\n";
  cout <<	(!in_ans.compare(my_alimento.mostrarPorOrdenA()) ? "success\n" : "fail\n");

  cout << "\n" <<"14.- Respuesta esperada en orden de calorías\n " << in_ans <<
   "\n Respuesta programa\n " << my_alimento.mostrarPorCalorias()<< "\n";
  cout <<	(!in_ans.compare(my_alimento.mostrarPorCalorias()) ? "success\n" : "fail\n");

  // Prueba nuevamente metodos acceso lista

  in_ans = "\n1. "+ platano.printAlimentos() + "\n2. "+ pera.printAlimentos() +
   "\n3. "+ pina.printAlimentos() + "\n4. "+ manzana.printAlimentos();

   cout << "\n" <<"15.- Respuesta esperada en orden de agregación reciente\n " << in_ans <<
   "\n Respuesta programa\n " << my_alimento.mostrarRecientes()<< "\n";
  cout <<	(!in_ans.compare(my_alimento.mostrarRecientes()) ? "success\n" : "fail\n");



}

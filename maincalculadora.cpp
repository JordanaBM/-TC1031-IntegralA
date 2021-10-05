/*
 * maincalculadora.cpp
 *
 *  Created on: 13/09/2021
 *      Author: Jordana Betancourt Menchaca A01707434
 */

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <stdio.h>
#include "Alimentos.h"
#include "Alimento.h"


using namespace std;
int main(){
    list <Alimento> pruebas;
	Persona persona; //Creo un objeto persona
	Alimentos alimento; //Creo objeto alimentos
	pruebas = alimento.leerAlimentos(); //Creo objetos alimento a partir de .csv


//Calcular calorías ejemplo
 	cout<<" =======Calorías Jordana================="<<endl;
	persona.calculaCalorias(42,156,19,"Mujer",2);
//Ordenamientos
 	cout<<"\n=======Ordenamientos================="<<endl;
	cout<<"\nEl orden alfabético de los alimentos es: "<<endl;
	alimento.mostrarPorOrdenA(pruebas);
	cout<<"\n\nEl orden por calorías de los alimentos es: "<<endl;
	alimento.mostrarPorCalorias(pruebas);
	cout<<"\n=========Uso de listas==============="<<endl;
	alimento.mostrarRecientes();
	cout<<endl;
	alimento.eliminaAlimento("Manzana");
	cout<<endl;
	alimento.eliminaAlimento("Papaya");
	cout<<endl;
	Alimento nuevoAl("Fruta","Naranja","45");
	alimento.agregaAlimento(nuevoAl);
	cout<<endl;
	alimento.mostrarRecientes();
	cout<<endl;
	//Alimento de CSV
	Alimento nuevoAli("Fruta","Pera","55");
	alimento.agregaAlimento(nuevoAli);

// 	//Declaro variables para ingresar datos
    int opcion, altura, edad,actFisica;
	float peso,porcion,calorias;
	string genero,tipo,nombre;
	
   
    //  do //Menú de opciones
	// {
	// 	cout<<"\n===========Menú=============\n"<<endl;
	// 	cout<<"1. Calcula tus calorías necesarias\n";
	// 	cout<<"2. Muestra alimentos por orden Alfabético\n";
	// 	cout<<"3. Muestra alimentos por calorías\n";
    //     cout<<"4. Elimina Alimento \n";
	//     cout<<"5. Agrega Alimento \n";
	//     cout<<"6. Encuentra Alimentos con Calorías similares\n";
	// 	cout<<"7. Salir\n";
	// 	cout<<"\n Digite la opcion que desee: ";
	// 	//Leer indice que selecciona la opción del menú
	// 	cin>>opcion;

    //     //Switch donde dependiendo la elección efectua un diferente procedimiento
	// 	switch (opcion)
	// 	{
	// 		//Caso 1: Para calcular las calorías que necesita una persona
	// 		case 1: 
	// 		cout<<"\nCalculadora de calorías \n\n";
	// 		cout<<"Digite su peso en kilogramos: ";
	// 		cin>>peso;
	// 		cout<<"\nDigite su altura en centímetros: ";
	// 		cin>>altura;
	// 		cout<<"\nDigite su edad: ";
	// 		cin>>edad;
	// 		cout<<"\nDigite su sexo (Mujer/Hombre): ";
	// 		cin>>genero;
	// 		cout<<"\nTeclee el número de sus actividad física: "<<endl;
	// 		cout<<"1.Nada de actividad física"<<endl;
	// 		cout<<"2.Ejercicio ligero (dos días por semana)"<<endl;
	// 		cout<<"3.Ejercicio moderado (cuatro días por semana)"<<endl;
	// 		cout<<"4.Deporte regular (6 días a la semana)"<<endl;
	// 		cout<<"5.Deportista o entrenamiento intenso cada día"<<endl;
	// 		cin>>actFisica;
	// 		persona.calculaCalorias(peso,altura, edad,genero,actFisica);
	// 		break;

	// 		//Caso 2: Para mostrar los alimentos por orden alfabético
	// 		case 2:
	// 		cout<<"\n=======Alimentos en Orden Alfabético=============\n"<<endl;
	// 		alimento.mostrarPorOrdenA(pruebas);
	// 		break;

	// 		//Caso 3: Para mostrar los alimentos por sus calorías
	// 		case 3:
	// 		cout<<"\n=======Alimentos en Por Calorías Ascendente=============\n"<<endl;
	// 		alimento.mostrarPorCalorias(pruebas);
	// 		break;
	
	// 		//Caso 4: Para eliminar Alimentos
	// 		case 4:
	// 		cout<<"\n=======Elimina Alimento=============\n"<<endl;
	// 		cout<<"Digite el nombre del alimento que desea eliminar de la lista ";
	// 		cin>>nombre;
	// 		alimento.eliminaAlimento(nombre);

	// 		//Caso 5: Para añadir Alimentos
	// 		case 5:
	//         cout<<"\n=======Agrega Alimento=============\n"<<endl;
    //         cout<<"Digite el tipo de Alimento (ej. Verdura,Proteína): ";
	// 		cin>>tipo;
	// 		cout<<"Digite el nombre del alimento empezando con mayúscula: ";
	// 		cin>>nombre;
	// 		cout<<"Digite la porción de alimento en gramos:  ";
	// 		cin>>porcion;
	// 		cout<<"Digite las calorías del alimento ";
	// 		cin>>calorias;
	// 		cout<<endl;
	// 		calorias = (calorias*100)/porcion;
	//         string calString;
	// 		stringstream ss;  
  	// 		ss << calorias;  
  	// 		ss >> calString;  
	//         Alimento nuevoAlimento(tipo,nombre,calString);
	// 		alimento.agregaAlimento(nuevoAlimento);
	// 		break;
			
			
			
    //     }
				
    // }while (opcion != 7); //Se sigue repitiendo el menú hasta que la opción sea 
	// 					 // (para salir del menú)

	
          
    return 0;
}

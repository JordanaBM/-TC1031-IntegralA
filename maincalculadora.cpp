/*
 * maincalculadora.cpp
 *
 *  Created on: 13/09/2021
 *      Author: Jordana Betancourt Menchaca
 */

#include <iostream>
#include <string>
#include "Alimentos.h"
#include "Alimento.h"


using namespace std;
int main(){
    vector<Alimento> pruebas;
	Persona persona; //Creo un objeto persona
	Alimentos alimento; //Creo objeto alimentos
	pruebas = alimento.leerAlimentos(); //Creo objetos alimento a partir de .csv


//Calcular calorías ejemplo
	persona.calculaCalorias(42,156,19,"Mujer",2);
//Ordenamientos
	cout<<"\nEl orden alfabético de los alimentos es: "<<endl;
	alimento.mostrarPorOrdenA(pruebas);
	cout<<"\n\nEl orden por calorías de los alimentos es: "<<endl;
	alimento.mostrarPorCalorias(pruebas);
	
	//Declaro variables para ingresar datos
    int opcion, altura, edad,actFisica;
	float peso;
	string genero;
	
   
    //  do //Menú de opciones
	// {
	// 	cout<<"1. Calcula tus calorías necesarias\n";
	// 	cout<<"2. Muestra alimentos por orden Alfabético\n";
	// 	cout<<"3. Muestra alimentos por calorías\n";
    //     cout<<"4. Muestra alimentos por tipo\n";
	// 	cout<<"5. Encuentra alimentos con calorías similares \n";
    //     cout<<"6. Agrega nuevo alimento\n";
    //     cout<<"7. Elimina alimento\n";
	// 	cout<<"8. Salir\n";
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
	// 		cout<<"\nDigite su género (Mujer/Hombre): ";
	// 		cin>>genero;
	// 		cout<<"\nTeclee el número de sus actividad física: "<<endl;
	// 		cout<<"1.Nada de actividad física"<<endl;
	// 		cout<<"2.Ejercicio ligero (dos días por semana)"<<endl;
	// 		cout<<"3.Ejercicio moderado (cuatro días por semana)"<<endl;
	// 		cout<<"4.Deporte regular (6 días a la semana)"<<endl;
	// 		cout<<"5.Deportista o entrenamiento intenso cada día"<<endl;
	// 		cin>>actFisica;
	// 		persona.calculaCalorias(peso,altura, edad,genero,actFisica);

	// 		//Caso 2: Para mostrar los alimentos por orden alfabético
	// 		case 2:
	// 		alimento.mostrarPorOrdenA(pruebas);

	// 		//Caso 3: Para mostrar los alimentos por sus calorías
	// 		case 3:
	// 		alimento.mostrarPorCalorias(pruebas);
	

			
			
    //     }
				
    // }while (opcion != 8); //Se sigue repitiendo el menú hasta que la opción sea 
	// 					 // (para salir del menú)

	
          
    return 0;
}

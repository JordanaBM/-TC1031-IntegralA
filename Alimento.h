/*
 * Alimentos.h
 *
 *  Created on: 12/09/2021
 *      Author: Jordana Betancourt Menchaca
 */

#ifndef ALIMENTO_H_
#define ALIMENTO_H_

#include <string> 
#include <iostream> 
#include <vector>
#include <list>
#include <sstream>   
#include <fstream>
#include <iomanip>

 using namespace std; 

 class Alimento {
    private:
        string tipo,nombre,cal;
        
    public:
    //Constructores
        Alimento(string tipoC,string nombreC,string calC){
            tipo = tipoC;
            nombre = nombreC;
            cal = calC;
        }

        Alimento(): tipo("N/A"),nombre("N/A"), cal("N/A"){}; 
    //Getters
        string get_calorias(){return cal;};
        string get_nombre(){return nombre;};
    //Funciones 
	    void printAlimentos(){
            cout<<" ========================"<<endl;
            cout<<"Todas las porciones son de 100 grs"<<endl;
            cout<<"Tipo: "<<tipo<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Calorías: "<<cal<<" Kcal"<<endl;
        };
};

//Clase persona
class Persona {
    public:
    
    void calculaCalorias(float,float, int, string, int);
	
};

void Persona:: calculaCalorias(float peso,float altura, int edad, string sexo, int actFisica) {
    float calorias;
    if (sexo == "Mujer"){
        calorias = (10* peso) + (6.25* altura) - (5 * edad) - 161;
        if (actFisica == 1){
            calorias = calorias * 1.2;
        }
        else if (actFisica == 2){
            calorias = calorias * 1.375;
        }
        else if (actFisica == 3){
            calorias = calorias * 1.55;
        }
        else if (actFisica == 4){
            calorias = calorias * 1.725;
        }
        else if (actFisica == 5){
            calorias = calorias * 1.9;
        }
        else{
            cout<<"Actividad física no existente"<<endl;
        }
    }
    else{
        calorias = (10 *peso) + (6.25* altura) - (5 *edad) + 5;
        if (actFisica == 1){
            calorias = calorias * 1.2;
        }
        else if (actFisica == 2){
            calorias = calorias * 1.375;
        }
        else if (actFisica == 3){
            calorias = calorias * 1.55;
        }
        else if (actFisica == 4){
            calorias = calorias * 1.725;
        }
        else if (actFisica == 5){
            calorias = calorias * 1.9;
        }
        else{
            cout<<"Actividad física no existente"<<endl;
        }
    
    }
    float hidrocarburos = calorias*.55;
    float proteinas = calorias*.15;
    float grasas = calorias*.30;

    cout<<"\nLas calorías que debes consumir al día son "<<calorias<<" KCal\n"<<endl;
    cout<<"Tu dieta debe contener un 55%"<<" de hidratos de carbono lo que equivale a: "<<endl;
    cout<<hidrocarburos<<" Kcal, lo que sería, aproximadamente "<<hidrocarburos/4;
    cout<<" gramos de fruta,verdura y carbohidratos\n"<<endl;
    cout<<"Tu dieta debe contener un 15%"<<" de proteínas lo que equivale a: "<<endl;
    cout<<proteinas<<" Kcal, lo que sería, aproximadamente "<<proteinas/4;
    cout<<" gramos de carnes y lácteos\n"<<endl;
    cout<<"Tu dieta debe contener un 30%"<<" de grasas lo que equivale a: "<<endl;
    cout<<grasas<<" Kcal, lo que sería, aproximadamente "<<grasas/9;
    cout<<" gramos de grasas y lácteos\n"<<endl;
}
#endif

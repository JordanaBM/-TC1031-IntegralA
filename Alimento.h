/*
 * Alimento.h
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
        string get_tipo(){return tipo;}
        string get_calorias(){return cal;};
        string get_nombre(){return nombre;};
    //Funciones 
	    string printAlimentos(){
			std::stringstream aux;
            aux <<" ========================"<<endl;
            aux <<"Todas las porciones son de 100 grs"<<endl;
            aux <<"Tipo: "<<tipo<<endl;
            aux <<"Nombre: "<<nombre<<endl;
            aux<<"Calorías: "<<cal<<" Kcal"<<endl;
			return aux.str();
        };
	
};

//Clase persona
class Persona {
    public:
    
    string calculaCalorias(float,float, int, string, int);
	
};

string Persona:: calculaCalorias(float peso,float altura, int edad, string sexo, int actFisica) {
    std::stringstream aux;
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
            aux <<"Actividad física no existente"<<endl;
			return aux.str();
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
            aux <<"Actividad física no existente"<<endl;
			return aux.str();
        }
    
    }
    float hidrocarburos = calorias*.55;
    float proteinas = calorias*.15;
    float grasas = calorias*.30;

    aux <<"\nLas calorías que debes consumir al día son "<<calorias<<" KCal\n"<<endl;
    aux <<"Tu dieta debe contener un 55%"<<" de hidratos de carbono lo que equivale a: "<<endl;
    aux <<hidrocarburos<<" Kcal, lo que sería, aproximadamente "<<hidrocarburos/4;
    aux<<" gramos de fruta,verdura y carbohidratos\n"<<endl;
    aux <<"Tu dieta debe contener un 15%"<<" de proteínas lo que equivale a: "<<endl;
    aux <<proteinas<<" Kcal, lo que sería, aproximadamente "<<proteinas/4;
    aux <<" gramos de carnes y lácteos\n"<<endl;
    aux <<"Tu dieta debe contener un 30%"<<" de grasas lo que equivale a: "<<endl;
    aux <<grasas<<" Kcal, lo que sería, aproximadamente "<<grasas/9;
    aux <<" gramos de grasas y lácteos\n"<<endl;
	return aux.str();
}



//Clase para crear un ábrol BST
// template <class T> class BST;

template <class T>
class Node {
private:
	Alimento value;
	Node *left, *right;

	Node<T>* succesor();
    
public:
	Node(Alimento);
	Node(Alimento, Node<Alimento>*, Node<Alimento>*);
	void add(Alimento);
	bool find(T);
	void remove(Alimento);
	std::string antesesor(T,Node<T>);
	//Implementaciones que emplearemos
	void calSimilar(Node<T>*,int,std::stringstream &aux) const;
	void buscaCal(Node<T> *,int,std::stringstream &aux) const;

	friend class BST;
};


//Constructor 
/*
 * Node
 *
 * @param Alimento val
 * @return Node<T>
 * 
*/
template <class T>
Node<T>::Node(Alimento val) : value(val), left(NULL), right(NULL) {}


/*
 * add
 *
 * @param Alimento val
 * @return 
 * 
*/
template <class T>
void Node<T>::add(Alimento val) {
	/*Si el valor de calorías es menor que las calorías del nodo actual se
	 agrega a la izquierda*/
	if (val.get_calorias() < value.get_calorias()) {
		if (left != 0) {
			left->add(val);
		//Hasta que la izquierda sea null agregamos el nuevo nodo
		} else {
			left = new Node<Alimento>(val);
		}
	/*Si el valor de calorías es mayor que las calorías del nodo actual se
	 agrega a la derecha*/
	} else {
		if (right != 0) {
			right->add(val);
		//Hasta que la derecha sea null agregamos el nuevo nodo
		} else {
			right = new Node<Alimento>(val);
		}
	}
}

/*
 * find
 *
 * @param T val
 * @return bool
 * 
*/
template <class T>
bool Node<T>::find(T val) {
	/*Si las calorias del alimento que se quiere encontrar son igual a las 
	calorías del nodo actual regresamos true*/
	if (val.get_calorias() == value.get_calorias()) {
		return true;
	/*Si las calorías del alimento son menores que las calorías del nodo actual
	 se busca a la izquierda*/
	} else if (val.get_calorias() < value.get_calorias()) {
		return (left != 0 && left->find(val));
	/*Si las calorías del alimento son menores que las calorías del nodo actual
	 se busca a la derecha*/
	} else if (val.get_calorias() > value.get_calorias()) {
		return (right != 0 && right->find(val));
	}
}


/*
 * calSimilar
 *
 * @param Node<T>, int val,stringstream
 * @return void
 * 
*/
template <class T>
void  Node<T>::calSimilar(Node<T> *root, int val, std::stringstream &aux) const {
	std::stringstream auxstr;
	//Agregamos 5 y restamos 5 para tener un intervalo de similitud
	int nuevoVal = val + 5;
	int nuevoVal2 = val - 5;
	stringstream ss,ss2;
	ss << nuevoVal;
	ss2 << nuevoVal2;
	//Cambiamos el valor a string
	string str = ss.str();
	string str2 = ss2.str();

	if (root == NULL){
        aux << ""; 
		return;
	}
	/* Vamos al hijo izquierdo */
	calSimilar(root->left,val,aux);
 
    /* Imprimimos el valor del nodo */
	if((root->value.get_calorias() <= str) && (root->value.get_calorias() >= str2)){
    	aux<< root->value.printAlimentos();
	}
    /* Ahora recurrimos al hijo derecho */
    calSimilar(root->right,val,aux);

}

/*
 * buscaCal
 *
 * @param Node<T>, int val,stringstream
 * @return void
 * 
*/
template <class T>
void Node<T>:: buscaCal(Node<T> *root,int val,std::stringstream &aux)const
{
	stringstream ss;
	ss << val;
	string str = ss.str();

	//Si el valor a buscar es igual al valor del nodo actual, se imprime
    if (str == root->value.get_calorias()) {
		aux << root->value.printAlimentos();	
		return;
		
	
	//Si el valor del nodo actual es menor al nombre se vuelve a llamar hacia la izquierda
	} 
	if ((str <= root->value.get_calorias()) && (root->left != 0)) {
		buscaCal(root->left,val,aux);
	//Si el valor del nodo actual es mayor al nombre se vuelve a llamar hacia la derecha	
	} 
	if ((str > root->value.get_calorias()) && (root->right != 0)) {
		buscaCal(root->right,val,aux);
	}
}

/*
 * succesor
 *
 * @param 
 * @return Node<T>*
 * 
*/
template <class T>
Node<T>* Node<T>::succesor() {
	Node<T> *le, *ri;

	le = left;
	ri = right;

	//Si el apuntador izquierdo tiene como null su apuntador derecho
	if (right->left == 0) {
		right = right->right;
		ri->right = 0;
		return ri;
	}

	Node<T> *parent, *child;
	parent = right;
	child = right->left;
	while (child->left != 0) {
		parent = child;
		child = child->left;
	}
	parent->left = child->right;
	child->right = 0;
	return child;
}


/*
 * remove
 *
 * @param Alimento val
 * @return void
 * 
*/
template <class T>
void Node<T>::remove(Alimento val) {
	Node<T> * succ, *old;

	if (val.get_calorias() < value.get_calorias()) {
		if (left != 0) {
			if (left->value.get_calorias() == val.get_calorias() && left->value.get_nombre() == val.get_nombre()) {
				old = left;
				if(old->left != 0 && old->right != 0){
					succ = left->succesor();
					if (succ != 0) {
						succ->left = old->left;
						succ->right = old->right;
					}
					left = succ;
				} else if (old->right != 0){ // solo hijo der
						left = old->right;
				} else if (old->left != 0){ // solo hijo izq
						left = old->left;
				} else {
						left = 0;
				}
				delete old;
			} else {
				left->remove(val);
			}
		}
	} else if (val.get_calorias() > value.get_calorias()) {
		if (right != 0) {
			if (right->value.get_calorias() == val.get_calorias() && right->value.get_nombre() == val.get_nombre()) {
				old = right;
				if(old->left != 0 && old->right != 0){ // dos hijos sucesor
					succ = right->succesor();
					if (succ != 0) {
						succ->left = old->left;
						succ->right = old->right;
					}
					right = succ;
				} else if (old->right != 0){ // solo hijo der
					right = old->right;
				} else if (old->left != 0){ // solo hijo izq
					right = old->left;
				} else {  // hoja
					right = 0;
				}
					delete old;
			} else {
				right->remove(val);
			}
		}
	}
}

//Clase para crear árboles BST
class BST {
private:
	Node<Alimento> *root;

public:
	BST();
	bool empty() const;
	void add(Alimento);
	bool find(Alimento) const;
	void remove(Alimento);
	//Implementaciones que emplearemos
	string calSimilar(int) const;
	string buscaCal(int) const;
};

//Constructor default
/*
 * Constructor
 *
 * @param 
 * @return BST
 * 
*/
BST::BST() : root(0) {}

/*
 * add
 *
 * @param Alimento val
 * @return void
 * 
*/
void BST::add(Alimento val) {
	//Si la raíz es diferente a 0 
	if (root != 0) {
		// Y, además no está repetido
		if (!root->find(val)) {
			//Lo agrego con la función de Node add
			root->add(val);
		}
	} else {
		//Si no, creo un nodo en la raíz
		root = new Node<Alimento>(val);
	}
}

/*
 * empty
 *
 * @param 
 * @return bool
 * 
*/
bool BST::empty() const {
	//Verifico si está vacío o no el árbol
	return (root == 0);
}

/*
 * calSimilar
 *
 * @param int val
 * @return string
 * 
*/
string BST::calSimilar(int val) const {
	std::stringstream aux;
	if (root == NULL){
        aux<<"No hay Alimentos en el árbol";
		return aux.str();
	}
	else{
	aux<<"Alimentos con calorías similares a "<<val<<" kcal."<<endl;
		if (!empty()) {
			 root->calSimilar(root,val,aux);
		}
	return aux.str();

	}

}

/*
 * buscaCal
 *
 * @param int nom
 * @return string
 * 
*/
string BST :: buscaCal(int nom)const{
	std::stringstream aux;
	//Mientras la raíz sea diferente a null
    if (root != 0) {
		aux <<"Mostando resultados para alimento con "<<nom<<" calorías"<<endl;
		if (!empty()) {
			 root->buscaCal(root,nom,aux);
		}
	return aux.str();	
	} else {
		aux <<"El árbol ésta vacío";
		return aux.str();
	}
    
}

/*
 * remove
 *
 * @param Alimento val 
 * @return void
 * 
*/
void BST::remove(Alimento val) {
	if (root != 0) {
		//Si encuentro que el alimento que quiero eliminar es la raíz
		if (val.get_nombre() == root->value.get_nombre()) {
			Node<Alimento> *succ = root->succesor();
			if (succ != 0) {
				succ->left = root->left;
				succ->right = root->right;
			}
			delete root;
			//Hago que el sucesor sea la nueva raíz
			root = succ;
		} else {
			//De otra forma llamo a remove de Node
			root->remove(val);
		}
	}
}


#endif

## Calculadora de calorías necesarias por día
Este proyecto se basa en la siguiente página web [Calculador de Calorías IMSS](http://www.imss.gob.mx/salud-en-linea/apps-sano/calculadora-calorias#tmb), que en conjunto con la información de [Cálculo de calorías diarias](https://www.axahealthkeeper.com/blog/calculo-de-calorias-diarias-cuantas-calorias-debo-consumir-al-dia/)  crea el programa que para su implementación sigue siguiente comporamiento:

Ejemplo 1: Jordana Betancourt Menchaca

* Paso 1: Introducir el peso del paciente.   **42 kg**
* Paso 2: Introducir la altura.  **156 cm**
* Paso 3: Introducir la edad.   **19 años**
* Paso 4: Introducir el género.  **"Femenino"**
* Paso 5: Introducir el nivel de actividad física.   **2**
1. Nada de actividad física
2. Ejercicio ligero (dos días por semana)
3. Ejercicio moderado (cuatro días por semana)
4. Deporte regular (6 días a la semana)
5. Deportista o entrenamiento intenso cada día"

  Lo que realiza el programa para calcular:
  - **TMB Mujer: (10 x peso) + (6,25 x altura) – (5 x edad) – 161**
  - TMB Jordana: (10 x 42) + (6.25 x 156) - (5 x 19) = 1139
  - Si realizas ejercicio ligero dos días por semana: TMB x 1,375

### **Obtenemos: 1566.125 Cal por día para Jordana**

# SICT0302B: Toma decisiones

## Selecciona un algoritmo de ordenamiento adecuado al problema

Para el problema se empleó un algoritmo de tipo merge sort, para ordenar alfabéticamente los alimentos por su nombre y otro para las calorías de menor a mayor, esto debido a que es rápido en la mayoría de los casos y porque es poco probable que me encuentre son su peor caso, ya que las lista inicial siempre estará medio desordenada y al añadir datos será desordenada. Las fuciones donde se puede ver es en mostrarPorCalorias y mostrarPorOrdenA en el archivo Alimentos.h las líneas 217 y 303 respectivamente.

## Selecciona y usa una estructura lineal adecuada al problema

Se emplea una lista doblemente encadenada para registrar Alimentos porque se quiere acceder rápidamente a los añadidos recientemente (head), pero también se necesita saber cual es la último en la lista (tail) , cada nodo es un objeto de tipo Alimento que contiene Tipo,Nombre y Calorías, los Alimentos se pueden insertar y eliminar usando la lista como se muestra en el código en las funciones eliminaAlimento, agregaAlimento y muestraRecientes, que se encuentran en el archivo Alimentos.h en las líneas 116,146 y 179 respectivamente.


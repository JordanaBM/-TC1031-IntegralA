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

Para el problema se empleó un algoritmo de tipo merge sort, para ordenar alfabéticamente los alimentos por su nombre y otro para las calorías de menor a mayor, esto debido a que es rápido en la mayoría de los casos y porque es poco probable que me encuentre son su peor caso, ya que las lista inicial siempre estará medio desordenada y al añadir datos será desordenada. Las fuciones donde se puede ver es en mostrarPorCalorias y mostrarPorOrdenA en el archivo Alimentos.h las líneas 299 y 395 respectivamente.

## Selecciona y usa una estructura lineal adecuada al problema

Se emplea una lista doblemente encadenada para registrar Alimentos porque se quiere acceder rápidamente a los añadidos recientemente (head), pero también se necesita saber cual es la último en la lista (tail) para emplear un iterador que lo recorra y evite que existan dos alimentos que tengan el mismo nombre o calorías , cada nodo es un objeto de tipo Alimento que contiene Tipo,Nombre y Calorías, los Alimentos se pueden insertar, eliminar o mostrar usando la lista como se muestra en el código en las funciones eliminaAlimento, agregaAlimento,muestraRecientes y encuentraNombre, que se encuentran en el archivo Alimentos.h en las líneas 123,158,206 y 229 respectivamente.

## Usa un árbol adecuado para resolver un problema

Se utilizó un árbol BST debido a que en el archivo los alimentos vienen poco ordenados por lo cual no se podría degenerar; de igual forma se pueden agregar y eliminar nodos del árbol como se muestra en las funciones eliminaElemento y agregaAlimento anteriormente mencionadas. Además, se implementaron funciones para encontrar alimentos sin tener que iterar toda la lista, estas son alimentosCalSimilares y alimentoCalIgual ubicadas en el archivo Alimentos.h en las líneas 256 y 270 respectivamente; a su vez, estás hacer referencia a calSimilar y buscaCal del archivo Alimento.h en las líneas 227<Nodo>/446<BST> y 263<Nodo>/470<BST> respectivamente.

# SICT0303B: Implementa acciones científicas
  
## Implementa mecanismos para consultar información de las estructras correctos

El programa tiene la opción de mostrar alimentos ordenados alfabéticamente (opción 2 en el menú) y por calorías de menor a mayor (opción 3) con Merge Sort.
  
Para consulta de listas, permite mostrar los alimentos de acuerdo a su tiempo de agregación, empezando por los más nuevos a más viejos (opción 4) y buscar por un nombre específico (opción 5)
  
El programa permite obtener alimentos con calorías iguales del árbol (opción 6 en el menú) y alimentos con calorías similares (opción 7).
  
## Implementa mecanismos de lectura de archivos correctos
  
Los alimentos están registrados en el archivo CaloriasAlimentos.csv de donde se leen al inicializar la función leerAlimentos del archivo Alimentos.h en la línea 85.

## Implementa mecanismos de escritura de archivos correctos
  
Los alimentos agregados se guardan al final del archivo CaloriasAlimentosPrueba.csv, con la función agregaAlimento del archivo Alimentos.h en la línea 158, para que no tengan que ser recapturados cada que vez que se corre el programa.

# SICT0301B
## Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa
  
  Los casos de pruebas para todas las funciones se encuentran pruebas.cpp donde se prueban las funciones de:

* Ordenamientos Merge sort (mostrarPorOrdenA y mostrarPorCalorias)

* Métodos de acceso a lista (mostrarRececientes y encuentraNombre)

* Agregación de nuevos alimentos a list y árbol (agregaAlimento)

* Métodos de consulta de árbol (alimentosCalSimilares y alimentoCalIgual)
  
* Eliminación de Alimentos en list y árbol (eliminaAlimento)
  
## Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes 
  
  ### Ordenamientos de Alimentos
  *Ordenamientos con Merge Sort*
  
  **mostrarPorCalorias y mostrarPorOrdenA:** Ambas funciones emplean recursividad, de modo que van diviendiendo el array en dos partes, hasta llegar a un sólo alimento y lo copian a otro array para acomodarlos, por lo cual su complejidad es O( n log (n)) <- El tiempo aumenta linealmente mientras que luego aumenta exponencialmente en el peor de los casos.
  
  ### Lista de Alimentos
  
  **agregaAlimento:**
  Se recorre toda la lista para verificar que el alimento que se quiera agregar no tenga el mismo nombre o calorías que otros por lo cual su complejidad es en el peor de los casos O(n) <- Lineal. Cuando comprueba que no existe simplemene lo agrega al principio de la lista O(1) <-Constante.
  
  **eliminaAlimento:** Recorre toda la lista hasta que encuentra el nombre del Alimento que se desea borrar, por lo cual su complejidad en el peor de los casos es O(n) <- Lineal, en donde el Alimento que se quiera eliminar se encuentra hasta el final de la lista. 
  
  **mostrarRecientes:** Imprime todos los alimentos de la lista hasta llegar al final, por lo cual su complejidad es O(n) <- Lineal en el peor de los casos
  
  **encuentraNombre:** Busca el nombre del Alimento que se desea encontrar recorriendo la lista, por lo cual su complejidad en el peor de los casos es O(n) <- Lineal, en donde el nombre de alimento que se quiere encontrar esté al final de la lista.
  
  ### Árbol de Alimentos

**agregaAlimento:** Como se empleó la misma función para lista y árbol en Alimentos. h, primero recorre toda la lista para verificar que no existan duplicados en nombre o calorías, después, si no existe ese alimento, lo agrega con add; por lo cual en el peor de los casos su complejidad es O(n) <- Lineal, donde incluso el agregar un elemento al árbol aunque recorra n/2 (agrega alimentos más pequeños a izquierda o  grandes a derecha) se redondea de igual forma a lineal.
  
**eliminaAlimento:** De igual forma se recorre toda la lista para buscar el nombre del alimento que se desea borrar, para posteriormente borrarlo del árbol con remove, de modo, que en el peor de los casos su complejidad sea O(n) <- Lineal, también para eliminar un alimento del árbol se recorre n/2 de éste, pero se redondea a lineal.
  
  **alimentosCalSimilares:** Se recorre un poco más de la mitad del árbol, esto debido a que las calorías similares se tomaron en un rango de +/-5 calorías, por lo cual puede que algunos alimentos tengan similares de ambos lados del árbol, por lo cual su complejidad en el peor de los casos es O(n) <- Lineal.
  
  **alimentoCalIgual:** Como no pueden existir duplicados, para encontrar un alimento por su valor de calorías, solamente se tendrá que recorrer n/2, es decir, la mitad del árbol, esto se redondea a n, por lo cual, en el peor de los casos, su complejidad es O(n) <- Lineal.


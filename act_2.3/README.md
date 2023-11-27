# Actividad 2.3 
## Programación de Estructura de Datos y Algoritmos 

### Como ejecutar el programa
```
g++ -std=c++11 main.cpp LinkedList.cpp -o project && ./project
```

En su defecto, puedes usar 

```
g++ -std=c++11 main.cpp LinkedList.cpp -o a.out
```
```
./a.out
```

### Makefile 

También se puede utilizar el siguiente comando para ejecutar el código: 
```
make run 
```

Para borrar la caché (la carpeta obj) utiliza el siguiente comando 
```
make clean
```



# Instrucciones

### ¿Qué tengo que hacer?

El canal de Suez es un canal navegable que conecta el mar Mediterráneo con el mar Rojo a través de alrededor de 190 km, uniendo por un el lado del mar Mediterráneo desde el puerto Said hasta el golfo de Suez en el mar Rojo. Este canal es navegado entre 49 y 97 barcos diariamente. Se tiene un registro de los barcos que navegan por el canal con el siguiente formato.

<fecha> <hora> <punto-entrada> <UBI-Identificador único del buque>

Ejemplo:

3-jan-20 13:45 M 8PAK7

Donde el punto de entrada puede ser M – Mar Mediterráneo y R – Mar Rojo.

En equipos de tres personas, hacer una aplicación que:

    Solicite el nombre del archivo de entrada (Ej. canal.txt) y lo abra, almacenando los datos en dos listas encadenadas, una para los que entran por el Mar Mediterráneo y otra para los buques que entran por el mar Rojo.
    Ordene ambas listas encadenadas por UBI + Fecha (primero por UBI, al haber empate ordenar por fecha).
    Solicite al usuario la serie a buscar (los primeros tres caracteres de el UBI).
    Despliegue mes por mes (empezando por el primer mes que venga un buque de esa serie y terminando en el mes de la última entrada) la cantidad de entrada de buques de esa serie por cada una de las entradas con el siguiente formato:

<mes><año> <cant-M> <cant-R><

Ejemplo:

jan 20 5 3

feb 20 2 4

mar 20 0 0

…

Realizar una investigación y reflexión en forma individual de la importancia y eficiencia del uso de la lista encadenada en una situación problema de esta naturaleza, generando un documento llamado "ReflexAct2.3.pdf"

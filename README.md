# TP1  AAyED UCR 2023 Manual de Usuario
Estudiantes: Keylor Palacios C25770 / Braunny Madrigal C24436

## Proyecto GIT: https://github.com/braunnymadrigal/AAyED_tp1.git

## ¿Cómo compilar y correr?
Abrir el archivo "algArbol.hh" y elegir la estructura del arbol con la que se desea ejecutar las pruebas, o sea se deben comentar las otras 3 estructuras de datos. Cuando este paso está listo se puede proceder a compilar de la siguiente forma:
1. Abrir shell en el directorio principal del proyecto
2. a Para compilar puede: ejecutar el comando de la siguiente manera "g++ main.cc interfaz.cc algArbol.cc -o algoritmos"
2. b Para compilar puede: escribir make compile en la consola
3. Ejecutar el comando ./algoritmos para correrlo

## ¿Cómo se usa?
Ejecuta el programa y a continuación se le presentará una interfaz diseñada completamente para ser utilizada en consola que le informara de como usar cada operador básico y algoritmos. El programa consiste de un menú principal que le permite 1) usar operadores básicos del árbol, 2)usar algoritmos del árbol, 3)ver manual, y 2 submenús que son aquellos que directamente le muestran cada operador o en su defecto cada algoritmo. Es importante recordar que el programa asume que el usuario leyó el manual y tiene entendido las especificaciones de cada operador y algoritmo. 

## ¿Qué funcionalidad implementa?
Se implementa la funcionalidad de una interfaz capaz de generar menús intuitivos para el usuario. Son implementados todos los operadores básicos de cada estructura de datos del modelo árbol n-ario tal que si importa el orden entre los hijos de un nodo. Los algoritmos del árbol también son implementados en su totalidad. Una cola implementada como una estructura de lista simplemente enlazada de forma totalmente funcional, la cola está totalmente emplantillada y es utilizada como modelo auxiliar para ciertos algoritmos del árbol. 

## ¿Que no fue implementado? 
Todos los casos fueron implementados y contemplados.

## Errores Conocidos:
Ninguno

## Arquitectura del programa: 
Todas las estructuras están implementada en archivos .hh, osea “header files”, ya que esto permite que el código sea más reutilizable, se sigue el estándar que use la propia librería estándar de C++ para implementar estructuras de datos. Dicho estándar es útil si en un futuro queremos usar templates con las estructuras, seguir las convenciones permite implementar templates en un corto periodo de tiempo. La interfaz si está implementada con su source file y su header file por aparte, la interfaz consiste de métodos muy pequeños que sirven como simples generadores de texto que ayuden al usuario a operar la estructura sin necesidad de entender cómo las estructuras están implementadas. La interfaz es semi modular, en el archivo header podemos ver las firmas y es posible notar que es relativamente sencillo cambiar el que hace cada método, tal que si se quiere probar una parte del programa u otra. Los algoritmos del árbol al igual que la interfaz están implementados con un archivo exclusivo para sus firmas y otro para la implementación de tales algoritmos, dichos algoritmos no dependen de ninguna estructura de datos específica y son además fácilmente modificables a conveniencia del programador. El archivo main.cc solo se encarga de crear una instancia de la interfaz y llamarla. 


## Especificación de las funciones del programa:
Navegar en menús.
Usar operadores básicos a través de un menú (hace traducciones de etiqueta a nodo y viceversa)
Usar algoritmos del árbol n-ario tal que si importa el orden entre los hijos de un nodo a través de un menú (hace traducciones de etiqueta a nodo y viceversa)

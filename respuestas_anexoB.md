# Anexo B: Respuestas a los ejercicios

Este anexo presenta respuestas a los ejercicios propuestos al final de cada uno de los nueve capítulos del libro. Para las preguntas conceptuales, se entrega una respuesta breve y directa; para los ejercicios de diseño, se entrega una posible solución en lenguaje C –generalmente no la única– junto con una explicación concisa. Se recomienda al lector intentar resolver cada ejercicio por su cuenta antes de consultar la respuesta correspondiente, ya que el aprendizaje surge principalmente del proceso de resolución, y no de la lectura de la solución.

## Capítulo 1: Introducción

1. Un algoritmo es una secuencia finita, ordenada y no ambigua de pasos que permite resolver un problema o realizar una tarea determinada.

2. Un algoritmo es una solución abstracta, independiente de cualquier lenguaje de programación; un programa es la implementación concreta de dicho algoritmo en un lenguaje específico, capaz de ser ejecutada por un computador.

3. El lenguaje de máquina corresponde al conjunto de instrucciones binarias (secuencias de 0 y 1) que el procesador puede interpretar y ejecutar directamente, sin necesidad de ninguna traducción adicional.

4. El bus de datos es el conjunto de líneas físicas que transportan información entre el procesador, la memoria y los demás dispositivos del computador.

5. Con un bus de datos de 30 bits es posible direccionar 2^30 = 1.073.741.824 celdas de memoria distintas.

6. Un bit es la unidad mínima de información, capaz de representar sólo dos estados (0 o 1); un byte agrupa 8 bits, y por lo tanto puede representar 2^8=256 valores distintos.

7. Para convertir un número decimal a hexadecimal, se divide sucesivamente por 16, registrando el resto de cada división (empleando las letras `A` a `F` para los restos entre 10 y 15), hasta que el cociente sea 0; el número hexadecimal resultante se lee ordenando los restos obtenidos desde el último hacia el primero. Por ejemplo, para convertir 202: 202÷16=12 resto 10 (`A`); 12÷16=0 resto 12 (`C`). Leyendo los restos en orden inverso, 202_10 = `CA`_16.

8. Un posible algoritmo: (1) apagar el interruptor de la luz; (2) verificar que la ampolleta esté fría; (3) conseguir una escalera si es necesario; (4) girar la ampolleta antigua en sentido antihorario hasta retirarla; (5) verificar el voltaje y tipo de la ampolleta nueva; (6) girar la ampolleta nueva en sentido horario hasta ajustarla; (7) encender el interruptor y verificar que funcione.

9. Un posible algoritmo: (1) acercarse al torniquete de acceso; (2) acercar la tarjeta o boleto al lector; (3) si el lector indica saldo o boleto válido, pasar por el torniquete; (4) si el lector indica saldo insuficiente o boleto inválido, dirigirse a recargar o comprar un boleto y volver al paso (2).

10. El número binario `10011011` corresponde, en decimal, a 1·128+0·64+0·32+1·16+1·8+0·4+1·2+1·1 = 128+16+8+2+1 = 155.

11. El número decimal 345 corresponde, en binario, a `101011001`, ya que 345 = 256+64+16+8+1 = 2^8+2^6+2^4+2^3+2^0.

12. Como 2^10=1024 es insuficiente para representar 1225, pero 2^11=2048 sí lo es, se necesitan 11 bits.

13. La arquitectura de von Neumann es un modelo de computador en el cual las instrucciones del programa y los datos que este manipula se almacenan en la *misma* memoria, y son accedidos por el procesador a través de un mismo bus, ejecutando una instrucción a la vez mediante el ciclo de búsqueda, decodificación y ejecución (*fetch-decode-execute*).

14. Se reconocen habitualmente cinco generaciones de lenguajes de programación: (1) lenguaje de máquina, (2) lenguaje ensamblador, (3) lenguajes de alto nivel de propósito general –como C, Pascal o Java–, (4) lenguajes declarativos o de dominio específico –como SQL–, y (5) lenguajes orientados a la inteligencia artificial y la programación lógica –como Prolog–. Respecto de cuál es la mejor'' generación, no existe una respuesta única: depende del problema a resolver. Sin embargo, los lenguajes de tercera generación –como C– suelen destacarse por ofrecer un buen equilibrio entre el control cercano al hardware y un nivel de abstracción razonable para el programador, razón por la cual continúan empleándose ampliamente incluso décadas después de su creación.

15. Los principales paradigmas son: el *imperativo*, donde el programa se expresa como una secuencia de instrucciones que modifican el estado de la memoria (por ejemplo, C); el *orientado a objetos*, donde los datos y el comportamiento se agrupan en objetos (por ejemplo, Java o C++); el *funcional*, donde el programa se expresa mediante la composición de funciones sin efectos secundarios (por ejemplo, Haskell); y el *declarativo o lógico*, donde el programador describe reglas y relaciones, y el sistema determina cómo satisfacerlas (por ejemplo, Prolog o SQL). El lenguaje C, que estudiaremos en este libro, corresponde principalmente al paradigma imperativo.

## Capítulo 2: Fundamentos del Lenguaje C

1. Al declarar una variable, el sistema operativo reserva un bloque de memoria de tamaño acorde a su tipo de dato, identificado por una dirección. Dicho bloque inicialmente puede contener cualquier valor residual (basura''), hasta que el programa le asigna un valor explícito.

2. El bus de datos determina la cantidad máxima de celdas de memoria que el procesador puede direccionar (2^n celdas para un bus de n bits); por lo tanto, a mayor ancho del bus, mayor es la cantidad de memoria que el computador puede emplear.

3. El modificador `unsigned` indica que una variable entera sólo puede almacenar valores no negativos, duplicando así el rango positivo representable a cambio de no poder representar valores negativos.

4. Evaluar una expresión significa calcular el valor resultante de aplicar los operadores correspondientes sobre sus operandos, en el orden que determina la precedencia de dichos operadores.

5. El operador de asignación es el símbolo `=`, el cual almacena en la variable ubicada a su izquierda el valor de la expresión evaluada a su derecha.

6. En la mayoría de los computadores actuales, una variable `int` ocupa 4 bytes, mientras que una variable `double` ocupa 8 bytes.

7. El operador `sizeof` retorna la cantidad de bytes que ocupa en memoria un tipo de dato o una variable ya declarada; puede aplicarse indistintamente a ambos, por ejemplo `sizeof(int)` o `sizeof(a)`.

8. Si se intenta modificar una variable declarada como `const`, el compilador genera un error de compilación, ya que dicho modificador impide cualquier asignación posterior a la inicialización de la variable.

9. La división entre dos operandos de tipo entero genera un resultado entero, descartando –sin redondear– la parte decimal del resultado (por ejemplo, `7/2` vale `3`, no `3.5`).

10. El *casting* realiza una conversión explícita de un valor de un tipo de dato a otro (por ejemplo, `(float)a`); su efecto es que la operación en la que participa dicho valor se realiza empleando el nuevo tipo, evitando así truncamientos no deseados, como el de la división entera.

11. El preincremento (`++a`) incrementa la variable *antes* de emplear su valor en la expresión; el postdecremento (`a–`) emplea el valor *actual* de la variable en la expresión, y sólo después la decrementa.

12. Los operadores aritméticos del lenguaje C son: suma (`+`), resta (`-`), multiplicación (`*`), división (`/`) y módulo (`%`).

13. Los operadores de incremento (`++`) y decremento (`–`) permiten aumentar o disminuir en una unidad el valor de una variable.

14. Las operaciones lógicas en C generan como resultado el valor entero `0` (falso) o `1` (verdadero).

15. Para que `a && b` sea siempre verdadera, ambas variables deben ser distintas de cero; para que `a || b` sea siempre verdadera, basta con que al menos una de las dos sea distinta de cero (aunque también es verdadera si ambas lo son).

16. Aplicando la precedencia de operadores (multiplicación y división antes que suma y resta, evaluadas de izquierda a derecha): `4*2-8/4+1` = 8-2+1 = 7.

17. Con `a=5` y `b=6`: `b*=a` equivale a `b=b*a=30`; luego `b+=a` equivale a `b=b+a=30+5=35`. Por lo tanto, `b` termina valiendo 35.

18. Como 23>9 es verdadero (`1`), `!(23>9)` vale `0` (falso); como `1` ya es verdadero, `!(1)` vale `0` (falso). Por lo tanto, `0 && 0` vale `0` (falso).

19. Para `a` entre 0 y 20, la expresión `a%10` genera el ciclo de valores 0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0, es decir, el resto de dividir `a` por 10 se repite cada diez valores consecutivos de `a`.

20. Una constante definida con `const` es una variable típica del lenguaje –con tipo de dato propio, verificada por el compilador y visible sólo dentro de su ámbito–, mientras que una constante definida con `#define` es reemplazada textualmente por el preprocesador antes de la compilación, sin tipo de dato asociado ni verificación alguna por parte del compilador.

21. Con `a=0110` y `b=0011`: `a&b` (Y bit a bit) vale `0010` (2); `a|b` (O bit a bit) vale `0111` (7); `a^b` (O exclusivo bit a bit) vale `0101` (5).

22. Desplazar una variable entera un bit hacia la izquierda (`<<1`) equivale a multiplicarla por 2; desplazarla un bit hacia la derecha (`>>1`) equivale a dividirla por 2, descartando el resto (división entera).

## Capítulo 3: Estructuras de control

1. El control del programa se refiere al orden en que las instrucciones de un programa efectivamente se ejecutan; por defecto es secuencial, pero los bifurcadores y ciclos permiten alterarlo.

2. Un bifurcador permite que el programa ejecute un bloque de instrucciones u otro según se cumpla o no una condición, ejecutándose a lo más una vez; un ciclo permite repetir un bloque de instrucciones mientras se cumpla una condición, ejecutándose potencialmente muchas veces.

3. Si omitimos las llaves de un bloque `if` que contiene más de una instrucción, sólo la instrucción inmediatamente siguiente al `if` queda condicionada a él; el resto se ejecuta siempre, independientemente de si la condición fue verdadera o falsa.

4. Un `IF-ELSE` evalúa una única condición y elige entre dos bloques mutuamente excluyentes; una sucesión de `IF-ELSE IF` evalúa condiciones adicionales en cascada sólo si las anteriores resultaron falsas, permitiendo elegir entre más de dos alternativas.

5. La sentencia reescrita con el operador ternario es `signo = (a>=0) ? 1 : -1;`. No es recomendable emplear el operador ternario cuando los bloques a ejecutar contienen más de una instrucción, o cuando su uso reduce excesivamente la legibilidad del código.

6. Conviene emplear `SWITCH` en lugar de una sucesión de `IF-ELSE IF` cuando se compara una misma variable u expresión contra un conjunto acotado de valores constantes, ya que resulta más legible y explícito que una larga cadena de comparaciones de igualdad.

7. Es necesario incluir la instrucción `break` al final de cada caso. Si la omitimos, el programa continúa ejecutando las instrucciones de los casos siguientes –fenómeno conocido como *fall-through*–, independientemente de si su valor coincide con la expresión evaluada.

8. El ciclo `WHILE` evalúa su condición *antes* de ejecutar el bloque, por lo que puede no ejecutarse ninguna vez; el ciclo `DO-WHILE` evalúa su condición *después*, por lo que siempre se ejecuta al menos una vez.

9. El encabezado del ciclo `FOR` se compone de: (1) la inicialización de la variable de control, (2) la condición de continuación, y (3) la actualización de la variable de control, ejecutada al final de cada iteración.

10. La instrucción `break` termina anticipadamente el ciclo por completo; la instrucción `continue` salta directamente a la siguiente iteración, sin ejecutar el resto de las instrucciones del bloque en la iteración actual.

11. Un comentario de bloque (`/* */`) puede abarcar varias líneas y debe cerrarse explícitamente; un comentario de línea (`//`) sólo afecta el resto de la línea en la que aparece.

12. Programa que indica si un número es positivo, negativo o cero:


   ```c
#include <stdio.h>

int main()
{
   int n;

   printf("Ingrese un numero: ");
   scanf("%d", &n);

   if (n > 0)
      printf("Es positivo");
   else if (n < 0)
      printf("Es negativo");
   else
      printf("Es igual a cero");
}
   ```

13. Programa que clasifica un triángulo según sus lados:


   ```c
#include <stdio.h>

int main()
{
   float a, b, c;

   printf("Ingrese los tres lados: ");
   scanf("%f %f %f", &a, &b, &c);

   if (a==b && b==c)
      printf("Es equilatero");
   else if (a==b || b==c || a==c)
      printf("Es isosceles");
   else
      printf("Es escaleno");
}
   ```

14. Programa que despliega el día de la semana empleando `switch`:


   ```c
#include <stdio.h>

int main()
{
   int dia;

   printf("Ingrese un numero entre 1 y 7: ");
   scanf("%d", &dia);

   switch (dia)
   {
      case 1: printf("Lunes"); break;
      case 2: printf("Martes"); break;
      case 3: printf("Miercoles"); break;
      case 4: printf("Jueves"); break;
      case 5: printf("Viernes"); break;
      case 6: printf("Sabado"); break;
      case 7: printf("Domingo"); break;
      default: printf("Numero invalido");
   }
}
   ```

15. Programa que suma los primeros N números enteros empleando `for`:


   ```c
#include <stdio.h>

int main()
{
   int n, i, suma=0;

   printf("Ingrese N: ");
   scanf("%d", &n);

   for (i=1; i<=n; i++)
      suma = suma + i;

   printf("La suma es: %d", suma);
}
   ```

16. Programa que calcula el factorial empleando `while`:


   ```c
#include <stdio.h>

int main()
{
   int n, i=1;
   long factorial=1;

   printf("Ingrese un numero: ");
   scanf("%d", &n);

   while (i <= n)
   {
      factorial = factorial * i;
      i++;
   }

   printf("El factorial es: %ld", factorial);
}
   ```

17. Programa con un menú de opciones empleando `do-while`:


   ```c
#include <stdio.h>

int main()
{
   int opcion;

   do
   {
      printf("1. Opcion A\n");
      printf("2. Opcion B\n");
      printf("3. Salir\n");
      printf("Ingrese una opcion: ");
      scanf("%d", &opcion);
   } while (opcion != 3);

   printf("Programa finalizado");
}
   ```

18. Programa que despliega los múltiplos de 3 entre 1 y 30 empleando `continue`:


   ```c
#include <stdio.h>

int main()
{
   int i;

   for (i=1; i<=30; i++)
   {
      if (i%3 != 0)
         continue;

      printf("%d ", i);
   }
}
   ```

19. El ciclo `for(i=0; i<10; i=i+2)` se ejecuta 5 veces, con `i` tomando los valores 0,2,4,6,8 (al llegar a `i=10` la condición `i<10` es falsa y el ciclo termina).

20. Con `a=4` y `b=2`: como `a>b`, se ejecuta `c=a-b=2`; luego `c=c*3=6`. Por lo tanto, `c` termina valiendo 6.

## Capítulo 4: Función main

1. Todo programa en C comienza su ejecución en la función `main` porque así lo establece el estándar del lenguaje: es el punto de entrada obligatorio que el sistema operativo invoca al ejecutar el programa.

2. El especificador de formato empleado en `printf` debe corresponder exactamente al tipo de dato de la variable que se despliega (por ejemplo, `%d` para `int`, `%f` para `float`, `%c` para `char`), ya que de ello depende cómo se interpretan los bytes almacenados en dicha variable.

3. Si empleamos un especificador de formato distinto del tipo real de la variable, el programa interpreta incorrectamente los bytes almacenados, desplegando un valor sin sentido o incluso provocando un comportamiento indefinido.

4. El modificador `\n` inserta un salto de línea; el modificador `\t` inserta una tabulación horizontal.

5. El símbolo `&` entrega a `scanf` la *dirección de memoria* de la variable, para que la función pueda escribir directamente el valor leído en ella. Si lo omitimos, `scanf` recibe por error el valor actual de la variable en lugar de su dirección, lo cual generalmente provoca que el programa intente escribir en una dirección de memoria inválida.

6. Se leen varios valores con un único llamado a `scanf` indicando varios especificadores de formato, separados por espacios, y entregando la dirección de cada variable correspondiente, por ejemplo: `scanf("%d %f", &edad, &promedio);`.

7. Si el dato ingresado no corresponde al formato esperado, `scanf` deja de leer en el punto donde encontró el primer carácter inválido, la variable correspondiente no se modifica (conservando su valor previo, posiblemente indeterminado), y el resto de la entrada permanece sin leer en el buffer.

8. Si empleamos `scanf` sobre una variable que ya posee un valor asignado previamente, dicho valor simplemente se sobrescribe con el nuevo valor ingresado por el usuario.

9. La función `scanf` retorna la cantidad de valores que logró leer y asignar correctamente. Comparando dicho valor de retorno con la cantidad de especificadores solicitados, el programa puede determinar si el usuario ingresó el dato en el formato correcto (por ejemplo, `if (scanf("%d", &n) != 1) ...`).

10. La función `srand` fija la semilla de la secuencia pseudoaleatoria generada por `rand`. Si un programa llama a `rand` sin haber llamado antes a `srand`, el lenguaje C emplea una semilla fija por defecto, por lo que el programa generará *siempre* la misma secuencia de números en cada ejecución.

11. Programa que calcula el área y el perímetro de un círculo:


   ```c
#include <stdio.h>

int main()
{
   float radio;
   const float PI = 3.14159;

   printf("Ingrese el radio: ");
   scanf("%f", &radio);

   printf("Area: %.2f\n", PI*radio*radio);
   printf("Perimetro: %.2f\n", 2*PI*radio);
}
   ```

12. Programa que convierte Celsius a Fahrenheit:


   ```c
#include <stdio.h>

int main()
{
   float celsius, fahrenheit;

   printf("Ingrese la temperatura en Celsius: ");
   scanf("%f", &celsius);

   fahrenheit = celsius*9.0/5.0 + 32;

   printf("Equivale a %.2f Fahrenheit", fahrenheit);
}
   ```

13. Programa que despliega la menor de tres notas:


   ```c
#include <stdio.h>

int main()
{
   float n1, n2, n3, menor;

   printf("Ingrese tres notas: ");
   scanf("%f %f %f", &n1, &n2, &n3);

   menor = n1;
   if (n2 < menor) menor = n2;
   if (n3 < menor) menor = n3;

   printf("La menor nota es: %.1f", menor);
}
   ```

14. Programa que despliega el nombre del mes empleando `switch`:


   ```c
#include <stdio.h>

int main()
{
   int mes;

   printf("Ingrese un numero entre 1 y 12: ");
   scanf("%d", &mes);

   switch (mes)
   {
      case 1:  printf("Enero"); break;
      case 2:  printf("Febrero"); break;
      case 3:  printf("Marzo"); break;
      case 4:  printf("Abril"); break;
      case 5:  printf("Mayo"); break;
      case 6:  printf("Junio"); break;
      case 7:  printf("Julio"); break;
      case 8:  printf("Agosto"); break;
      case 9:  printf("Septiembre"); break;
      case 10: printf("Octubre"); break;
      case 11: printf("Noviembre"); break;
      case 12: printf("Diciembre"); break;
      default: printf("Numero invalido");
   }
}
   ```

15. Programa que determina si un número entero es capicúa, comparando el número original con su versión invertida:


   ```c
#include <stdio.h>

int main()
{
   int n, original, invertido=0, digito;

   printf("Ingrese un numero entero: ");
   scanf("%d", &n);

   original = n;

   while (n > 0)
   {
      digito = n%10;
      invertido = invertido*10 + digito;
      n = n/10;
   }

   if (original == invertido)
      printf("Es capicua");
   else
      printf("No es capicua");
}
   ```

16. Programa que convierte un número decimal a binario:


   ```c
#include <stdio.h>

int main()
{
   int n, binario[32], i=0, j;

   printf("Ingrese un numero decimal: ");
   scanf("%d", &n);

   while (n > 0)
   {
      binario[i] = n%2;
      n = n/2;
      i++;
   }

   printf("En binario es: ");
   for (j=i-1; j>=0; j--)
      printf("%d", binario[j]);
}
   ```

17. Programa que determina si un número entero es primo:


   ```c
#include <stdio.h>

int main()
{
   int n, i, primo=1;

   printf("Ingrese un numero entero positivo: ");
   scanf("%d", &n);

   if (n < 2)
      primo = 0;

   for (i=2; i<n; i++)
   {
      if (n%i == 0)
      {
         primo = 0;
         break;
      }
   }

   if (primo)
      printf("Es primo");
   else
      printf("No es primo");
}
   ```

18. Programa que aproxima el número e mediante su serie infinita:


   ```c
#include <stdio.h>

int main()
{
   int n, i;
   double termino=1, suma=0;

   printf("Ingrese la cantidad de terminos: ");
   scanf("%d", &n);

   for (i=0; i<n; i++)
   {
      if (i > 0)
         termino = termino/i;   //termino = 1/i!, acumulado progresivamente

      suma = suma + termino;
   }

   printf("Aproximacion de e: %.6f", suma);
}
   ```

Note que, en lugar de calcular i! completo en cada iteración –lo cual sería ineficiente–, cada término se obtiene dividiendo el término anterior por `i`, ya que 1/i! = 1/(i-1)! × 1/i.

19. Modificación del programa del Ejemplo 9, incorporando un retiro mensual fijo antes de aplicar el interés:


   ```c
#include <stdio.h>

int main()
{
   double int_mensual, cuota, retiro, acum=0;
   int mes, i;

   printf("Ingrese numero de meses: ");
   scanf("%d", &mes);

   printf("Ingrese interes mensual: ");
   scanf("%lf", &int_mensual);

   printf("Ingrese cuota mensual: ");
   scanf("%lf", &cuota);

   printf("Ingrese el retiro mensual: ");
   scanf("%lf", &retiro);

   for (i=0; i<mes; i++)
      acum = (acum + cuota - retiro) * (1+int_mensual);

   printf("En %d meses ha acumulado: $%.2f", mes, acum);
}
   ```

La única diferencia respecto del programa original es que, antes de aplicar el interés, restamos el monto retirado (`acum + cuota - retiro`), ya que el enunciado indica que el retiro ocurre antes de que el interés se aplique sobre el saldo restante.

20. Programa que simula el lanzamiento de un dado:


   ```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int dado;

   srand(time(NULL));
   dado = rand()%6 + 1;

   printf("El dado cayo en: %d", dado);
}
   ```

## Capítulo 5: Funciones y bibliotecas

1. Dividir un programa en funciones favorece la reutilización de código, la abstracción –al encapsular la complejidad de una tarea–, y la simplificación del problema general al dividirlo en partes más pequeñas y manejables (dividir y conquistar'').

2. El encabezado de una función se compone de: (1) el tipo de retorno, (2) el nombre de la función, y (3) los parámetros de entrada entre paréntesis.

3. El tipo de retorno `void` indica que la función no devuelve ningún valor a quien la invoca; cualquier otro tipo de dato (`int`, `float`, etc.) indica que la función sí debe devolver, mediante `return`, un valor de ese tipo.

4. Si una función no incluye `return` y su tipo de retorno no es `void`, el comportamiento es indefinido: el valor retornado'' corresponde a cualquier dato que se encontrara en el lugar de memoria empleado para el retorno, sin ningún sentido garantizado.

5. El paso de parámetros por valor consiste en que la función recibe una *copia* de los datos entregados al invocarla, almacenada en un nuevo espacio de memoria; por lo tanto, cualquier modificación realizada dentro de la función no afecta a la variable original.

6. En el paso por valor, la función recibe una copia de los datos, por lo que no puede modificar las variables originales; en el paso por referencia, la función recibe la dirección de memoria de dichas variables, por lo que sí puede modificarlas directamente.

7. El ámbito de una variable determina en qué parte del programa dicha variable es visible y puede emplearse. Una variable local sólo existe y es accesible mientras se ejecuta la función en la que fue declarada; una variable global es accesible desde cualquier parte del programa durante toda su ejecución.

8. No es recomendable el uso extensivo de variables globales porque cualquier función puede modificarlas sin restricción, lo que dificulta predecir y depurar el comportamiento del programa, y reduce la independencia –y por lo tanto la reutilización– de las funciones.

9. Una variable local común pierde su valor cada vez que la función termina su ejecución, reiniciándose en la siguiente invocación; una variable local declarada `static` conserva su valor entre invocaciones sucesivas, inicializándose sólo la primera vez que la función es invocada.

10. Debe incluirse la biblioteca `math.h`. Función que determina si un número es un cuadrado perfecto:


   ```c
#include <stdio.h>
#include <math.h>

int es_cuadrado_perfecto(int n)
{
   int raiz;

   raiz = (int) sqrt(n);

   return(raiz*raiz == n);
}
   ```

11. No es correcto. Ambas características –recibir parámetros y retornar un valor– son independientes entre sí; una función puede no recibir parámetros y, sin embargo, retornar un valor (por ejemplo, una función que solicita un dato por teclado y lo retorna, como `leer_numero` estudiada en este capítulo).

12. Función sin parámetros que imprime la tabla del 5:


   ```c
#include <stdio.h>

void tabla_del_5(void)
{
   int i;

   for (i=1; i<=10; i++)
      printf("5 x %d = %d\n", i, 5*i);
}
   ```

13. Función sin parámetros que retorna la edad aproximada:


   ```c
#include <stdio.h>

int calcular_edad(void)
{
   int nacimiento;

   printf("Ingrese su año de nacimiento: ");
   scanf("%d", &nacimiento);

   return(2026 - nacimiento);
}
   ```

14. Función que retorna el mayor de dos números enteros:


   ```c
int mayor(int a, int b)
{
   if (a > b)
      return(a);
   else
      return(b);
}
   ```

15. Función que determina si un número entero es primo:


   ```c
int es_primo(int n)
{
   int i;

   if (n < 2)
      return(0);

   for (i=2; i<n; i++)
   {
      if (n%i == 0)
         return(0);
   }

   return(1);
}
   ```

16. Una función recursiva es aquella que se invoca a sí misma para resolver un problema, descomponiéndolo en una versión más pequeña del mismo problema. Sus dos componentes fundamentales son el *caso base* –la condición de término, resuelta directamente sin nuevas invocaciones– y el *caso recursivo* –la invocación de la función sobre un problema de menor tamaño–.

17. Si una función recursiva no posee un caso base, o éste nunca se alcanza, las invocaciones se acumulan indefinidamente en la pila de llamadas hasta agotar la memoria disponible, provocando un error de desbordamiento de pila (*stack overflow*).

18. Función recursiva que calcula b^n:


   ```c
int potencia(int b, int n)
{
   if (n == 0)               //caso base
      return(1);
   else
      return(b * potencia(b, n-1));   //caso recursivo
}
   ```

19. Función recursiva que retorna el máximo entre las posiciones 0 y p de un arreglo:


   ```c
int maximo(int A[], int p)
{
   if (p == 0)                        //caso base
      return(A[0]);

   int resto = maximo(A, p-1);        //caso recursivo

   if (A[p] > resto)
      return(A[p]);
   else
      return(resto);
}
   ```

20. Versión iterativa de la misma función:


   ```c
int maximo_iterativo(int A[], int p)
{
   int i, max;

   max = A[0];

   for (i=1; i<=p; i++)
   {
      if (A[i] > max)
         max = A[i];
   }

   return(max);
}
   ```

Ambas versiones producen exactamente el mismo resultado. La versión recursiva expresa la idea de forma más cercana a su definición matemática, dividiendo el problema en subproblemas más pequeños, mientras que la versión iterativa resuelve el problema mediante un único ciclo, sin invocaciones adicionales.

21. La principal ventaja de la recursión es la simplicidad y elegancia con que pueden expresarse problemas definidos naturalmente en forma recursiva –como los que involucran estructuras de datos como árboles–. Su principal desventaja es el uso adicional de memoria debido a las invocaciones apiladas, y un menor rendimiento respecto de una solución iterativa equivalente, por lo que el programador debe evaluar caso a caso cuál alternativa resulta más apropiada.

## Capítulo 6: Vectores y ordenamiento

1. Un vector es una colección de elementos del mismo tipo de dato, almacenados en posiciones de memoria contiguas y accesibles mediante un índice; a diferencia de una variable simple, que sólo almacena un único valor, un vector permite agrupar múltiples valores bajo un mismo nombre.

2. En un vector de tamaño 10, el índice del primer elemento es 0 y el del último es 9.

3. Si accedemos a una posición de un vector fuera de su rango válido, el lenguaje C no detecta ni impide dicho acceso: el programa lee o escribe en una posición de memoria adyacente al vector, produciendo un comportamiento indefinido –que puede incluir la corrupción de otras variables o una falla del programa–.

4. Es necesario entregar el tamaño de un vector como parámetro adicional porque, al traspasarlo a una función, éste se convierte en un puntero a su primer elemento, perdiendo la información sobre su tamaño original; sin dicho parámetro, la función no tendría forma de saber hasta qué posición puede recorrerlo con seguridad.

5. Los vectores se traspasan siempre por referencia, ya que –como veremos en el capítulo 8– el nombre de un vector es equivalente a un puntero a su primer elemento; por lo tanto, cualquier modificación realizada sobre sus elementos dentro de una función afecta directamente al vector original.

6. Función que retorna la suma de los elementos de un vector:


   ```c
int suma_vector(int vector[], int tamano)
{
   int i, suma=0;

   for (i=0; i<tamano; i++)
      suma = suma + vector[i];

   return(suma);
}
   ```

7. Función que retorna el valor máximo de un vector:


   ```c
int maximo_vector(int vector[], int tamano)
{
   int i, max;

   max = vector[0];

   for (i=1; i<tamano; i++)
   {
      if (vector[i] > max)
         max = vector[i];
   }

   return(max);
}
   ```

8. Función que retorna la cantidad de números pares de un vector:


   ```c
int contar_pares(int vector[], int tamano)
{
   int i, contador=0;

   for (i=0; i<tamano; i++)
   {
      if (vector[i]%2 == 0)
         contador++;
   }

   return(contador);
}
   ```

9. Función que invierte el orden de los elementos de un vector:


   ```c
void invertir(int vector[], int tamano)
{
   int i, tmp;

   for (i=0; i<tamano/2; i++)
   {
      tmp = vector[i];
      vector[i] = vector[tamano-1-i];
      vector[tamano-1-i] = tmp;
   }
}
   ```

10. Toda cadena de caracteres debe terminar con el carácter nulo (`'\0'`) porque, a diferencia de un vector numérico –cuyo tamaño se conoce explícitamente–, las funciones que manipulan cadenas (como `printf` o `strlen`) determinan dónde termina el texto recorriendo el vector hasta encontrar dicho carácter, sin conocer de antemano su longitud.

11. La función `strlen` retorna la cantidad de caracteres válidos de una cadena, sin incluir el carácter nulo dentro de dicho conteo.

12. `scanf` (con `%s`) sólo lee una palabra, deteniéndose en el primer espacio en blanco; `fgets` lee una línea completa, incluyendo los espacios intermedios, hasta encontrar un salto de línea o alcanzar el tamaño máximo indicado. Es necesario eliminar en ocasiones el último carácter leído por `fgets` porque, a diferencia de `scanf`, éste incluye el propio carácter de salto de línea (`'\n'`) dentro de la cadena resultante.

13. No podemos comparar el contenido de dos cadenas con `==` porque dicho operador compararía las direcciones de memoria de ambos vectores, y no el contenido almacenado en ellas. En su lugar, debemos emplear la función `strcmp`.

14. Programa que solicita el nombre completo empleando `fgets`:


   ```c
#include <stdio.h>
#include <string.h>

int main()
{
   char nombre[50];

   printf("Ingrese su nombre completo: ");
   fgets(nombre, 50, stdin);

   nombre[strcspn(nombre, "\n")] = '\0';   //elimina el salto de linea

   printf("Hola, %s", nombre);
}
   ```

15. Función que cuenta las vocales de una cadena:


   ```c
int contar_vocales(char texto[])
{
   int i, contador=0;

   for (i=0; texto[i] != '\0'; i++)
   {
      char c = texto[i];

      if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
          c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
         contador++;
   }

   return(contador);
}
   ```

16. Función que convierte una cadena a mayúsculas:


   ```c
void a_mayusculas(char texto[])
{
   int i;

   for (i=0; texto[i] != '\0'; i++)
   {
      if (texto[i] >= 'a' && texto[i] <= 'z')
         texto[i] = texto[i] - 32;
   }
}
   ```

17. El ordenamiento burbuja recorre repetidamente el vector, comparando cada par de elementos adyacentes e intercambiándolos si están en el orden incorrecto; en cada recorrido completo, el elemento de mayor valor burbujea'' hasta su posición final en el extremo derecho, por lo que el rango a recorrer se reduce en cada iteración sucesiva.

18. El ordenamiento por selección busca, en cada recorrido, el elemento de menor valor dentro de la porción no ordenada del vector, y lo intercambia con el primer elemento de dicha porción, ordenando el vector de izquierda a derecha.

19. La principal diferencia es que el ordenamiento burbuja puede realizar múltiples intercambios en un mismo recorrido, mientras que el ordenamiento por selección realiza como máximo un único intercambio por recorrido, ya que primero determina el índice del valor mínimo y luego lo intercambia.

20. Modificación del ordenamiento burbuja para orden descendente (basta con invertir la comparación):


   ```c
void ordenamiento_burbuja_descendente(int vector[], int tamano)
{
   int i, j, tmp;

   for (i=0; i<tamano-1; i++)
   {
      for (j=0; j<tamano-1-i; j++)
      {
         if (vector[j] < vector[j+1])   //unica diferencia: < en lugar de >
         {
            tmp = vector[j];
            vector[j] = vector[j+1];
            vector[j+1] = tmp;
         }
      }
   }
}
   ```

21. Traza del ordenamiento burbuja sobre {8,3,5,1,9,2}, mostrando el estado del vector al finalizar cada recorrido del ciclo externo:


| **Recorrido** | **Estado del vector** |
|---|---|
| Inicial | 8,3,5,1,9,2 |
| 1 | 3,5,1,8,2,9 |
| 2 | 3,1,5,2,8,9 |
| 3 | 1,3,2,5,8,9 |
| 4 | 1,2,3,5,8,9 |
| 5 | 1,2,3,5,8,9 (sin cambios, ya estaba ordenado) |

En el primer recorrido, el valor 9 –el mayor del vector– llega a su posición final; en cada recorrido sucesivo, el siguiente valor mayor entre los restantes alcanza su posición correspondiente, hasta que el vector queda completamente ordenado.

22. La búsqueda lineal recorre secuencialmente cada elemento del vector, comparándolo con el valor buscado, hasta encontrarlo o llegar al final del vector. En el peor caso –cuando el valor no se encuentra, o se encuentra en la última posición–, debe realizar n comparaciones sobre un vector de tamaño n.

23. La búsqueda binaria requiere que el vector se encuentre previamente ordenado porque, en cada paso, descarta la mitad de los elementos restantes comparando el valor buscado únicamente con el elemento central; esta estrategia sólo es válida si se puede garantizar que todos los elementos a un lado del centro son menores (o mayores) que él, lo cual únicamente se cumple si el vector está ordenado.

24. Traza de la búsqueda binaria de 23 sobre {2,5,8,12,16,23,38,45,56,72} (índices 0 a 9):


   1. `bajo=0`, `alto=9`, `medio=4`: `vector[4]=16`, que es menor que 23; se descarta la mitad izquierda, actualizando `bajo=5`.
   2. `bajo=5`, `alto=9`, `medio=7`: `vector[7]=45`, que es mayor que 23; se descarta la mitad derecha, actualizando `alto=6`.
   3. `bajo=5`, `alto=6`, `medio=5`: `vector[5]=23`, que coincide con el valor buscado. El algoritmo retorna el índice 5, empleando en total 3 comparaciones.

25. Función que suma los elementos de la diagonal principal de una matriz 3×3:


   ```c
int suma_diagonal(int matriz[3][3])
{
   int i, suma=0;

   for (i=0; i<3; i++)
      suma = suma + matriz[i][i];

   return(suma);
}
   ```

26. Función que determina si una matriz n× n es simétrica (empleando el mismo tamaño de columnas del Ejemplo 6 de este capítulo, ya que dicho valor debe conocerse en tiempo de compilación):


   ```c
int es_simetrica(int datos[][4], int n)
{
   int i, j;

   for (i=0; i<n; i++)
   {
      for (j=i+1; j<n; j++)   //solo se necesita comparar la mitad superior
      {
         if (datos[i][j] != datos[j][i])
            return(0);
      }
   }

   return(1);
}
   ```

## Capítulo 7: Estructuras de datos

1. Una estructura (`struct`) agrupa, bajo un mismo nombre, un conjunto de campos que pueden tener *distintos* tipos de dato; un vector, en cambio, sólo permite almacenar elementos de un *único* tipo de dato.

2. Al declarar una estructura –sin crear ninguna variable de dicho tipo– no se reserva ningún espacio en memoria; sólo se define un nuevo tipo de dato compuesto, de la misma forma en que el lenguaje ya conoce de antemano los tipos `int` o `float`.

3. Para acceder a los campos de una variable de tipo estructura se emplea el operador punto (`.`), escrito entre el nombre de la variable y el nombre del campo.

4. No es posible asignar directamente un texto a un campo de tipo `char[ ]` empleando `=` porque dicho campo corresponde a un vector, y el operador de asignación no puede emplearse para copiar el contenido completo de un vector; en su lugar, debemos emplear la función `strcpy`.

5. No, los campos de una estructura no necesitan ser del mismo tipo de dato; de hecho, esa es precisamente la razón de ser de las estructuras: permitir agrupar atributos de naturaleza distinta (por ejemplo, texto, enteros y flotantes) bajo una misma entidad lógica.

6. Las estructuras se traspasan siempre por *valor*, es decir, la función recibe una copia completa de la estructura. Esto se diferencia del comportamiento de los vectores, los cuales –como vimos en el capítulo anterior– se traspasan siempre por *referencia*.

7. Sí, es posible copiar el contenido completo de una estructura en otra empleando `=`, siempre que ambas variables sean del mismo tipo. Esto no es posible con un vector, cuyo contenido debe copiarse elemento por elemento (o mediante una función como `memcpy`, no estudiada en este libro).

8. Sí, una función puede retornar una estructura completa. El tipo de retorno declarado en su encabezado debe corresponder exactamente al tipo de dicha estructura (por ejemplo, `struct persona`).

9. Función que construye y retorna una estructura `persona`:


   ```c
struct persona crear_persona(char nombre[30], int edad, float promedio)
{
   struct persona nueva;

   strcpy(nueva.nombre, nombre);
   nueva.edad = edad;
   nueva.promedio = promedio;

   return(nueva);
}
   ```

10. La instrucción `typedef` permite crear un nombre alternativo (alias) para un tipo de dato ya existente, simplificando su escritura –por ejemplo, evitando repetir la palabra `struct` cada vez–. No modifica en absoluto el comportamiento del programa, ya que es puramente una facilidad sintáctica para el programador, resuelta en tiempo de compilación.

11. Estructura `libro`:


   ```c
struct libro
{
   char titulo[100];
   char autor[50];
   int anio;
};
   ```

12. Vector de 10 libros, con al menos tres inicializados:


   ```c
struct libro biblioteca[10];

strcpy(biblioteca[0].titulo, "Cien anios de soledad");
strcpy(biblioteca[0].autor, "Gabriel Garcia Marquez");
biblioteca[0].anio = 1967;

strcpy(biblioteca[1].titulo, "1984");
strcpy(biblioteca[1].autor, "George Orwell");
biblioteca[1].anio = 1949;

strcpy(biblioteca[2].titulo, "El Principito");
strcpy(biblioteca[2].autor, "Antoine de Saint-Exupery");
biblioteca[2].anio = 1943;
   ```

13. Función que retorna el promedio de edad de un vector de estructuras `persona`:


   ```c
float promedio_edad(struct persona curso[], int tamano)
{
   int i, suma=0;

   for (i=0; i<tamano; i++)
      suma = suma + curso[i].edad;

   return((float)suma / tamano);
}
   ```

14. Función que retorna un puntero a la persona con el mayor promedio de notas, siguiendo la misma técnica estudiada en la sección de este capítulo dedicada a retornar un puntero a una estructura:


   ```c
struct persona *mejor_promedio(struct persona curso[], int tamano)
{
   struct persona *mejor;
   int i;

   mejor = &curso[0];

   for (i=1; i<tamano; i++)
   {
      if (curso[i].promedio > mejor->promedio)
         mejor = &curso[i];
   }

   return(mejor);
}
   ```

15. Redefinición de `libro` empleando `typedef`:


   ```c
typedef struct libro
{
   char titulo[100];
   char autor[50];
   int anio;
} Libro;
   ```

A partir de esta declaración, podemos escribir directamente `Libro miLibro;` en lugar de `struct libro miLibro;`.

16. Si deseamos que una función modifique los campos de una estructura recibida como parámetro, existen dos alternativas: (1) hacer que la función retorne la estructura modificada, reasignando el resultado a la variable original en quien la invoca, o (2) emplear punteros, traspasando la dirección de memoria de la estructura –alternativa que estudiaremos en detalle en el capítulo 8–.

17. Por defecto, el compilador asigna a la primera constante de una enumeración el valor entero 0, y a cada constante siguiente el valor de la anterior más 1. Sí es posible modificar este comportamiento, asignando explícitamente un valor a una o más constantes; las constantes siguientes continúan la numeración de forma correlativa a partir de dicho valor.

18. Enumeración `Dia` y función que determina si corresponde a un día de fin de semana:


   ```c
typedef enum {LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO} Dia;

int es_fin_de_semana(Dia d)
{
   return(d==SABADO || d==DOMINGO);
}
   ```

## Capítulo 8: Punteros y estructuras dinámicas

1. Una variable de tipo puntero almacena una dirección de memoria –la dirección en la que se encuentra otra variable–, y no un número, un carácter o un valor lógico directamente.

2. El operador de dirección (`&`) retorna la dirección de memoria de una variable; el operador de indirección (`*`) accede al valor almacenado en la dirección referenciada por un puntero.

3. Un puntero debe declararse indicando el tipo de dato al que apunta porque el compilador necesita saber cuántos bytes debe leer o escribir cada vez que se emplea el operador de indirección sobre él, y también para calcular correctamente los desplazamientos al aplicar aritmética de punteros.

4. El paso por referencia permite a una función modificar variables externas porque, en lugar de recibir una copia del valor, la función recibe la *dirección* de memoria de la variable original; al emplear el operador de indirección sobre dicha dirección, la función accede y modifica directamente el mismo bloque de memoria que la variable original, y no una copia.

5. Se emplea el operador flecha (`->`) para acceder a los campos de una estructura a través de un puntero. La expresión `p->campo` es equivalente a `(*p).campo`.

6. El nombre de un vector, sin ningún índice, es interpretado por el compilador como un puntero a su primer elemento; es decir, `vector` es equivalente a `&vector[0]`.

7. El parámetro `argc` indica la cantidad de argumentos recibidos al ejecutar el programa, incluido el nombre del propio programa; el parámetro `argv` es un vector de *strings* con dichos argumentos. `argv[0]` almacena siempre el nombre del programa invocado.

8. Es necesario emplear `atoi` porque los argumentos de la línea de comandos siempre se reciben como cadenas de caracteres (*strings*), independientemente de si el usuario ingresó un número; `atoi` convierte dicha cadena a su valor entero equivalente para poder operar numéricamente con ella.

9. La memoria estática tiene un tamaño fijo, determinado en tiempo de compilación, y es administrada automáticamente por el sistema; la memoria dinámica se reserva y libera explícitamente durante la ejecución del programa, permitiendo tamaños que se determinan sólo en tiempo de ejecución.

10. `malloc` reserva un bloque de memoria dinámica del tamaño solicitado, retornando un puntero a dicho bloque; `free` libera un bloque previamente reservado. Si un programa reserva memoria dinámica y nunca la libera, se produce una fuga de memoria (*memory leak*), que puede agotar progresivamente la memoria disponible del computador.

11. `malloc` recibe la cantidad total de bytes a reservar y no inicializa dicha memoria; `calloc` recibe por separado el número de elementos y el tamaño de cada uno, e inicializa automáticamente toda la memoria reservada en cero. Conviene emplear `calloc` cuando se necesita memoria inicializada en cero; en caso contrario, `malloc` resulta ligeramente más eficiente.

12. `realloc` permite modificar el tamaño de un bloque de memoria previamente reservado, ampliándolo o reduciéndolo, conservando su contenido hasta el tamaño mínimo entre ambos bloques. No es recomendable reasignar directamente su resultado a la misma variable porque, si `realloc` falla, retorna `NULL` sin liberar el bloque original; al sobrescribir dicha variable con `NULL`, se perdería la única referencia al bloque original, provocando una fuga de memoria.

13. Una estructura no puede contener una variable de su propio tipo porque ello generaría un tamaño de memoria infinito (cada instancia contendría otra instancia dentro de sí, indefinidamente); sin embargo, sí puede contener un *puntero* a su propio tipo, ya que un puntero siempre ocupa un tamaño fijo en memoria –la dirección que almacena–, independientemente del tipo de dato al que apunte.

14. Un nodo es la unidad básica que compone una lista enlazada. Como mínimo, un nodo posee dos campos: el valor que almacena, y un puntero al siguiente nodo de la lista.

15. El final de una lista enlazada se determina al encontrar un nodo cuyo campo `siguiente` sea `NULL`, valor que marca explícitamente que no existe ningún nodo posterior.

16. Función que intercambia dos valores flotantes mediante punteros:


   ```c
void intercambiar(float *a, float *b)
{
   float tmp;

   tmp = *a;
   *a = *b;
   *b = tmp;
}
   ```

17. Función que suma 0.5 al promedio de una estructura `persona` a través de un puntero:


   ```c
void aumentar_promedio(struct persona *p)
{
   p->promedio = p->promedio + 0.5;
}
   ```

18. Función que recorre un vector empleando aritmética de punteros:


   ```c
void recorrer(int *vector, int tamano)
{
   int *p;

   for (p=vector; p<vector+tamano; p++)
      printf("%d ", *p);
}
   ```

19. Programa que despliega el mayor de un número indeterminado de argumentos enteros por la línea de comandos:


   ```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int i, mayor, valor;

   if (argc < 2)
   {
      printf("Uso: %s <numero1> [numero2 ...]\n", argv[0]);
      return(1);
   }

   mayor = atoi(argv[1]);

   for (i=2; i<argc; i++)
   {
      valor = atoi(argv[i]);
      if (valor > mayor)
         mayor = valor;
   }

   printf("El mayor valor es: %d", mayor);
}
   ```

20. Función que duplica la capacidad de un vector dinámico empleando `realloc`:


   ```c
int *duplicar_capacidad(int *vector, int tamano_actual)
{
   vector = (int*) realloc(vector, (tamano_actual*2)*sizeof(int));
   return(vector);
}
   ```

21. Función que inserta un nuevo nodo al inicio de una lista enlazada:


   ```c
Nodo *insertar_inicio(Nodo *primero, int valor)
{
   Nodo *nuevo;

   nuevo = (Nodo*) malloc(sizeof(Nodo));
   nuevo->valor = valor;
   nuevo->siguiente = primero;   //el nuevo nodo apunta al antiguo primero

   return(nuevo);   //el nuevo nodo pasa a ser el primero
}
   ```

Insertar al inicio es *más* eficiente que insertar al final: como el nuevo nodo siempre pasa a ser el primero, la operación se realiza en un número constante de pasos, sin necesidad de recorrer la lista. Insertar al final, en cambio, requiere recorrer la lista completa hasta encontrar el último nodo (a menos que se mantenga, además, un puntero auxiliar al último nodo).

22. Función que cuenta la cantidad de nodos de una lista enlazada:


   ```c
int contar_nodos(Nodo *primero)
{
   int contador=0;
   Nodo *actual;

   actual = primero;
   while (actual != NULL)
   {
      contador++;
      actual = actual->siguiente;
   }

   return(contador);
}
   ```

23. Es necesario guardar una referencia al siguiente nodo antes de liberar el nodo actual porque, una vez ejecutada la instrucción `free` sobre dicho nodo, su contenido –incluido su campo `siguiente`– ya no puede accederse de forma segura; si no guardáramos dicha referencia previamente, perderíamos el camino hacia el resto de la lista.

## Capítulo 9: Pilas, colas y árboles

1. La política LIFO (*Last In, First Out*) retira siempre primero al último elemento insertado, tal como ocurre en una pila; la política FIFO (*First In, First Out*) retira siempre primero al elemento que lleva más tiempo esperando –el primero en ser insertado–, tal como ocurre en una cola.

2. Una pila debe implementar, como mínimo, las operaciones *apilar* (*push*) y *desapilar* (*pop*); una cola debe implementar, como mínimo, las operaciones *encolar* (*enqueue*) y *desencolar* (*dequeue*).

3. Resulta natural emplear dos punteros porque una cola necesita acceder eficientemente a *ambos* extremos de la colección: el `frente`, para desencolar, y el `final`, para encolar. Con un único puntero –por ejemplo, sólo al frente–, encolar un nuevo elemento obligaría a recorrer toda la lista hasta llegar al final en cada inserción, perdiendo la eficiencia de la operación.

4. Un ejemplo de pila (LIFO) distinto de los mencionados en el capítulo es el botón deshacer'' (`Ctrl+Z`) de un editor de texto, que siempre revierte la última acción realizada. Un ejemplo de cola (FIFO) es la fila de vehículos esperando pasar por un peaje, donde el primer vehículo en llegar es siempre el primero en cruzar.

5. La raíz de un árbol es su nodo superior, del cual descienden todos los demás nodos; una hoja es un nodo que no posee ningún hijo.

6. En un árbol binario de búsqueda, para cualquier nodo, todos los valores almacenados en su subárbol izquierdo deben ser menores que él, y todos los valores almacenados en su subárbol derecho deben ser mayores.

7. La función que inserta un valor se diseña en forma recursiva porque el problema de insertar en un árbol es, en esencia, el mismo problema de insertar en uno de sus subárboles –izquierdo o derecho–, sólo que de menor tamaño. Su caso base ocurre cuando se alcanza una posición vacía del árbol (`raiz == NULL`), momento en el cual se crea el nuevo nodo.

8. Un recorrido inorden sobre un árbol binario de búsqueda despliega siempre los valores en orden *ascendente*.

9. Función que emplea una pila para determinar si una expresión con paréntesis está balanceada, reutilizando el tipo `Pila` y las funciones `apilar`, `desapilar` y `pila_vacia` definidas en este capítulo:


   ```c
int expresion_balanceada(char expresion[])
{
   Pila p;
   int i;

   p.tope = -1;

   for (i=0; expresion[i] != '\0'; i++)
   {
      if (expresion[i] == '(')
         apilar(&p, 1);
      else if (expresion[i] == ')')
      {
         if (pila_vacia(&p))
            return(0);   //cierre sin apertura correspondiente

         desapilar(&p);
      }
   }

   return(pila_vacia(&p));   //balanceada solo si no quedan parentesis pendientes
}
   ```

Cada apertura `(` se apila, y cada cierre `)` desapila una apertura previa. Si en algún momento encontramos un cierre sin ninguna apertura pendiente, la expresión está desbalanceada; si al finalizar el recorrido quedan aperturas sin cerrar, la pila no estará vacía, y la expresión tampoco estará balanceada.

10. Función que invierte el orden de los elementos de una pila empleando una segunda pila auxiliar:


   ```c
void invertir_pila(Pila *p)
{
   Pila aux;
   aux.tope = -1;

   while (!pila_vacia(p))
      apilar(&aux, desapilar(p));

   *p = aux;   //copiamos la pila completa, tal como estudiamos en el capitulo 7
}
   ```

Al desapilar sucesivamente todos los elementos de `p` y apilarlos en `aux`, su orden queda invertido: el elemento que estaba en el fondo de `p` termina en el tope de `aux`, y viceversa. Finalmente, copiamos `aux` completa sobre `*p` mediante asignación de estructuras.

11. Función que determina si un valor se encuentra en un árbol binario de búsqueda:


   ```c
int buscar_valor(NodoArbol *raiz, int valor)
{
   if (raiz == NULL)
      return(0);

   if (valor == raiz->valor)
      return(1);
   else if (valor < raiz->valor)
      return(buscar_valor(raiz->izquierdo, valor));
   else
      return(buscar_valor(raiz->derecho, valor));
}
   ```

Gracias a la propiedad del árbol binario de búsqueda, en cada paso podemos descartar por completo uno de los dos subárboles, dirigiendo la búsqueda hacia la izquierda o hacia la derecha según corresponda.

12. Función que retorna la cantidad total de nodos de un árbol binario:


   ```c
int contar_nodos(NodoArbol *raiz)
{
   if (raiz == NULL)         //caso base: arbol vacio
      return(0);

   return(1 + contar_nodos(raiz->izquierdo) + contar_nodos(raiz->derecho));
}
   ```

13. Función que retorna la altura de un árbol binario:


   ```c
int altura(NodoArbol *raiz)
{
   int alt_izq, alt_der;

   if (raiz == NULL)         //caso base: arbol vacio
      return(0);

   alt_izq = altura(raiz->izquierdo);
   alt_der = altura(raiz->derecho);

   if (alt_izq > alt_der)
      return(1 + alt_izq);
   else
      return(1 + alt_der);
}
   ```

La altura de cada subárbol se calcula recursivamente, y la función retorna 1 más la mayor de las dos alturas –la del subárbol izquierdo o la del derecho–, ya que la hoja más profunda se encontrará necesariamente en uno de los dos.

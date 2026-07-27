/* Codigo 7.18: Función que retorna una cuenta con el saldo actualizado */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

struct cuenta
{
   char titular[30];
   float saldo;
};

struct cuenta depositar(struct cuenta c, float monto)
{
   c.saldo = c.saldo + monto;
   return(c);
}

int main()
{
   struct cuenta c = {"Ana", 50000};

   c = depositar(c, 20000);
   printf("Saldo de %s: %.0f", c.titular, c.saldo);
}

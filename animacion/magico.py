# -*- coding: utf-8 -*-
# ============================================================
#  magico.py  —  Animacion estilo 3Blue1Brown del algoritmo
#  que verifica si un numero es "magico": descompone el numero
#  en digitos con %10 y /10, los acumula, y compara dig^2 con
#  la suma acumulada.
#
#  Codigo 4.26 del libro. Ejemplo animado: num = 22 (magico).
#
#  Requiere:  pip install manim
#  Renderizar:
#     manim -pqh magico.py NumeroMagico     (alta calidad)
#     manim -pqm magico.py NumeroMagico     (media, mas rapido)
# ============================================================

from manim import *

# ----- paleta 3Blue1Brown -----
FONDO      = "#000000"
AZUL_3B1B  = "#3B87C4"
AZUL_CLARO = "#58C4DD"
AMARILLO   = "#F0C15A"
VERDE      = "#83C167"
ROJO_SUAVE = "#E07A5F"
GRIS       = "#888888"
MORADO     = "#9A72AC"

config.background_color = FONDO

NUM_INICIAL = 22


class NumeroMagico(Scene):
    def construct(self):
        self.intro()
        self.mostrar_variables()
        self.ejecutar_bucle()
        self.comparacion_final()

    # --------------------------------------------------------
    #  1. Intro
    # --------------------------------------------------------
    def intro(self):
        titulo = Text("¿Es un número mágico?", font="sans-serif", weight=BOLD)
        titulo.scale(1.1).to_edge(UP)

        regla = Text(
            "un número es mágico si  (último dígito)²  =  suma de sus dígitos",
            font="sans-serif", color=GRIS,
        ).scale(0.42).next_to(titulo, DOWN, buff=0.25)

        self.play(Write(titulo), run_time=1.2)
        self.play(FadeIn(regla, shift=UP * 0.2), run_time=0.8)
        self.wait(1.0)

        self.titulo = titulo
        self.regla = regla

    # --------------------------------------------------------
    #  2. Estado de las variables
    # --------------------------------------------------------
    def mostrar_variables(self):
        # numero a analizar, grande y centrado arriba
        etiqueta_num = Text("num =", font="sans-serif", color=GRIS).scale(0.6)
        self.num_val = Integer(NUM_INICIAL, color=AZUL_CLARO).scale(1.4)
        self.num_val.next_to(etiqueta_num, RIGHT, buff=0.3)
        grupo_num = VGroup(etiqueta_num, self.num_val)
        grupo_num.move_to(UP * 1.4)

        self.play(FadeIn(etiqueta_num), FadeIn(self.num_val), run_time=0.8)
        self.etiqueta_num = etiqueta_num

        # cajas de estado: dig y acum
        self.dig_box, self.dig_val = self._caja_variable("dig", "—", AMARILLO)
        self.acum_box, self.acum_val = self._caja_variable("acum", "0", VERDE)

        grupo_dig = VGroup(self.dig_box, self.dig_val).move_to(LEFT * 2.5 + DOWN * 0.3)
        grupo_acum = VGroup(self.acum_box, self.acum_val).move_to(RIGHT * 2.5 + DOWN * 0.3)

        self.play(
            *[FadeIn(m) for m in [self.dig_box, self.dig_val,
                                   self.acum_box, self.acum_val]],
            run_time=0.8,
        )
        self.wait(0.5)

    def _caja_variable(self, nombre, valor_inicial, color):
        caja = RoundedRectangle(
            width=2.4, height=1.2, corner_radius=0.12,
            stroke_color=color, stroke_width=2.5,
            fill_color=color, fill_opacity=0.08,
        )
        etiq = Text(nombre, font="sans-serif", color=color).scale(0.45)
        etiq.move_to(caja.get_top() + DOWN * 0.3)
        val = Text(str(valor_inicial), font="sans-serif", color=WHITE).scale(0.7)
        val.move_to(caja.get_center() + DOWN * 0.15)
        return VGroup(caja, etiq), val

    # --------------------------------------------------------
    #  3. El bucle while: extraer digitos
    # --------------------------------------------------------
    def ejecutar_bucle(self):
        # traza precalculada para num = 22
        num = NUM_INICIAL
        acum = 0
        iteracion = 0

        indicador = Text("while (num):", font="Monospace", color=MORADO).scale(0.5)
        indicador.to_edge(LEFT).shift(UP * 0.2 + RIGHT * 0.3)
        self.play(FadeIn(indicador), run_time=0.5)

        while num:
            iteracion += 1
            dig = num % 10
            acum_ant = acum
            acum = acum + dig
            num_nuevo = num // 10

            # -- resaltar iteracion --
            marco_iter = Text(f"iteración {iteracion}", font="sans-serif",
                              color=AZUL_CLARO).scale(0.45)
            marco_iter.to_corner(UL).shift(DOWN * 1.4 + RIGHT * 0.2)
            if iteracion == 1:
                self.play(FadeIn(marco_iter), run_time=0.4)
                self.marco_iter = marco_iter
            else:
                self.play(Transform(self.marco_iter, marco_iter), run_time=0.4)

            # -- paso A: dig = num % 10 --
            op_dig = MathTex(
                r"\text{dig} = ", str(num), r"\bmod 10 = ", str(dig),
                color=WHITE,
            ).scale(0.7).to_edge(DOWN, buff=1.4)
            op_dig[1].set_color(AZUL_CLARO)
            op_dig[3].set_color(AMARILLO)
            self.play(Write(op_dig), run_time=0.7)

            # actualizar caja dig
            nuevo_dig = Text(str(dig), font="sans-serif", color=WHITE).scale(0.7)
            nuevo_dig.move_to(self.dig_val)
            self.play(
                Transform(self.dig_val, nuevo_dig),
                Flash(self.dig_box[0].get_center(), color=AMARILLO,
                      line_length=0.15, flash_radius=0.7),
                run_time=0.6,
            )

            # -- paso B: acum = acum + dig --
            op_acum = MathTex(
                r"\text{acum} = ", str(acum_ant), " + ", str(dig), " = ", str(acum),
                color=WHITE,
            ).scale(0.7).to_edge(DOWN, buff=0.6)
            op_acum[1].set_color(VERDE)
            op_acum[3].set_color(AMARILLO)
            op_acum[5].set_color(VERDE)
            self.play(Write(op_acum), run_time=0.7)

            nuevo_acum = Text(str(acum), font="sans-serif", color=WHITE).scale(0.7)
            nuevo_acum.move_to(self.acum_val)
            self.play(
                Transform(self.acum_val, nuevo_acum),
                Flash(self.acum_box[0].get_center(), color=VERDE,
                      line_length=0.15, flash_radius=0.7),
                run_time=0.6,
            )
            self.wait(0.3)

            # -- paso C: num = num / 10 --
            op_num = MathTex(
                r"\text{num} = ", str(num), r"\div 10 = ", str(num_nuevo),
                color=WHITE,
            ).scale(0.7).move_to(op_dig)
            op_num[1].set_color(AZUL_CLARO)
            op_num[3].set_color(AZUL_CLARO)
            self.play(
                FadeOut(op_dig), FadeOut(op_acum),
                Write(op_num), run_time=0.7,
            )

            nuevo_num = Integer(num_nuevo, color=AZUL_CLARO).scale(1.4)
            nuevo_num.move_to(self.num_val)
            self.play(Transform(self.num_val, nuevo_num), run_time=0.6)
            self.wait(0.4)
            self.play(FadeOut(op_num), run_time=0.4)

            num = num_nuevo
            self.ultimo_dig = dig
            self.acum_final = acum

        # num llego a 0: el bucle termina
        fin_bucle = Text("num = 0  →  el bucle termina",
                         font="sans-serif", color=MORADO).scale(0.5)
        fin_bucle.to_edge(DOWN, buff=1.0)
        self.play(FadeIn(fin_bucle, shift=UP * 0.2), run_time=0.7)
        self.wait(0.8)
        self.play(FadeOut(fin_bucle), FadeOut(indicador),
                  FadeOut(self.marco_iter), run_time=0.5)

    # --------------------------------------------------------
    #  4. Comparacion final: dig^2 == acum ?
    # --------------------------------------------------------
    def comparacion_final(self):
        # limpiar la escena central, dejar solo dig y acum
        self.play(
            FadeOut(self.num_val), FadeOut(self.etiqueta_num),
            FadeOut(self.regla),
            run_time=0.6,
        )

        dig = self.ultimo_dig
        acum = self.acum_final

        # la condicion:  dig * dig == acum
        pregunta = MathTex(
            r"\text{dig}^2", r"\;=\;", r"\text{acum}", r"\;?",
            color=WHITE,
        ).scale(1.0).move_to(UP * 0.5)
        pregunta[0].set_color(AMARILLO)
        pregunta[2].set_color(VERDE)
        self.play(Write(pregunta), run_time=1.0)
        self.wait(0.5)

        # sustituir por los valores
        valores = MathTex(
            str(dig), r"^2", r"\;=\;", str(acum), r"\;?",
            color=WHITE,
        ).scale(1.0).move_to(pregunta)
        valores[0].set_color(AMARILLO)
        valores[3].set_color(VERDE)
        self.play(TransformMatchingShapes(pregunta, valores), run_time=0.9)
        self.wait(0.5)

        # resolver dig^2
        resultado = MathTex(
            str(dig * dig), r"\;=\;", str(acum), r"\;?",
            color=WHITE,
        ).scale(1.0).move_to(valores)
        resultado[0].set_color(AMARILLO)
        resultado[2].set_color(VERDE)
        self.play(TransformMatchingShapes(valores, resultado), run_time=0.9)
        self.wait(0.7)

        # veredicto
        es_magico = (dig * dig == acum)
        if es_magico:
            veredicto = Text(f"El número {NUM_INICIAL} es mágico",
                             font="sans-serif", color=AMARILLO,
                             weight=BOLD).scale(0.8)
            color_flash = AMARILLO
        else:
            veredicto = Text("No es mágico", font="sans-serif",
                             color=ROJO_SUAVE, weight=BOLD).scale(0.8)
            color_flash = ROJO_SUAVE

        veredicto.move_to(DOWN * 1.5)

        # el signo = se vuelve verde si es verdadero
        check = MathTex(str(dig * dig), r"\;=\;", str(acum),
                        color=VERDE).scale(1.0).move_to(resultado)
        self.play(TransformMatchingShapes(resultado, check), run_time=0.6)

        self.play(
            FadeIn(veredicto, shift=UP * 0.3),
            Flash(veredicto.get_center(), color=color_flash,
                  line_length=0.4, num_lines=16, flash_radius=1.2),
            run_time=1.2,
        )
        self.wait(2.0)

        # cierre: la idea del algoritmo
        idea = Text(
            "%10 extrae el último dígito  ·  /10 lo elimina  ·  se repite",
            font="sans-serif", color=GRIS,
        ).scale(0.42).to_edge(DOWN, buff=0.4)
        self.play(FadeIn(idea), run_time=0.8)
        self.wait(2.5)


class CodigoC(Scene):
    """Escena opcional: el codigo C original con resaltado.

    La API de Code() cambio en Manim 0.18 (code= paso a ser code_string=).
    Este bloque intenta la forma nueva y cae a la antigua si falla, para
    funcionar en cualquier version instalada.
    """
    def construct(self):
        codigo = '''#include <stdio.h>

int main()
{
   int num, old_num, dig, acum = 0;
   printf("Ingrese un número: ");
   scanf("%d", &num);
   old_num = num;

   while (num) {
      dig  = num % 10;
      acum = acum + dig;
      num  = num / 10;
   }

   if (dig*dig == acum)
      printf("El número %d es mágico\\n", old_num);
   else
      printf("No es mágico\\n");
}'''
        try:
            # Manim >= 0.18
            bloque = Code(
                code_string=codigo, language="c",
                background="window",
            ).scale(0.7)
        except TypeError:
            # Manim < 0.18
            bloque = Code(
                code=codigo, language="c", font="Monospace",
                background="window", style="monokai",
            ).scale(0.7)
        self.play(FadeIn(bloque), run_time=1.5)
        self.wait(3.0)

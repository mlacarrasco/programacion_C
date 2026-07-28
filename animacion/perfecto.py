# -*- coding: utf-8 -*-
# ============================================================
#  perfecto.py  —  Animacion estilo 3Blue1Brown del algoritmo
#  que determina si un numero es PERFECTO.
#
#  Un numero es perfecto si es igual a la suma de sus divisores
#  propios (los divisores menores que el, excluyendo el mismo).
#  El bucle prueba cada b desde a-1 hasta 1; si a % b == 0,
#  entonces b es divisor y se acumula.
#
#  Codigo 4.30 del libro. Ejemplo animado: a = 6 (perfecto).
#      divisores propios: 1, 2, 3   ->   1 + 2 + 3 = 6
#
#  Requiere:  pip install manim
#  Renderizar:
#     manim -pqh perfecto.py NumeroPerfecto   (alta calidad)
#     manim -pqm perfecto.py NumeroPerfecto   (media, mas rapido)
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

A = 6   # numero a verificar


class NumeroPerfecto(Scene):
    def construct(self):
        self.intro()
        self.preparar_estado()
        self.probar_divisores()
        self.comparacion_final()

    # --------------------------------------------------------
    #  1. Intro
    # --------------------------------------------------------
    def intro(self):
        titulo = Text("¿Es un número perfecto?", font="sans-serif",
                      weight=BOLD).scale(1.0).to_edge(UP)
        self.play(Write(titulo), run_time=1.0)

        regla = Text(
            "un número es perfecto si es igual a la suma de sus divisores propios",
            font="sans-serif", color=GRIS,
        ).scale(0.42).next_to(titulo, DOWN, buff=0.25)
        self.play(FadeIn(regla, shift=UP * 0.2), run_time=0.8)
        self.wait(1.0)
        self.titulo = titulo
        self.regla = regla

    # --------------------------------------------------------
    #  2. Estado: el numero, el acumulador y la lista de divisores
    # --------------------------------------------------------
    def preparar_estado(self):
        # el numero a analizar, grande
        etiqueta = Text("a =", font="sans-serif", color=GRIS).scale(0.7)
        self.num = Integer(A, color=AZUL_CLARO).scale(1.6)
        self.num.next_to(etiqueta, RIGHT, buff=0.3)
        grupo = VGroup(etiqueta, self.num).move_to(UP * 1.5)
        self.play(FadeIn(etiqueta), FadeIn(self.num), run_time=0.8)

        # acumulador
        self.acum_box = RoundedRectangle(
            width=2.4, height=1.1, corner_radius=0.12,
            stroke_color=VERDE, stroke_width=2.5,
            fill_color=VERDE, fill_opacity=0.08,
        ).move_to(RIGHT * 3.5 + UP * 1.5)
        acum_lbl = Text("acum", font="sans-serif", color=VERDE).scale(0.42)
        acum_lbl.move_to(self.acum_box.get_top() + DOWN * 0.28)
        self.acum_val = Text("0", font="sans-serif", color=WHITE).scale(0.65)
        self.acum_val.move_to(self.acum_box.get_center() + DOWN * 0.12)
        self.play(FadeIn(self.acum_box), FadeIn(acum_lbl),
                  FadeIn(self.acum_val), run_time=0.7)

        # zona para ir listando los divisores encontrados
        self.divisores_lbl = Text("divisores propios:", font="sans-serif",
                                  color=AMARILLO).scale(0.45)
        self.divisores_lbl.move_to(LEFT * 3.8 + UP * 0.2)
        self.play(FadeIn(self.divisores_lbl), run_time=0.5)
        self.divisores_txt = VGroup()   # se ira llenando
        self.wait(0.4)

    # --------------------------------------------------------
    #  3. Probar cada divisor candidato b = a-1, a-2, ..., 1
    # --------------------------------------------------------
    def probar_divisores(self):
        subtit = Text("for b = a-1 … 1 :  ¿a % b == 0?",
                      font="Monospace", color=MORADO).scale(0.42)
        subtit.to_edge(DOWN, buff=0.5)
        self.play(FadeIn(subtit), run_time=0.5)

        acum = 0
        divisores = []
        pos_x = -3.8   # donde empieza la lista de divisores
        contador_div = 0

        for b in range(A - 1, 0, -1):
            es_div = (A % b == 0)
            resto = A % b

            # -- mostrar el candidato b y la operacion modulo --
            op = MathTex(
                str(A), r"\bmod", str(b), "=", str(resto),
                color=WHITE,
            ).scale(0.7).to_edge(DOWN, buff=1.3)
            op[0].set_color(AZUL_CLARO)
            op[2].set_color(AMARILLO)
            op[4].set_color(VERDE if es_div else ROJO_SUAVE)
            self.play(Write(op), run_time=0.6)
            self.wait(0.3)

            if es_div:
                acum += b
                divisores.append(b)
                contador_div += 1

                # veredicto: es divisor
                marca = Text("si es divisor", font="sans-serif",
                             color=VERDE).scale(0.4)
                marca.next_to(op, RIGHT, buff=0.4)
                self.play(FadeIn(marca), run_time=0.4)

                # agregar b a la lista de divisores
                div_item = Text(str(b), font="Monospace", color=AMARILLO).scale(0.55)
                div_item.move_to([pos_x + contador_div * 0.7, -0.4, 0])
                self.play(FadeIn(div_item, shift=UP * 0.2), run_time=0.4)
                self.divisores_txt.add(div_item)

                # actualizar acumulador
                nuevo_acum = Text(str(acum), font="sans-serif",
                                  color=WHITE).scale(0.65)
                nuevo_acum.move_to(self.acum_val)
                self.play(
                    Transform(self.acum_val, nuevo_acum),
                    Flash(self.acum_box.get_center(), color=VERDE,
                          line_length=0.15, flash_radius=0.6),
                    run_time=0.5,
                )
                self.play(FadeOut(op), FadeOut(marca), run_time=0.4)
            else:
                # no es divisor
                marca = Text("no divide", font="sans-serif",
                             color=ROJO_SUAVE).scale(0.4)
                marca.next_to(op, RIGHT, buff=0.4)
                self.play(FadeIn(marca), run_time=0.3)
                self.wait(0.2)
                self.play(FadeOut(op), FadeOut(marca), run_time=0.4)

        self.acum_final = acum
        self.divisores_final = divisores
        self.play(FadeOut(subtit), run_time=0.4)

    # --------------------------------------------------------
    #  4. Comparacion final: acum == a ?
    # --------------------------------------------------------
    def comparacion_final(self):
        # mostrar la suma de divisores como formula
        suma_str = " + ".join(str(d) for d in sorted(self.divisores_final))
        formula = MathTex(
            suma_str, "=", str(self.acum_final),
            color=WHITE,
        ).scale(0.8).move_to(DOWN * 1.3)
        formula[-1].set_color(VERDE)
        self.play(Write(formula), run_time=1.0)
        self.wait(0.6)

        # la condicion acum == a
        pregunta = MathTex(
            str(self.acum_final), r"\;=\;", str(A), r"\;?",
            color=WHITE,
        ).scale(0.9).move_to(DOWN * 2.3)
        pregunta[0].set_color(VERDE)
        pregunta[2].set_color(AZUL_CLARO)
        self.play(Write(pregunta), run_time=0.8)
        self.wait(0.6)

        es_perfecto = (self.acum_final == A)
        if es_perfecto:
            veredicto = Text(f"El número {A} es perfecto",
                             font="sans-serif", color=AMARILLO,
                             weight=BOLD).scale(0.75)
            color_flash = AMARILLO
        else:
            veredicto = Text(f"El número {A} no es perfecto",
                             font="sans-serif", color=ROJO_SUAVE,
                             weight=BOLD).scale(0.75)
            color_flash = ROJO_SUAVE

        # limpiar para el veredicto
        self.play(FadeOut(self.regla), run_time=0.4)
        veredicto.to_edge(DOWN, buff=0.6)
        self.play(
            FadeIn(veredicto, shift=UP * 0.3),
            Flash(self.num.get_center(), color=color_flash,
                  line_length=0.4, num_lines=16, flash_radius=1.2),
            run_time=1.2,
        )
        self.wait(2.5)


class CodigoC(Scene):
    """Escena opcional: el codigo C original con resaltado."""
    def construct(self):
        codigo = '''#include <stdio.h>

int main()
{
   int a, b, acum = 0;

   printf("Ingrese un número: ");
   scanf("%d", &a);

   for (b = a-1; b > 0; b--) {
      if (a % b == 0)
         acum += b;
   }

   if (acum == a)
      printf("El numero %d es perfecto", a);
}'''
        try:
            bloque = Code(code_string=codigo, language="c",
                          background="window").scale(0.7)
        except TypeError:
            bloque = Code(code=codigo, language="c", font="Monospace",
                          background="window", style="monokai").scale(0.7)
        self.play(FadeIn(bloque), run_time=1.5)
        self.wait(3.0)

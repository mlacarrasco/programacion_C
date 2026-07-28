# -*- coding: utf-8 -*-
# ============================================================
#  binario.py  —  Animacion estilo 3Blue1Brown del algoritmo
#  que convierte un numero binario a decimal.
#
#  El programa procesa el binario de derecha a izquierda:
#  extrae cada digito con %10, lo multiplica por una potencia
#  de 2 creciente (exp = 1, 2, 4, 8, ...) y lo acumula.
#
#  Codigo 4.27 del libro. Ejemplo animado: 1011 -> 11.
#
#  Requiere:  pip install manim
#  Renderizar:
#     manim -pqh binario.py BinarioADecimal   (alta calidad)
#     manim -pqm binario.py BinarioADecimal   (media, mas rapido)
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

BINARIO = "1011"          # numero binario a convertir (como texto)
BITS = [int(c) for c in BINARIO]   # [1, 0, 1, 1]


class BinarioADecimal(Scene):
    def construct(self):
        self.intro()
        self.mostrar_bits()
        self.procesar_bits()
        self.resultado_final()

    # --------------------------------------------------------
    #  1. Intro
    # --------------------------------------------------------
    def intro(self):
        titulo = Text("De binario a decimal", font="sans-serif", weight=BOLD)
        titulo.scale(1.1).to_edge(UP)

        regla = VGroup(
            Text("cada bit vale", font="sans-serif", color=GRIS).scale(0.5),
            MathTex(r"d \times 2^{\,k}", color=GRIS).scale(0.6),
            Text("según su posición", font="sans-serif", color=GRIS).scale(0.5),
        ).arrange(RIGHT, buff=0.25).next_to(titulo, DOWN, buff=0.25)

        self.play(Write(titulo), run_time=1.2)
        self.play(FadeIn(regla, shift=UP * 0.2), run_time=0.8)
        self.wait(1.0)
        self.titulo = titulo
        self.regla = regla

    # --------------------------------------------------------
    #  2. Mostrar los bits con sus posiciones
    # --------------------------------------------------------
    def mostrar_bits(self):
        # dibujar cada bit en una caja, de izquierda a derecha como se escribe
        self.cajas = VGroup()
        self.bits_txt = VGroup()
        self.pesos_txt = VGroup()

        n = len(BITS)
        ancho_caja = 1.1
        sep = 1.3
        x_inicio = -(n - 1) * sep / 2

        for i, bit in enumerate(BITS):
            x = x_inicio + i * sep
            caja = Square(side_length=ancho_caja,
                          stroke_color=AZUL_3B1B, stroke_width=2.5,
                          fill_color=AZUL_3B1B, fill_opacity=0.08)
            caja.move_to([x, 1.3, 0])
            bit_t = Text(str(bit), font="Monospace", color=WHITE).scale(0.8)
            bit_t.move_to(caja.get_center())
            self.cajas.add(caja)
            self.bits_txt.add(bit_t)

        self.play(
            LaggedStart(*[FadeIn(c) for c in self.cajas], lag_ratio=0.15),
            LaggedStart(*[FadeIn(b) for b in self.bits_txt], lag_ratio=0.15),
            run_time=1.5,
        )

        # etiquetas de peso posicional debajo de cada bit
        # el bit MAS a la derecha es 2^0, hacia la izquierda crece
        for i in range(len(BITS)):
            # posicion desde la derecha
            pos_desde_derecha = len(BITS) - 1 - i
            peso = MathTex(f"2^{{{pos_desde_derecha}}}", color=GRIS).scale(0.55)
            peso.next_to(self.cajas[i], DOWN, buff=0.25)
            self.pesos_txt.add(peso)

        self.play(
            LaggedStart(*[FadeIn(p) for p in self.pesos_txt], lag_ratio=0.1),
            run_time=1.0,
        )
        self.wait(0.8)

        # cajas de estado: acum y exp
        self.acum_box, self.acum_val = self._caja_estado("acum", "0", VERDE, LEFT * 3.5 + DOWN * 1.3)
        self.exp_box, self.exp_val = self._caja_estado("exp", "1", AMARILLO, RIGHT * 3.5 + DOWN * 1.3)
        self.play(
            *[FadeIn(m) for m in [self.acum_box, self.acum_val,
                                   self.exp_box, self.exp_val]],
            run_time=0.8,
        )
        self.wait(0.5)

    def _caja_estado(self, nombre, valor, color, pos):
        caja = RoundedRectangle(width=2.2, height=1.1, corner_radius=0.12,
                                stroke_color=color, stroke_width=2.5,
                                fill_color=color, fill_opacity=0.08)
        caja.move_to(pos)
        etiq = Text(nombre, font="sans-serif", color=color).scale(0.42)
        etiq.move_to(caja.get_top() + DOWN * 0.28)
        val = Text(valor, font="sans-serif", color=WHITE).scale(0.65)
        val.move_to(caja.get_center() + DOWN * 0.12)
        return VGroup(caja, etiq), val

    # --------------------------------------------------------
    #  3. Procesar bits de derecha a izquierda
    # --------------------------------------------------------
    def procesar_bits(self):
        acum = 0
        exp = 1
        n = len(BITS)

        indicador = Text("procesa de derecha a izquierda →",
                         font="sans-serif", color=MORADO).scale(0.42)
        indicador.to_edge(DOWN, buff=1.6)
        self.play(FadeIn(indicador), run_time=0.5)

        # recorrer de derecha (indice n-1) a izquierda (indice 0)
        for paso, i in enumerate(range(n - 1, -1, -1)):
            bit = BITS[i]
            contrib = bit * exp
            acum_ant = acum
            acum = acum + contrib

            # -- resaltar el bit actual --
            self.play(
                self.cajas[i].animate.set_fill(AMARILLO, opacity=0.35)
                                     .set_stroke(AMARILLO),
                self.bits_txt[i].animate.set_color(AMARILLO),
                run_time=0.5,
            )

            # -- ecuacion de contribucion: bit x exp = contrib --
            ecuacion = MathTex(
                str(bit), r"\times", str(exp), "=", str(contrib),
                color=WHITE,
            ).scale(0.8).to_edge(DOWN, buff=0.55)
            ecuacion[0].set_color(AMARILLO)   # bit
            ecuacion[2].set_color(AMARILLO)   # exp
            ecuacion[4].set_color(VERDE)      # contribucion
            self.play(Write(ecuacion), run_time=0.7)

            # -- actualizar acum --
            nuevo_acum = Text(str(acum), font="sans-serif", color=WHITE).scale(0.65)
            nuevo_acum.move_to(self.acum_val)
            self.play(
                Transform(self.acum_val, nuevo_acum),
                Flash(self.acum_box[0].get_center(), color=VERDE,
                      line_length=0.15, flash_radius=0.6),
                run_time=0.6,
            )
            self.wait(0.3)

            # -- exp se duplica (salvo en el ultimo paso) --
            exp_sig = exp * 2
            if paso < n - 1:
                nuevo_exp = Text(str(exp_sig), font="sans-serif",
                                 color=WHITE).scale(0.65)
                nuevo_exp.move_to(self.exp_val)
                self.play(
                    Transform(self.exp_val, nuevo_exp),
                    Flash(self.exp_box[0].get_center(), color=AMARILLO,
                          line_length=0.15, flash_radius=0.6),
                    run_time=0.5,
                )

            # -- apagar el resaltado del bit --
            color_final = VERDE if bit == 1 else GRIS
            self.play(
                self.cajas[i].animate.set_fill(color_final, opacity=0.15)
                                     .set_stroke(color_final),
                self.bits_txt[i].animate.set_color(color_final),
                FadeOut(ecuacion),
                run_time=0.5,
            )
            exp = exp_sig
            self.wait(0.2)

        self.acum_final = acum
        self.play(FadeOut(indicador), run_time=0.4)

    # --------------------------------------------------------
    #  4. Resultado final
    # --------------------------------------------------------
    def resultado_final(self):
        # suma completa como formula
        n = len(BITS)
        terminos = []
        for i in range(n):
            pos = n - 1 - i
            bit = BITS[i]
            terminos.append(f"{bit}\\cdot 2^{{{pos}}}")
        formula_str = " + ".join(terminos)

        formula = MathTex(
            formula_str, "=", str(self.acum_final),
            color=WHITE,
        ).scale(0.7).move_to(DOWN * 0.3)
        formula[-1].set_color(VERDE)
        self.play(Write(formula), run_time=1.3)
        self.wait(0.8)

        # veredicto grande
        resultado = VGroup(
            Text(f"{BINARIO}", font="Monospace", color=AZUL_CLARO).scale(0.9),
            Text("(base 2)", font="sans-serif", color=GRIS).scale(0.45),
            MathTex(r"=", color=WHITE).scale(0.9),
            Text(f"{self.acum_final}", font="Monospace", color=AMARILLO,
                 weight=BOLD).scale(0.9),
            Text("(base 10)", font="sans-serif", color=GRIS).scale(0.45),
        ).arrange(RIGHT, buff=0.3).move_to(DOWN * 2.0)

        self.play(
            FadeIn(resultado, shift=UP * 0.3),
            Flash(resultado.get_center(), color=AMARILLO,
                  line_length=0.4, num_lines=16, flash_radius=1.5),
            run_time=1.3,
        )
        self.wait(2.5)


class CodigoC(Scene):
    """Escena opcional: el codigo C original con resaltado."""
    def construct(self):
        codigo = '''#include <stdio.h>

int main()
{
   int num_bin, digito, acum = 0, exp = 1;

   printf("Ingrese un número binario:");
   scanf("%d", &num_bin);

   while (num_bin)
   {
      digito  = num_bin % 10;
      num_bin = num_bin / 10;
      acum    = acum + digito*exp;
      exp     = exp * 2;
   }

   printf("El numero decimal es: %d", acum);
}'''
        try:
            bloque = Code(code_string=codigo, language="c",
                          background="window").scale(0.7)
        except TypeError:
            bloque = Code(code=codigo, language="c", font="Monospace",
                          background="window", style="monokai").scale(0.7)
        self.play(FadeIn(bloque), run_time=1.5)
        self.wait(3.0)

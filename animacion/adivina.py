# -*- coding: utf-8 -*-
# ============================================================
#  adivina.py  —  Animacion estilo 3Blue1Brown del juego de
#  adivinar un numero, mostrando la estrategia de busqueda
#  binaria acorralando al numero secreto.
#
#  Requiere:  pip install manim
#  Renderizar:
#     manim -pqh adivina.py JuegoAdivinanza     (alta calidad)
#     manim -pqm adivina.py JuegoAdivinanza     (media, mas rapido)
#
#  Escenas incluidas:
#     JuegoAdivinanza  -> animacion principal (la que quieres)
#     CodigoC          -> muestra el codigo C original (opcional)
# ============================================================

from manim import *

# ----- paleta 3Blue1Brown -----
FONDO      = "#000000"
AZUL_3B1B  = "#3B87C4"   # azul caracteristico
AZUL_CLARO = "#58C4DD"
AMARILLO   = "#F0C15A"   # el "1 brown"/amarillo de acento
VERDE      = "#83C167"
ROJO_SUAVE = "#E07A5F"
GRIS       = "#888888"

config.background_color = FONDO

SECRETO = 239421216
RANGO_MAX = 1_000_000_000


class JuegoAdivinanza(Scene):
    def construct(self):
        # ----------------------------------------------------
        #  1. Titulo de apertura
        # ----------------------------------------------------
        titulo = Text("Adivina el número", font="sans-serif", weight=BOLD)
        titulo.scale(1.1).to_edge(UP)
        subtitulo = Text(
            "¿cuántos intentos necesitas?",
            font="sans-serif", color=GRIS,
        ).scale(0.5).next_to(titulo, DOWN, buff=0.2)

        self.play(Write(titulo), run_time=1.2)
        self.play(FadeIn(subtitulo, shift=UP * 0.3), run_time=0.8)
        self.wait(0.5)

        # ----------------------------------------------------
        #  2. La recta numerica (rango de busqueda)
        # ----------------------------------------------------
        recta = NumberLine(
            x_range=[0, RANGO_MAX, RANGO_MAX / 10],
            length=11,
            color=GRIS,
            include_numbers=False,
        ).shift(DOWN * 0.5)

        etiq_0 = Text("0", font="sans-serif").scale(0.4)
        etiq_0.next_to(recta.n2p(0), DOWN, buff=0.2)
        etiq_max = Text("1.000.000.000", font="sans-serif").scale(0.4)
        etiq_max.next_to(recta.n2p(RANGO_MAX), DOWN, buff=0.2)

        self.play(Create(recta), run_time=1.0)
        self.play(FadeIn(etiq_0), FadeIn(etiq_max), run_time=0.6)

        # marcador del numero secreto (oculto al inicio)
        pos_secreto = recta.n2p(SECRETO)
        marca_secreto = DashedLine(
            pos_secreto + UP * 0.4, pos_secreto + DOWN * 0.4,
            color=AMARILLO, stroke_width=3,
        )
        etiq_secreto = Text("secreto", font="sans-serif", color=AMARILLO).scale(0.4)
        etiq_secreto.next_to(marca_secreto, UP, buff=0.15)

        self.play(Create(marca_secreto), FadeIn(etiq_secreto), run_time=0.8)
        self.wait(0.5)

        # ----------------------------------------------------
        #  3. La region de busqueda activa (lo..hi)
        # ----------------------------------------------------
        # rectangulo semitransparente que representa el rango vivo
        def rect_region(lo, hi):
            izq = recta.n2p(lo)
            der = recta.n2p(hi)
            ancho = der[0] - izq[0]
            r = Rectangle(
                width=max(ancho, 0.02), height=0.8,
                fill_color=AZUL_3B1B, fill_opacity=0.25,
                stroke_color=AZUL_CLARO, stroke_width=2,
            )
            r.move_to([(izq[0] + der[0]) / 2, recta.n2p(0)[1], 0])
            return r

        lo, hi = 0, RANGO_MAX
        region = rect_region(lo, hi)
        self.play(FadeIn(region), run_time=0.6)

        # contador de intentos
        contador = Text("intento: 0", font="sans-serif", color=AZUL_CLARO).scale(0.5)
        contador.to_corner(UR).shift(DOWN * 0.3)
        self.play(FadeIn(contador))

        # ----------------------------------------------------
        #  4. Iteraciones de busqueda binaria (primeras 7)
        # ----------------------------------------------------
        pasos = self._calcular_pasos()
        pasos_visibles = pasos[:7]

        flecha_guess = None
        etiq_guess = None
        etiq_resp = None

        for (intento, plo, phi, guess, resp) in pasos_visibles:
            # actualizar contador
            nuevo_cont = Text(f"intento: {intento}", font="sans-serif",
                              color=AZUL_CLARO).scale(0.5)
            nuevo_cont.to_corner(UR).shift(DOWN * 0.3)

            # flecha que apunta al guess
            pos_guess = recta.n2p(guess)
            nueva_flecha = Arrow(
                pos_guess + UP * 1.3, pos_guess + UP * 0.15,
                color=AZUL_CLARO, buff=0, stroke_width=4,
                max_tip_length_to_length_ratio=0.3,
            )
            nueva_etiq_guess = Text(f"{guess:,}".replace(",", "."),
                                    font="sans-serif", color=WHITE).scale(0.4)
            nueva_etiq_guess.next_to(nueva_flecha, UP, buff=0.1)

            if flecha_guess is None:
                self.play(
                    GrowArrow(nueva_flecha),
                    FadeIn(nueva_etiq_guess),
                    Transform(contador, nuevo_cont),
                    run_time=0.7,
                )
            else:
                self.play(
                    Transform(flecha_guess, nueva_flecha),
                    Transform(etiq_guess, nueva_etiq_guess),
                    Transform(contador, nuevo_cont),
                    run_time=0.7,
                )
                if etiq_resp:
                    self.remove(etiq_resp)

            if flecha_guess is None:
                flecha_guess = nueva_flecha
                etiq_guess = nueva_etiq_guess

            # mensaje de respuesta "es mayor" / "es menor"
            if resp == "menor":
                texto_resp = "es menor →  descarto la derecha"
                color_resp = ROJO_SUAVE
            elif resp == "mayor":
                texto_resp = "es mayor →  descarto la izquierda"
                color_resp = VERDE
            else:
                texto_resp = "¡correcto!"
                color_resp = AMARILLO

            etiq_resp = Text(texto_resp, font="sans-serif",
                             color=color_resp).scale(0.45)
            etiq_resp.to_edge(DOWN, buff=0.4)
            self.play(FadeIn(etiq_resp, shift=UP * 0.2), run_time=0.5)
            self.wait(0.3)

            # contraer la region segun la respuesta
            if resp == "menor":
                hi = guess - 1
            elif resp == "mayor":
                lo = guess + 1

            nueva_region = rect_region(lo, hi)
            self.play(Transform(region, nueva_region), run_time=0.8)
            self.wait(0.2)

        # ----------------------------------------------------
        #  5. Salto a la convergencia final
        # ----------------------------------------------------
        if etiq_resp:
            self.play(FadeOut(etiq_resp))

        puntos = Text(". . .", font="sans-serif", color=GRIS).scale(0.8)
        puntos.to_edge(DOWN, buff=0.8)
        self.play(FadeIn(puntos))

        mensaje = Text(
            "la región se reduce a la mitad cada vez",
            font="sans-serif", color=AZUL_CLARO,
        ).scale(0.5).to_edge(DOWN, buff=0.4)
        self.play(FadeIn(mensaje, shift=UP * 0.2), run_time=0.8)
        self.wait(1.0)
        self.play(FadeOut(puntos), FadeOut(mensaje))

        # colapsar al secreto
        region_final = rect_region(SECRETO, SECRETO)
        animaciones_finales = [Transform(region, region_final)]
        if flecha_guess:
            animaciones_finales.append(
                flecha_guess.animate.move_to(recta.n2p(SECRETO) + UP * 0.75)
            )
        self.play(*animaciones_finales, run_time=1.2)

        # ----------------------------------------------------
        #  6. Revelacion final
        # ----------------------------------------------------
        cont_final = Text("29 intentos", font="sans-serif",
                          color=AMARILLO, weight=BOLD).scale(0.6)
        cont_final.to_corner(UR).shift(DOWN * 0.3)
        self.play(Transform(contador, cont_final), run_time=0.6)

        formula = MathTex(
            r"\log_2(10^9) \approx 30",
            color=WHITE,
        ).scale(0.9).shift(DOWN * 2.2)
        self.play(Write(formula), run_time=1.2)

        explica = Text(
            "de mil millones de posibilidades a una, en ~30 pasos",
            font="sans-serif", color=GRIS,
        ).scale(0.42).next_to(formula, DOWN, buff=0.3)
        self.play(FadeIn(explica), run_time=0.8)

        self.play(
            Flash(recta.n2p(SECRETO), color=AMARILLO,
                  line_length=0.4, num_lines=16, flash_radius=0.6),
            run_time=1.0,
        )
        self.wait(2.0)

    def _calcular_pasos(self):
        """Reproduce la busqueda binaria y devuelve la lista de pasos."""
        lo, hi = 0, RANGO_MAX
        pasos, intento = [], 0
        while True:
            intento += 1
            guess = (lo + hi) // 2
            if guess > SECRETO:
                pasos.append((intento, lo, hi, guess, "menor"))
                hi = guess - 1
            elif guess < SECRETO:
                pasos.append((intento, lo, hi, guess, "mayor"))
                lo = guess + 1
            else:
                pasos.append((intento, lo, hi, guess, "correcto"))
                break
            if intento > 60:
                break
        return pasos


class CodigoC(Scene):
    """Escena opcional: muestra el codigo C original con resaltado."""
    def construct(self):
        codigo = '''#include <stdio.h>

int main()
{
   int numero, puntaje = 100;
   int secreto = 239421216;

   do {
      printf("Ingrese un número: ");
      scanf("%d", &numero);
      puntaje--;

      if (numero > secreto)
         printf("Es menor \\n");
      else if (numero < secreto)
         printf("Es mayor \\n");

   } while (numero != secreto);

   printf("\\n¡Adivinaste el número!\\n");
   printf("Obtuviste %d puntos", puntaje + 1);
}'''

        bloque = Code(
            code=codigo,
            language="c",
            font="Monospace",
            background="window",
            style="monokai",
        ).scale(0.7)

        self.play(FadeIn(bloque), run_time=1.5)
        self.wait(3.0)

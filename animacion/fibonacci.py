# -*- coding: utf-8 -*-
# ============================================================
#  fibonacci.py  —  Animacion estilo 3Blue1Brown de la funcion
#  recursiva de Fibonacci, mostrando el ARBOL DE LLAMADAS.
#
#  Cada fibonacci(n) se ramifica en fibonacci(n-1) y
#  fibonacci(n-2) hasta llegar a los casos base (n=0 o n=1).
#  Luego los valores "suben" sumandose hasta la raiz.
#
#  Codigo 5.11 del libro. Ejemplo animado: fibonacci(5) = 5.
#
#  Requiere:  pip install manim
#  Renderizar:
#     manim -pqh fibonacci.py ArbolFibonacci   (alta calidad)
#     manim -pqm fibonacci.py ArbolFibonacci   (media, mas rapido)
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

N_FIB = 5   # calcular fibonacci(5)


# ------------------------------------------------------------
#  Estructura del arbol (se construye en Python, no en Manim)
# ------------------------------------------------------------
class NodoFib:
    def __init__(self, n):
        self.n = n
        self.val = None
        self.hijos = []
        self.depth = 0
        self.x = 0.0
        # objetos graficos (se llenan luego)
        self.circulo = None
        self.etiqueta = None
        self.valor_txt = None
        self.arista = None   # linea al padre


def construir_arbol(n, depth=0):
    nodo = NodoFib(n)
    nodo.depth = depth
    if n <= 1:
        nodo.val = n
    else:
        nodo.hijos = [construir_arbol(n - 1, depth + 1),
                      construir_arbol(n - 2, depth + 1)]
        nodo.val = nodo.hijos[0].val + nodo.hijos[1].val
    return nodo


def asignar_x(nodo, contador):
    """Asigna coordenada x: hojas consecutivas, padres al centro."""
    if not nodo.hijos:
        nodo.x = contador[0]
        contador[0] += 1
    else:
        for h in nodo.hijos:
            asignar_x(h, contador)
        nodo.x = sum(h.x for h in nodo.hijos) / len(nodo.hijos)


def recorrer(nodo, lista):
    lista.append(nodo)
    for h in nodo.hijos:
        recorrer(h, lista)


class ArbolFibonacci(Scene):
    def construct(self):
        self.intro()
        self.preparar_arbol()
        self.desplegar_llamadas()
        self.resolver_casos_base()
        self.propagar_valores()
        self.cierre()

    # --------------------------------------------------------
    #  1. Intro con el codigo de la funcion
    # --------------------------------------------------------
    def intro(self):
        titulo = Text("Fibonacci recursivo", font="sans-serif", weight=BOLD)
        titulo.scale(1.0).to_edge(UP)
        self.play(Write(titulo), run_time=1.0)

        # la regla, en notacion clara
        regla = VGroup(
            MathTex(r"F(0)=0,\quad F(1)=1", color=GRIS).scale(0.6),
            MathTex(r"F(n)=F(n-1)+F(n-2)", color=AZUL_CLARO).scale(0.6),
        ).arrange(DOWN, buff=0.2).next_to(titulo, DOWN, buff=0.3)
        self.play(FadeIn(regla, shift=UP * 0.2), run_time=1.0)
        self.wait(1.0)
        self.play(regla.animate.scale(0.7).to_corner(UL).shift(DOWN * 0.3),
                  run_time=0.8)
        self.titulo = titulo
        self.regla = regla

    # --------------------------------------------------------
    #  2. Construir el arbol y crear los objetos graficos
    # --------------------------------------------------------
    def preparar_arbol(self):
        self.raiz = construir_arbol(N_FIB)
        asignar_x(self.raiz, [0])

        self.nodos = []
        recorrer(self.raiz, self.nodos)

        # rango de x para centrar
        xs = [nd.x for nd in self.nodos]
        x_min, x_max = min(xs), max(xs)
        x_centro = (x_min + x_max) / 2

        max_depth = max(nd.depth for nd in self.nodos)

        # factores de escala para que quepa en pantalla
        esc_x = 1.55
        esc_y = 1.25
        y_top = 2.2

        for nd in self.nodos:
            px = (nd.x - x_centro) * esc_x
            py = y_top - nd.depth * esc_y

            circ = Circle(radius=0.42, color=AZUL_3B1B,
                          fill_color=AZUL_3B1B, fill_opacity=0.15,
                          stroke_width=2.5)
            circ.move_to([px, py, 0])

            etiq = MathTex(f"F({nd.n})", color=WHITE).scale(0.5)
            etiq.move_to(circ.get_center())

            nd.circulo = circ
            nd.etiqueta = etiq
            nd.pos = np.array([px, py, 0])

        # aristas (lineas al padre)
        for nd in self.nodos:
            for h in nd.hijos:
                linea = Line(nd.pos, h.pos, color=GRIS, stroke_width=1.5)
                h.arista = linea

    # --------------------------------------------------------
    #  3. Desplegar las llamadas recursivas (arbol crece hacia abajo)
    # --------------------------------------------------------
    def desplegar_llamadas(self):
        # aparecer nivel por nivel (BFS por profundidad)
        subtit = Text("cada llamada se divide en dos",
                      font="sans-serif", color=MORADO).scale(0.45)
        subtit.to_edge(DOWN, buff=0.4)
        self.play(FadeIn(subtit), run_time=0.5)

        max_depth = max(nd.depth for nd in self.nodos)
        for d in range(max_depth + 1):
            nivel = [nd for nd in self.nodos if nd.depth == d]
            animaciones = []
            for nd in nivel:
                if nd.arista is not None:
                    animaciones.append(Create(nd.arista))
                animaciones.append(GrowFromCenter(nd.circulo))
                animaciones.append(FadeIn(nd.etiqueta, scale=0.5))
            self.play(*animaciones, run_time=0.8)
            self.wait(0.2)

        self.wait(0.5)
        self.play(FadeOut(subtit), run_time=0.4)

    # --------------------------------------------------------
    #  4. Resolver los casos base (hojas: n=0 o n=1)
    # --------------------------------------------------------
    def resolver_casos_base(self):
        subtit = Text("casos base: F(0)=0, F(1)=1",
                      font="sans-serif", color=AMARILLO).scale(0.45)
        subtit.to_edge(DOWN, buff=0.4)
        self.play(FadeIn(subtit), run_time=0.5)

        hojas = [nd for nd in self.nodos if not nd.hijos]
        animaciones = []
        for nd in hojas:
            # pintar la hoja de amarillo y mostrar su valor
            animaciones.append(
                nd.circulo.animate.set_stroke(AMARILLO)
                                  .set_fill(AMARILLO, opacity=0.25)
            )
        self.play(*animaciones, run_time=0.8)

        # mostrar el valor dentro de cada hoja (reemplaza la etiqueta)
        transformaciones = []
        for nd in hojas:
            val_txt = MathTex(str(nd.val), color=AMARILLO).scale(0.6)
            val_txt.move_to(nd.circulo.get_center())
            nd.valor_txt = val_txt
            transformaciones.append(
                Transform(nd.etiqueta, val_txt)
            )
        self.play(*transformaciones, run_time=0.8)
        self.wait(0.6)
        self.play(FadeOut(subtit), run_time=0.4)

    # --------------------------------------------------------
    #  5. Propagar los valores hacia arriba (sumar hijos)
    # --------------------------------------------------------
    def propagar_valores(self):
        subtit = Text("los resultados suben sumándose",
                      font="sans-serif", color=VERDE).scale(0.45)
        subtit.to_edge(DOWN, buff=0.4)
        self.play(FadeIn(subtit), run_time=0.5)

        # resolver de mayor profundidad a menor, solo nodos internos
        max_depth = max(nd.depth for nd in self.nodos)
        for d in range(max_depth, -1, -1):
            internos = [nd for nd in self.nodos if nd.depth == d and nd.hijos]
            if not internos:
                continue
            trans = []
            for nd in internos:
                # destello en las aristas de los hijos
                val_txt = MathTex(str(nd.val), color=VERDE).scale(0.6)
                val_txt.move_to(nd.circulo.get_center())
                trans.append(Transform(nd.etiqueta, val_txt))
                trans.append(
                    nd.circulo.animate.set_stroke(VERDE)
                                      .set_fill(VERDE, opacity=0.2)
                )
            self.play(*trans, run_time=0.9)
            self.wait(0.3)

        self.play(FadeOut(subtit), run_time=0.4)

    # --------------------------------------------------------
    #  6. Cierre: resaltar la raiz
    # --------------------------------------------------------
    def cierre(self):
        # resaltar la raiz con el resultado
        self.play(
            self.raiz.circulo.animate.set_stroke(AMARILLO, width=4)
                                     .set_fill(AMARILLO, opacity=0.3),
            Flash(self.raiz.circulo.get_center(), color=AMARILLO,
                  line_length=0.3, num_lines=16, flash_radius=0.8),
            run_time=1.0,
        )

        resultado = MathTex(
            f"F({N_FIB})", "=", str(self.raiz.val),
            color=WHITE,
        ).scale(1.0).to_edge(DOWN, buff=0.6)
        resultado[0].set_color(AZUL_CLARO)
        resultado[2].set_color(AMARILLO)
        self.play(Write(resultado), run_time=1.0)
        self.wait(1.0)

        # observacion: llamadas repetidas
        nota = Text(
            "nota: algunas ramas se recalculan varias veces",
            font="sans-serif", color=GRIS,
        ).scale(0.4).next_to(resultado, UP, buff=0.3)
        self.play(FadeIn(nota), run_time=0.8)
        self.wait(2.5)


class CodigoC(Scene):
    """Escena opcional: el codigo C original con resaltado."""
    def construct(self):
        codigo = '''int fibonacci(int n)
{
   if (n == 0 || n == 1)          // casos base
      return (n);
   else
      return (fibonacci(n-1) + fibonacci(n-2));  // recursivo
}'''
        try:
            bloque = Code(code_string=codigo, language="c",
                          background="window").scale(0.75)
        except TypeError:
            bloque = Code(code=codigo, language="c", font="Monospace",
                          background="window", style="monokai").scale(0.75)
        self.play(FadeIn(bloque), run_time=1.5)
        self.wait(3.0)

from manim import *

class PilaLIFO(Scene):
    def construct(self):
        self.camera.background_color = "#0e1116"

        # ----- Paleta estilo 3b1b -----
        AZUL     = "#58C4DD"
        AMARILLO = "#FFD166"
        VERDE    = "#83C167"
        ROJO     = "#FC6255"
        GRIS     = "#3d4450"

        ancho, alto = 2.2, 0.9
        base_y = -3.0            # y donde se apoya la pila
        col_x  = -3.2            # x de la columna de la pila

        # ----- Título -----
        titulo = Text("Pila (Stack) — estructura LIFO",
                      font="sans-serif", weight=BOLD).scale(0.6).to_edge(UP)
        self.play(Write(titulo))
        self.wait(0.3)

        # ----- Base de la pila y etiqueta 'tope' -----
        base = Line(LEFT * (ancho/2) + RIGHT*col_x + UP*base_y,
                    RIGHT * (ancho/2) + RIGHT*col_x + UP*base_y,
                    color=GRIS, stroke_width=6)
        base.move_to([col_x, base_y, 0])
        base_txt = Text("base", font="sans-serif", color="#7a8290").scale(0.4)
        base_txt.next_to(base, DOWN, buff=0.15)
        self.play(Create(base), FadeIn(base_txt))

        # Indicador de 'tope'
        tope_lbl = Text("tope = -1", font="monospace", color=AMARILLO).scale(0.5)
        tope_lbl.to_corner(UR).shift(DOWN*0.6 + LEFT*0.3)
        self.play(FadeIn(tope_lbl))
        self.wait(0.4)

        # ----- Estado de la pila -----
        celdas = []   # lista de VGroup(rect, texto)

        def y_de_nivel(nivel):
            # nivel 0 = primer elemento sobre la base
            return base_y + alto/2 + nivel * alto

        def apilar(valor):
            nivel = len(celdas)
            rect = Rectangle(width=ancho, height=alto,
                             stroke_color=AZUL, stroke_width=3,
                             fill_color="#1a2530", fill_opacity=1)
            num = Text(str(valor), font="sans-serif").scale(0.6)
            grupo = VGroup(rect, num)
            # Empieza arriba y "cae" a su posición
            destino = [col_x, y_de_nivel(nivel), 0]
            grupo.move_to([col_x, 2.2, 0])
            num.move_to(rect.get_center())

            etiqueta = Text(f"apilar({valor})", font="monospace",
                            color=VERDE).scale(0.5).to_edge(DOWN)
            self.play(FadeIn(etiqueta), run_time=0.3)
            self.play(grupo.animate.move_to(destino),
                      rate_func=rush_into, run_time=0.7)
            # el número debe quedar centrado tras mover el grupo
            num.move_to(rect.get_center())

            celdas.append(grupo)
            nuevo_tope = Text(f"tope = {nivel}", font="monospace",
                              color=AMARILLO).scale(0.5)
            nuevo_tope.move_to(tope_lbl)
            self.play(Transform(tope_lbl, nuevo_tope),
                      rect.animate.set_stroke(AMARILLO, width=4),
                      run_time=0.4)
            # las celdas de abajo vuelven a azul; solo el tope amarillo
            for c in celdas[:-1]:
                c[0].set_stroke(AZUL, width=3)
            self.play(FadeOut(etiqueta), run_time=0.2)
            self.wait(0.2)

        def desapilar():
            grupo = celdas.pop()
            valor = grupo[1].text
            etiqueta = Text(f"desapilar() → {valor}", font="monospace",
                            color=ROJO).scale(0.5).to_edge(DOWN)
            self.play(FadeIn(etiqueta), run_time=0.3)
            self.play(grupo[0].animate.set_stroke(ROJO, width=4), run_time=0.3)
            # sale hacia la derecha
            self.play(grupo.animate.shift(RIGHT*3 + UP*0.3).set_opacity(0.0),
                      rate_func=rush_from, run_time=0.7)
            self.remove(grupo)

            nivel = len(celdas) - 1
            nuevo_tope = Text(f"tope = {nivel}", font="monospace",
                              color=AMARILLO).scale(0.5)
            nuevo_tope.move_to(tope_lbl)
            self.play(Transform(tope_lbl, nuevo_tope), run_time=0.4)
            # nuevo tope resaltado
            if celdas:
                self.play(celdas[-1][0].animate.set_stroke(AMARILLO, width=4),
                          run_time=0.3)
            self.play(FadeOut(etiqueta), run_time=0.2)
            self.wait(0.2)
            return valor

        # ----- Secuencia del main() -----
        # apilar 10, 20, 30
        apilar(10)
        apilar(20)
        apilar(30)
        self.wait(0.5)

        # Mostrar zona de salida
        salida_lbl = Text("salida:", font="sans-serif", color="#7a8290").scale(0.5)
        salida_lbl.move_to([1.5, 1.8, 0])
        self.play(FadeIn(salida_lbl))

        salida = VGroup()
        # while (!pila_vacia): desapilar → 30 20 10
        while celdas:
            v = desapilar()
            t = Text(v, font="sans-serif", color=VERDE).scale(0.7)
            if len(salida) == 0:
                t.next_to(salida_lbl, RIGHT, buff=0.4)
            else:
                t.next_to(salida[-1], RIGHT, buff=0.4)
            salida.add(t)
            self.play(FadeIn(t, shift=UP*0.2), run_time=0.4)

        # ----- Estado final -----
        vacia = Text("Pila vacía  (tope == -1)", font="sans-serif",
                     color=ROJO, weight=BOLD).scale(0.55).to_edge(DOWN)
        self.play(Write(vacia))
        self.wait(2)
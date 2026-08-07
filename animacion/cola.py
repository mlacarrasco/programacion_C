from manim import *

class ColaEnlazada(Scene):
    def construct(self):
        self.camera.background_color = "#0e1116"

        # ----- Paleta estilo 3b1b -----
        AZUL     = "#58C4DD"
        AMARILLO = "#FFD166"
        VERDE    = "#83C167"
        ROJO     = "#FC6255"
        GRIS     = "#3d4450"
        MORADO   = "#C39BD3"

        w_val, w_ptr, h = 1.0, 0.7, 1.0   # ancho campo valor, campo puntero, alto
        w_nodo = w_val + w_ptr
        y_nodos = -0.3                      # y de la fila de nodos
        x_ini   = -4.8                      # x del primer nodo
        gap     = 1.0                       # separación entre nodos

        # ----- Título -----
        titulo = Text("Cola enlazada (Queue) — estructura FIFO",
                      font="sans-serif", weight=BOLD).scale(0.55).to_edge(UP)
        self.play(Write(titulo))
        self.wait(0.3)

        # ----- Estado -----
        nodos = []   # cada elemento: dict con rects, texto, flecha, posición

        def x_de_indice(i):
            return x_ini + i * (w_nodo + gap)

        def construir_nodo(valor, i):
            x = x_de_indice(i)
            # Campo valor
            r_val = Rectangle(width=w_val, height=h, stroke_color=AZUL,
                              stroke_width=3, fill_color="#1a2530", fill_opacity=1)
            # Campo puntero (siguiente)
            r_ptr = Rectangle(width=w_ptr, height=h, stroke_color=AZUL,
                              stroke_width=3, fill_color="#222b1a", fill_opacity=1)
            r_val.move_to([x, y_nodos, 0])
            r_ptr.next_to(r_val, RIGHT, buff=0)

            num = Text(str(valor), font="sans-serif").scale(0.6)
            num.move_to(r_val.get_center())
            grupo = VGroup(r_val, r_ptr, num)
            return {"grupo": grupo, "r_val": r_val, "r_ptr": r_ptr,
                    "num": num, "valor": valor, "flecha": None}

        # ----- Punteros frente y final -----
        frente_lbl = Text("frente", font="monospace", color=VERDE, weight=BOLD).scale(0.5)
        final_lbl  = Text("final",  font="monospace", color=ROJO,  weight=BOLD).scale(0.5)
        frente_flecha = None
        final_flecha  = None

        def actualizar_punteros():
            nonlocal frente_flecha, final_flecha
            anims = []
            if nodos:
                # frente apunta al primer nodo (desde arriba)
                n0 = nodos[0]["r_val"]
                top0 = n0.get_top() + UP*1.0
                f_new = Arrow(top0, n0.get_top()+UP*0.08, buff=0,
                              color=VERDE, stroke_width=6,
                              max_tip_length_to_length_ratio=0.35)
                fl_lbl = frente_lbl.copy().next_to(f_new, UP, buff=0.1)
                # final apunta al último nodo (desde abajo)
                nL = nodos[-1]["r_val"]
                bot = nL.get_bottom() + DOWN*1.0
                l_new = Arrow(bot, nL.get_bottom()+DOWN*0.08, buff=0,
                              color=ROJO, stroke_width=6,
                              max_tip_length_to_length_ratio=0.35)
                ll_lbl = final_lbl.copy().next_to(l_new, DOWN, buff=0.1)

                if frente_flecha is None:
                    frente_flecha = VGroup(f_new, fl_lbl)
                    final_flecha  = VGroup(l_new, ll_lbl)
                    anims += [GrowArrow(f_new), FadeIn(fl_lbl),
                              GrowArrow(l_new), FadeIn(ll_lbl)]
                else:
                    anims += [Transform(frente_flecha, VGroup(f_new, fl_lbl)),
                              Transform(final_flecha,  VGroup(l_new, ll_lbl))]
            return anims

        # ----- encolar (enqueue) -----
        def encolar(valor):
            i = len(nodos)
            nodo = construir_nodo(valor, i)
            etiqueta = Text(f"encolar({valor})", font="monospace",
                            color=VERDE).scale(0.5).to_edge(DOWN)
            self.play(FadeIn(etiqueta), run_time=0.3)

            # el nodo nuevo aparece desde la derecha
            nodo["grupo"].shift(RIGHT*2 + UP*0.1)
            self.play(FadeIn(nodo["grupo"], shift=LEFT*1.5), run_time=0.5)
            nodo["num"].move_to(nodo["r_val"].get_center())

            # NULL en el campo puntero del nuevo (último) nodo
            null_txt = Text("∅", font="sans-serif", color=GRIS).scale(0.5)
            null_txt.move_to(nodo["r_ptr"].get_center())
            self.play(FadeIn(null_txt), run_time=0.2)
            nodo["null"] = null_txt

            # enlazar el nodo anterior -> nuevo (final->siguiente = nuevo)
            if nodos:
                prev = nodos[-1]
                self.play(FadeOut(prev["null"]), run_time=0.2)
                flecha = Arrow(prev["r_ptr"].get_center(),
                               nodo["r_val"].get_left(),
                               buff=0.05, color=AMARILLO, stroke_width=5,
                               max_tip_length_to_length_ratio=0.25)
                prev["flecha"] = flecha
                self.play(GrowArrow(flecha), run_time=0.5)

            nodos.append(nodo)
            self.play(*actualizar_punteros(), run_time=0.6)
            self.play(FadeOut(etiqueta), run_time=0.2)
            self.wait(0.2)

        # ----- desencolar (dequeue) -----
        salida_lbl = None
        salida = VGroup()

        def desencolar():
            nonlocal frente_flecha, final_flecha
            nodo = nodos.pop(0)
            valor = nodo["valor"]
            etiqueta = Text(f"desencolar() → {valor}", font="monospace",
                            color=MORADO).scale(0.5).to_edge(DOWN)
            self.play(FadeIn(etiqueta), run_time=0.3)

            # resaltar el nodo del frente
            self.play(nodo["r_val"].animate.set_stroke(MORADO, width=4),
                      nodo["r_ptr"].animate.set_stroke(MORADO, width=4),
                      run_time=0.3)

            # quitar la flecha que sale de este nodo (si existe)
            fade = [FadeOut(nodo["grupo"])]
            if nodo.get("flecha"):
                fade.append(FadeOut(nodo["flecha"]))
            if nodo.get("null"):
                fade.append(FadeOut(nodo["null"]))
            # free(tmp): el nodo se desvanece hacia arriba
            self.play(nodo["grupo"].animate.shift(UP*1.2).set_opacity(0.0),
                      *([FadeOut(nodo["flecha"])] if nodo.get("flecha") else []),
                      *([FadeOut(nodo["null"])] if nodo.get("null") else []),
                      run_time=0.7)
            self.remove(nodo["grupo"])

            # agregar a la salida
            t = Text(str(valor), font="sans-serif", color=VERDE).scale(0.7)
            if len(salida) == 0:
                t.next_to(salida_lbl, RIGHT, buff=0.4)
            else:
                t.next_to(salida[-1], RIGHT, buff=0.4)
            salida.add(t)
            self.play(FadeIn(t, shift=UP*0.2), run_time=0.4)

            # actualizar punteros o vaciar
            if nodos:
                self.play(*actualizar_punteros(), run_time=0.6)
            else:
                anims = []
                if frente_flecha: anims.append(FadeOut(frente_flecha))
                if final_flecha:  anims.append(FadeOut(final_flecha))
                if anims:
                    self.play(*anims, run_time=0.4)
                frente_flecha = None
                final_flecha = None
            self.play(FadeOut(etiqueta), run_time=0.2)
            self.wait(0.2)

        # ----- Secuencia del main() -----
        encolar(10)
        encolar(20)
        encolar(30)
        self.wait(0.5)

        # zona de salida
        salida_lbl = Text("salida:", font="sans-serif", color="#7a8290").scale(0.5)
        salida_lbl.to_edge(DOWN).shift(UP*1.4 + LEFT*4.5)
        self.play(FadeIn(salida_lbl))

        # while (c.frente != NULL): desencolar → 10 20 30
        while nodos:
            desencolar()

        # ----- Estado final -----
        vacia = Text("Cola vacía  (frente == NULL)", font="sans-serif",
                     color=ROJO, weight=BOLD).scale(0.55).to_edge(DOWN)
        self.play(Write(vacia))
        self.wait(2)
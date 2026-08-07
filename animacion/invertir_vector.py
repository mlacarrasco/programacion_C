from manim import *

class InvertirVector(Scene):
    def construct(self):
        self.camera.background_color = "#0e1116"

        # ----- Parámetros -----
        n = 6
        valores = list(range(1, n + 1))   # 1..n
        ancho = 1.1
        alto = 1.1

        AZUL = "#58C4DD"      # color 3b1b clásico
        AMARILLO = "#FFD166"
        VERDE = "#83C167"
        ROJO = "#FC6255"
        GRIS = "#3d4450"

        # ----- Título -----
        titulo = Text("Inversión de un vector con dos punteros",
                      font="sans-serif", weight=BOLD).scale(0.6)
        titulo.to_edge(UP)
        self.play(Write(titulo))
        self.wait(0.5)

        # ----- Construcción de las celdas del arreglo -----
        celdas = VGroup()
        textos = VGroup()
        indices = VGroup()
        for i, val in enumerate(valores):
            cuadro = Rectangle(width=ancho, height=alto,
                               stroke_color=GRIS, stroke_width=3,
                               fill_color="#1a1f28", fill_opacity=1)
            num = Text(str(val), font="sans-serif").scale(0.6)
            num.move_to(cuadro.get_center())
            idx = Text(f"[{i}]", font="sans-serif", color="#7a8290").scale(0.35)
            idx.next_to(cuadro, DOWN, buff=0.15)
            celdas.add(cuadro)
            textos.add(num)
            indices.add(idx)

        celdas.arrange(RIGHT, buff=0)
        for i in range(n):
            textos[i].move_to(celdas[i].get_center())
            indices[i].next_to(celdas[i], DOWN, buff=0.15)

        grupo_arreglo = VGroup(celdas, textos, indices)
        grupo_arreglo.move_to(ORIGIN).shift(DOWN * 0.3)

        self.play(LaggedStart(*[Create(c) for c in celdas], lag_ratio=0.1))
        self.play(LaggedStart(*[FadeIn(t) for t in textos], lag_ratio=0.1),
                  LaggedStart(*[FadeIn(x) for x in indices], lag_ratio=0.1))
        self.wait(0.5)

        # ----- Punteros inicio y fin -----
        def flecha_puntero(idx, color, etiqueta, arriba=True):
            celda = celdas[idx]
            if arriba:
                inicio_f = celda.get_top() + UP * 0.9
                fin_f = celda.get_top() + UP * 0.1
            flecha = Arrow(inicio_f, fin_f, buff=0,
                           color=color, stroke_width=6,
                           max_tip_length_to_length_ratio=0.4)
            lbl = Text(etiqueta, font="sans-serif", color=color,
                       weight=BOLD).scale(0.45)
            lbl.next_to(flecha, UP, buff=0.1)
            return VGroup(flecha, lbl)

        i_ptr, j_ptr = 0, n - 1
        p_inicio = flecha_puntero(i_ptr, VERDE, "inicio")
        p_fin = flecha_puntero(j_ptr, ROJO, "fin")

        self.play(GrowArrow(p_inicio[0]), FadeIn(p_inicio[1]),
                  GrowArrow(p_fin[0]), FadeIn(p_fin[1]))
        self.wait(0.5)

        # ----- Bandera de código (opcional): línea while -----
        cond = Text("mientras  inicio < fin", font="monospace",
                    color=AMARILLO).scale(0.5)
        cond.to_edge(DOWN)
        self.play(FadeIn(cond))
        self.wait(0.5)

        # ----- Bucle de intercambio -----
        while i_ptr < j_ptr:
            # Resaltar las dos celdas que se van a intercambiar
            self.play(
                celdas[i_ptr].animate.set_stroke(AMARILLO, width=5),
                celdas[j_ptr].animate.set_stroke(AMARILLO, width=5),
                run_time=0.4
            )

            # Animar el swap: los dos textos hacen un arco cruzado
            t_i = textos[i_ptr]
            t_j = textos[j_ptr]
            pos_i = celdas[i_ptr].get_center()
            pos_j = celdas[j_ptr].get_center()

            self.play(
                t_i.animate.move_to(pos_j),
                t_j.animate.move_to(pos_i),
                path_arc=-PI * 0.9,
                run_time=1.0
            )
            # Intercambiar referencias en la lista para mantener consistencia
            textos[i_ptr], textos[j_ptr] = textos[j_ptr], textos[i_ptr]

            # Quitar resaltado
            self.play(
                celdas[i_ptr].animate.set_stroke(GRIS, width=3),
                celdas[j_ptr].animate.set_stroke(GRIS, width=3),
                run_time=0.3
            )

            # Avanzar punteros: inicio++, fin--
            i_ptr += 1
            j_ptr -= 1
            if i_ptr <= j_ptr:
                nuevo_inicio = flecha_puntero(i_ptr, VERDE, "inicio")
                nuevo_fin = flecha_puntero(j_ptr, ROJO, "fin")
                self.play(
                    Transform(p_inicio, nuevo_inicio),
                    Transform(p_fin, nuevo_fin),
                    run_time=0.7
                )
            else:
                # Los punteros se cruzan: fin del bucle
                self.play(
                    p_inicio.animate.set_opacity(0.4),
                    p_fin.animate.set_opacity(0.4),
                    run_time=0.5
                )
            self.wait(0.3)

        # ----- Resultado final -----
        self.play(FadeOut(cond))
        final = Text("¡Vector invertido!", font="sans-serif",
                     color=VERDE, weight=BOLD).scale(0.6)
        final.to_edge(DOWN)
        self.play(
            *[c.animate.set_stroke(VERDE, width=4) for c in celdas],
            Write(final)
        )
        self.wait(2)
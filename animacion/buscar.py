# -*- coding: utf-8 -*-
# ============================================================
#  buscar.py  —  Animacion estilo 3Blue1Brown de una busqueda
#  lineal que RETORNA UN PUNTERO a la estructura encontrada
#  dentro de un arreglo.
#
#  Recorre el arreglo comparando nombres con strcmp; al
#  encontrar coincidencia, devuelve la DIRECCION del elemento
#  (no una copia). El puntero 'encontrado' apunta a esa celda.
#
#  Codigo 7.9 del libro. Ejemplo: buscar "Luis" en el curso.
#
#  Requiere:  pip install manim
#  Renderizar:
#     manim -pqh buscar.py BuscarAlumno   (alta calidad)
#     manim -pqm buscar.py BuscarAlumno   (media, mas rapido)
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

# datos del curso: (nombre, edad, promedio, direccion_ficticia)
CURSO = [
    ("Ana",  20, 6.2, "0x1000"),
    ("Luis", 22, 5.4, "0x1010"),
]
BUSCADO = "Luis"


class BuscarAlumno(Scene):
    def construct(self):
        self.intro()
        self.dibujar_arreglo()
        self.recorrer_buscando()
        self.retornar_puntero()
        self.usar_resultado()

    # --------------------------------------------------------
    #  1. Intro
    # --------------------------------------------------------
    def intro(self):
        titulo = Text("Buscar y retornar un puntero",
                      font="sans-serif", weight=BOLD).scale(0.95).to_edge(UP)
        self.play(Write(titulo), run_time=1.0)

        firma = MathTex(
            r"\texttt{struct persona *buscar\_alumno(...)}",
            color=AZUL_CLARO,
        ).scale(0.55).next_to(titulo, DOWN, buff=0.25)
        self.play(FadeIn(firma, shift=UP * 0.2), run_time=0.8)

        objetivo = VGroup(
            Text("objetivo: encontrar", font="sans-serif", color=GRIS).scale(0.5),
            Text(f'"{BUSCADO}"', font="Monospace", color=AMARILLO).scale(0.5),
        ).arrange(RIGHT, buff=0.2).next_to(firma, DOWN, buff=0.3)
        self.play(FadeIn(objetivo), run_time=0.6)
        self.wait(0.8)
        self.play(FadeOut(objetivo), firma.animate.scale(0.85).to_corner(UL).shift(DOWN*0.4),
                  run_time=0.7)
        self.titulo = titulo
        self.firma = firma

    # --------------------------------------------------------
    #  2. Dibujar el arreglo de estructuras en memoria
    # --------------------------------------------------------
    def dibujar_arreglo(self):
        self.celdas = []      # cada celda: dict con mobjects
        n = len(CURSO)
        ancho = 3.2
        alto = 1.6
        sep = 0.5
        total_ancho = n * ancho + (n - 1) * sep
        x0 = -total_ancho / 2 + ancho / 2

        subtit = Text("curso[]  — arreglo de estructuras en memoria",
                      font="sans-serif", color=GRIS).scale(0.42)
        subtit.to_edge(UP, buff=1.9)
        self.play(FadeIn(subtit), run_time=0.5)
        self.subtit_arr = subtit

        animaciones = []
        for i, (nombre, edad, prom, dir_mem) in enumerate(CURSO):
            x = x0 + i * (ancho + sep)
            caja = Rectangle(width=ancho, height=alto,
                             stroke_color=AZUL_3B1B, stroke_width=2.5,
                             fill_color=AZUL_3B1B, fill_opacity=0.08)
            caja.move_to([x, 0.5, 0])

            idx_txt = Text(f"curso[{i}]", font="Monospace",
                           color=AZUL_CLARO).scale(0.4)
            idx_txt.next_to(caja, UP, buff=0.15)

            # contenido de la estructura
            campos = VGroup(
                Text(f'nombre: "{nombre}"', font="Monospace", color=WHITE).scale(0.4),
                Text(f"edad: {edad}", font="Monospace", color=WHITE).scale(0.4),
                Text(f"promedio: {prom}", font="Monospace", color=WHITE).scale(0.4),
            ).arrange(DOWN, aligned_edge=LEFT, buff=0.12)
            campos.move_to(caja.get_center())

            # direccion de memoria debajo
            dir_txt = Text(dir_mem, font="Monospace", color=GRIS).scale(0.38)
            dir_txt.next_to(caja, DOWN, buff=0.15)

            self.celdas.append({
                "caja": caja, "idx": idx_txt, "campos": campos,
                "dir": dir_txt, "nombre": nombre, "x": x,
            })
            animaciones += [Create(caja), FadeIn(idx_txt),
                            FadeIn(campos), FadeIn(dir_txt)]

        self.play(LaggedStart(*animaciones, lag_ratio=0.05), run_time=1.8)
        self.wait(0.6)

    # --------------------------------------------------------
    #  3. Recorrer comparando con strcmp
    # --------------------------------------------------------
    def recorrer_buscando(self):
        subtit = Text("for i = 0 … tamaño-1 :  strcmp(curso[i].nombre, buscado)",
                      font="Monospace", color=MORADO).scale(0.4)
        subtit.to_edge(DOWN, buff=0.5)
        self.play(FadeIn(subtit), run_time=0.5)
        self.subtit_for = subtit

        # cursor 'i' que se mueve
        flecha_i = None
        self.encontrado_idx = None

        for i, celda in enumerate(self.celdas):
            # resaltar la celda actual
            nueva_flecha = Arrow(
                celda["caja"].get_top() + UP * 1.1,
                celda["caja"].get_top() + UP * 0.15,
                color=AMARILLO, buff=0, stroke_width=4,
                max_tip_length_to_length_ratio=0.35,
            )
            etiq_i = Text(f"i = {i}", font="Monospace", color=AMARILLO).scale(0.4)
            etiq_i.next_to(nueva_flecha, UP, buff=0.1)

            if flecha_i is None:
                self.play(GrowArrow(nueva_flecha), FadeIn(etiq_i), run_time=0.5)
                flecha_i = nueva_flecha
                etiq_i_actual = etiq_i
            else:
                self.play(Transform(flecha_i, nueva_flecha),
                          Transform(etiq_i_actual, etiq_i), run_time=0.6)

            self.play(
                celda["caja"].animate.set_stroke(AMARILLO)
                                     .set_fill(AMARILLO, opacity=0.12),
                run_time=0.4,
            )

            # comparacion strcmp
            coincide = (celda["nombre"] == BUSCADO)
            simbolo = "=" if coincide else r"\neq"
            comp = MathTex(
                rf'\texttt{{"{celda["nombre"]}"}}', simbolo,
                rf'\texttt{{"{BUSCADO}"}}',
                color=WHITE,
            ).scale(0.6).to_edge(DOWN, buff=1.3)
            comp[0].set_color(AZUL_CLARO)
            comp[2].set_color(AMARILLO)
            self.play(Write(comp), run_time=0.6)
            self.wait(0.4)

            if coincide:
                # encontrado: pintar verde
                self.play(
                    celda["caja"].animate.set_stroke(VERDE)
                                         .set_fill(VERDE, opacity=0.2),
                    comp.animate.set_color(VERDE),
                    run_time=0.6,
                )
                self.encontrado_idx = i
                self.flecha_i = flecha_i
                self.etiq_i = etiq_i_actual
                self.play(FadeOut(comp), run_time=0.4)
                break
            else:
                # no coincide: volver a azul y seguir
                self.play(
                    celda["caja"].animate.set_stroke(AZUL_3B1B)
                                         .set_fill(AZUL_3B1B, opacity=0.08),
                    FadeOut(comp),
                    run_time=0.5,
                )

        self.play(FadeOut(subtit), FadeOut(self.flecha_i),
                  FadeOut(self.etiq_i), run_time=0.5)

    # --------------------------------------------------------
    #  4. Retornar el puntero (la direccion, no una copia)
    # --------------------------------------------------------
    def retornar_puntero(self):
        celda = self.celdas[self.encontrado_idx]

        subtit = Text("return &curso[i];   →   retorna la DIRECCIÓN",
                      font="sans-serif", color=VERDE).scale(0.45)
        subtit.to_edge(DOWN, buff=0.5)
        self.play(FadeIn(subtit), run_time=0.6)

        # crear la variable puntero 'encontrado'
        ptr_caja = RoundedRectangle(width=2.6, height=0.9, corner_radius=0.1,
                                    stroke_color=MORADO, stroke_width=2.5,
                                    fill_color=MORADO, fill_opacity=0.1)
        ptr_caja.to_edge(LEFT, buff=0.8).shift(DOWN * 2.0)
        ptr_label = Text("encontrado", font="Monospace", color=MORADO).scale(0.4)
        ptr_label.next_to(ptr_caja, UP, buff=0.1)
        ptr_val = Text(CURSO[self.encontrado_idx][3], font="Monospace",
                       color=WHITE).scale(0.42)
        ptr_val.move_to(ptr_caja.get_center())

        self.play(FadeIn(ptr_caja), FadeIn(ptr_label), run_time=0.6)
        self.play(Write(ptr_val), run_time=0.5)

        # flecha del puntero a la estructura encontrada
        flecha_ptr = Arrow(
            ptr_caja.get_right(),
            celda["caja"].get_left(),
            color=MORADO, stroke_width=4, buff=0.15,
            max_tip_length_to_length_ratio=0.15,
        )
        self.play(GrowArrow(flecha_ptr), run_time=0.9)
        self.wait(0.5)

        # enfatizar: apunta, no copia
        nota = Text("el puntero apunta a la celda original, no la copia",
                    font="sans-serif", color=GRIS).scale(0.4)
        nota.to_edge(DOWN, buff=1.3)
        self.play(FadeIn(nota), run_time=0.7)
        self.wait(1.2)
        self.play(FadeOut(subtit), FadeOut(nota), run_time=0.5)

        self.ptr_caja = ptr_caja
        self.flecha_ptr = flecha_ptr

    # --------------------------------------------------------
    #  5. Usar el resultado: (*encontrado).nombre y .edad
    # --------------------------------------------------------
    def usar_resultado(self):
        celda = self.celdas[self.encontrado_idx]
        nombre, edad, prom, _ = CURSO[self.encontrado_idx]

        # dereferenciar para leer los campos
        expr = MathTex(
            r"(\texttt{*encontrado}).\texttt{nombre}", r"\;\to\;",
            rf'\texttt{{"{nombre}"}}',
            color=WHITE,
        ).scale(0.55).shift(DOWN * 2.0 + RIGHT * 1.5)
        expr[2].set_color(AMARILLO)
        self.play(Write(expr), run_time=0.9)
        self.wait(0.4)

        expr2 = MathTex(
            r"(\texttt{*encontrado}).\texttt{edad}", r"\;\to\;", str(edad),
            color=WHITE,
        ).scale(0.55).next_to(expr, DOWN, buff=0.3)
        expr2[2].set_color(AMARILLO)
        self.play(Write(expr2), run_time=0.9)
        self.wait(0.5)

        # salida final
        salida = Text(f'{nombre} tiene {edad} años',
                      font="sans-serif", color=VERDE, weight=BOLD).scale(0.7)
        salida.to_edge(DOWN, buff=0.6)
        self.play(
            FadeIn(salida, shift=UP * 0.3),
            Flash(celda["caja"].get_center(), color=VERDE,
                  line_length=0.3, num_lines=16, flash_radius=1.5),
            run_time=1.2,
        )
        self.wait(2.5)


class CodigoC(Scene):
    """Escena opcional: el codigo C original con resaltado."""
    def construct(self):
        codigo = '''struct persona *buscar_alumno(struct persona curso[],
                              int tamano, char nombre[])
{
   int i;
   for (i = 0; i < tamano; i++)
   {
      if (strcmp(curso[i].nombre, nombre) == 0)
         return (&curso[i]);   // direccion del encontrado
   }
   return (NULL);   // no se encontro
}'''
        try:
            bloque = Code(code_string=codigo, language="c",
                          background="window").scale(0.7)
        except TypeError:
            bloque = Code(code=codigo, language="c", font="Monospace",
                          background="window", style="monokai").scale(0.7)
        self.play(FadeIn(bloque), run_time=1.5)
        self.wait(3.0)

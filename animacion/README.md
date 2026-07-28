# Animación del juego "Adivina el número" (estilo 3Blue1Brown)

Script de Manim que visualiza cómo la estrategia de **búsqueda binaria**
acorrala el número secreto del juego, reduciendo el rango a la mitad en
cada intento.

## Instalación en Mac

```bash
# dependencias del sistema
brew install py3cairo ffmpeg pango pkg-config

# Manim
pip install manim
```

## Renderizar

```bash
# escena principal — la animación del juego
manim -pqh adivina.py JuegoAdivinanza     # alta calidad (1080p)
manim -pqm adivina.py JuegoAdivinanza     # media, renderiza más rápido
manim -pql adivina.py JuegoAdivinanza     # baja, para pruebas rápidas

# escena opcional — el código C con resaltado de sintaxis
manim -pqh adivina.py CodigoC
```

Banderas:
- `-p` reproduce el video al terminar
- `-q` calidad: `l` (baja), `m` (media), `h` (alta), `k` (4K)

El `.mp4` queda en `media/videos/adivina/<resolución>/`.

## Qué muestra la animación

1. Una recta numérica de 0 a mil millones.
2. El número secreto marcado en amarillo.
3. La región de búsqueda activa (azul) que se contrae en cada intento.
4. Los primeros 7 intentos de búsqueda binaria, con las pistas
   "es mayor / es menor" y el descarte de media región cada vez.
5. Un salto a la convergencia final y la revelación: **29 intentos**
   para pasar de mil millones de posibilidades a una.
6. La fórmula log₂(10⁹) ≈ 30 que explica por qué.

## Personalización

- **SECRETO**: cambia la constante al inicio para animar otro número.
- **pasos_visibles = pasos[:7]**: ajusta cuántos intentos se muestran
  en detalle antes del salto a la convergencia.
- **Paleta**: las constantes de color al inicio replican la estética
  de 3Blue1Brown; modifícalas si quieres otro esquema.

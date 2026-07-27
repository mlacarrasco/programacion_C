SHELL   := /bin/bash

CC      ?= gcc
CFLAGS  ?= -std=c11 -Wall -Wextra
LDLIBS  := -lm

BINDIR  := bin

# Códigos del libro que son programas completos y autocontenidos
# (compilan y enlazan sin depender de otro fragmento). El resto del
# repositorio son esquemas, declaraciones sueltas o la segunda mitad
# de un ejemplo que se apoya en el código anterior, y no se incluyen
# aquí porque no compilan de forma independiente.
SRC := \
	codigo_cap_1_3.c \
	codigo_cap_2_1.c codigo_cap_2_2.c codigo_cap_2_3.c codigo_cap_2_4.c codigo_cap_2_5.c \
	codigo_cap_2_6.c codigo_cap_2_7.c codigo_cap_2_8.c codigo_cap_2_9.c codigo_cap_2_10.c \
	codigo_cap_2_11.c codigo_cap_2_12.c codigo_cap_2_13.c codigo_cap_2_14.c codigo_cap_2_15.c \
	codigo_cap_4_1.c codigo_cap_4_2.c codigo_cap_4_3.c codigo_cap_4_5.c codigo_cap_4_7.c \
	codigo_cap_4_9.c codigo_cap_4_11.c codigo_cap_4_13.c codigo_cap_4_15.c codigo_cap_4_17.c \
	codigo_cap_4_19.c codigo_cap_4_20.c codigo_cap_4_21.c codigo_cap_4_22.c codigo_cap_4_23.c \
	codigo_cap_4_24.c codigo_cap_4_25.c codigo_cap_4_26.c codigo_cap_4_27.c codigo_cap_4_28.c \
	codigo_cap_4_29.c codigo_cap_4_30.c \
	codigo_cap_5_1.c codigo_cap_5_2.c codigo_cap_5_6.c codigo_cap_5_7.c codigo_cap_5_8.c \
	codigo_cap_5_14.c codigo_cap_5_15.c codigo_cap_5_16.c codigo_cap_5_17.c codigo_cap_5_18.c \
	codigo_cap_5_19.c codigo_cap_5_20.c codigo_cap_5_21.c codigo_cap_5_22.c codigo_cap_5_23.c \
	codigo_cap_5_24.c codigo_cap_5_25.c \
	codigo_cap_6_4.c codigo_cap_6_5.c codigo_cap_6_6.c codigo_cap_6_7.c codigo_cap_6_9.c \
	codigo_cap_6_10.c codigo_cap_6_11.c codigo_cap_6_12.c codigo_cap_6_13.c codigo_cap_6_14.c \
	codigo_cap_6_15.c codigo_cap_6_22.c \
	codigo_cap_7_5.c codigo_cap_7_11.c \
	codigo_cap_8_1.c codigo_cap_8_2.c codigo_cap_8_3.c codigo_cap_8_5.c codigo_cap_8_7.c \
	codigo_cap_8_9.c codigo_cap_8_10.c codigo_cap_8_11.c codigo_cap_8_16.c codigo_cap_8_17.c \
	codigo_cap_8_18.c codigo_cap_8_19.c codigo_cap_8_20.c codigo_cap_8_21.c codigo_cap_8_22.c \
	codigo_cap_8_23.c codigo_cap_8_24.c codigo_cap_8_25.c codigo_cap_8_26.c codigo_cap_8_27.c \
	codigo_cap_8_28.c \
	codigo_cap_10_1.c codigo_cap_10_3.c codigo_cap_10_5.c codigo_cap_10_6.c codigo_cap_10_8.c \
	codigo_cap_10_9.c codigo_cap_10_11.c codigo_cap_10_12.c codigo_cap_10_13.c \
	codigo_cap_anexoA_5.c \
	codigo_cap_anexoB_1.c codigo_cap_anexoB_2.c codigo_cap_anexoB_3.c codigo_cap_anexoB_4.c \
	codigo_cap_anexoB_5.c codigo_cap_anexoB_6.c codigo_cap_anexoB_7.c codigo_cap_anexoB_8.c \
	codigo_cap_anexoB_9.c codigo_cap_anexoB_10.c codigo_cap_anexoB_11.c codigo_cap_anexoB_12.c \
	codigo_cap_anexoB_13.c codigo_cap_anexoB_14.c codigo_cap_anexoB_15.c codigo_cap_anexoB_16.c \
	codigo_cap_anexoB_17.c codigo_cap_anexoB_30.c codigo_cap_anexoB_46.c

BIN := $(addprefix $(BINDIR)/,$(SRC:.c=))

.PHONY: all chapter run clean list help

all: $(BIN)
	@echo "Compilados: $(words $(BIN)) programas en ./$(BINDIR)"

$(BINDIR)/%: %.c | $(BINDIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)

$(BINDIR):
	mkdir -p $(BINDIR)

## Compila sólo los códigos autocontenidos de un capítulo: make chapter N=6
chapter:
	@test -n "$(N)" || { echo "Uso: make chapter N=<numero|anexoA|anexoB>  (ej: make chapter N=6)"; exit 1; }
	@$(MAKE) --no-print-directory all SRC="$(filter codigo_cap_$(N)_%.c,$(SRC))"

## Compila y ejecuta un único archivo: make run FILE=codigo_cap_6_16.c
run:
	@test -n "$(FILE)" || { echo "Uso: make run FILE=codigo_cap_6_16.c"; exit 1; }
	@mkdir -p $(BINDIR)
	@$(CC) $(CFLAGS) "$(FILE)" -o "$(BINDIR)/$${FILE%.c}" $(LDLIBS) && ./$(BINDIR)/$${FILE%.c}

## Lista los binarios ya compilados
list:
	@ls -1 $(BINDIR) 2>/dev/null || echo "Aún no se ha compilado nada. Ejecuta 'make'."

## Elimina los binarios generados
clean:
	rm -rf $(BINDIR)

help:
	@echo "make                     - compila los códigos autocontenidos del libro en ./$(BINDIR)"
	@echo "make chapter N=6         - compila sólo los códigos autocontenidos del capítulo 6"
	@echo "make chapter N=anexoB    - compila sólo los códigos autocontenidos del Anexo B"
	@echo "make run FILE=codigo_cap_6_16.c - compila y ejecuta un código puntual (incluye fragmentos, si se combinan a mano)"
	@echo "make list                - lista los binarios ya compilados"
	@echo "make clean               - elimina ./$(BINDIR)"

CC     = mpicc
CFLAGS = -O2 -Wall

TARGETS      = p3Ej1a p3Ej1b p3Ej1c p3Ej2 p3Ej3 p3Ej4 p3Ej5
TARGETS_BLAS = p3Ej1c_blas

all: $(TARGETS)
# Para compilar la variante BLAS (requiere: sudo apt install libblas-dev):
blas: $(TARGETS_BLAS)

p3Ej1a:      p3Ej1a.c      ; $(CC) $(CFLAGS) -o $@ $< -lm
p3Ej1b:      p3Ej1b.c      ; $(CC) $(CFLAGS) -o $@ $< -lm
p3Ej1c:      p3Ej1c.c      ; $(CC) $(CFLAGS) -o $@ $< -lm
p3Ej1c_blas: p3Ej1c.c      ; $(CC) $(CFLAGS) -DUSE_BLAS -o $@ $< -lm -lblas
p3Ej2:       p3Ej2.c       ; $(CC) $(CFLAGS) -o $@ $< -lm
p3Ej3:       p3Ej3.c       ; $(CC) $(CFLAGS) -o $@ $< -lm
p3Ej4:       p3Ej4.c       ; $(CC) $(CFLAGS) -o $@ $<
p3Ej5:       p3Ej5.c       ; $(CC) $(CFLAGS) -o $@ $<

gen_ref: gen_ref.c ; gcc -O2 -o $@ $<

clean:
	rm -f $(TARGETS) $(TARGETS_BLAS) gen_ref
	rm -rf mats resultados.txt

# ── Ejemplos de ejecución ────────────────────────────────────────────────────
# Ej 1a (naive opt): mpirun -np 4 ./p3Ej1a N A.bin B.bin R.bin
# Ej 1b (C=A*A):     mpirun -np 4 ./p3Ej1b N A.bin R.bin
# Ej 1c (bloques):   mpirun -np 4 ./p3Ej1c N BS A.bin B.bin R.bin
# Ej 1c (blas):      mpirun -np 4 ./p3Ej1c_blas N BS A.bin B.bin R.bin
# Ej 2  (stats):     mpirun -np 4 ./p3Ej2 N
# Ej 3  (transp):    mpirun -np 4 ./p3Ej3 N
# Ej 4  (nreinas):   mpirun -np 4 ./p3Ej4 N
# Ej 5  (mergesort): mpirun -np 4 ./p3Ej5 N

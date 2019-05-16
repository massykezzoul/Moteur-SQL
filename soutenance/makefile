all: diapo

diapo:
	@pdflatex diapo.tex 2> /dev/null && echo "fichier diapo.pdf créé\n'make see' pour affiché" || echo "Erreur"

see:
	@evince diapo.pdf &

clean:
	rm -f diapo.fdb_latexmk  diapo.log  diapo.out  diapo.snm  diapo.toc diapo.aux diapo.fls diapo.nav diapo.vrb

mrproper: clean
	rm -f diapo.pdf
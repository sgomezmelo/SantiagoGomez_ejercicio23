PDE.pdf: datos.txt graf.py
	python graf.py
datos.txt: onda.cpp
	c++ onda.cpp
	./a.out > datos.txt
	rm a.out

build: euclideo.c klib
	gcc -o euclideo euclideo.c klib/klib.o

klib:
	git clone "https://gitlab.com/kappanneo/klib.git"
	make -C klib

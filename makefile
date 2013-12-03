FEA_MHD_CPU:pre_tri_cpu
objects_cpu=pre_tri_cpu.o
pre_tri_cpu:pre_tri_cpu.o
	g++ -o pre_tri_cpu pre_tri_cpu.o
pre_tri_cpu.o:pre_tri_cpu.h pre_tri_cpu.cpp
	g++ -c pre_tri_cpu.cpp
.PHONY:clean run
clean:
	rm *.o
run:FEA_MHD_CPU
	./pre_tri_cpu

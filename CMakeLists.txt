cmake_minimum_required(VERSION 4.2)
project(ProyectoAlgoritmos C)

set(CMAKE_C_STANDARD 11)

add_executable(ProyectoAlgoritmos
        solucionComputacional/main.c
        solucionComputacional/package_list.c
        solucionComputacional/package_list.h
        solucionComputacional/delivery_queue.c
        solucionComputacional/delivery_queue.h
        solucionComputacional/returns_stack.c
        solucionComputacional/returns_stack.h
        solucionComputacional/client_bst.c
        solucionComputacional/client_bst.h
        solucionComputacional/package_avl.c
        solucionComputacional/package_avl.h
        solucionComputacional/routes_graph.c
        solucionComputacional/routes_graph.h
        solucionComputacional/files.c
        solucionComputacional/files.h
        solucionComputacional/types.h
)


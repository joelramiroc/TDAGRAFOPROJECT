cmake_minimum_required(VERSION 3.8)
project(GrafoProyecto)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES cmake-build-debug/cpp/main.cpp cmake-build-debug/cpp/Grafo.cpp cmake-build-debug/hd/Grafo.h cmake-build-debug/cpp/Grafo.cpp cmake-build-debug/hd/Grafo.h cmake-build-debug/cpp/DragWidget.cpp cmake-build-debug/hd/DragWidget.h cmake-build-debug/cpp/Arista.cpp cmake-build-debug/hd/Arista.h cmake-build-debug/cpp/Vertice.cpp cmake-build-debug/hd/Vertice.h cmake-build-debug/cpp/ArrayList.cpp cmake-build-debug/hd/ArrayList.h cmake-build-debug/cpp/CirculoVertice.cpp cmake-build-debug/hd/CirculoVertice.h cmake-build-debug/cpp/Cola.cpp cmake-build-debug/hd/Cola.h cmake-build-debug/cpp/Information.cpp cmake-build-debug/hd/Information.h cmake-build-debug/cpp/Nodo.cpp cmake-build-debug/hd/Nodo.h cmake-build-debug/cpp/Pila.cpp cmake-build-debug/hd/Pila.h cmake-build-debug/CMakeFiles/header.cpp cmake-build-debug/CMakeFiles/header.h cmake-build-debug/cpp/Lista.cpp cmake-build-debug/hd/Lista.h)
add_executable(GrafoProyecto ${SOURCE_FILES})
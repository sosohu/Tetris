
HOME=/home/sosohu/huqinghai/GraduationDesign/graph/opengl/Tetris
CC=gcc
CFLAGS=-O3 -fPIC -g
CXXFLAGS=-O3 -fPIC --std=c++0x -g
AR=ar
ARFLAGS=-r

LIBGL=-lglut -lGLU -lGL -lm -llog4cpp
#LIBGL=
LIBS=$(LIBGL)

INC=$(HOME)/include
SRC=$(HOME)/src
LIB_PATH=$(HOME)/lib
TEST=$(HOME)/test


###########################################
# Simple Makefile for OctoPower
#
# Mauro Cecchi
# 2016-11-12
###########################################

all: octopower

CC=gcc
CXX=g++
COBJS=octopower.o
OBJS=$(COBJS)
CFLAGS=-I./hidapi/hidapi -Wall -g -c `pkg-config libudev --cflags`
LIBS=./hidapi/linux/hid.o `pkg-config libudev --libs`

octopower: $(OBJS)
	g++ -Wall -g $^ $(LIBS) -o octopower

$(COBJS): %.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o octopower

.PHONY: clean

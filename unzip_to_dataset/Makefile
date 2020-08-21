LDLIBS=-lz

all: unzip_to_dataset 

unzip_to_dataset: main.o unzip_to_dataset.o
	$(LINK.cc) $^ $(LDLIBS) -o $@

clean:
	rm -f unzip_to_dataset *.o

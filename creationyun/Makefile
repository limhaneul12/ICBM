LDLIBS=-lz

all: malware_unzip

malware_unzip: main.o malware_unzip.o
	$(LINK.cc) $^ $(LDLIBS) -o $@

clean:
	rm -f malware_unzip *.o

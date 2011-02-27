#	export CPLUS_INCLUDE_PATH=/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/JavaVM.framework/Versions/1.6.0/Headers/
INCLUDES = -I../v8-read-only/include
LIBS = -L/opt/local/lib
DYLIB = -arch x86_64 libv8.a
INSTALL_PATH = -install_name /usr/local/lib/libSparqlParserWrapper.dylib
CC = g++

all: SparqlParserWrapper

SparqlParserWrapper: SparqlParser.o
	$(CC) $(DYLIB) sparql_parser.o SparqlParser.o $(LIBS) -dynamiclib -o libSparqlParserWrapper.dylib

SparqlParser.o: sparql_parser.o
	$(CC) $(INCLUDES) -c src/SparqlParser.c

sparql_parser.o:
	$(CC) $(INCLUDES) -c src/sparql_parser.cc

clean_obj:
	rm -rf *.o

clean: clean_obj
	rm -rf hello_world

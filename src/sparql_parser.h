#ifndef __SPARQL_PARSER_H__
#define __SPARQL_PARSER_H__

#include <v8.h>
#include <iostream>  // I/O
#include <fstream>   // file I/O
#include <iomanip>   // format manipulation
#include <string>
#include <stdio.h>

using namespace v8;

class SparqlParser {

  Persistent<Context> context;

public:

  SparqlParser();
  ~SparqlParser();

  std::string parse(std::string query);

};

#endif // __SPARQL_PARSER_H__

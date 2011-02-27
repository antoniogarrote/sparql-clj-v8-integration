#include "sparql_parser.h"

using namespace v8;

const char* ToCString(const v8::String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}

SparqlParser::SparqlParser() {

  char script[500000];

  // load the parser js code
  std::ifstream fin;
  fin.open("sparql_parser.js", std::ios::in);
  fin.read(script,500000);
  fin.close();

  context = Context::New();
  HandleScope handle_scope;
  Context::Scope context_scope(context);

  // compiles the parser function
  Handle<Script> parserScript = Script::Compile(String::New(script));
  parserScript->Run();

};

SparqlParser::~SparqlParser() {
  context.Dispose();
};

std::string SparqlParser::parse(std::string query) {
  Context::Scope context_scope(context);
  HandleScope handle_scope;

  // executes the parser function call on the global object
  std::string query_string =  "sparql_query('";
  query_string = query_string.append(query);
  query_string = query_string.append("');");

  Handle<Script> runnerScript = Script::Compile(String::New(query_string.c_str()));
  Handle<Value> result = runnerScript->Run();

  if (!result.IsEmpty() && !result->IsUndefined()) {
    String::Utf8Value str(result);
    std::string toReturn = std::string(ToCString(str));

    return toReturn;
  } else {
    std::cout << "Something went wrong";
    return NULL;
  }
};


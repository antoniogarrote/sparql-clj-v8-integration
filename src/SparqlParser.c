#include <jni.h>
#include <stdio.h>
#include "sparql_parser.h"
#include "sparqltest_SparqlParser.h"


JNIEXPORT jstring JNICALL Java_sparqltest_SparqlParser_parse_1query (JNIEnv *env, jobject obj, jstring javaQuery) {
  SparqlParser parser;
  parser = SparqlParser();

  const char *query = env->GetStringUTFChars(javaQuery, 0);
  //std::cout << "QUERY:";
  //std::cout << std::string(query);

  std::string result = parser.parse(std::string(query));

  env->ReleaseStringUTFChars(javaQuery, query);

  jstring javaResult = env->NewStringUTF(result.c_str());

  return javaResult;
}

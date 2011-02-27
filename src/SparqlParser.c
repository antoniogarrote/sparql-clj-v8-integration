#include <jni.h>
#include <stdio.h>
#include "sparql_parser.h"
#include "sparqltest_SparqlParser.h"


SparqlParser parser;

JNIEXPORT void JNICALL Java_sparqltest_SparqlParser_init (JNIEnv *env , jobject obj) {
  parser = SparqlParser();
}

JNIEXPORT jstring JNICALL Java_sparqltest_SparqlParser_parse_1query (JNIEnv *env, jobject obj, jstring javaQuery) {

  const char *query = env->GetStringUTFChars(javaQuery, 0);
  std::string result = parser.parse(std::string(query));

  jstring javaResult = env->NewStringUTF(result.c_str());

  return javaResult;
}

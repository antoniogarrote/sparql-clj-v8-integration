(ns clj-sparql-test.core
  (:import sparqltest.SparqlParser)
  (:use [clojure.contrib.json :only [read-json]]))

(defn parse-sparql [query]
  (read-json (SparqlParser/parse query)))

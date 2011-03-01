package sparqltest;

public class SparqlParser {
     static {
         System.loadLibrary("SparqlParserWrapper");
     }

    private native String parse_query(String query);

    public static String parse(String query) {
        return (new SparqlParser()).parse_query(query);
    }

    public static void main(String[] argv) {
        String query = "BASE <a> PREFIX test: <b> INSERT DATA { <a> <b> \"c\" }";
        System.out.println("QUERY BEFORE:"+query);
        System.out.println("RESULT: "+SparqlParser.parse(query));
    }
 }

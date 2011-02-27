package sparqltest;

public class SparqlParser {
     static {
         System.loadLibrary("SparqlParserWrapper");
     }

    private native void init();
    private native String parse_query(String query);

    private static SparqlParser parser;

    private SparqlParser() {
        init();
    }

    public String _parse(String query){
        return parse_query(query);
    }

    public static String parse(String query) {
        if(parser == null) {
            parser = new SparqlParser();
        }
        return parser._parse(query);
    }

    public static void main(String[] argv) {
        System.out.println("RESULT: "+SparqlParser.parse("SELECT * { ?s ?p ?o }"));
    }
 }

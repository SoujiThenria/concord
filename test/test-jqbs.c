#include <stdio.h>
#include <string.h>
#include "jqbs.c"
#include "json-scanf.h"

int main (int argc, char ** argv)
{
  size_t len = 0;
  char * s;

  char * spec =
    "{ |namespace|: [ |A|, |B| ],"
      "|description|: |url|,"
      "|structs|:"
      "["
      "  { |name|:|dati|,"
      "    |fields|:"
      "    ["
      "      { |name|:|f1|, |type|:{ |base|:|char|, |decorator|:|*| } },"
      "      { |name|:|f2|, |type|:{ |base|:|char|, |decorator|:|*| } }"
      "      { |name|:|f3|, |type|:{ |base|:|uint64_t| } }"
      "      { |name|:|f4|, |c_name|:|c_f4|, |type|:{ |base|:|uint64_t| } }"
      "      { |name|:|f5 asdfasdf |, |c_name|:|c_f5|, |type|:{ |base|:|u64|, |converter|:|convert| } }"
      "      { |name|:|f6|, |type|:{ |base|:|char|, |decorator|:|*| }, |loc|:|form| }"
      "      { |name|:|f7|, |type|:{ |base|:|bool|}, |loc|:|query| }"
      "    ]"
      "  }"
      "]"
    "}";

  spec =
    "{ |namespace|: [ |A|, |B| ],"
      "|description|: |url|,"
      "|structs|:"
      "["
      "  { |name|:|dati|,"
      "    |fields|:"
      "    ["
      "      { |name|:|f1_str|, |type|:{ |base|:|char|, |decorator|:|*| }, |comment|:| this is field f1 | },"
      "      { |name|:|f2_str|, |type|:{ |base|:|char|, |decorator|:|*| } }"
      "      { |name|:|f3_int|, |type|:{ |base|:|int|, |c_base|:|code| } }"
      "      { |name|:|f4_uint64|, |c_name|:|c_f4|, |type|:{ |base|:|uint64_t| } }"
      "      { |name|:|f5 asdfasdf |, |c_name|:|c_f5|, |type|:{ |base|:|u64|, |converter|:|convert| } }"
      "      { |name|:|f6_carray|, |type|:{ |base|:|char|, |decorator|:|[10]| } }"
      "    ]"
      "  }"
      "]"
      "}";

  if (argc == 2) {
    s = orka_load_whole_file(argv[1], &len);
  }
  else {
    json_asprintf(&s, spec);
    len = strlen(s);
  }

  /*
  fprintf(stderr, "%.*s\n", len, s);
   */

  struct jc_definition d;
  memset(&d, 0, sizeof(d));
  definition_from_json(s, len, &d);
  //print_definition(stderr, &d);
  gen_definition(stderr, 0, &d);
  return 0;
}
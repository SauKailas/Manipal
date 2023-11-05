%{
    #include "q1.tab.h"
%}
%%
"int" {return INT;}
"char" {return CHAR;}
";" {return SC;}
"," {return CM;}
"=" {return EQ;}
[a-zA-Z][a-zA-Z]* {return ID; }
[0-9]+ {return NUM;}
\n {return NL;}
%%

int yywrap(){
    return 1;
}

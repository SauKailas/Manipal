%{
	#include "sample.tah.h"
%}

%%
"+" {return PLUS;}
"*" {return STAR;}
[0-9]+ {return NUMBER;}
\n {return NL;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}
. {return yytext[0];}
%%
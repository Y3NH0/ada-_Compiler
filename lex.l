%{
/*---------------------------------------*/
/*--------------- Scanner ---------------*/
/*---------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "Symbol.h"

#define LIST strcat(buf, yytext)
#define token(t) {LIST; return(t);}


#define MAX_LINE_LENG 256

int linecount = 1;
char buf[MAX_LINE_LENG];


/* ----- print_line -----
 * print line number & buf
 * clear buf 
 * in proj2, we dont need to print
 */
void print_line() {
    //printf("%d: %s\n", linecount, buf);
    linecount++;
    buf[0]='\0';
}

%}
/*------------------------------------*/
/*-------- Regular definition --------*/
/*------------------------------------*/
digs        [0-9]+
integer     {digs}
plain_real  {digs}"."{digs}
expreal     {digs}"."{digs}[Ee][+-]?{digs}
real        {plain_real}|{expreal}
newline     \n
string      \"[^\"]*\"
id          [a-zA-Z][0-9a-zA-Z]*
space       [\t ]*

%x COMMENT

/*------------------------------------*/
/*-------- Pattern and Action --------*/
/*------------------------------------*/
%%

<<EOF>> { LIST; 
          print_line(); 
          return(0); 
        }


"{"     { LIST; BEGIN(COMMENT); }
\-\-.*  { LIST; }
<COMMENT>"}"        { LIST; BEGIN(INITIAL); }
<COMMENT>{newline}  { print_line(); }
<COMMENT>.          { LIST; }

".."      { token(LOOPDOT); }
","       { token(COM); }
":"       { token(COL); }
"."       { token(PER); }
";"       { token(SEM); }
"("       { token(PAR_L); }
")"       { token(PAR_R); }
"["       { token(SBRA_L); }
"]"       { token(SBRA_R); }

"+"       { token(ADD); }
"-"       { token(SUB); }
"*"       { token(MUL); }
"/"       { token(DIV); }
"%"       { token(REM); }
":="      { token(ASS); }
"and"     { token(AND); }
"or"      { token(OR); }
"not"     { token(NOT); }

"<"       { token(LE); }
"<="      { token(LEEQ); }
">="      { token(GREQ); }
">"       { token(GR); }
"="       { token(EQ); }
"/="       { token(NEQ); }


begin     { token(BEGIN_TOKEN); }
boolean   { token(BOOLEAN); }
break     { token(BREAK); }
character { token(CHARACTER); }
case      { token(CASE); }
continue  { token(CONTINUE); }
constant  { token(CONSTANT); }
declare   { token(DECLARE); }
do        { token(DO); }
else      { token(ELSE); }
end       { token(END); }
exit      { token(EXIT); }
float     { token(FLOAT); }
for       { token(FOR); }
if        { token(IF); }
in        { token(IN); }
integer   { token(INTEGER); }
loop      { token(LOOP); }
print     { token(PRINT); }
println   { token(PRINTLN); }
procedure { token(PROCEDURE); }
program   { token(PROGRAM); }
return    { token(RETURN); }
string    { token(STRING); }
while     { token(WHILE); }
then      { token(THEN); }
true      { token(TRUE);}
false     { token(FALSE);}
{space}         { LIST; }
{integer}       {   
                    yylval.intVal = atoi(yytext);
                    token(INT_VAL);
                }
{plain_real}    { 
                    yylval.floatVal = atof(yytext);
                    token(FLOAT_VAL);
                }
{expreal}       {
                    yylval.floatVal = atof(yytext);
                    token(FLOAT_VAL); 
                }
{string}        {                
                    char c = yyinput();
                    unput(c);
                    
                    if(c == '\"') {
                        yymore();
                    }
                    else {
                        yyless(yyleng);
                        char str[MAX_LINE_LENG];
                        int i,j=0;
                        for(i = 1; i < yyleng - 1; i++) {
                            if(yytext[i] == yytext[i+1] && yytext[i] == '"') {
                                i++;
                            }
                            str[j] = yytext[i];
                            j++;
                        }
                        str[j]='\0';
                        yylval.stringVal = strdup(str);
                        token(STRING_VAL);
                    }
                }
{id}            { 
                    yylval.stringVal = strdup(yytext);
                    token(ID);
                }
{newline}       { print_line(); }

%%
/*----- C code -----*/
int yywrap() {
  return(1);
}

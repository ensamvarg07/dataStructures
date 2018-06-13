#include<stdio.h>

char* fetchLine(char line[], char * bp)
{	
int i=0;
	
for( i=0; *bp != '\n' && *bp != EOF; bp++, i++)
	line[i] = *bp;

if(*bp == '\n')
	line[i]='\n';

i++;
line[i]='\0';
bp++;
return bp;
}

char* fetchWord(char word[], char *wp)
{
int i=0;

while( *wp != ' ' && *wp != '\n')
{
	word[i] = *wp;
	i++;
	wp++;
}
word[i] = '\0';
if(*wp== ' ')
	wp++;

return wp;
}



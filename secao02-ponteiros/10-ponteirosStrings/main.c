#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char *content;
} String;

String stringCreate(char *);
int stringDestroy(String *);

size_t stringLength(String);
size_t stringLength2(String);

char stringCharAt(String, unsigned int);
String stringConcat(String, String);
String stringToLower(String);

void strcpy2(char *, char *);

int main(void)
{
    String s1, s2, s3, s4;

    char s5[20] = "Joana", *s6 = "AAABBBCCC";

    s1 = stringCreate("Rafael Portugal");

    printf("\n");
    printf("s1 = %s\n", s1.content);
    printf("Tamanho de s1 = %lu\n", stringLength(s1));
    printf("Tamanho de s1 = %lu\n", stringLength2(s1));

    s2 = stringCreate("Um texto QUALQUER AAAAAA");

    printf("\n");
    printf("s2 = %s\n", s2.content);
    printf("Tamanho de s2 = %lu\n", stringLength(s2));
    printf("Tamanho de s2 = %lu\n", stringLength2(s2));
    printf("s2[3] = %c\n", stringCharAt(s2, 3));
    printf("s2[6] = %c\n", stringCharAt(s2, 6));

    s3 = stringConcat(s2, s1);

    printf("\n");
    printf("s3 = %s\n", s3.content);
    printf("Tamanho de s3 = %lu\n", stringLength(s3));
    printf("Tamanho de s3 = %lu\n", stringLength2(s3));
    printf("s3[0] = %c\n", stringCharAt(s3, 0));
    printf("s3[10] = %c\n", stringCharAt(s3, 10));

    s4 = stringToLower(s3);

    printf("\n");
    printf("s4 = %s\n", s4.content);
    printf("Tamanho de s4 = %lu\n", stringLength(s4));
    printf("Tamanho de s4 = %lu\n", stringLength2(s4));

    stringDestroy(&s1);
    stringDestroy(&s2);
    stringDestroy(&s3);
    stringDestroy(&s4);

    printf("\n");
    printf("s5 = %s\n", s5);

    strcpy2(s5, s6);

    printf("\n");
    printf("s5 = %s\n", s5);
    printf("s6 = %s\n", s6);
}

String stringCreate(char *string)
{
    String result;
    size_t length, i;
    char *content;

    result.content = NULL;
    content = NULL;

    length = strlen(string);
    content = (char *)malloc(length + 1);

    if (content == NULL)
        return result;

    for (i = 0; i < length; i++)
    {
        content[i] = string[i];
    }

    content[length] = '\0';

    result.content = content;

    return result;
}

int stringDestroy(String *string)
{
    char *aux;

    aux = string->content;

    if (aux == NULL)
        return 0;

    free(aux);
    aux = NULL;
    return 1;
}

size_t stringLength(String string)
{
    size_t i;

    i = 0;

    while (string.content[i] != '\0')
    {
        i++;
    }

    return i;
}

size_t stringLength2(String string)
{
    char *p = string.content;

    while (*p != '\0')
        p++;

    return (size_t)(p - string.content);
}

char stringCharAt(String string, unsigned int index)
{
    size_t lengthString;

    lengthString = stringLength(string);

    if (index > lengthString - 1)
        return -1;

    return string.content[index];
}

String stringConcat(String source, String destination)
{
    size_t lengthSource, lengthDestination, lengthResult, i;
    String resultString;
    char *resultContent;

    resultString.content = NULL;
    resultContent = NULL;

    lengthSource = stringLength(source);
    lengthDestination = stringLength(destination);
    lengthResult = lengthSource + lengthDestination;

    resultContent = (char *)malloc(lengthResult + 1);

    if (resultContent == NULL)
        return resultString;

    for (i = 0; i < lengthResult; i++)
    {
        if (i < lengthDestination)
            resultContent[i] = destination.content[i];

        else
            resultContent[i] = source.content[i - lengthDestination];
    }

    resultContent[lengthResult] = '\0';

    resultString = stringCreate(resultContent);

    free(resultContent);

    return resultString;
}

String stringToLower(String original)
{
    size_t lengthOriginal, i;
    String resultString;
    char *resultContent;

    resultString.content = NULL;
    resultContent = NULL;

    lengthOriginal = stringLength(original);

    resultContent = (char *)malloc(lengthOriginal + 1);

    if (resultContent == NULL)
        return resultString;

    for (i = 0; i < lengthOriginal; i++)
    {
        resultContent[i] = tolower(original.content[i]);
    }

    resultContent[lengthOriginal] = '\0';
    resultString = stringCreate(resultContent);

    free(resultContent);

    return resultString;
}

// Copia o conteúdo da string t para a string s
// CUIDADO: é necessário alocar um buffer de tamanho suficiente
//          em s para que não haja overflow
void strcpy2(char *s, char *t)
{
    while ((*s++ = *t++));

    /* EXPLICAÇÃO DETALHADA:
       O valor de *t++ é o caractere que t apontou antes
       de t ser incrementado. 
       
       O sufixo ++ não altera t até
       depois que esse caractere tenha sido buscado.

       Assim, o caractere é armazenado na antiga posição
       de s antes de s ser incrementado.

       Caso seja detectado o terminador nulo em s o laço
       termina, efetivamente tendo copiado todo o conteúdo
       de t para s.
    */
}
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#define MAX_TEMP 100
int validInt(char *s);
int validFloat(char *s);
int scanInt(char s[]);
float scanFloat(char s[]);
double scanDouble(char s[]);
char *trimStr(char *str);
char *reformStr (char *str);
//str: string can duoc split
//delim: dau ngan cach giua cac word
//numtokens: so word trong string
char **splitStr(char* str, const char* delim, int* numtokens);
int validName(char *s);

char *trimStr(char *str) {
    int n = strlen(str);
    int flag = 1;
    int i, cnt = 0;
    char *res = (char *)malloc(n+1);
    for (i=0; i<n; ++i)
        if ( str[i] == ' ' )
            if ( flag == 0 ) {
                flag = 1;
                res[cnt++] = ' ';
            }
            else continue;
        else {
            flag = 0;
            res[cnt++] = str[i];
        }
    res[cnt++] = '\0';
    return res;
}
char *reformStr (char *str) {
    int n = strlen(str);
    char *res = (char *)malloc(n + 1);
    int i;
    int flag = 1;
    for (i=0; i<n; ++i)
        if ( str[i] != ' ' ) {
            if ( flag == 1 && (int)str[i] >= (int)'a' ) {
                res[i] = str[i] ^ ' ';
            }
            else if ( flag == 0 && (int)str[i] <(int)'a' )
                res[i] = str[i] ^ ' ';
            else res[i] = str[i];
            flag = 0;
        }
        else {
            flag = 1;
            res[i] = str[i];
        }
    res[n] = '\0';
    return res;
}

int validSignedInt(char *s){
  int i,check;
  if(isdigit(s[0])){
    check=1;
    for(i=1;i<strlen(s);i++)
      if(!isdigit(s[i]))
	check*=0;
  }
  if(s[0]=='+'){
    check=2;
    for(i=1;i<strlen(s);i++)
      if(!isdigit(s[i]))
	check*=0;
  }
  if(s[0]=='-'){
    check=3;
    for(i=1;i<strlen(s);i++)
      if(!isdigit(s[i]))
	check*=0;
  }
  return check;
}

int validInt(char *s){
  int i,check=1;
  for(i=0;i<strlen(s);i++)
    if(!isdigit(s[i]))
      check=0;
  return check;
}
int validFloat(char *s){
  int i,check=1;
  //- first
  if(s[0]=='-'){
    check*=isdigit(s[1]);
    for(i=2;i<strlen(s);i++){
      if(s[i]=='.')
	break;
      else{
	if(!isdigit(s[i]))
	  check*=0;
      }
    }
    i++;
    for(;i<strlen(s);i++){
	if(!isdigit(s[i]))
	  check*=0;
      }
  }

  //+ first
  else if(s[0]=='+'){
    check*=isdigit(s[1]);
    for(i=2;i<strlen(s);i++){
      if(s[i]=='.'){
	break;
      }
      else{
	if(!isdigit(s[i]))
	  check*=0;
      }
    }
    i++;
    for(;i<strlen(s);i++){
	if(!isdigit(s[i]))
	  check*=0;
    }
  }

  //digit first
  check*=isdigit(s[0]);
  for(i=1;i<strlen(s);i++){
    if(s[i]=='.')
      break;
    else{
	if(!isdigit(s[i]))
	  check*=0;
    }
  }
  i++;
  for(;i<strlen(s);i++){
    if(!isdigit(s[i]))
      check*=0;
  }  
  return check;
}
int scanInt(char s[]){
  char *temp=(char*)malloc(100*sizeof(char));
  int itemp;
  do{
    printf("[+]%s:",s);scanf("%[^\n]s",temp);getchar();
  }while(!validInt(temp));
  itemp=atoi(temp);
  free(temp);
  return itemp;
}
float scanFloat(char s[]){
  char *temp=(char*)malloc(100*sizeof(char));
  float ftemp;
  do{
    printf("[+]%s:",s);scanf("%[^\n]s",temp);getchar();
  }while(!validFloat(temp));
  ftemp=atof(temp);
  free(temp);
  return ftemp;
}
double scanDouble(char s[]){
  char *temp=(char*)malloc(100*sizeof(char));
  double dtemp;
  do{
    printf("[+]%s:",s);scanf("%[^\n]s",temp);getchar();
  }while(!validFloat(temp));
  dtemp=atof(temp);
  free(temp);
  return dtemp;
}
char **splitStr(char* str, const char* delim, int* numtokens) {
    char *s = strdup(str);
    size_t tokens_alloc = 1;
    size_t tokens_used = 0;
    char **tokens = calloc(tokens_alloc, sizeof(char*));
    char *token, *strtok_ctx;
    for (token = strtok_r(s, delim, &strtok_ctx);
            token != NULL;
            token = strtok_r(NULL, delim, &strtok_ctx)) {
        if (tokens_used == tokens_alloc) {
            tokens_alloc *= 2;
            tokens = realloc(tokens, tokens_alloc * sizeof(char*));
        }
        tokens[tokens_used++] = strdup(token);
    }
    if (tokens_used == 0) {
        free(tokens);
        tokens = NULL;
    } else {
        tokens = realloc(tokens, tokens_used * sizeof(char*));
    }
    *numtokens = tokens_used;
    free(s);
    return tokens;
}
int validName(char *s){
  int i;
  for(i=0;i<strlen(s);i++){
    if(!isalpha(s[i])&&s[i]!=' ')
      return 0;
  }
  return 1;
}

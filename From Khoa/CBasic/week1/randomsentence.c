#include<stdio.h>
#include<string.h>
#include<time.h>

 char article[5][10]={"the",
		       "a",
		       "one",
		       "some",
		       "any"};
  char noun[5][10]={"boy",
		    "girl",
		    "dog",
		    "town",
		    "car"};
  
  char verb[5][10]={"drove",
		    "jumped",
		    "ran",
		    "walked",
		    "skipped"};

  char preposition[5][10]={"to",
			   "from",
			   "over",
			   "under",
			   "on"};

//generate a number < n
int random(int n){
  return rand()%n;
}

void print_sentence(int s[10][6]){
  int i;
  for(i=0;i<10;i++)
    printf("%s %s %s %s %s %s\n",article[s[i][0]],noun[s[i][1]],verb[s[i][2]],preposition[s[i][3]],article[s[i][4]],noun[s[i][5]]);
}

int main(){
  srand(time(NULL));
  int sentence[10][6];
  int i,j;
  for(i=0;i<10;i++)
    for(j=0;j<6;j++)
      sentence[i][j]=random(5);

  print_sentence(sentence);
  
  return 0;
}

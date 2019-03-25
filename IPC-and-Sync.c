//critical_example2.c
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "se207_sems.h"

int main(int argc, char argv[]){
  //Use our source file as the "key"
  int id=se207_semget("critical_example2.c",1);

  int pid=fork();  
  if(pid){
    //Henry
      se207_wait(id);
      fprintf(stdout, "%s", "1 Henry: There's a hole in the bucket, deat Liza, dear Liza, There's a hole in the bucket, dear Liza, a hole.\n");      
      se207_signal(id);
      sleep(1);

      se207_wait(id);
      fprintf(stdout, "%s", "3 Henry: with what shall I fix it, dear Liza, dear Liza? With what shall I fix it, dear Liza, with what?\n");
      se207_signal(id);
      sleep(1);

      se207_wait(id);
      fprintf(stdout, "%s", "5 Henry: The straw is too long, dear Liza, dear Liza, The straw is too long, dear liza, too long.\n");
      se207_signal(id);
      sleep(1);

      se207_wait(id);
      fprintf(stdout, "%s", "7 Henry: With what shall i cut it, dear Liza, dear Liza? With what shall I cut it, dear Liza, with what?\n");
      se207_signal(id);
      sleep(1);
    
  }else{
    //Liza
      se207_wait(id);
      fprintf(stderr, "%s", "2 Liza: Then fix it, dear Henry, dear Henry, dear Henry, Then fix it, dear Henry, dear Henry fix it.\n");
      se207_signal(id);
      sleep(1);

      se207_wait(id);
      fprintf(stderr, "%s", "4 Liza: With straw, dear Henry, dear Henry, dear Henry, With straw, dear Henry, dear Henry, with straw.\n");
      se207_signal(id);
      sleep(1);
    
      se207_wait(id);
      fprintf(stderr, "%s", "6 Liza: Then cut it, dear Henry. dear Henry, Then cut it dear Henry, dear Henry, cut it.\n");
      se207_signal(id);
      sleep(1);

      se207_wait(id);
      fprintf(stderr, "%s", "8 Liza: With an axe, dear Henry, dear Henry, dear Henry, with an axe, dear Henry, dear Henry, an axe.\n");
      se207_signal(id);
      sleep(1);
  }
}

#define _GNU_SOURCE 
#include <string.h>
#include <mysql.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <pthread.h>  
#include <linux/unistd.h> 
#include <unistd.h>
#include <sys/syscall.h> 
#include <pthread.h>

my_bool set_pthread_name_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
  if (args->arg_count != 1)
  {
    strcpy(message, "set_pthread_name() requires one argument");
    return 1;
  }

  return 0;
}

long long set_pthread_name(UDF_INIT *initid, UDF_ARGS *args,
              char *is_null, char *error)
{
  pthread_t ptid;
  ptid = pthread_self();
  pthread_setname_np(ptid, args->args[0]);  
}

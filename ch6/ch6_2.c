#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
static jmp_buf env, env2;
int jumper(int arg) {
longjmp(env, arg * 2);
}
void obfuscate(int x, int y) {
printf("BEFORE: %d @ %p\n", x, &x);
if (setjmp(env2) == 0) {
jumper(y);
} else {
printf("AFTER: %d @ %p\n\n", x, &x);
}
}
void mouse_trap() {
int c = 0, ret;
if ((ret = setjmp(env)) == 0) {
++c;
printf("setting up the trap...\n");
return;
} else {
c = rand();
printf("c: %d @ %p, ret: %d @ %p\n", c, &c, ret, &ret);
longjmp(env2, 1);
}
}
int main(void) {
mouse_trap();
printf("calling jumper()...\n\n");
obfuscate(123, 1);
obfuscate(456, 2);
obfuscate(789, 3);
obfuscate(1024, 4);
return 0;
}
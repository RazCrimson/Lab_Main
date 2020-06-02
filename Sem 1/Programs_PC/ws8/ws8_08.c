
#include <stdio.h>
void main()
{
    printf("\nPointer: Use of & and *:\n");
    int m = 300, *pi = &m;
    float fx = 300, *pfx = &fx;
    char cht = 'z', *pcht = &cht;
    printf("\nm=%d fx=%f cht=%c", m, fx, cht);
    printf("\nUsing &:\n&m=0x%x\n&fx=0x%x\n&cht=0x%x", &m, &fx, &cht);
    printf("\nUsing *, &:\nm=%d\nfx=%f\ncht=%c\n", *&m, *&fx, *&cht);
    printf("\nUsing * :\nm=0x%x\nfx=0x%x\ncht=0x%x\n", pi, pfx, pcht);
    printf("\nUsing * op:\nm=%d\nfx=%f\ncht=%c\n", *pi, *pfx, *pcht);
}

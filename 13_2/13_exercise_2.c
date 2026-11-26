#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int number;
    char title[20];
};

void main(void)
{
    struct Book *p;

    /* Book 구조체 2개 크기만큼 동적 할당 */
    p = (struct Book *)malloc(2 * sizeof(struct Book));
    if (p == NULL) {
        printf("memory allocation error\n");
        return 1;
    }

    /* 첫 번째 구조체: p->멤버  ( (*p).멤버 와 같음 ) */
    p->number = 1;
    strcpy(p->title, "C Programming");

    /* 두 번째 구조체: (p+1)->멤버  ( p[1].멤버 와 같음 ) */
    (p + 1)->number = 2;
    strcpy((p + 1)->title, "Electronics");

    /* 저장된 값 확인 */
    printf("book 0 : %d, %s\n", p->number, p->title);
    printf("book 1 : %d, %s\n", p[1].number, p[1].title);

    free(p);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int number;
    char title[30];     /* 강의안은 [10] → "Communications Theory"(21자+'\0')가 넘쳐서 30으로 늘림 */
};

int main(void)
{
    int i;
    struct Book **bookshelf;

    /* 1. Book 구조체 포인터 변수 3개를 동적 할당 */
    bookshelf = (struct Book **)malloc(3 * sizeof(struct Book *));
    if (bookshelf == NULL) {
        printf("메모리 할당 오류\n");
        return 1;
    }

    /* 2. 각 포인터마다 Book 구조체 변수 10개를 동적 할당 */
    for (i = 0; i < 3; i++) {
        bookshelf[i] = (struct Book *)malloc(10 * sizeof(struct Book));
        if (bookshelf[i] == NULL) {
            printf("메모리 할당 오류\n");
            return 1;
        }
    }

    /* 3. 이중 포인터 형태의 동적 메모리 접근 */
    /*    bookshelf[1][3].멤버  ==  (bookshelf[1]+3)->멤버 */
    bookshelf[1][3].number = 5;
    strcpy(bookshelf[1][3].title, "C++ Programming");

    (bookshelf[2] + 4)->number = 3;
    strcpy((bookshelf[2] + 4)->title, "Communications Theory");

    /* 저장할 때와 다른 표기법으로 읽어서 두 표기가 같은 곳을 가리킴을 확인 */
    printf("book (1,3) : %i, %s\n", (bookshelf[1] + 3)->number, (bookshelf[1] + 3)->title);
    printf("book (2,4) : %i, %s\n", bookshelf[2][4].number, bookshelf[2][4].title);

    /* 4. 메모리 반납 : 할당의 역순 (안쪽 → 바깥쪽) */
    for (i = 0; i < 3; i++)
        free(bookshelf[i]);     /* 각 칸의 Book 10개 반납 */
    free(bookshelf);            /* 포인터 3개짜리 배열 반납 */

    return 0;
}
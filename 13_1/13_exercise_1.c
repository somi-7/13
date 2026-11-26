#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *pc = NULL;
    int i = 0;

    /* 1. 동적 메모리 할당 (char 100개 = 100바이트) */
    pc = (char *)malloc(100 * sizeof(char));
    if (pc == NULL) {                 /* 할당 실패 검사 */
        printf("메모리 할당 오류\n");
        exit(1);
    }

    /* 2. 할당받은 메모리를 배열처럼 사용: 'a' ~ 'z' 저장 */
    for (i = 0; i < 26; i++) {
        pc[i] = 'a' + i;
    }
    pc[i] = 0;                        /* pc[26] = '\0' : 문자열의 끝 표시 */

    /* 3. 문자열로 출력 */
    printf("%s\n", pc);

    /* 4. 사용이 끝난 메모리 반납 */
    free(pc);

    return 0;
}
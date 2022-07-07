#include <stdio.h>

void main(void) {
	struct data {
		int id;
		char name[20];
	};
	struct data card[2] = { {1, "student1"}, {2, "student1"} };
	struct data* p;
	p = &card[1];

  [a] = '2';

	printf("%d\n", [b]);
	printf("%s", [c]);
}

//[a], [b], [c] 칸에 명령문을 완성하시면 됩니다..

//기본적으로 구조체에 대한 기본 개념을 잡으시고 접근하시면 쉽습니다.

//위 프로그램에서 id가 2인 학생의 name을 student1에서 student2로 바꾸고
//id가 2인 학생의 data가 출력되도록 a,b,c를 채워 넣으시오.








//////////////////////////////////////////////////////////////////////////////////////////////////


//정답

#include <stdio.h>

void main(void) {
	struct data {
		int id;
		char name[20];
	};
	struct data card[2] = { {1, "student1"}, {2, "student1"} };
	struct data* p;
	p = &card[1];

	p->name[7] = '2';

	printf("%d\n", p->id);
	printf("%s", p->name);
}

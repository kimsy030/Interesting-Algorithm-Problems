#include <stdio.h>
int main(){
	int a, b, c;
	int count = 1;

	for (b = c = 10;
		a = "- FIGURE?, UMKC,XYZHello Folks,\
			TFy!QJu ROo TNn(ROo)SLq SLq ULo+\
			UHs UJq TNn*RPn/QPbEWS_JSWQAIJO^\
			NBELPeHBFHT}TnALVlBLOFAkHFOuFETp\
			HCStHAUFAgcEAelclcn^r^r\\tZvYxXy\
			T|S~Pn SPm SOn TNn ULo0ULo#ULo-W\
			Hq!WFs XDt!"[b++ + 21]; )
		for (; a-- > 64; )
			putchar(++c == 'Z' ? c = c / 9 : 33 ^ b & 1);
	return 0;
}
/*
이 코드는 C 언어 문법에 어긋나지 않지만 알아보기 힘들게 교묘하게 섞어 놨다.
잘 보면 위의 코드를 이해할 수 있는 몇 가지 단서를 발견할 수 있다.
  
  이 코드를 잘 보면, for (b = c = 10; a = "- FIGURE?, .. 중간 생략 ..     Hq!WFs XDt!"[b+++21]; )
a 변수에 대입 되는 값은 "...문자열..."[인덱스] 값인 char 문자가 된다. 

b = 10 초기 값을 가지므로 배열의 인덱스 값은 [11+21], 즉 32번 문자부터 시작하므로
a 변수의 문자열 "- FIGURE?, UMKC,XYZHello Folks,\" 은 그냥 더미(쓰레기) 값임을 알 수 있다.
    
    이 코드에서 for (b = c = 10; a = "- FIGURE?, .. 중간 생략 ..  Hq!WFs XDt!"[b+++21]; )
배열 인덱스를 나타내는 [b+++21] 코드는 [(b++)+21] 로 풀어 쓸 수 있다.

putchar ( ++c=='Z' ? c = c/ 9:33^b&1); 코드는 일반적인 삼항식이다.
삼항식인 ++c=='Z' ? c = c/ 9:33^b&1 코드는 (++c == 'Z') ? (c = c / 9) : (33 ^ b & 1) 이렇게 풀어 쓸 수 있다.

이 두 가지의 문법적인 부분만 발견하고 풀어냈다면 다 한 것이나 다름 없다.

(++c == 'Z')는 ASCII 코드 표를 참고해 보면 (++c == 90)이 되고, c = 10인 초기 값을 갖는다.
그러므로 80번 반복 후에 c=c/9 코드의 값은 언제나 10=90/9이 되므로 10인 ASCII 코드인 'new line', 새로운 행에서 문자를 계속 찍는다. 

(33 ^ b & 1) 코드는 (33 xor b and 1) 비트 연산과 같다. xor, and 연산 중 and 연산이 더 우선 순위이므로 (b and 1) xor 33 이렇게 표현할 수 있겠다.

33 - (b ^ 1) 코드로 최종적으로 표현되는데, b^1은 홀수면 1, 짝수면 0이 된다.
ASCII 코드 표를 참고해 보면 33,32 값은 각각 '!' 문자와 'Space' 문자가 된다.
  
코드가 실행되는 순서대로 ASCII 값을 대입해 보면, 코드가 어떻게 실행 결과처럼 출력 되는지 이해할 수 있을 것이다.

코드를 자세히 보니 별 것 아니란 걸 느꼈을 것이다. 이 코드를 리팩토링여 알아보기 쉬운 코드로 아래와 같이 바꿀 수 있다.
*/

#include <stdio.h>
int main()
{
    int a,b,c;

    char *str = "- FIGURE?, UMKC,XYZHello Folks,\
                TFy!QJu ROo TNn(ROo)SLq SLq ULo+\
                UHs UJq TNn*RPn/QPbEWS_JSWQAIJO^\
                NBELPeHBFHT}TnALVlBLOFAkHFOuFETp\
                HCStHAUFAgcEAelclcn^r^r\\tZvYxXy\
                T|S~Pn SPm SOn TNn ULo0ULo#ULo-W\
                Hq!WFs XDt!";

    for (b = c = 10; a = *(str + (b++) + 21); ) {
        for(; a-- > 64 ; ) {
            putchar ( ++c==90 ? c = c / 9 : 33 - (b&1));
        }
    }   
}



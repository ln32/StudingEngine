# 240807
## 1. c)  char* char[]
char str[] = "abc";
char *str = "abc";

> gcc2_compiled.:
> .section .rodata
> .LC0:
> .byte 0x61,0x62,0x63,0x0

 str은 .rodata 영역에 있는 "abc"에 대한 포인터
 str[]의 경우 함수 호출 시에 .rodata의 "abc" 문자열을 함수의 스택으로 복사

***

## 2. c#) ref list == list

***

## 3. Memory section ( code data heap stack )

Text Segment or Code Segment 	
						실행가능한 명령어(Instruction)가 포함된 오브젝트 파일 또는 메모리 공간을 할당받은 프로그램 섹션
						명령어(Instruction)을 변경하지 못하도록 Read-Only다
						일반적으로 텍스트 세그먼트는 공유 가능하므로, 텍스트 편집기, C 컴파일러, 셸 등과 같이 자주 실행되는 프로그램 복사본을 메모리에 저장하여 사용할 수 있다

Initialized Data Segment (.data)	
						초기화된 전역 변수와 Static 정적 변수
						읽기 전용 영역(Initialized Read-Only Area)과 초기화된 읽기-쓰기 영역(Initialized Read-Write Area)로 구분
            chars s[] = "hello world" 의 경우 "hello world"는 전자, str 은 후자다

## 4. async lock

***

## 5. void func == internal void func

***

## 6. class struct 차이 및 struct 초기화



***

## 7. 아키텍쳐 설계



***

## 8. data 영역 

# Figure 
1. https://skyul.tistory.com/28
2.
3. https://m.blog.naver.com/techref/222270185816
4.
5.
6.
7. https://velog.io/@wjdtmfgh/%EC%95%84%ED%82%A4%ED%85%8D%EC%B2%98-%EC%84%A4%EA%B3%84

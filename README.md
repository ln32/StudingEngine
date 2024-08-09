# 240807
## 1. c)  char* char[]
char str[] = "abc";
char *str = "abc";

> gcc2_compiled.:
> > 
> .section .rodata
> 
> .LC0:
> 
> .byte 0x61,0x62,0x63,0x0

 str은 .rodata 영역에 있는 "abc"에 대한 포인터
 str[]의 경우 함수 호출 시에 .rodata의 "abc" 문자열을 함수의 스택으로 복사

***

## 2. c#) ref list == list


        static void Func1(List<int> target,int input)
        {
        00007FFD576971F0  push        rbp  
        00007FFD576971F1  push        rdi  
        00007FFD576971F2  push        rsi  
        00007FFD576971F3  sub         rsp,20h  
        00007FFD576971F7  mov         rbp,rsp  
        00007FFD576971FA  mov         qword ptr [rbp+40h],rcx  
        00007FFD576971FE  mov         dword ptr [rbp+48h],edx  
        00007FFD57697201  cmp         dword ptr [7FFD5759AD20h],0  
        00007FFD57697208  je          Testtt0809.Program.Func1(System.Collections.Generic.List`1<Int32>, Int32)+01Fh (07FFD5769720Fh)  
        00007FFD5769720A  call        00007FFDB71AD2F0  
        00007FFD5769720F  nop  
    		target.Add(input);
        00007FFD57697210  mov         rcx,qword ptr [rbp+40h]  
	00007FFD57697214  mov         edx,dword ptr [rbp+48h]  
	00007FFD57697217  cmp         dword ptr [rcx],ecx  
	00007FFD57697219  call        CLRStub[MethodDescPrestub]@7ffd574ffb20 (07FFD574FFB20h)  
	00007FFD5769721E  nop  
        }

        static void Func2(ref List<int> target, int input)
        {
	00007FFD5769A970  push        rbp  
	00007FFD5769A971  push        rdi  
	00007FFD5769A972  push        rsi  
	00007FFD5769A973  sub         rsp,20h  
	00007FFD5769A977  mov         rbp,rsp  
	00007FFD5769A97A  mov         qword ptr [rbp+40h],rcx  
	00007FFD5769A97E  mov         dword ptr [rbp+48h],edx  
	00007FFD5769A981  cmp         dword ptr [7FFD5759AD20h],0  
	00007FFD5769A988  je          Testtt0809.Program.Func2(System.Collections.Generic.List`1<Int32> ByRef, Int32)+01Fh (07FFD5769A98Fh)  
	00007FFD5769A98A  call        00007FFDB71AD2F0  
	00007FFD5769A98F  nop  
    		target.Add(input);
	00007FFD5769A990  mov         rcx,qword ptr [rbp+40h]  
	00007FFD5769A994  mov         rcx,qword ptr [rcx]  
	00007FFD5769A997  mov         edx,dword ptr [rbp+48h]  
	00007FFD5769A99A  cmp         dword ptr [rcx],ecx  
	00007FFD5769A99C  call        System.Collections.Generic.List`1[[System.Int32, System.Private.CoreLib]].Add(Int32) (07FFD73CD1080h)  
	00007FFD5769A9A1  nop  
        }


 결론 : 형식의 차이는 있다. 하지만 값의 복사는 참조 위치가 복사될 뿐 딥카피는 일어나지 않는다.


***

## 3. Memory section ( code data heap stack )

Text Segment or Code Segment 	

	실행가능한 명령어(Instruction)가 포함된 오브젝트 파일 또는 메모리 공간을 할당받은 프로그램 섹션
      
	명령어(Instruction)을 변경하지 못하도록 Read-Only다
      
	일반적으로 텍스트 세그먼트는 공유 가능 하기에 텍스트 편집기, C 컴파일러, 셸같은 프로그램 복사본을 메모리에 저장 후 활용가능

Initialized Data Segment (.data)	

	초기화된 전역 변수와 Static 정적 변수
      
	읽기 전용 영역(Initialized Read-Only Area)과 초기화된 읽기-쓰기 영역(Initialized Read-Write Area)로 구분
      
	chars s[] = "hello world" 의 경우 "hello world"는 전자, str 은 후자다

Uninitialized Data Segment (.bss)

	static int i1 ; int i2 ; 
	    
	초기값이 없는 정적변수 i1, 전역 변수 i2 는 BSS 세그먼트에 저장된다

Stack Heap

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

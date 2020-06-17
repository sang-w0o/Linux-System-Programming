cat 구현하기
======

* Cat 명령어는 다음과 같이 사용할 수 있다.
```sh
cat fileName
```

* 예시 코드 (1) - cat 구현하기
```C
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv ){
	if(argc != 2){
		fprintf(stderr, "usage : %s FILENAME\n", *argv);
		return -1;
	}
    // argc를 하나 줄이고, argv는 다음 원소를 가리키게 한다.
    // 즉, "./a.out"는 버린다는 뜻이다.
	--argc, ++argv;

    // 인수로 들어온 파일을 read 모드로 연다.
	FILE *fp = fopen(*argv, "r");
	if(fp == NULL) {
		perror("fopen");
		return -1;
	}

	while(1) {
        // 파일 내용을 int형으로 캡쳐하여 char단위로 fgetc로 가져옴
		int ch = fgetc(fp);
		if(ch == EOF)
			break;
        
        // 출력
        usleep(100000);
		fputc(ch, stdout);
		fflush(stdout);
	}

	fclose(fp);
	return 0;
}
```
* 위 코드는 Byte단위로 입출력을 수행하기에 성능상의 문제가 존재한다.
* 이를 해결하기 위해 buffer를 도입해보자.
<hr/>

<h3>#1. 버퍼의 도입</h3>

```C
#include <stdio.h>

int main(int args, char **argv ){
	if(argc != 2){
		fprintf(stderr, "usage : %s FILENAME\n", *argv);
		return -1;
	}
	--argc, ++argv;

	FILE *fp = fopen(*argv, "r");
	if(fp == NULL) {
		perror("fopen");
		return -1;
	}

    char buf[4096];
	while(1) {
		if(fgets(buf, sizeof(buf), fp) == NULL){
            break;
        }
        
		fputs(buf, stdout);
		fflush(stdout);
	}

	fclose(fp);
	return 0;
}
```
* fgets는 성공 시, 첫 번째로 들어온 포인터값을 그대로 반환하고, 오류가 발생하거나   
  EOF를 만나면 NULL을 반환한다.
* 위 코드는 line-buffered를 사용하므로 다소 빠르게 동작한다.
* 하지만 buffer 전체를 온전히 사용하는 것이 아니므로, 여전히 성능 상의 이슈가 존재한다.
* 이를 해결하기 위해 fully-buffered를 도입한다.
<hr/>

<h3>#2. Fully-buffered 의 도입</h3>

```C
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv ){
	if(argc != 2){
		fprintf(stderr, "usage : %s FILENAME\n", *argv);
		return -1;
	}
	--argc, ++argv;

	FILE *fp = fopen(*argv, "r");
	if(fp == NULL) {
		perror("fopen");
		return -1;
	}
	while(1) {
	char buf[4096];
		int nRead = fread(buf, sizeof(char), 4096, fp);
		if(nRead){
			usleep(100000);
			fwrite(buf, sizeof(char), nRead, stdout);
			fflush(stdout);
		}
		else {
			break;	
		}
	}
	fclose(fp);
	return 0;
}
```
* fread는 binary stream 으로 입출력을 수행하기 위한 함수이다.
* fwrite 사용 시, 버퍼의 크기 만큼을 인수로 넣어주면, 버퍼가 가득 차지 않았다면 쓰레기 값이 출력될 수 있다.
* 따라서 읽어온 만큼만 출력되도록 읽어온 크기를 fwrite의 인수로 넣어줘야 한다.
<hr/>


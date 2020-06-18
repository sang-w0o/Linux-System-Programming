System Programming
======

<h2>Linux System Programming</h2>

* Linux가 제공하는 함수(SystemCall, syscall)를 사용하여 프로그래밍을 하는 것.
  * printf와 같은 함수는 Linux가 제공하는 함수가 아니라, Linux가 제공하는 함수를 Wrapping하여 만든 것이다.
  * 주로 C, C++를 사용하여 개발한다.
<hr/>

<h2>개발 환경 설정</h2>

* Linux가 제공하는 함수(syscall)은 C언어로 구현되어 있다.
* C언어를 빌드하기 위해서는 gcc가 필요하다.

* gcc : GNU Compiler Collection의 약자로, 아래 명령어로 설치한다.
```sh
sudo apt install gcc
```
* gcc를 설치하고, c 파일을 빌드하는 것은 다음과 같다. (hello.c)
```sh
gcc -o hello hello.c 

# -o 옵션을 주지 않으면 실행 파일은 a.out으로 생성된다.

# 여러 개의 파일 빌드하기
gcc- o hello hello.c world.c bye.c
```
<hr/>
<h2>C 언어 라이브러리 도움말을 보는 방법</h2>

* vi에서 원하는 함수에 커서를 두고, __3+K__ 를 누른다.
<hr/>

<h2>Buffer의 개념</h2>

```c
#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Hello, world");
	sleep(-1);
	return 0;
}
```
* 위 코드를 실행하면, sleep에 의해 약 136동안 프로세스가 delay된다.
* 하지만 실행하면 Hello, world 가 출력되지 않는다.
* 위 문제를 이해하기 위해서는 Buffer의 개념이 필요하다.

* Buffer의 종류 
  (1) stdin
  (2) stdout
  (3) stderr

* Buffer가 flush하는 방식
  * (1) Fully buffered : 버퍼가 가득 찬 경우, flush 수행
  * (2) Line buffered : 개행이 입력됐을 때, flush 수행 (ex. printf, scanf)
  * (3) Non-buffered : Buffer없이 바로바로 flush 수행

* 위 코드의 문제를 해결하기 위해서는 __fflush__ 를 사용하면 된다.
  * fflush : 인수로 들어온 FILE *stream의 버퍼를 비운다.
  * 단, fflush는 표준 출력에서만 동작 한다.
```c
#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Hello, world");
    fflush(stderr);
	sleep(-1);
	return 0;
}

```
* 아래 코드를 보자.
```C
#include <stdio.h>

int main() {
    int i; scanf("%d", &i);
    char c; scanf("%c", &c);

    printf("%d, %c\n", i, c);
    return 0;
}
```
* 위 코드는 정수 1개를 입력하고 enter를 누르는 순간, 종료된다.
* 즉, scanf는 입력된 값이 개행을 만나는 순간 데이터를 읽어오는 것이다.
```C
#include <stdio.h>

void flush_stdin() {
    int ch;
    do {
        ch = getchar();
    } while(ch != EOF && ch != '\n')
}
int main() {
    int i; scanf("%d", &i);
    char c; scanf("%c", &c);
    flush_stdin();
    printf("%d, %c\n", i, c);
    return 0;
}
```
* 위와 같이 표준 입력에 대한 버퍼의 처리는 개발자가 직접 해야 한다.

* main 함수의 인자인 args, argv는 다음과 같다.
* args : Argument Count
* argv : Argument Vector Table

* 명령행에 다음과 같이 입력되었다고 하자.
  ```sh
  ./a.out "hello" "world"
  ```
  * 위 경우에 argc는 인수의 개수인 3이 된다.
  * argv[0] = "./a.out", argv[1] = "hello", argv[2] = "world"가 된다.
<hr/>

<h2>파일의 offset</h2>

* 현재 파일의 크기를 구하는 프로그램을 만들어보자.
```C
#include <stdio.h>

int main(int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "usage : %s FILENAME\n", *argv);
		return -1;
	}
	--argc, ++argv;

	FILE *fp = fopen(*argv, "r");
	if(fp == NULL) {
		perror("fopen");
		return -1;
	}

	size_t fsize = 0;
	while(1) {
		if(fgetc(fp) == EOF)
			break;
		++fsize;
	}

	printf("File size : %lu\n", fsize);
	
	fclose(fp);
	return 0;
}
```

* 위 코드는 버퍼를 사용하지 않는 다는 것을 제외하고, loop를 사용한다는 단점이 있다. buffer를 도입해도   
  loop를 제거할 수는 없다.

* FILE 정보 구조체에는 다음과 같은 멤버들이 있다.
  * FILE의 내용을 담는 멤버
  * FILE의 특정 부분을 가리키는 offset pointer
    * 초기에는 -1번째를 가리키고, fgetc가 호출될 때 마다 한byte 뒤의    
        문자를 가리킨다.
    * offset은 파일의 처음부터 현재 가리키는 문자와의 거리를 나타낸다.
    * 기본적으로 offset은 C언어 라이브러리가 제어하는데, 사용자의 필요에   
        의해 직접적으로 제어할 수도 있다.
    * 이 기능을 구현하는 함수가 __fseek__ 함수이다.

* fseek함수 : __int seek(FILE *stream, long offset, int whence)__
  * whence : 기준 위치를 의미한다.
    * whence는 SEEK_SET, SEEK_CUR, SEEK_END가 있는데, SEEK_END는 현재 offset ponter를   
    파일의 끝으로 이동시킨다는 의미이다.
  * 반환값 : 함수의 성공 유무를 반환한다. (성공 : 0, 실패 : -1)
    * 즉, 0번째 위치부터 떨어진 거리값을 반환하는 것이다. 이는 곧 파일에서   
    읽은 Byte수를 의미하기도 한다.
* ftell 함수 : 0번째 위치부터 offset pointer까지의 거리를 반환한다.
  * 주의 : 무언가 문제가 있다면 -1을 반환한다.

* 따라서 해당 offset을 파일의 끝으로 옮기면 파일 크기를 구할 수 있다.

```C
#include <stdio.h>

int main(int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "usage : %s FILENAME\n", *argv);
		return -1;
	}
	--argc, ++argv;

	FILE *fp = fopen(*argv, "r");
	if(fp == NULL) {
		perror("fopen");
		return -1;
	}

	if(fseek(fp,0, SEEK_END)== -1) {
		perror("fseek");
		return -1;
	}

	long fsize = ftell(fp);
	if(fsize == -1) {
		perror("ftell");
		return -1;
	}

	printf("File size : %ld\n", fsize);
	
	fclose(fp);
	return 0;
}
```

* 파일의 크기와 내용을 출력하는 프로그램의 구현
  * 사용법 : ./a.out FILENAME
  * 출력 : FILE SIZE : n (개행 후 내용 출력)
```C
#include <stdio.h>
#include <unistd.h>

int getFileSize(FILE *fp);
int showFileContent(FILE *fp);

int main(int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "usage : %s FILENAME\n", *argv);
		return -1;
	}
	--argc, ++argv;


	FILE *fp = fopen(*argv, "r");
	if(fp == NULL){
		perror("fopen");
		return -1;
	}

	getFileSize(fp);
	showFileContent(fp);

	fclose(fp);
	return 0;
}

int getFileSize(FILE *fp) {
	
	if(fseek(fp, 0, SEEK_END) == -1) {
		perror("fseek");
		return -1;
	}

	long fsize = ftell(fp);
	if(fsize == -1) {
		perror("ftell");
		return -1;
	}

	printf("FILE SIZE : %ld\n", fsize);
	return 0;
}

int showFileContent(FILE *fp) {

	if(fseek(fp, 0, SEEK_SET) == -1) {
		perror("fseek");
		return -1;
	}
	
	while(1){
		char buf[4096];
		int nRead = fread(buf, sizeof(char), 4096, fp);
		if(nRead) {
			usleep(100000);
			fwrite(buf, sizeof(char), nRead, stdout);
			fflush(stdout);
		}
		else
			break;
	}
	return 0;
}
```
<hr/>

<h2>Syscall</h2>

* Process는 user space와 kernel space로 나뉜다.
* kernel space는 모든 프로세스가 공유할 수 있는 영역인데, 이 영역에 키보드가 있다.
* 만약 키보드의 주소를 user space에 주게 된다면, 키보드의 주소를 따라가서 kernel space에 접근할 수 있는 위험이 존재한다.
* 따라서 암묵적인 약속을 정했는데 다음과 같다.
  * 만약 키보드가 필요하다면, kernel space는 user space에 0을 넘겨주고, user space로부터   
    0이 오면 kernel space는 이를 키보드라고 인지한다.
  * 모니터의 경우 같은 원리로 다른 번호를 사용하면 된다.
* 이렇게 된다면 user space입장에서는 정수형 상수값만 받을 뿐이다.
* 이러한 상수값을 __file descriptor__ 라 한다.

* 버퍼 생성시에는 효율적인 버퍼의 크기가 정의된 매크로인 __BUFSIZ__ 를 사용하자.(File : stdio.h)
<hr/>

<h2>File Descriptor 정수 값의 의미</h2>

* 만약 프로그램에서 open syscall함수를 통해 파일을 열면, 반환되는 file descriptor값은 __3__ 이다.

* Linux내에는 PCB(Process Control Block)라는 정보 구조체가 있는데, 여기에는 각각의 파일을   
  가리키는 정보를 저장하는 배열이 있다.
  * 0 : Keyboard (Buffer 있음)
  * 1 : Monitor (Buffer 있음)
  * 2 : Monitor (Buffer 없음)
  * 그 이후부터는 fd_table(File Descriptor Table)에서   
    비어있는 가장 작은 index순으로 반환된다.

```C
int main(int argc, char **argv) {

    int fd1 = open(argv[0], O_RDONLY);
    printf("fd1 : %d\n", fd1);
    // fd1 : 3

    int fd2 = open(arfv[0], O_RDONLY);
    printf("fd2 : %d\n", fd2);
    // fd2 : 4

    close(fd2);
    close(fd1);
}
```

<h2>File Offset</h2>

* 리눅스 커널은 열려있는 파일마다 각각의 file offset을 기록한다.
* file offset은 파일에서 다음 읽기 또는 쓰기가 시작될 위치를 의미한다.   
  또는 파일의 시작에서부터 떨어진 거리를 의미하기도 한다.
* 파일의 첫 Byte는 offset이 0이다.

* file offset은 파일이 열렸을 때, 파일의 시작을 가리키도록 설정되어 있고,   
  read나 write가 호출될 때 마다 방금 읽거나 쓴 byte의 다음 byte를 가리키도록 자동으로 조정된다.

* 위를 알기 위해 C 표준에서는 __fseek__ 을 사용하지만, syscall 에는 __lseek__ 함수가 있다.

* 프로세스 내에서 동일한 파일을 열었을 때에는 파일 정보 구조체는 각각 가지게 된다. 즉, __파일을 열 때 마다 파일 정보 구조체는 개별적으로 생성된다__.
* 하지만 프로세스 내에서 __dup()로 해당 file descriptor__ 를 복제한 경우에는 __정보 구조체를 공유한다__.

<h2>연결 계수, inode의 n_link</h2>

* file 생성 시의 inode 연결 계수는 1이다.
* dir 생성 시의 inode 연결 계수는 2이다.
  * 그 이유는 __..__ 과 __.__ 이 있기 때문이다.
<hr/>

<h2>파일의 삭제</h2>

* 파일 삭제 시에는 __unlink__ 라는 함수를 사용한다.
* unlink함수는 인자로 전달된 파일의 연결 계수를 1 감소시킨다.
* unlink를 수행한다고 해서 파일이 바로 삭제되는 것이 아니라, 프로세스 내에서   
  파일을 참조하는 __참조 계수__ 와 파일 시스템에서 해당 파일을 참조하는   
  __연결 계수가 모두 0일 때__ 삭제된다.
<hr/>

<h2>mmap(Memory Mapping)</h2>

```C
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct Person {
	char name[32];
	int age;
}Person;

int writePerson(const char *fname, Person *person) {
	if(fname == NULL || person == NULL) {
		fprintf(stderr, "argument is NULL.\n");
		return -1;
	}

	int fd = open(fname, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if(fd < 0) {
		perror("open");
		return -1;
	}

	int nWritten = write(fd, person, sizeof(Person));
	if(nWritten < 0) {
		perror("write");
		return -1;
	}
	close(fd);
	return 0;
}

int dumpFile(const char *fname) {
	if(fname == NULL) {
		fprintf(stderr, "argument is NULL.\n");
		return -1;
	}

	int fd = open(fname, O_RDONLY);
	if(fd < 0) {
		perror("open");
		return -1;
	}

	Person buf;
	while(1) {
		ssize_t nRead = read(fd, &buf, sizeof(buf));
		if(nRead < 0) {
			perror("read");
			return -1;
		}
		else if(nRead == 0) {
			break;
		}
		else{
			printf("name : %s, age : %d\n", buf.name, buf.age);
		}
	}
	close(fd);
	return 0;
}

int main(int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "usage : %s FILENAME\n", *argv);
		return -1;
	}

	--argc, ++argv;

	Person arr[] = { {"A", 11}, {"B", 22}, {"C", 33}, {"D",44} };

	for(int i = 0; i < 4; i++) {
		writePerson(*argv, &arr[i]);
	}

	dumpFile(*argv);

	return 0;
}

```
* 위 코드의 문제점은 함수(writePerson, dumpFile)이 호출될 때 마다 내부에서   
  open, close, read 등 버퍼 입출력 함수를 항상 호출하기 때문에 성능이 떨어진다는 것이다.

* 이러한 문제를 해결하기 위해 mmap(Memory Mapping) 이 등장했다.
* mmap : 파일의 일부분을 프로세스의 가상 메모리에 저장하는 것.
  * 즉, 파일을 곧 포인터(배열) 로써 처리할 수 있게 된다.
  * mmap으로 파일에 대해 메모리 매핑을 수행하면, 해당 파일에 대한   
    참조 계수가 1 증가한다. 또한 파일을 닫는다 하더라도 프로세스는   
    여전히 매핑된 메모리에 접근할 수 있다.
* mmap의 장점
  * (1) 불필요한 복사가 발생하지 않는다.
  * (2) 포인터의 조작만으로 파일 탐색이 가능하다.
  * (3) IPC(Inter-Process Communicator)로 사용 가능하다.

* mmap의 단점
  * (1) 메모리 매핑은 페이지 단위(메모리 입출력을 위한 최소 단위)로 처리되므로   
    작은 파일에 대하여 매핑할 경우, 메모리 낭비가 발생할 수 있다.
  * (2) 메모리 매핑 시, 크기를 크게 잡으면 메모리 부족이 발생할 수 있다.
    * 단, 64비트 시스템에서는 문제가 되지 않는다.
  * (3) 메모리 매핑과 관련된 정보를 생성 및 유지하는 오버헤드가 발생할 수 있다.
<hr/>

<h2>파일의 정보 추출</h2>

* lstat 함수 : 파일의 정보 추출해주는 syscall 함수.
<hr/>
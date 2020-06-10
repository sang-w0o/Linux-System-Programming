명령어의 개념
======

<h2>Linux의 명령어</h2>

* (1) 프로그래밍 언어나 스크립트 언어로 구현되어 실행 가능한 프로그램.
  * C, C++와 같은 언어로 작성되어 컴파일된 binary file
  * Python, Ruby, JavaScript, Shell 등의 스크립트 언어로 작성된 text file
* (2) 내장 명령어(Shell Builtins) : Shell이 자체적으로 실행 가능한 명령어
  * ex) cd : cd는 which cd명령어를 실행해도 위치가 나오지 않는다.
    * 그 이유는 cd는 쉘이 자체적으로 제공하는 기능이기 때문이다.
* (3) 쉘 함수(Mini Script)
* (4) 별칭(Alias) : alias 명령어로 지정한다.
<hr/>

<h2>명령어의 도움말</h2>

* 명령어의 도움말을 보기 전에, 해당 명령어의 타입을 알아야 한다.
  * 예를 들어, cd 명령어는 cd -h 옵션이 없고, man cd를 해도 설명이 나오지 않는다.
  * 이럴 때를 위해, 타입을 먼저 알아야 한다.
    * type 명령어 : 명령어의 종류를 알려준다.
      * 사용법 : type cmd
    * type으로 명령어의 종류를 알아낸 후, 그에 맞게 도움말을 봐야한다.

* (1) 내장 명령어의 도움말 확인 방법 : help 명령어 사용
  * 사용법 : help cmd
  * ex) help alias
* (2) 실행 파일 명령어의 도움말 확인 방법
  * -h 또는 --help 옵션을 사용한다.

* man 명령어 : 리눅스의 각종 도움말을 출력하는 명령어
  * 사용법 : man [section] 명령어
  * 사용자 명령어는 빈번하게 사용되므로 생락할 수 있다.
  * 즉, ls에 대해서 도움말을 출력하려면 __man 1 ls__ 또는 __man ls__ 를 하면 된다.
  * 섹션(Section) : 종류
    * (1) 사용자 명령어
    * (2) Syscall API (System Call)
    * (3) C Library
    * (4) 특수 파일 (Device 관련)
    * (5) File Format
    * (6) Game, Media File
    * (7) 그 외 여러 종류
    * (8) 시스템 관리용 명령어

* 최근에는 명령어의 타입에 관계없이 --help 옵션을 지원하고 있는 추세이다.
<hr/>

<h2>표준 스트림</h2>

* Linux에서 표준 스트림이란, 사용자의 터미널(모니터와 키보드가 연결된 단말기)   
  사이에 미리 연결된 입출력의 통로 또는 흐름이다.
* 터미널의 입출력은 일반적으로 키보드와 모니터를 통해 일어나는데, 표준 스트림은   
  이를 추상화한 개념이다.
* C언어와 비교해보자.
<table>
    <tr>
        <td>C언어의 스트림</td>
        <td>bash의 스트림</td>
    </tr>
    <tr>
        <td>stdin</td>
        <td>0(표준 입력)</td>
    </tr>
    <tr>
        <td>stdout</td>
        <td>1(표준 출력)</td>
    </tr>
    <tr>
        <td>stderr</td>
        <td>2(표준 에러)</td>
    </tr>
</table>

  * 표준 입력 : 입력을 위한 스트림으로, 쉘에서는 0으로 표현
  * 표준 출력 : 출력을 위한 스트림으로, 쉘에서는 1로 표현
  * 표준 오류 : 오류 출력을 위한 스트림으로, 쉘에서는 2로 표현
  * 위 3가지 스트림 중 stderr만 버퍼가 없다.
<hr/>

<h2>Redirection</h2>

* 쉘에서 제공하는 기능으로, 실행되는 명령어에 대하여 표준 스트림을 변경할 수 있는 개념이다.

* (1) Standard Output Redirection
  * 표준 출력을 redirect하는 방법 : __명령어 > 파일명__
  * 주의(1) : 파일에 내용이 있다면 기존 내용은 지워지고 덮어씌워진다.
  * 주의 (2) : 명령어 실행 도중 오류 발생 시, 오류 메시지는 표준 오류로 보내지고,   
  출력 파일은 초기화된다.
  * 위는 출력 리다이렉션의 특징으로, 기존 파일이 존재할 경우 이를 삭제하고   
  다시 파일을 생성하기 때문에 주의해야 한다.
  * 다수의 명령에 대한 출력 재지정 방법
    * (cmd1; cmd2; cmd3;...) > fileName
  * 기존 파일의 내용을 유지하고, 추가적으로 명령의 결과를 붙이고 싶은 경우
    * cmd >> fileName
  * cat 명령어를 이용하여 출력 리다이렉션을 활용할 수 있다.
    * cat file1 file2 [file3, ...] > newFile
    * 이 때, __와일드 카드__ 사용 시, __파일명은 오름차순으로 정렬__ 된다.

* (2) Standard Input Redirection
  * 표준 입력을 키보드가 아닌 파일로부터 입력받을 때 사용한다.
  * 사용법 : 명령어 __<__ 파일명

  * Here Document
  * 입력 재지정의 추가적인 형태로, 다수의 text를 명령어의 표준 입력으로    동시에 보낼 때 사용한다.
    * 사용 방법 : __명령어 << 식별자__ 문자열 입력.. __식별자__ 
    * 식별자 : 문자열의 끝을 알리기 위해 사용자가 임의로 지정한 것.

* (3) Standard Error Redirection
  * 표준 오류를 redirect하는 방법 : __명령어 2> 파일명__
    * ex) ls adsfasdfasdf 2> error.txt
  * 표준 오류 재지정도 표준 출력 재지정과 같이 기존 파일의 내용을 덮어씌운다.

* 표준 출력과 표준 입력 재지정은 한번에 사용할 수 있다.
  * ex) cat < error.txt > error_copy.txt
    * error_copy.txt와 error.txt의 내용이 동일하다.
* 표준 출력과 표준 오류를 모두 하나의 파일에 저장하고 싶을 경우
  * __>&__ 사용
<hr/>

<h2>Pipelining</h2>

* 현재 directory에 있는 파일의 수를 알고 싶다면?
  * ls > list.txt; wc -w list.txt; rm list.txt
  * 위는 불필요하게 임시 파일이 생성되었다는 단점이 있다.
  * 이러한 문제를 조금 더 편하게 하기 위해 등장한 것이 pipeline 이다.
  * 위의 문제를 pipeline으로 조합하면 __ls | wc -w__ 가 된다.
* Pipeline은 __|__ 기호를 사용함으로써 어떤 명령어의 출력을 다른 명령어의 입력으로 전송하는 메커니즘이다.

* tee 명령어 : pipe에서 어떤 명령어의 출력을 다른 명령어의 입력과 파일로 동시에 출력하는 명령어
* ex) ls | wc - w는 ls의 출력이 pipe를 통해 wc -w로 가는 것이다.
* 이 때, ls에서 출력된 결과를 wc -w에도 보내고, 파일에도 보내고 싶다면   
  __ls | tee result.txt | wc -w__ 처럼 하면 된다.
  * 위는 ls의 결과는 result.txt로 redirect하고, wc -w에도 전송한 것이다.
  * tee 다음에는 여러 개의 파일이 올 수 있다.

* 파이프는 이름이 존재하는 named pipe와 이름이 없는 unnamed pipe가 있다.
* 위에서 살펴본 | 는 unnamed pipe이다.

* 이름이 있는 파이프(Named Pipe)
  * 생성 방법 : mkfifo 파일명
  * 이는 물리적인 시스템(HDD, SSD)에 파일명으로 파이프를 만든다.
<hr/>

<h2>확장 및 인용</h2>

* 확장
  * 쉘은 명령어가 입력되면 이를 수행하기 전에 입력된 text에 대하여 전처리를 수행한다.
  * (1) 경로명 확장 : *, ?, []가 임의의 문자로 이루어진 파일명으로 확장하는 것.
  * (2) 틸드 확장 : ~가 현재 사용자의 홈 directory명으로 확장되는 것.
  * (3) 변수 확장 : $기호를 사용하여 변수명을 변수가 가진 값으로 확장하는 것.
    * 변수의 선언 및 초기화 방법 : __변수명=값__ 
    * ex) name=thisisname; echo $name -> thisisname 출력
    * ex) name=thisisname; echo name -> name 출력
    * 주의 : 대입 연산자의 앞뒤에 공백이 오면 안된다.
  * (4) 산술 확장 : 쉘이 제공하는 기본적인 연산의 결과로 확장되는 것.
    * ex) echo $((1+1))
    * 주의 : 부동소수점 연산은 불가하다.
  * (5) 명령어 확장 : 명령어의 출력 결과를 확장하는 것.
    * ex) echo `ls -l` 또는 echo $(ls -l)
    * ex) ls의 명령어에 대한 정보를 알고 싶다면 __ls -l $(which ls)__
  * (6) 중괄호 확장 : 중괄호 내에 포함된 패턴과 일치하는 문자열로 확장하는 것.
    * ex) echo file.{1,2} --> file.1 file.2 출력
    * ex) touch file.{1,2,3} --> file.1 file.2 file.3이 생김
    * 주의 : 콤마의 앞뒤에 공백이 있으면 안된다.
    * 단축 표기법
      * {0,1,2,3,4,5,6,7,8,9}를 단축 표기법으로 {0..9}로 할 수 있다.
      * 단축 표기법은 숫자 뿐만 아니라 대소문자의 영문자도 가능하다.
    * 중괄호는 1개 이상 사용 가능하며, 중첩도 가능하다.
      * ex) echo {0..9}{A..Z}
      * ex) echo _{A{1,2},B{3,4}} --> _A1 _A2 _B3 _B4 출력

* 인용
  * 쉘에서의 인용 부호 사용법 : ' ' 또는 " "
  * (1) 큰 따옴표(" ")
    * echo hello,          world를 하면 hello, world가 출력된다.   
      이는 쉘이 불필요한 공백을 제거했기 때문이다.
    * 쉘은 기본적으로 공백과 탭을 사용하여 토큰을 구분하는데, 추가적인 공백이나   
    탭의 경우 불필요하므로 이를 제거한다.
    * 사용하는 이유
      * (1) 공백과 탭을 토큰 구분 목적이 아닌, 단순 문자로 해석하기 원할 때
      * (2) 메타 문자를 단순 문자로 취급하기를 원할 때
      * (3) 작은 따옴표를 인용 부호가 아닌 단순 문자로 취급하기를 원할 때
    * 예외
      * (1) 명령어의 치환은 그대로 동작한다.
        * ex) echo "`ls`", echo "$(ls)"
      * (2) 매개변수의 치환, 확장은 그대로 동작한다.
        * ex) echo "$HOME"
      * (3) 백슬래시(\)는 그대로 동작한다.
        * ex) echo $HOME --> /home/linux 출력
        * ex) echo \$SHOME --> $HOME 출력
        * ex) echo "$HOME" --> /home/linux 출력
        * ex) echo "\$HOME" --> $HOME 출력
  * (2) 작은 따옴표 (' ')
    * 사용하는 이유
      * (1) 큰 따옴표와 같은 이유가 있다.
      * (2) 작은 따옴표 안의 모든 문자를 확장 또는 치환 없이 문자 그대로 처리할 때 사용한다.
      * 단, 큰 따옴표와 같이 예외가 없이 모든 경우를 다 문자 그대로 처리한다.
  * (3) 백슬래시(\) : 탈출 문자의 역할 뿐만 아니라 __제어 문자__ 를 표현하는데에도 사용한다.
    <table>
        <tr>
            <td>\a</td>
            <td>벨 소리(사용X)</td>
        </tr>
        <tr>
            <td>\b</td>
            <td>BackSpace</td>
        </tr>
        <tr>
            <td color="red">\n</td>
            <td color="red">개행</td>
        </tr>
        <tr color="red">
            <td>\r</td>
            <td>행의 시작위치로 복귀</td>
        </tr>
        <tr>
            <td color="red">\t</td>
            <td color="red">Tab</td>
        </tr>
    </table>
      * 탈출 문자가 포함된 문자열을 __확장 문자열__ 이라 한다.
      * 확장 문자열을 단순 문자열이 아닌 확장 문자열로 해석하기를 원한다면   
        echo에 __-e 옵션__ 을 주어야 한다.
        * ex) echo -e "Hi\nHello"
<hr/>

<h2>탐색</h2>

* (1) 파일 시스템 내의 특정 파일 탐색 --> find
  * 다른 명령들은 하위 directory에 대하여 처리하려면, 재귀 옵션을 주어야 하는데,   
  find 명령어는 별도의 옵션 없이 하위 directory까지 검색한다.
  * 권한 오류 등의 오류를 처리할 때는 다음과 같이 한다.
    * __find / -name '*.c' 2> /dev/null__
    * /dev/null은 필요 없는 파일을 덤프하는 일종의 블랙홀 개념이다.

  * find 명령어의 사용법 (기본 : find [경로] findName)
    * (1) test : 일종의 검색 옵션
      * (1) name : 패턴과 일치하는 file 및 dir 검색 시 사용하는 옵션
        * 사용법 : find -name 'pattern';
        * pattern은 메타 문자가 포함된 문자열을 의미한다.
        * ex) find -name '*.txt'
        * __주의 : 메타 문자 포함 시, 반드시 작은 따옴표로 감싸야 한다.__
      * (2) iname : name과 동일하나 대소문자를 무시하고 검색한다.
      * (3) size N : 크기가 N인 파일을 검색한다.
      * (4) type T : T 형식의 파일을 검색한다.
        * T에 들어갈 수 있는 항목들
        <table>
            <tr>
                <td>d</td>
                <td>Directory를 검색</td>
            </tr>
            <tr>
                <td>f</td>
                <td>File을 검색</td>
            </tr>
            <tr>
                <td>l</td>
                <td>Symbolic Link를 검색</td>
            </tr>
            <tr>
                <td>b</td>
                <td>Block Device를 검색</td>
            </tr>
            <tr>
                <td>c</td>
                <td>Character Device를 검색</td>
            </tr>
            <tr>
                <td>p</td>
                <td>Pipe를 검색</td>
            </tr>
            <tr>
                <td>s</td>
                <td>Socket을 검색</td>
            </tr>
        </table>
        * ex) find . -name '*.txt' -type l 
        * 위는 현재 위치에서 .txt로 끝나고 타입이 Symbolic Link인 것을 찾는다.
      * (5) empty : 빈 파일만 검색한다.

    * (2) 연산자(Operator) : 테스트 간의 논리적인 연산 수행
      * -and, -a : 연산자를 기준으로 양쪽 조건이 참인 경우에만 검색 수행
        * 아무런 연산자가 없을 경우, 이 연산자가 자동으로 수행된다.
        * ex) find . -name '*.txt' -and -type f -and -empty
        * ex) find . -name '*.txt' -a -type f -a -empty
        * ex) find . -name '*.txt' -type f -empty 
          * 위 3개는 모두 동일한 결과를 가져온다.
      * -or, -o : 연산자를 기준으로 양쪽 조건 중 하나라도 참인 경우 검색 수행
        * ex) find . -name '*.c' -or -name '*.cpp' -and -type f
        * ex) find . -name '*.c' -o -name '*.cpp' -type f
          * 위는 확장자가 .c이거나 .cpp인 파일을 검색한다.
      * -not, -! : 단항 연산자로, 우측 조건이 거짓인 경우에 검색 수행
        * ex) find . -name '*.c' -a -type f -a -not -empty
        * 위는 확장자가 .c이고 크기가 0이 아닌 파일을 검색한다.
      * -() : 조건과 연산자를 조합한 표현식을 하나로 묶어 처리할 때 사용
        * 주의 : 명령어의 인자로 전달되도록(전처리 되지 않도록) 백슬래시   
            를 사용해야 하고, 반드시 앞뒤에 공백이 있어야 한다.
        * ex) find . -name '*.c' -o -name '*.cpp' -type f
        * ex) find . \( -name '*.c' -o -name '*.cpp' \) -a -type f
        * ex) find . \( -name '*.c' -o -name '*.cpp' \) -type f

    * (3) 액션(Action) : find명령에 대한 결과 처리 방식 결정
      * (1) 미리 정의된 액션(Pre-defined Action)
        * print : 검색 결과를 상대 경로를 포함하여 출력하는 액션 
          * print는 별도의 액션을 설정 또는 사용하지 않으면 참인 표현식에   
            대해 암묵적으로 사용된다.   
            (액션은 기본적으로 참으로 해석된다.)
          * ex) find . -name 'log*' -type f -empty
          * ex) find . -name 'log*' -a -type f -a -empty -a -print
          * print가 명시적으로 쓰인 코드가 두번 째 코드이다.
        * delete : 검색된 결과를 삭제하는 액션
          * ex) 확장자가 .c인 일반 파일이며 크기가 0인 것을 검색하고,   
            검색 결과로 나온 것들을 삭제한다.
          * find . -name '*.c' -a -type f -a -empty -a -delete

      * (2) 사용자 정의 액션(Custom Action)
        * -exec : 검색된 결과에 대하여 지정된 명령 실행
        * 사용법 : -exec 명령어\{}\;
          * ; 는 Custom Action의 끝을 의미한다.
          * ex) 빈 디렉토리에 대해서만 삭제 수행
          * ex) find . -type d -empty -and -exec rmdir \{} \;
            * 위 예시는 찾은 것에 대하여 각각 rmdir명령을 수행한다.
            * 이를 효율적으로 하기 위해 한번에 찾고 찾은 것들에 대하여   
                rmdir를 한 번 실행하도록 하려면 다음과 같이 한다.
            * find . -name '*.c' -empty -exec rm \{} \+
    * (4) 옵션(Option) : find명령의 검색이 범위를 설정할 때 사용
      * 기본적으로 find는 시작 위치부터 최하위까지 모두 검색한다.
      * 이 때, 검색 범위를 제한하고 싶을 때 __maxdepth__ 옵션을 사용한다.
      * maxdepth : test와 action 실행 시, directory의 최대 탐색 깊이를   
        숫자로 지정한다.
        * 주의 : maxdepth는 반드시 test와 action이 수행되기 전에 지정하라.
        * ex) find . -maxdepth 1 -type f -empty
        * 위 예시는 현재 위치에서만 빈 파일만을 검색한다.

* (2) 파일 내의 특정 토큰 탐색 --> grep
  
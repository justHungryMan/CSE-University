# Web Crawling using Python

This document is about how we crawl the web using Python  

---
## Index
1. [Install Python library](#Install)
2. [Web Crawling](#Crawling)
3. [BeautifulSoup4](#BeautifulSoup4)

<a id = "Install"></a>
## 1. Install Python library
* Ubuntu
  1. `sudo apt-get update`
  2. `sudo apt-get install python3-pip`
  3. `pip3 install requests`
* Mac
  1. AppStore에서 Xcode 설치
  2. Homebrew 설치 : `/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`
  3. `export PATH=/usr/local/bin:/usr/local/sbin:$PATH`
  4. `brew install python3`
  5. `pip3 install requests`

<a id = "Crawling"></a>

## 2. Web Crawling  
1. `import requests` : requests를 import 해옴
2. `r = requests.get("http://cspro.sogang.ac.kr/")`
3. `print(r.content)`
  * result
  ```html
  b'<!DOCUTYPE HTML>\n<META http-equiv="Content-Type" content="text/html;charset=UTF-8">\n<meta http-equiv="X-UA-Compatible" content="IE=edge" /> \n<html LANG="ko" xml:lang="ko" xmlns="http://www.w3.org/1999/xhtml">\n<head>\n<style>\n\nbody {\nfont-family: "Arial", sans-serif;\nbackground: url("img/ui_img01.jpg");\nbackground-size: 15% ;\nbackground-repeat: no-repeat;\nbackground-position: center;\n}\nul.tab {\n    list-style-type: none;\n    margin: 0;\n    padding: 0;\n    overflow: hidden;\n    border: 1px solid #ccc;\n    background-color: #f1f1f1;\n}\n\n/* Float the list items side by side */\nul.tab li {float: left;}\n\n/* Style the links inside the list items */\nul.tab li a {\n    display: inline-block;\n    color: black;\n    text-align: center;\n    padding: 14px 16px;\n    text-decoration: none;\n    transition: 0.3s;\n    font-size: 17px;\n}\n\n/* Change background color of links on hover */\nul.tab li a:hover {\n    background-color: #ddd;\n}\n\n/* Create an active/current tablink class */\nul.tab li a:focus, .active {\n    background-color: #ccc;\n}\n\n/* Style the tab content */\n.tabcontent {\n    display: none;\n    padding: 6px 12px;\n    border: 1px solid #ccc;\n    border-top: none;\n}\n</style>\n</head>\n<body>\n<h1>CSPro: <a href="http://cse.sogang.ac.kr" target="_blank"> \xec\x84\x9c\xea\xb0\x95\xeb\x8c\x80\xed\x95\x99\xea\xb5\x90 \xec\xbb\xb4\xed\x93\xa8\xed\x84\xb0\xea\xb3\xb5\xed\x95\x99\xea\xb3\xbc</a>\xec\x8b\xa4\xec\x8a\xb5\xec\x84\x9c\xeb\xb2\x84</h1>\n<p>!!** MS Edge User **!! Uncheck the "Use Microsoft compatibility lists" box </p> \n<ul class="tab">\n<li><a href="javascript:void(0)" class="tablinks" onclick="openMNL(event, \'connect\')" id="defaultOpen">\xec\xa0\x91\xec\x86\x8d</a></li>\n<li><a href="javascript:void(0)" class="tablinks" onclick="openMNL(event, \'account\')">\xea\xb3\x84\xec\xa0\x95\xec\x8b\xa0\xec\xb2\xad</a></li>\n<li><a href="javascript:void(0)" class="tablinks" onclick="openMNL(event, \'htmlDir\')">html\xeb\x94\x94\xeb\xa0\x89\xed\x86\xa0\xeb\xa6\xac\xec\x82\xac\xec\x9a\xa9</a></li>\n<li><a href="javascript:void(0)" class="tablinks" onclick="openMNL(event, \'contact\')">\xec\x8b\xa4\xec\x8a\xb5\xec\x84\x9c\xeb\xb2\x84 \xea\xb4\x80\xeb\xa0\xa8 \xeb\xac\xb8\xec\x9d\x98</a></li>\n</ul>\n<div id="connect" class="tabcontent">\n<p>================\xec\x8b\xa4\xec\x8a\xb5 \xec\x84\x9c\xeb\xb2\x84 ssh \xec\xa0\x91\xec\x86\x8d ==================</p>\n<p>****\xeb\xb3\xb4\xec\x95\x88 \xec\xa0\x95\xec\xb1\x85\xec\x83\x81 ssh\xeb\x8a\x94 <b>\xea\xb3\xb5\xec\x9d\xb8 \xec\x95\x84\xec\x9d\xb4\xed\x94\xbc</b>\xec\x97\x90\xec\x84\x9c\xeb\xa7\x8c  \xec\xa0\x91\xec\x86\x8d\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xec\x8a\xb5\xeb\x8b\x88\xeb\x8b\xa4****</p>\n<p>\xea\xb3\x84\xec\xa0\x95 \xec\x8b\xa0\xec\xb2\xad  \xeb\xb0\x8f \xec\x8b\xa4\xec\x8a\xb5 \xea\xb4\x80\xeb\xa0\xa8 \xec\x82\xac\xed\x95\xad\xec\x9d\x80 <b>"<u>\xec\x88\x98\xec\x97\x85 \xec\xa1\xb0\xea\xb5\x90</u>"</b>\xec\x97\x90\xea\xb2\x8c \xeb\xac\xb8\xec\x9d\x98 \xed\x95\x98\xec\x84\xb8\xec\x9a\x94</p>\n<p>\n</div>\n\n<div id="account" class="tabcontent">\n<p>================\xea\xb3\x84\xec\xa0\x95 \xec\x8b\xa0\xec\xb2\xad \xeb\xb0\xa9\xeb\xb2\x95==================</p>\n<p>cse.sogang.ac.kr \xec\xa0\x91\xec\x86\x8d \xed\x9b\x84  \xec\xbb\xa4\xeb\xae\xa4\xeb\x8b\x88\xed\x8b\xb0->\xec\x96\x91\xec\x8b\x9d\xed\x95\xa8:<a href="http://cse.sogang.ac.kr/bbs/board.php?bo_table=05_02&wr_id=2" target="_blank">\xec\xbb\xb4\xed\x93\xa8\xed\x84\xb0\xea\xb3\xb5\xed\x95\x99\xea\xb3\xbc \xec\x8b\xa4\xec\x8a\xb5 \xec\x84\x9c\xeb\xb2\x84 \xea\xb3\x84\xec\xa0\x95 \xec\x8b\xa0\xec\xb2\xad\xec\x84\x9c</a></p>\n<p>\xea\xb2\x8c\xec\x8b\x9c \xeb\x82\xb4\xec\x9a\xa9\xec\x97\x90 \xeb\x94\xb0\xeb\x9d\xbc <b>"<u>\xec\x88\x98\xec\x97\x85 \xec\xa1\xb0\xea\xb5\x90</u>"</b>\xea\xb0\x80 \xec\x8b\xa0\xec\xb2\xad\xec\x84\x9c\xeb\xa5\xbc \xec\x9e\x91\xec\x84\xb1\xed\x95\x98\xec\x97\xac \xec\x9d\xbc\xea\xb4\x84 \xec\x8b\xa0\xec\xb2\xad</p>\n</div>\n\n<div id="htmlDir" class="tabcontent">\n<p>==========\xea\xb3\x84\xec\xa0\x95\xeb\xb3\x84 public_html \xec\x82\xac\xec\x9a\xa9\xeb\xb0\xa9\xeb\xb2\x95(cspro\xeb\xa7\x8c \xea\xb0\x80\xeb\x8a\xa5)==========</p>\n<p>$ mkdir ~/public_html</p>\n<p>$ chmod 711 ~/</p>\n<p>$ chmod 755 ~/public_html</p>\n<p>$ cd ~/public_html</p>\n<p> index.html \xed\x8c\x8c\xec\x9d\xbc\xec\x97\x90 \xec\x9b\x90\xed\x95\x98\xeb\x8a\x94 \xeb\x82\xb4\xec\x9a\xa9 \xec\x9e\x91\xec\x84\xb1 \xed\x9b\x84</p>\n<p> index.html\xec\x97\x90 chmod\xeb\xaa\x85\xeb\xa0\xb9\xec\x9d\x84 \xec\x82\xac\xec\x9a\xa9\xed\x95\x98\xec\x97\xac \xec\x9d\xbd\xea\xb8\xb0 \xea\xb6\x8c\xed\x95\x9c\xec\x9d\x84 \xeb\xb6\x80\xec\x97\xac\xed\x95\x98\xea\xb3\xa0</p>\n<p> \xec\x9b\xb9 \xeb\xb8\x8c\xeb\x9d\xbc\xec\x9a\xb0\xec\xa0\x80 \xec\xa3\xbc\xec\x86\x8c\xec\xb0\xbd\xec\x97\x90</p>\n<p> http://cspro.sogang.ac.kr/~\xec\x9e\x90\xec\x8b\xa0\xec\x9d\x98\xeb\xa1\x9c\xea\xb7\xb8\xec\x9d\xb8\xec\x95\x84\xec\x9d\xb4\xeb\x94\x94</p>\n<p> \xeb\xa5\xbc \xec\x9e\x85\xeb\xa0\xa5\xed\x95\x98\xeb\xa9\xb4 \xeb\x90\xa9\xeb\x8b\x88\xeb\x8b\xa4</p>\n<p> cgi\xeb\xa5\xbc \xec\x8b\xa4\xec\x8a\xb5\xed\x95\x98\xea\xb3\xa0\xec\x9e\x90 \xed\x95\xa0 \xeb\x95\x8c\xec\x97\x90\xeb\x8a\x94 </p>\n<p>$ mkdir -p ~/public_html/cgi-bin</p>\n<p> \xec\x9c\xbc\xeb\xa1\x9c \xeb\x94\x94\xeb\xa0\x89\xed\x86\xa0\xeb\xa6\xac \xec\x83\x9d\xec\x84\xb1 \xed\x9b\x84 \xed\x95\x84\xec\x9a\x94\xed\x95\x9c \xea\xb6\x8c\xed\x95\x9c\xec\x9d\x84 \xec\x84\xa4\xec\xa0\x95\xed\x95\x98\xea\xb3\xa0 \xec\x82\xac\xec\x9a\xa9\xed\x95\x98\xeb\xa9\xb4 \xeb\x90\xa9\xeb\x8b\x88\xeb\x8b\xa4 </p>\n<p> \xec\x83\x81\xec\x84\xb8\xed\x95\x9c \xeb\x82\xb4\xec\x9a\xa9\xec\x9d\x80 \xec\x88\x98\xec\x97\x85 \xeb\x8b\xb4\xeb\x8b\xb9 \xec\xa1\xb0\xea\xb5\x90\xeb\xa5\xbc \xed\x86\xb5\xed\x95\xb4 \xed\x99\x95\xec\x9d\xb8 \xeb\xb0\x94\xeb\x9e\x8d\xeb\x8b\x88\xeb\x8b\xa4</p>\n<p></p>\n</div>\n<div id="contact" class="tabcontent">\n<p>================\xec\x8b\xa4\xec\x8a\xb5 \xec\x84\x9c\xeb\xb2\x84 \xea\xb4\x80\xeb\xa0\xa8 \xeb\xac\xb8\xec\x9d\x98==================</p>\n<p>\xec\x88\x98\xec\x97\x85\xec\x8b\x9c\xea\xb0\x84 : \xec\x88\x98\xec\x97\x85 \xeb\x8b\xb4\xeb\x8b\xb9 \xec\xa1\xb0\xea\xb5\x90</a></p>\n</div>\n<script>\ndocument.getElementById("defaultOpen").click();\n\nfunction openMNL(evt, cityName) {\n\tvar i, tabcontent, tablinks;\n\ttabcontent = document.getElementsByClassName("tabcontent");\n\tfor (i = 0; i < tabcontent.length; i++) {\n\t\ttabcontent[i].style.display = "none";\n\t}\n\ttablinks = document.getElementsByClassName("tablinks");\n\tfor (i = 0; i < tablinks.length; i++) {\n\t\ttablinks[i].className = tablinks[i].className.replace(" active", "");\n\t}\n\tdocument.getElementById(cityName).style.display = "block";\n\tevt.currentTarget.className += " active";\n}\n</script>\n\n</body></html>\n'
  ```
  python3에서는 기본적으로 UNICODE를 사용하기 때문에 한글로 decoding해야한다.
 4. print(r.content.decode('utf-8'))
   * result
   ```html
   <!DOCUTYPE HTML>
<META http-equiv="Content-Type" content="text/html;charset=UTF-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge" />
<html LANG="ko" xml:lang="ko" xmlns="http://www.w3.org/1999/xhtml">
<head>
<style>

body {
font-family: "Arial", sans-serif;
background: url("img/ui_img01.jpg");
background-size: 15% ;
background-repeat: no-repeat;
background-position: center;
}
ul.tab {
    list-style-type: none;
    margin: 0;
    padding: 0;
    overflow: hidden;
    border: 1px solid #ccc;
    background-color: #f1f1f1;
}

/* Float the list items side by side */
ul.tab li {float: left;}

/* Style the links inside the list items */
ul.tab li a {
    display: inline-block;
    color: black;
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;
    transition: 0.3s;
    font-size: 17px;
}

/* Change background color of links on hover */
ul.tab li a:hover {
    background-color: #ddd;
}

/* Create an active/current tablink class */
ul.tab li a:focus, .active {
    background-color: #ccc;
}

/* Style the tab content */
.tabcontent {
    display: none;
    padding: 6px 12px;
    border: 1px solid #ccc;
    border-top: none;
}
</style>
</head>
<body>
<h1>CSPro: <a href="http://cse.sogang.ac.kr" target="_blank"> 서강대학교 컴퓨터공학과</a>실습서버</h1>
<p>!!** MS Edge User **!! Uncheck the "Use Microsoft compatibility lists" box </p>
<ul class="tab">
<li><a href="javascript:void(0)" class="tablinks" onclick="openMNL(event, 'connect')" id="defaultOpen">접속</a></li>
<li><a href="javascript:void(0)" class="tablinks" onclick="openMNL(event, 'account')">계정신청</a></li>
<li><a href="javascript:void(0)" class="tablinks" onclick="openMNL(event, 'htmlDir')">html디렉토리사용</a></li>
<li><a href="javascript:void(0)" class="tablinks" onclick="openMNL(event, 'contact')">실습서버 관련 문의</a></li>
</ul>
<div id="connect" class="tabcontent">
<p>================실습 서버 ssh 접속 ==================</p>
<p>****보안 정책상 ssh는 <b>공인 아이피</b>에서만  접속할 수 있습니다****</p>
<p>계정 신청  및 실습 관련 사항은 <b>"<u>수업 조교</u>"</b>에게 문의 하세요</p>
<p>
</div>

<div id="account" class="tabcontent">
<p>================계정 신청 방법==================</p>
<p>cse.sogang.ac.kr 접속 후  커뮤니티->양식함:<a href="http://cse.sogang.ac.kr/bbs/board.php?bo_table=05_02&wr_id=2" target="_blank">컴퓨터공학과 실습 서버 계정 신청서</a></p>
<p>게시 내용에 따라 <b>"<u>수업 조교</u>"</b>가 신청서를 작성하여 일괄 신청</p>
</div>

<div id="htmlDir" class="tabcontent">
<p>==========계정별 public_html 사용방법(cspro만 가능)==========</p>
<p>$ mkdir ~/public_html</p>
<p>$ chmod 711 ~/</p>
<p>$ chmod 755 ~/public_html</p>
<p>$ cd ~/public_html</p>
<p> index.html 파일에 원하는 내용 작성 후</p>
<p> index.html에 chmod명령을 사용하여 읽기 권한을 부여하고</p>
<p> 웹 브라우저 주소창에</p>
<p> http://cspro.sogang.ac.kr/~자신의로그인아이디</p>
<p> 를 입력하면 됩니다</p>
<p> cgi를 실습하고자 할 때에는 </p>
<p>$ mkdir -p ~/public_html/cgi-bin</p>
<p> 으로 디렉토리 생성 후 필요한 권한을 설정하고 사용하면 됩니다 </p>
<p> 상세한 내용은 수업 담당 조교를 통해 확인 바랍니다</p>
<p></p>
</div>
<div id="contact" class="tabcontent">
<p>================실습 서버 관련 문의==================</p>
<p>수업시간 : 수업 담당 조교</a></p>
</div>
<script>
document.getElementById("defaultOpen").click();

function openMNL(evt, cityName) {
	var i, tabcontent, tablinks;
	tabcontent = document.getElementsByClassName("tabcontent");
	for (i = 0; i < tabcontent.length; i++) {
		tabcontent[i].style.display = "none";
	}
	tablinks = document.getElementsByClassName("tablinks");
	for (i = 0; i < tablinks.length; i++) {
		tablinks[i].className = tablinks[i].className.replace(" active", "");
	}
	document.getElementById(cityName).style.display = "block";
	evt.currentTarget.className += " active";
}
</script>

</body></html>
   ```

<a id = "BeautifulSoup4"></a>
## 3. BeautifulSoup4  
용도 : http 문서의 tag를 이용하여 원하는 정보를 얻는다.
* 설치 : `pip3 install beautifulsoup4`
* **practice1 Code**
```python
import requests
from bs4 import BeautifulSoup
r = requests.get('http://cspro.sogang.ac.kr')
soup = BeautifulSoup(r.content, "html.parser")
results = soup.find_all('a')

for element in results:
    print(element.get_text())

for element in results:
    print(element.get('href'))
```
* result
```
서강대학교 컴퓨터공학과
접속
계정신청
html디렉토리사용
실습서버 관련 문의
컴퓨터공학과 실습 서버 계정 신청서
http://cse.sogang.ac.kr
javascript:void(0)
javascript:void(0)
javascript:void(0)
javascript:void(0)
http://cse.sogang.ac.kr/bbs/board.php?bo_table=05_02&wr_id=2
```
* 네이버 기사 crawling 하기
```python
import requests
from bs4 import BeautifulSoup

r = requests.get("http://news.naver.com/main/read.nhn?mode=LSD&mid=shm&sid1=105&oid=277&aid=0003987954")
soup = BeautifulSoup(r.content, "html.parser")
results = soup.find_all('div', id = 'articleBodyContents')

for i in results:
        print(i.get_text())
```
* results
```
// flash 오류를 우회하기 위한 함수 추가
function _flash_removeCallback() {}

미국 국제무역위원회에 제소 준비 중…애플 현재 특허료 지급 중단 퀄컴[아시아경제 임온유 기자] 퀄컴이 특허료를 놓고 법적 다툼 중인 애플에 반격을 시작한다. 퀄컴은 미국 국제무역위원회(ITC)에 아이폰이 미국 시장에 들어오지 못하게 해달라고 요청할 계획이다. 3일(현지시간) 블룸버그통신은 소식통을 인용해 "퀄컴이 아이폰의 미국 수입을 막아달라고 ITC에 제소하기 위해 준비 중"이라고 보도했다. 아이폰은 중국 등 아시아 지역에서 생산되고 있다. ITC는 워싱턴에 있는 준사법기관으로 상품의 미국 수입을 금지할 권한이 있다. 연방 지방법원보다 사건 처리가 빠른 것이 장점으로 꼽힌다.퀄컴의 제소가 성공하면 미국 시장에서 아이폰의 판로가 막히게 된다. 블룸버그는 "애플이 지난달 말 스마트폰 칩 특허료 지급을 중단하자 퀄컴이 반격한 것"이라고 풀이했다. 퀄컴이 보유한 특허는 데이터를 빠른 속도로 송수신하는 스마트폰에 모두 적용된다. 퀄컴은 해당 기기가 자사 칩을 사용하든 아니든 간에 전체 기기 판매 가격의 1%를 특허료로 받고 있다. 애플은 이런 체계가 부당하며, 퀄컴이 특허를 무기로 반도체 부문을 불법적으로 지원했다고 주장해왔다.팀 쿡 애플 최고경영자(CEO)는 전날 실적 콘퍼런스콜에서 "퀄컴이 특허 사용 계약 규정에서 요구하는 정당한 조건을 제시하지 않았다"고 말했다.현재 아이폰에는 네트워크 접속을 위한 인텔과 퀄컴의 모뎀이 들어간다. 아이폰 7 출시 전까지 퀄컴이 독점적인 공급업체였다. ITC가 어떤 결정을 내릴지는 예상하기 어렵다. 법률회사 오블론의 특허 변호사 알렉스 하지스는 특허의 산업 기준 기여에 대한 규정이 모호하다면서도 ITC의 이전 판결을 보면 "특허 소유자에 유리한 결과가 나올 수 있다"고 말했다. 퀄컴은 영국과 독일, 중국에서도 법원에 소송을 낼 가능성이 있다.임온유 기자 ioy@asiae.co.kr▶ 뉴스가 재밌다! 세상의 모든 재미 [티잼]▶ 인기최신만화  ▶ 오늘의 띠별, 별자리 운세<ⓒ세계를 보는 창 경제를 보는 눈, 아시아경제 무단전재 배포금지>
```

import requests
from bs4 import BeautifulSoup

r = requests.get("http://news.naver.com/main/read.nhn?mode=LSD&mid=shm&sid1=105&oid=277&aid=0003987954")
soup = BeautifulSoup(r.content, "html.parser")
results = soup.find_all('div', id = 'articleBodyContents')
for i in results:
        print(i.get_text())

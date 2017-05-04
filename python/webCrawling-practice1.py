import requests
from bs4 import BeautifulSoup
r = requests.get('http://cspro.sogang.ac.kr')
soup = BeautifulSoup(r.content, "html.parser")
results = soup.find_all('a')

for element in results:
    print(element.get_text())

for element in results:
    print(element.get('href'))

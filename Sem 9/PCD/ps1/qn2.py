import httpx
from bs4 import BeautifulSoup

res = httpx.get('https://stackoverflow.com/')
html = res.text
print("Before removing")
print(html)

cleaned = BeautifulSoup(html, "lxml").text
print("After removing:")
print(cleaned)

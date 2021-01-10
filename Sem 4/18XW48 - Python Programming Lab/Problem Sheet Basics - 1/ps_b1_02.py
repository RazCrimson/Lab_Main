count = int(input("Please enter the number of websites: "))
sites = [input() for _ in range(count)]
[print(site.split(".")[-1]) for site in sites]
class LittleElephantAndBooks:
 def getNumber(self, pages, number):
    pages = sorted(pages)
    # sum of number-1 smallest elements + pages[number]:
    return sum(x for x in pages[0:number-1]) + pages[number]
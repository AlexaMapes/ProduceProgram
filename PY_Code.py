import re
import string
from collections import Counter
import os.path

# Creates a dictionary of each item and its frequency
produceFile = open("InputFile.txt")
produceFileContent = produceFile.read()

produceRecord = produceFileContent.split("\n")

produceFile.close()

produceCounter = Counter(produceRecord)

# Creates a new file with each item and its frequency
def createFile():
    save_path = r"C:\Users\Lexi\Documents\School\Programming Languages\Project_Three\Project_Three"
    file_name = "frequency.dat"

    completeName = os.path.join(save_path, file_name)

    newFile = open(completeName, "w")

    for x, y in produceCounter.items():
        newFile.write("{} {}\n".format(x, y))

    newFile.close()

# Prints the frequency list
def frequencyList():
    print("\n")

    for x, y in produceCounter.items():
        print("{}: {}".format(x, y))

    print("\n")

# Prints how many times a particular item was purchased
def itemSearch(t_itemToSearch):
    x = produceCounter.get(t_itemToSearch)

    print("\n")

    print("{} was purchased {} time(s)".format(t_itemToSearch, x))

    print("\n")


    

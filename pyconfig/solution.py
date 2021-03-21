from typing import List
def read(filename: str, delim: str) -> List[int]:
    return list(map(int, open(filename, 'r').readlines()))

if __name__ == '__main__':
    print(read("data.txt", '\n'))

from typing import List

def read(filename: str, delim:str) -> List[int]:
    return list(map(lambda x: int(x), open(filename).read().split(delim)[:-1]))




def main() -> None:
    print(read("data.txt", '\n'))


if __name__ == '__main__':
    main()

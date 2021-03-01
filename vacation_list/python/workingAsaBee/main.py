import os
import glob
import socket
import sys




def more(text, numlines=15):
    lines = text.splitlines()
    while lines:
        chunk = lines[:numlines]
        lines = lines[numlines:]
        for line in chunk: print(line)
        if lines and input('More?') not in ["y", "Y"]: break



if __name__ == "__main__":
    import sys

    a = str(help(os))
    more(a)
    a = input("ok")


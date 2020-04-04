import numpy as np
import sys
from itertools import combinations

def complement(bits): return [
    '_' if b is '_' else
    '1' if b=='0' else '0'
    for b in bits
]

class Barray():
    def __init__(self, B):
        self.bits = ['_'] * B
        self.unkowns = list(range(B))
        self.read(10)
        self.run()

    def read(self, n):
        for _ in range(n):
            i = self.unkowns.pop()
            self.bits[i] = self.read_bit(i+1)
            self.unkowns = self.unkowns[::-1]
        self.update_stat()

    def read_bit(self, i):
        print(i, flush=True)
        return input()

    def get_index(self):
        cdt = list(set(range(B)) - set(self.unkowns))
        max_stat = len(set(map(tuple, self.states)))
        for idx in combinations(cdt, 2):
            no_stst = len(set(
                tuple(np.take(state, idx))
                for state in self.states
            ))
            if no_stst == max_stat: return idx
    
    def update_stat(self):
        self.bits_c  = complement(self.bits)
        self.bits_cr = self.bits_c[::-1]
        self.bits_r  = complement(self.bits_cr)
        self.states = [self.bits, self.bits_c, self.bits_cr, self.bits_r]

    def clps(self):
        test_idx = self.get_index()
        test = [self.read_bit(i+1) for i in test_idx]

        self.bits = next(state
            for state in self.states
            if test == list(np.take(state, test_idx))
        )

    def run(self):
        while True:
            self.clps()
            try: self.read(8)
            except IndexError: break


_case, B = map(int, input().split())
print('B:', B, file=sys.stderr)
for _ in range(_case):
    array = Barray(B)
    print('guess:', ''.join(array.bits), file=sys.stderr)
    print(''.join(array.bits), flush=True)
    if input() == 'N': sys.exit()

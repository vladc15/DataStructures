from numpy import *
import time

# selection sort
def findMaxAndSwap(L, n):
    maxim = L[n]
    poz = n
    for i in range(n-1, 0, -1):
        if L[i] > maxim:
            maxim = L[i]
            poz = i
    L[poz], L[n] = L[n], L[poz]

def selectionSort(L):
    n = len(L)
    for i in range(n-1, 0, -1):
        findMaxAndSwap(L, i)

# heapsort

def heapify(H, size, i):
    if (2*i > size):
        return
    largest = i
    if (2*i <= size and H[i] < H[2*i]):
        largest = 2*i
    else:
        largest = i
    if (2*i+1 <= size and H[largest] < H[2*i+1]):
        largest = 2*i+1
    if (largest != i):
        H[i], H[largest] = H[largest], H[i]
        heapify(H, size, largest)

def buildHeap(L):
    n = len(L)-1
    for i in range(n//2 + n % 2, 0, -1):
        heapify(L, n, i)

def findMaxAndSwapHeap(L, i):
    L[1], L[i] = L[i], L[1]

def heapSort(L):
    n = len(L)
    for i in range(n-1, 0, -1):
        findMaxAndSwapHeap(L, i)
        heapify(L, i - 1, 1)

#L = [0] + [1, 3, 2, 5, 4]
L = [0] + random.permutation(10000).tolist()
L1 = L.copy()
L2 = L.copy()

t0 = time.time()
selectionSort(L1)
t1 = time.time()
buildHeap(L2)
heapSort(L2)
t2 = time.time()

print(t1 - t0)
print(t2 - t1)
#print(L1 == L2)



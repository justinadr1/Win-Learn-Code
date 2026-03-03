import threading
import time

def task(n):
    tid = threading.get_ident()
    print(f"thread id = {tid}, n = {n}")
    
threads = []

for i in range(1, 6):
    t = threading.Thread(target=task, args=(i,))
    threads.append(t)
    t.start()
    time.sleep(1)

print("main id:", threading.get_ident())

for t in threads:
    t.join()
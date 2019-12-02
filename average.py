import subprocess
import sys

# run the program a with inputs num, name
def s(a, num, name):
  return subprocess.check_output([a, str(num), name])

# create input files with names starting with batchname
# eg: batch100.txt, batch200.txt etc
def createInputs(batchname):
  s("create", 100, batchname)
  s("create", 200, batchname)
  s("create", 300, batchname)
  s("create", 400, batchname)
  s("create", 500, batchname)
  s("create", 600, batchname)
  s("create", 700, batchname)
  s("create", 800, batchname)
  s("create", 900, batchname)
  s("create", 1000, batchname)
  s("create", 1500, batchname)
  s("create", 2000, batchname)
  s("create", 2500, batchname)
  s("create", 3000, batchname)
  s("create", 4000, batchname)
  s("create", 5000, batchname)
  s("create", 6000, batchname)
  s("create", 7000, batchname)
  s("create", 8000, batchname)
  s("create", 9000, batchname)
  s("create", 100000, batchname)

# run the average for one number on type a
def s2(a, num):
  print("Calculating " + a + " average runtime for " + str(num) + " inputs...")
  av = 0
  dist = -1
  for i in range(3):
    createInputs(a + str(i))                    # create the input file for this test
    x = str.split(str(s(a, num, a + str(i))))   # run the program on the input, split it's output into a list
    av2 = int(x[0][2:])                         # grab the runtime (cut off b')
    dist = float(x[1])                          # grab the distance between closest points
    p1 = str(x[2])                              # grab the first point
    p2 = str(x[3][:-1])                         # grab the second point (cut off end bytestring)
    av += av2                                   # add to average

    print("Completed iteration in " + str(av2) + " μs, got " + str(dist) + " units apart.")
    print("Points: " + p1 + ", " + p2)
  av = (av) / 3                                 # calculate the average
  print("########## Average runtime for " + str(num) + " inputs: " + str(av) + " μs.")

# run algorithm tp, get the runtimes (average it), print it.
def run(tp):
  print("Average runtimes:")
  s2(tp, 100)
  s2(tp, 200)
  s2(tp, 300)
  s2(tp, 400)
  s2(tp, 500)
  s2(tp, 600)
  s2(tp, 700)
  s2(tp, 800)
  s2(tp, 900)
  s2(tp, 1000)
  s2(tp, 1500)
  s2(tp, 2000)
  s2(tp, 2500)
  s2(tp, 3000)
  s2(tp, 4000)
  s2(tp, 5000)
  s2(tp, 6000)
  s2(tp, 7000)
  s2(tp, 8000)
  s2(tp, 9000)
  s2(tp, 100000)

run("brute")
print("--------------------------")
print("--------------------------")
run("divide")

from subprocess import Popen, PIPE
import subprocess
filename = "random_file"
total_bytes = 100
block_size = 100

process = subprocess.Popen(["./create_random_file", filename, "%d" % total_bytes, "%d" % block_size],stdout=PIPE)
stdout = process.stdout.readline()#process.communicate()[0]

stdout_array = stdout.split()
time = stdout_array[0]

f = open('result.txt', 'w')
f.write(str(time) + " " + str(block_size) + "\n")
f.close()

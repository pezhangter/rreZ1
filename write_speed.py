from subprocess import Popen, PIPE
import subprocess
KB = 1024
MB = 1024 * KB
filename = "random_file"
total_bytes = 20 * MB
block_sizes = [100, 500, 1 * KB, 5 * KB, 10 * KB, 50 * KB, 100 * KB, 500 * KB, 1 * MB, 3 * MB]
f = open('result.txt', 'w')
for i in range(10):
    process = subprocess.Popen(["./create_random_file", filename, "%d" % total_bytes, "%d" % block_sizes[i]],stdout=PIPE,shell=True)
    stdout = process.communicate()[0]#process.stdout.readline()#
    stdout_array = stdout.split()
    time = stdout_array[0]
    f.write(str(time) + " " + str(block_sizes[i]) + "\n")
f.close()
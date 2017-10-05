from subprocess import Popen, PIPE
import subprocess

KB = 1024
MB = 1024 * KB
filename = "random_file"
block_sizes = [100, 500, 1 * KB, 5 * KB, 10 * KB, 50 * KB, 100 * KB, 500 * KB, 1 * MB, 3 * MB]
f = open('read_result.txt', 'w')
for i in range(10):
	process = subprocess.Popen(["./get_histogram", filename, "%d" % block_sizes[i]],stdout=PIPE)
	stdout = process.communicate()[0]#process.stdout.readline()#
	stdout_array = stdout.split()
	speed = stdout_array[0]
	f.write(str(round(float(speed),2)) + " " + str(block_sizes[i]) + "\n")
f.close()
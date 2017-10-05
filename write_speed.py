from subprocess import Popen, PIPE
import subprocess

KB = 1024
MB = 1024 * KB
filename = "random_file"
total_bytes = 200 #* MB
block_sizes = [1,2,3,4,5,6,7,8,9,10]#[100, 500, 1 * KB, 5 * KB, 10 * KB, 50 * KB, 100 * KB, 500 * KB, 1 * MB, 3 * MB]
f = open('write_result.txt', 'w')
for i in range(10):
	process = subprocess.Popen(["./create_random_file", filename, "%d" % total_bytes, "%d" % block_sizes[i]],stdout=PIPE)
	stdout = process.communicate()[0]#process.stdout.readline()#
	stdout_array = stdout.split()
	time = stdout_array[0]
	f.write(str(round(float(total_bytes)/float(time),2))+ " " + str(block_sizes[i]) + "\n")
f.close()
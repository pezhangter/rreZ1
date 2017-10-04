import subprocess


filename = "random_file"
total_bytes = 100
block_size = 100

process = subprocess.Popen("./create_random_file", filename, total_bytes, block_size)
stdout = process.communicate[0]
stdout_array = stdout.split()
speed = stdout_array[0]

f = open('result.txt', 'w')
f.write(speed, block_size, "\n")
f.close()
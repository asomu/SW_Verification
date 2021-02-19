#%%
import subprocess
import os
cmd = ["python", "test.py"]
stdin_r, stdin_w = os.pipe()
stdout_r, stdout_w = os.pipe()
p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stdin=stdin_r)
a = p.communicate()
b = a[0].decode('utf-8')
b.strip()

# p.stdin.write(b"1")
# os.read()
# p = p.communicate()
# print(p)
# output = p.communicate("stdin input string")
# output = output[0].strip()
# print(output.decode('utf-8'))

# %%
import subprocess
p = subprocess.run(["dir"], shell=True, stdout=subprocess.PIPE)

# %%
import subprocess
cmd = ["python", "test.py"]
data = b"Hello World\r\n"
data2 = b"What's going on"
p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stdin=subprocess.PIPE)
p.stdin.write(data)
p.stdin.write(data2)

ret = p.communicate()

print(ret)

# %%

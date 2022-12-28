rm -f cipher.txt plaintext.txt
g++ generateInput.cpp -o gInp.out
g++ input.cpp -o input.out
./gInp.out > plaintext.txt
./input.out > in.txt
sshpass -p "cs641a" ssh students@172.27.26.188 < in.txt > out.txt 
python3 clean.py
rm in.txt out.txt
rm gInp.out  input.out

g++ -c ./src/main/main.cpp -o out/main.o
g++ -o out/run.exe ./out/*.o
rm ./out/*.o
./out/run.exe
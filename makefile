queens: main.o
      g++ -g -o -c queens.cpp

main.o: queens.cpp
        g++ -g -c queens.cpp
        
    clean: 
        rm -r ".o"
        rm queens
        
 run queens
        ./queens

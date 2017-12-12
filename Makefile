CMP = g++ -std=c++11
CLASS = enemyship
CLASS2 = ship
MAIN = project
EXEC = galaga

$(EXEC): $(CLASS).o $(MAIN).o $(CLASS2).o
	$(CMP) gfxnew.o -lX11 $(CLASS).o $(CLASS2).o $(MAIN).o -o $(EXEC)

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp -o $(CLASS).o

$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h
	$(CMP) -c $(CLASS2).cpp -o $(CLASS2).o

$(MAIN).o: $(MAIN).cpp $(CLASS).h 
	$(CMP) -c $(MAIN).cpp -o $(MAIN).o

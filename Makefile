all: ./a.out

compRun:
	g++ -std=c++11 main.cpp registrationRunner.cpp exeAddCandidate.cpp PartyCandidate.cpp Party.cpp PartyRegistration.cpp addCities.cpp sectorModuleRunner.cpp addSectors.cpp Province.cpp Provinces.cpp Address.cpp District.cpp Sector.cpp Person.cpp Candidate.cpp Voter.cpp FederalSector.cpp ProvisionalSector.cpp -o r.out
compTest:
	g++ -std=c++11 -o a.out

test: clean compTest; ./a.out

run: clean compRun; ./r.out

clean:
	rm -f *.out

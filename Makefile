

CXX = g++
CXXFLAGS = -Wall

#----------------------------------------------------------------------------

main:	User.o schedule.o statistics.o systemAccess.o bill.o coronaInfo.o main.o
	${CXX} ${CXXFLAGS} User.o schedule.o statistics.o systemAccess.o bill.o coronaInfo.o main.o -o CPSIC 

User.o:	User.h ksuPatient.h ksuPatient.cpp hsFaculty.h hsFaculty.cpp

schedule.o:	schedule.h schedule.cpp
	${CXX} ${CXXFLAGS} -c schedule.cpp

statistics.o:	statistics.h statistics.cpp 
	${CXX} ${CXXFLAGS} -c statistics.cpp

systemAccess.o:	systemAccess.h systemAccess.cpp
	${CXX} ${CXXFLAGS} -c systemAccess.cpp

bill.o:	bill.h bill.cpp
	${CXX} ${CXXFLAGS} -c bill.cpp

coronaInfo.o:	coronaInfo.h coronaInfo.cpp
	${CXX} ${CXXFLAGS} -c coronaInfo.cpp

main.o:	main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

#----------------------------------------------------------------------------

clean:
#	rm -f CPSIC  # removes the executable CPSIC
	rm -f *.o  # remove ALL object files in the directory

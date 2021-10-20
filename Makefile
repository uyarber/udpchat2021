#MakeFile to build simple UPS client server program
# For CSC Computer Networking

CC= g++

FLAGS = -L -lsocket -lnsl


all:	server client

server.o: server.cpp	
		$(CC) -c server.cpp

client.o: client.cpp	
		$(CC) -c client.cpp

server: server.o
		$(CC) server.o -o server $(FLAGS)

client: client.o
		$(CC) client.o -o client $(FLAGS)


clean:
		rm -f *.o client server